 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "mcp6s26.h"
#include "rlc.h"
#include "display.h"

/*
    Main application
*/

/* 
    SAMPLE_NO - number of complete waveform used for computation
    SAMPLE_NO_AUTOGAIN - number of complete waveform used for computation for auto gain algorithm
    CALIBRATION_REPEAT_NO - repeat number for calibration process
*/
#define SAMPLE_NO                   16
#define SAMPLE_NO_AUTOGAIN          4
#define CALIBRATION_REPEAT_NO       8

#define CALIBRATION_DATA_ADDRESS    (EEPROM_START_ADDRESS)
#define CALIBRATION_DONE_STATUS     (0xAA)

extern uint8_t adcSamplesArray1[512];
extern uint8_t adcSamplesArray3[512];

int16_t voltageSampleArray[WAVE_STEPS];
int16_t currentSampleArray[WAVE_STEPS];

uint32_t voltageRealMax;
uint32_t voltageImagMax;
uint32_t currentRealMax;
uint32_t currentImagMax;

float oldZReal = 0.0, oldZImag = 0.0;
float oldVRealUnscaled = 0.0, oldVImagUnscaled = 0.0, oldIRealUnscaled = 0.0, oldIImagUnscaled = 0.0;

volatile bool dma1TransferEnded = false;
volatile bool dma3TransferEnded = false;
volatile bool dmaTransferDone = false;
volatile bool buttonShortPress = false;
volatile bool buttonLongPress = false;
volatile bool buttonPress = false;
volatile uint8_t vGainIndex = MCP6S26_GAIN_1X;
volatile uint8_t iGainIndex = MCP6S26_GAIN_1X;

static calibration_state_t calibrationState = VOLTAGE_PREPARE;
static int16_t *adcValue;
static uint8_t dmaCounter;

enum COMPONENT component = CAPACITOR;

void Button_Handler(void)
{
    __delay_ms(10); // Debouncing
    if(!(BUTTON_GetValue() & 0x01))
    {
       buttonPress = true;
       TMR2_Write(0x00);
       TMR2_Start(); 
    }
    else if(buttonPress)
    {
        buttonPress = false;
        buttonShortPress = true;
        TMR2_Stop();
    }
}

void TMR2_Handler(void)
{
    buttonLongPress = true;
    buttonPress = false;
    TMR2_Stop();
}

void PWM2_Set_Autoload_Trigger(void)
{
    //PWMLDS DMA2_Destination_Count_Done;
    PWM2LDS = 0xC;
}

void DMA1_Transfer_Ended_Handler(void)
{
    dmaCounter--; 
    if (dmaCounter == 0)
    {
        DisableADCTrigger();
        dmaTransferDone = true;
    }
    else
    {
        DMA3_TransferWithTriggerStart();
    }
    dma1TransferEnded = true;        
    DEBUG_PIN1_Toggle();
}

void DMA3_Transfer_Ended_Handler(void)
{
    dmaCounter--; 
    if (dmaCounter == 0)
    {
        DisableADCTrigger();
        dmaTransferDone = true;
    } 
    else
    {
        DMA1_TransferWithTriggerStart();
    }
    dma3TransferEnded = true;        
    DEBUG_PIN1_Toggle();
}

void Get_Raw_Data(uint8_t noSamples, int16_t* dataBuffer)
{
    static bool rawDataReady;
    
    rawDataReady = false;
    
    dmaCounter = noSamples;
    dma1TransferEnded = false;    
    dma3TransferEnded = false;
    dmaTransferDone = false;
    
    for (uint8_t i = 0; i < WAVE_STEPS; i++)
    {
        dataBuffer[i] = 0;
    }
    
    DEBUG_LED_Toggle();
    
    DMA1_TransferWithTriggerStart();
    EnableADCTrigger();
    
    while (rawDataReady == false)
    {
       if (dma1TransferEnded == true)
       {
            adcValue = (int16_t*)adcSamplesArray1;
            for (uint8_t i = 0; i < WAVE_STEPS; i++)
            {
                dataBuffer[i] += adcValue[i];
            }           
            dma1TransferEnded = false;  
       }
       
       if (dma3TransferEnded == true)
       {
            adcValue = (int16_t*)adcSamplesArray3;
            for (uint8_t i = 0; i < WAVE_STEPS; i++)
            {
                dataBuffer[i] += adcValue[i];
            }
            dma3TransferEnded = false;  
       }    
       
       if ((dmaTransferDone == true) && (dma1TransferEnded == false) && (dma3TransferEnded == false))
       {
           rawDataReady = true;
       }
    }
    
    DEBUG_LED_Toggle();
}

