 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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
#include "rlc.h"
#include "math.h"
#include "display.h"


/* SAMPLE_NO - number of complete waveform used for computation
 * 
 *   Maximum value for SAMPLE_NO is 32 with op. gain set to 2
 */

#define SAMPLE_NO                   16
#define SAMPLE_NO_CALIBRATION       4
#define BUFFER_NO                   4

extern uint8_t adcSamplesArray[512];
extern uint8_t adcSamplesArray3[512];

int16_t voltageSampleArray[WAVE_STEPS];
int16_t currentSampleArray[WAVE_STEPS];

volatile bool dma1TransferEnded = false;
volatile bool dma3TransferEnded = false;
volatile bool dmaTransferDone = false;

static int16_t *adcValue;
static uint8_t dmaCounter;

enum COMPONENT component = CAPACITOR;

/*
    Main application
*/

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
    LED0_Toggle();
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
    LED0_Toggle();
}

void Aquire_Waveform(void)
{
    DMA1_TransferWithTriggerStart();
    EnableADCTrigger();
    while (dma1TransferEnded != true){};
    DisableADCTrigger();       
    dma1TransferEnded = false;    
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
    
    DMA1_TransferWithTriggerStart();
    EnableADCTrigger();
    
    while (rawDataReady == false)
    {
       if (dma1TransferEnded == true)
       {
            adcValue = (int16_t*)adcSamplesArray;
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
}

float Abs_Val(float x)
{
    return x > 0 ? x : (-1.0 * x);
}

int main(void)
{
    uint8_t bufferIndex = 0;
    bool bufferFull = false;
    float resultsBuffer[BUFFER_NO] = {0};
    float theta;
    float Q;
    float result;
    
    volatile bool componentDetected = false;
    volatile bool newComponent = false;
    volatile uint8_t vGainIndex = OPA2_R2byR1_is_1;
    volatile uint8_t iGainIndex = OPA2_R2byR1_is_1;
    volatile bool vGainOk = false;
    volatile bool iGainOk = false;
    
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable();
    
    Display_Init();
    Display_Interface();
    Display_No_Component();
    
    printf("Start\n\r");
    
    DMA1_SetDCNTIInterruptHandler(DMA1_Transfer_Ended_Handler);
    DMA3_SetDCNTIInterruptHandler(DMA3_Transfer_Ended_Handler);
    
    LED0_SetLow();

    adcValue = (int16_t*)adcSamplesArray;
   
    TMR0_Reload(TIMER0_PERIOD);
    TMR4_PeriodCountSet((TIMESAMPLING_RATE - 1)); 
    EnableClock();
    __delay_ms(10);
    EnableWaveformGenerator();
    
    while (1)
    {
        if (componentDetected == false)
        {
            // Automatic gain selection when a component is inserted
            
            SelectVoltage();

            GainSet(vGainIndex);
            Set_VGain(vGainIndex);

            __delay_ms(7); 
            Get_Raw_Data(SAMPLE_NO_CALIBRATION, voltageSampleArray);

            SelectCurrent();

            GainSet(iGainIndex);
            Set_IGain(iGainIndex);

            __delay_ms(13); 
            Get_Raw_Data(SAMPLE_NO_CALIBRATION, currentSampleArray);

            Process_Impedance_Values();
            
            if (Abs_Val(Get_VReal()) < V_REAL_MIN || Abs_Val(Get_VImag()) < V_IMAG_MIN)
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
            
            else if (Abs_Val(Get_VReal()) > V_REAL_MAX || Abs_Val(Get_VImag()) > V_IMAG_MAX)
            {
                if(vGainIndex > 0) 
                {
                    vGainIndex--;
                }
                else
                {
                    vGainOk = true;
                }
            }
            
            else
            {
                vGainOk = true;
            }
            
            if (Abs_Val(Get_IReal()) < I_REAL_MIN || Abs_Val(Get_IImag()) < I_IMAG_MIN)
            {
                if(iGainIndex < 7)
                {
                    iGainIndex = iGainIndex + 1;
                }
                else
                {
                    iGainOk = true;
                }
            }
            
            else if (Abs_Val(Get_IReal()) > I_REAL_MAX || Abs_Val(Get_IImag()) > I_IMAG_MAX)
            {
                if(iGainIndex > 0) 
                {
                    iGainIndex--;
                }
                else
                {
                    iGainOk = true;
                }
            }
            
            else
            {
                iGainOk = true;
            }
            
            printf("Vr: %.3f\n\r",Get_VReal());
            printf("Vi: %.3f\n\r",Get_VImag());
            printf("Ir: %.3f\n\r",Get_IReal());
            printf("Ii: %.3f\n\r",Get_IImag());
            printf("Zr: %.3f\n\r",Get_ZReal());
            printf("Zi: %.3f\n\r",Get_ZImag());
            printf("\n\r");
            
            if(newComponent == true && vGainOk == true && iGainOk == true)
            {
                componentDetected = true;
                newComponent = false;
                bufferIndex = 0;
                bufferFull = false;
            }
            
            if ((Get_ZReal() < 2000000.0) && (Get_ZReal() > -2000000.0) && 
                (Get_ZImag() > -2000000.0) && (Get_ZImag() < 2000000.0)
                && componentDetected == false && newComponent == false)
            {
                newComponent = true;
                vGainIndex = OPA2_R2byR1_is_1;
                iGainIndex = OPA2_R2byR1_is_1;
                vGainOk = false;
                iGainOk = false;
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

            printf("Vr: %.3f\n\r",Get_VReal());
            printf("Vi: %.3f\n\r",Get_VImag());
            printf("Ir: %.3f\n\r",Get_IReal());
            printf("Ii: %.3f\n\r",Get_IImag());
            printf("Zr: %.3f\n\r",Get_ZReal());
            printf("Zi: %.3f\n\r",Get_ZImag());

            theta = ((Get_ZArg() * 180)/PI);

            if ((Get_ZReal() > 2000000.0) || (Get_ZReal() < -2000000.0) || 
                (Get_ZImag() < -2000000.0) ||(Get_ZImag() > 2000000.0))
            {
                printf("No component detected\n\r");
                Display_No_Component();
                componentDetected = false;
                vGainOk = false;
                iGainOk = false;
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
             
            resultsBuffer[bufferIndex++] = result;
            bufferIndex %= BUFFER_NO;
            
            if(bufferIndex == 0)
            {
                bufferFull = true;
            }
            
            if(bufferFull)
            {
                double meanResult = 0.0;
                for(uint8_t i = 0; i < BUFFER_NO; i++)
                {
                    meanResult += resultsBuffer[i];
                }
                
                result = meanResult / BUFFER_NO;
            }
            
            if(componentDetected)
            {
                Display_Result(component, result, Q, Get_ZMod(), theta);
            }
        }
    }          
}