float Abs_Val(float x)
{
    return x > 0.0 ? x : (-1.0 * x);
}

void EEPROM_Write_Double_Word(eeprom_address_t address, uint32_t data)
{
    eeprom_data_t tmpData;
    
    NVM_UnlockKeySet(UNLOCK_KEY);
    
    tmpData = (uint8_t)((data & 0xFF000000) >> 24);
    while(NVM_IsBusy());
    EEPROM_Write(address, tmpData);
    
    tmpData = (uint8_t)((data & 0x00FF0000) >> 16);
    while(NVM_IsBusy());
    EEPROM_Write(address + 1, tmpData);
    
    tmpData = (uint8_t)((data & 0x0000FF00) >> 8);
    while(NVM_IsBusy());
    EEPROM_Write(address + 2, tmpData);
    
    tmpData = (uint8_t)((data & 0x000000FF) >> 0);
    while(NVM_IsBusy());
    EEPROM_Write(address + 3, tmpData);
    
    NVM_UnlockKeyClear();
}

bool Check_Calibration_Mode(bool calibrationMode)
{
    if(buttonLongPress == true)
    {
        buttonLongPress = false;
            
        if(calibrationMode == false)
        {
            calibrationMode = true;
            calibrationState = VOLTAGE_PREPARE;
                
            printf("\n\rEnter calibration mode. Long press the button for exit.\n\r");
            Display_Message("Calibration mode", "Long press exit");
            __delay_ms(1000);
        }
            
        else
        {
            calibrationMode = false;
            printf("\n\rExit calibration mode.\n\r");
            Display_Message("", "");
        }
    }
    
    return calibrationMode;
}

bool Calibration_Process(void)
{
    static uint32_t voltageRealCalibrationValue = 0;
    static uint32_t voltageImagCalibrationValue = 0;
    static uint32_t currentRealCalibrationValue = 0;
    static uint32_t currentImagCalibrationValue = 0;
    
    switch(calibrationState)
    {
        case VOLTAGE_PREPARE:
        {
            printf("\n\r");
            printf("Voltage calibration\n\r");
            printf("DUT must not be inserted\n\r");
            printf("Short press to start the calibration\n\r\n\r");
            Display_Message("Voltage calib", "DUT not connect");
                    
            calibrationState = VOLTAGE_CALIBRATION;
                    
            break;
        }
                
        case VOLTAGE_CALIBRATION:
        {
            if(buttonShortPress == true)
            {
                buttonShortPress = false;
                        
                printf("Calibration...\n\r");
                Display_Message("Calibration...", "");
                        
                voltageRealCalibrationValue = 0;
                voltageImagCalibrationValue = 0;
                
                uint8_t vGainIndex = MCP6S26_GAIN_1X;
                        
                SelectVoltage();

                GainSet(vGainIndex);
                Set_VGain(vGainIndex);

                __delay_ms(7); 
                
                for(uint8_t i = 0; i < CALIBRATION_REPEAT_NO; i++)
                {
                    Get_Raw_Data(1, voltageSampleArray);

                    Process_Impedance_Values();
                    
                    // The maximum value is considered to be 40% grater than the read value
                    voltageRealCalibrationValue += (uint32_t)(1.4 * Abs_Val(Get_VRealUnscaled()));
                    voltageImagCalibrationValue += (uint32_t)(1.4 * Abs_Val(Get_VImagUnscaled()));
                }
                
                calibrationState = CURRENT_PREPARE;
            }
                    
            break;
        }
                
        case CURRENT_PREPARE:
        {
            printf("\n\r");
            printf("Current calibration\n\r");
            printf("The DUT terminals must be in short circuit\n\r");
            printf("Short press to start the calibration\n\r\n\r");
            Display_Message("Current calib", "DUT in short");
                    
            calibrationState = CURRENT_CALIBRATION;
                    
            break;
        }
                
        case CURRENT_CALIBRATION:
        {
            if(buttonShortPress == true)
            {
                buttonShortPress = false;
                        
                printf("Calibration...\n\r");
                Display_Message("Calibration...", "");
                        
                currentRealCalibrationValue = 0;
                currentImagCalibrationValue = 0;
                
                uint8_t iGainIndex = MCP6S26_GAIN_1X;

                SelectCurrent();

                GainSet(iGainIndex);
                Set_IGain(iGainIndex);

                __delay_ms(13);
                
                for(uint8_t i = 0; i < CALIBRATION_REPEAT_NO; i++)
                { 
                    Get_Raw_Data(1, currentSampleArray);

                    Process_Impedance_Values();
                    
                    // The maximum value is considered to be 40% grater than the read value
                    currentRealCalibrationValue += (uint32_t)(1.4 * Abs_Val(Get_IRealUnscaled()));
                    currentImagCalibrationValue += (uint32_t)(1.4 * Abs_Val(Get_IImagUnscaled()));
                }
                
                calibrationState = WRITE_CALIBRATION;
            }
                    
            break;
        }
                
        case WRITE_CALIBRATION:
        {       
            voltageRealMax = (uint32_t)(voltageRealCalibrationValue / CALIBRATION_REPEAT_NO);
            voltageImagMax = (uint32_t)(voltageImagCalibrationValue / CALIBRATION_REPEAT_NO);
            currentRealMax = (uint32_t)(currentRealCalibrationValue / CALIBRATION_REPEAT_NO);
            currentImagMax = (uint32_t)(currentImagCalibrationValue / CALIBRATION_REPEAT_NO);
                    
            // Store calibration data in EEPROM
            eeprom_address_t address = CALIBRATION_DATA_ADDRESS;
                    
            EEPROM_Write_Double_Word(address + 1, voltageRealMax);
            EEPROM_Write_Double_Word(address + 5, voltageImagMax);
            EEPROM_Write_Double_Word(address + 9, currentRealMax);
            EEPROM_Write_Double_Word(address + 13, currentImagMax);
            
            // Store calibration done status in EEPROM
            NVM_UnlockKeySet(UNLOCK_KEY);
                    
            while(NVM_IsBusy());
            EEPROM_Write(address, CALIBRATION_DONE_STATUS);
                    
            NVM_UnlockKeyClear();
            
            printf("\n\r");
            printf("Calibration data:\n\r");
            printf("V REAL MAX: %lu\n\r", voltageRealMax);
            printf("V IMAG MAX: %lu\n\r", voltageImagMax);                 
            printf("I REAL MAX: %lu\n\r", currentRealMax);
            printf("I IMAG MAX: %lu\n\r", currentImagMax); 
            printf("\n\r");
            printf("Calibration done.\n\r\n\r");
            Display_Message("Calibration done", "");
            __delay_ms(2000);
            Display_Message("", "");
            
            return true;
                    
            break;
        }
                
        default:
        {
            break;
        }
    }
    
    return false;
}

bool Autogain_Process(void)
{
    static bool newComponent = false;
    static bool vGainOk = false;
    static bool iGainOk = false;
    
    SelectVoltage();

    GainSet(vGainIndex);
    Set_VGain(vGainIndex);

    __delay_ms(7); 
    Get_Raw_Data(SAMPLE_NO_AUTOGAIN, voltageSampleArray);
            
    SelectCurrent();

    GainSet(iGainIndex);
    Set_IGain(iGainIndex);

    __delay_ms(13); 
    Get_Raw_Data(SAMPLE_NO_AUTOGAIN, currentSampleArray);

    Process_Impedance_Values();
            
    printf("New component: %hhu\n\r", newComponent);
    printf("Vgain: %.1f, Igain: %.1f\n\r", Get_Gain(vGainIndex), Get_Gain(iGainIndex));
    printf("vRealUn: %.2f\n\r", Get_VRealUnscaled());
    printf("vImagUn: %.2f\n\r", Get_VImagUnscaled());
    printf("iRealUn: %.2f\n\r", Get_IRealUnscaled());
    printf("iImagUn: %.2f\n\r\n\r", Get_IImagUnscaled());
    printf("\n\r");
    
    // A new component is detected when the calculated values are relatively stable for two consecutive reads
    if((newComponent == false && Abs_Val(Get_ZReal() - oldZReal) < 15000.0 && Abs_Val(Get_ZImag() - oldZImag) < 15000.0)
        && (   ( (Abs_Val(Get_VRealUnscaled() - oldVRealUnscaled) < 100.0) && (Abs_Val(Get_VImagUnscaled() - oldVImagUnscaled) < 100.0) )
            || ( (Abs_Val(Get_IRealUnscaled() - oldIRealUnscaled) < 100.0) && (Abs_Val(Get_IImagUnscaled() - oldIImagUnscaled) < 100.0) ) )
        )
    {
        newComponent = true;
        vGainIndex = MCP6S26_GAIN_1X;
        iGainIndex = MCP6S26_GAIN_1X;
        vGainOk = false;
        iGainOk = false;
                
        Display_Message("Measuring...", "");
    }
            
    if(newComponent == true)
    {
        if(!vGainOk)
        {
            if (Abs_Val(Get_VRealUnscaled()) > voltageRealMax*SAMPLE_NO_AUTOGAIN || Abs_Val(Get_VImagUnscaled()) > voltageImagMax*SAMPLE_NO_AUTOGAIN)
            {
                if(vGainIndex > 0)
                {
                        vGainIndex--;
                }
                        
                vGainOk = true;
            }
                    
            else
            {
                if(vGainIndex < 7) 
                {
                    vGainIndex++;
                }
                else
                {
                    vGainOk = true;
                }
            }
        }
        
        // The auto gain algorithm finds the maximum gain that not saturates the output for voltage and current measurements
        // The saturation is detected when the output exceeds the maximum value determined in the calibration process
        // The comparison is done on the unscaled (raw) values that are not divided by gain
        if(!iGainOk)
        {
            if (Abs_Val(Get_IRealUnscaled()) > currentRealMax*SAMPLE_NO_AUTOGAIN || Abs_Val(Get_IImagUnscaled()) > currentImagMax*SAMPLE_NO_AUTOGAIN)
            {
                if(iGainIndex > 0)
                {
                    iGainIndex--;
                }

                iGainOk = true;
            }
                    
            else 
            {
                if(iGainIndex < 7)
                {
                    iGainIndex++;
                }
                else
                {
                    iGainOk = true;
                }
            }
        }
        
        if(vGainOk == true && iGainOk == true)
        {
            newComponent = false;
                
            Display_Message("", "");
        
            return true;
        }
    }
             
    return false;
}

int main(void)
{
    float theta;
    float Q;
    float result;
    
    volatile bool componentDetected = false;
    volatile bool calibrationMode = false;
    
    SYSTEM_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable();
    
    PWM2_Set_Autoload_Trigger();
    
    DMA1_SetDCNTIInterruptHandler(DMA1_Transfer_Ended_Handler);
    DMA3_SetDCNTIInterruptHandler(DMA3_Transfer_Ended_Handler);
    
    BUTTON_SetInterruptHandler(Button_Handler);
    TMR2_PeriodMatchCallbackRegister(TMR2_Handler);
    
    DEBUG_LED_SetLow();
    DEBUG_PIN1_SetLow();
    
    adcValue = (int16_t*)adcSamplesArray1;
    
    TMR0_PeriodSet(TIMER0_PERIOD);
    TMR4_PeriodSet(timesamplingRates[TIMESAMPLING_RATE] - 1); 
    
    Display_Init(); 
    Display_Interface();
    Display_No_Component();

    EnableClock();
    __delay_ms(10);
    EnableWaveformGenerator();
    __delay_ms(10);
    
    // Verify if the calibration data are already stored in EEPROM
    while(NVM_IsBusy());
    eeprom_data_t data = EEPROM_Read(CALIBRATION_DATA_ADDRESS);
    
    if(data != CALIBRATION_DONE_STATUS)
    {
        // If calibration data are not available, the calibration process must be done before starting the application
        
        calibrationMode = true;
        calibrationState = VOLTAGE_PREPARE;
        
        printf("Calibration data are not available\n\r");
        Display_Message("Calibration data", "not available");
        __delay_ms(2000);
    }
    
    else
    {
        // If calibration data are available, they should be read from EEPROM
        
        calibrationMode = false;
        
        printf("Read calibration data\n\r");
        Display_Message("Read calibration", "data");
        __delay_ms(1000);
        
        eeprom_address_t address = CALIBRATION_DATA_ADDRESS;
        eeprom_data_t data[16];
        
        for(uint32_t i = 0; i < 16; i++)
        {
            while(NVM_IsBusy());
            data[i] = EEPROM_Read(address + i + 1);
        }
        
        voltageRealMax = (uint32_t)((((uint32_t)data[0] & 0x00000FF) << 24) | (((uint32_t)data[1] & 0x00000FF) << 16) | (((uint32_t)data[2] & 0x00000FF) << 8) | (((uint32_t)data[3] & 0x00000FF) << 0));
        voltageImagMax = (uint32_t)((((uint32_t)data[4] & 0x00000FF) << 24) | (((uint32_t)data[5] & 0x00000FF) << 16) | (((uint32_t)data[6] & 0x00000FF) << 8) | (((uint32_t)data[7] & 0x000000FF) << 0));
        currentRealMax = (uint32_t)((((uint32_t)data[8] & 0x00000FF) << 24) | (((uint32_t)data[9] & 0x00000FF) << 16) | (((uint32_t)data[10] & 0x00000FF) << 8) | (((uint32_t)data[11] & 0x000000FF) << 0));
        currentImagMax = (uint32_t)((((uint32_t)data[12] & 0x00000FF) << 24) | (((uint32_t)data[13] & 0x00000FF) << 16) | (((uint32_t)data[14] & 0x00000FF) << 8) | (((uint32_t)data[15] & 0x000000FF) << 0));
        
        printf("\n\r");
        printf("Calibration data:\n\r");
        printf("V REAL MAX: %lu\n\r", voltageRealMax);
        printf("V IMAG MAX: %lu\n\r", voltageImagMax);                 
        printf("I REAL MAX: %lu\n\r", currentRealMax);
        printf("I IMAG MAX: %lu\n\r", currentImagMax); 
        
        Display_Message("", "");
    }

    while(1)
    {   
        calibrationMode = Check_Calibration_Mode(calibrationMode);
        
        if(calibrationMode == true)
        {
            if(Calibration_Process() == true)
            {
                calibrationMode = false;
            }
        }
            
        else if(componentDetected == false)
        {
            // Automatic gain selection when a component is inserted
            
            if(Autogain_Process() == true)
            {
                componentDetected = true;
            }
        }
        
        else
        {
            SelectVoltage();

            GainSet(vGainIndex);
            Set_VGain(vGainIndex);

            __delay_ms(7); 
            Get_Raw_Data(SAMPLE_NO, voltageSampleArray);
            
            SelectCurrent();

            GainSet(iGainIndex);
            Set_IGain(iGainIndex);

            __delay_ms(13); 
            Get_Raw_Data(SAMPLE_NO, currentSampleArray);

            Process_Impedance_Values(); 

            printf("Vgain: %.1f, Igain: %.1f\n\r", Get_Gain(vGainIndex), Get_Gain(iGainIndex));
            printf("Vr: %.3f\n\r",Get_VReal());
            printf("Vi: %.3f\n\r",Get_VImag());
            printf("Ir: %.3f\n\r",Get_IReal());
            printf("Ii: %.3f\n\r",Get_IImag());
            printf("Zr: %.3f\n\r",Get_ZReal());
            printf("Zi: %.3f\n\r",Get_ZImag());

            theta = ((Get_ZArg() * 180)/PI);
            
            // It is considered that no component is inserted when two consecutive reads are very different
            if(Abs_Val(Get_ZReal() - oldZReal) > 15000.0 || Abs_Val(Get_ZImag() - oldZImag) > 15000.0)
            {
                Display_No_Component();
                printf("No component detected\n\r");
                componentDetected = false;
                vGainIndex = MCP6S26_GAIN_1X;
                iGainIndex = MCP6S26_GAIN_1X;
            }
            
            else if((theta >= 4.0) && (theta < 176.0))
            {
                component = CAPACITOR;
                result = 1000000000.0;
                Q = Get_ZImag() / Get_ZReal();
                result = result/(2 * PI * FREQ * Get_ZImag());
                printf("Capacitor: %.3f nF\n\r", result);    
            }
            
            else if ((theta <= -4.0) && (theta > -176.0))
            {
                component = INDUCTOR;
                result = -1000.0;
                result = (result * Get_ZImag())/(2 * PI * FREQ);
                Q = Get_ZImag() / Get_ZReal();
                printf("Inductor: %.3f mF\n\r", result);
            }
            
            else
            {
                component = RESISTOR;
                result = Get_ZReal();
                printf("Resistor: %.3f Ohm\n\r", Get_ZReal());
            }
            printf("\n\r\n\r");  
            
            if(componentDetected == true)
            {
                Display_Result(component, result, Q, Get_ZMod(), theta);
            }
        }
        
        // Store the old calculated values for the next iteration
        oldZReal = Get_ZReal();
        oldZImag = Get_ZImag();
        
        oldVRealUnscaled = Get_VRealUnscaled();
        oldVImagUnscaled = Get_VImagUnscaled();
        oldIRealUnscaled = Get_IRealUnscaled();
        oldIImagUnscaled = Get_IImagUnscaled();
    }    
}