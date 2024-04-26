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

volatile bool dma1_transfer_ended = false;
volatile bool dma3_transfer_ended = false;
volatile bool dma_transfer_done = false;
volatile uint8_t adc_buffer_index = 0;
volatile bool adc_buffer_full = false;

static bool isVoltage = true;
static int16_t * adc_value;
static uint8_t dmaCounter;
static float dutRes, dutReact;

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
        dma_transfer_done = true;
    }
    else
    {
        DMA3_TransferWithTriggerStart();
    }
    dma1_transfer_ended = true;        
    LED0_Toggle();
}

void DMA3_Transfer_Ended_Handler(void)
{
    dmaCounter--; 
    if (dmaCounter == 0)
    {
        DisableADCTrigger();
        dma_transfer_done = true;
    } 
    else
    {
        DMA1_TransferWithTriggerStart();
    }
    dma3_transfer_ended = true;        
    LED0_Toggle();
}

void AquireWaveform(void)
{
    DMA1_TransferWithTriggerStart();
    EnableADCTrigger();
    while (dma1_transfer_ended != true){};
    DisableADCTrigger();       
    dma1_transfer_ended = false;    
}

void GetRawData(uint8_t noSamples, int16_t* dataBuffer)
{
    static bool raw_data_ready;
    
    raw_data_ready = false;
    
    dmaCounter = noSamples;
    dma1_transfer_ended = false;    
    dma3_transfer_ended = false;
    dma_transfer_done = false;
    
    for (uint8_t i = 0; i < WAVE_STEPS; i++)
    {
        dataBuffer[i] = 0;
    }
    
    DMA1_TransferWithTriggerStart();
    EnableADCTrigger();
    
    while (raw_data_ready == false)
    {
       if (dma1_transfer_ended == true)
       {
            adc_value = (int16_t*)adcSamplesArray;
            for (uint8_t i = 0; i < WAVE_STEPS; i++)
            {
                dataBuffer[i] += adc_value[i];
            }           
            dma1_transfer_ended = false;  
       }
       
       if (dma3_transfer_ended == true)
       {
            adc_value = (int16_t*)adcSamplesArray3;
            for (uint8_t i = 0; i < WAVE_STEPS; i++)
            {
                dataBuffer[i] += adc_value[i];
            }
            dma3_transfer_ended = false;  
       }    
       
       if ((dma_transfer_done == true) && (dma1_transfer_ended == false) && (dma3_transfer_ended == false))
       {
           raw_data_ready = true;
       }
    }
}

float abs_val(float x)
{
    return x > 0 ? x : (-1.0 * x);
}

int main(void)
{
    uint8_t dma1_transfer_number = 0;
    uint8_t buffer_index = 0;
    bool buffer_full = false;
    float results_buffer[BUFFER_NO] = {0};
    float theta;
    float Q;
    float result;
    
    volatile bool isComponent = false;
    volatile bool newComponent = false;
    volatile uint8_t v_gain_index = OPA2_R2byR1_is_1;
    volatile uint8_t i_gain_index = OPA2_R2byR1_is_1;
    volatile bool v_gain_ok = false;
    volatile bool i_gain_ok = false;
    
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

    adc_value = (int16_t*)adcSamplesArray;
   
    TMR0_Reload(TIMER0_PERIOD);
    TMR4_PeriodCountSet((TIMESAMPLING_RATE - 1)); 
    EnableClock();
    __delay_ms(10);
    EnableWaveformGenerator();
    dma1_transfer_number = 0;
    
    while (1)
    {
        if (isComponent == false)
        {
            // Automatic gain selection when a component is inserted
            
            SelectVoltage();

            GainSet(v_gain_index);
            set_vGain(v_gain_index);

            __delay_ms(7); 
            GetRawData(SAMPLE_NO_CALIBRATION, voltageSampleArray);

            SelectCurrent();

            GainSet(i_gain_index);
            set_iGain(i_gain_index);

            __delay_ms(13); 
            GetRawData(SAMPLE_NO_CALIBRATION, currentSampleArray);

            processImpedanceValues();
            
            if (abs_val(getVReal()) < V_REAL_MIN || abs_val(getVImag()) < V_IMAG_MIN)
            {
                if(v_gain_index < 7) 
                {
                    v_gain_index++;
                }
                else
                {
                    v_gain_ok = true;
                }
            }
            
            else if (abs_val(getVReal()) > V_REAL_MAX || abs_val(getVImag()) > V_IMAG_MAX)
            {
                if(v_gain_index > 0) 
                {
                    v_gain_index--;
                }
                else
                {
                    v_gain_ok = true;
                }
            }
            
            else
            {
                v_gain_ok = true;
            }
            
            if (abs_val(getIReal()) < I_REAL_MIN || abs_val(getIImag()) < I_IMAG_MIN)
            {
                if(i_gain_index < 7)
                {
                    i_gain_index = i_gain_index + 1;
                }
                else
                {
                    i_gain_ok = true;
                }
            }
            
            else if (abs_val(getIReal()) > I_REAL_MAX || abs_val(getIImag()) > I_IMAG_MAX)
            {
                if(i_gain_index > 0) 
                {
                    i_gain_index--;
                }
                else
                {
                    i_gain_ok = true;
                }
            }
            
            else
            {
                i_gain_ok = true;
            }
            
            printf("V_gain %hhu, I_gain %hhu\n\r", v_gain_index, i_gain_index);
            printf("Vr: %.3f\n\r",getVReal());
            printf("Vi: %.3f\n\r",getVImag());
            printf("Ir: %.3f\n\r",getIReal());
            printf("Ii: %.3f\n\r",getIImag());
            printf("Zr: %.3f\n\r",getZReal());
            printf("Zi: %.3f\n\r",getZImag());
            printf("\n\r");
            
            if(newComponent == true && v_gain_ok == true && i_gain_ok == true)
            {
                isComponent = true;
                newComponent = false;
                buffer_index = 0;
                buffer_full = false;
            }
            
            if ((getZReal() < 2000000.0) && (getZReal() > -2000000.0) && 
                (getZImag() > -2000000.0) && (getZImag() < 2000000.0)
                && isComponent == false && newComponent == false)
            {
                newComponent = true;
                v_gain_index = OPA2_R2byR1_is_1;
                i_gain_index = OPA2_R2byR1_is_1;
                v_gain_ok = false;
                i_gain_ok = false;
            }
        }
        
        else
        {
            SelectVoltage();

            GainSet(v_gain_index);
            set_vGain(v_gain_index);

            __delay_ms(7); 
            GetRawData(SAMPLE_NO, voltageSampleArray);

            SelectCurrent();

            GainSet(i_gain_index);
            set_iGain(i_gain_index);

            __delay_ms(13); 
            GetRawData(SAMPLE_NO, currentSampleArray);

            processImpedanceValues(); 

            printf("V_gain %hhu, I_gain %hhu\n\r", v_gain_index, i_gain_index);
            printf("Vr: %.3f\n\r",getVReal());
            printf("Vi: %.3f\n\r",getVImag());
            printf("Ir: %.3f\n\r",getIReal());
            printf("Ii: %.3f\n\r",getIImag());
            printf("Zr: %.3f\n\r",getZReal());
            printf("Zi: %.3f\n\r",getZImag());

            theta = ((getzArg() * 180)/PI);

            if ((getZReal() > 2000000.0) || (getZReal() < -2000000.0) || 
                (getZImag() < -2000000.0) ||(getZImag() > 2000000.0))
            {
                printf("No component detected\n\r");
                Display_No_Component();
                isComponent = false;
                v_gain_ok = false;
                i_gain_ok = false;
            }
            
            else if((theta >= 4.0) && (theta < 176.0))
            {
                component = CAPACITOR;
                result = 1000000000.0;
                Q = getZImag() / getZReal();
                result = result/(2 * PI * FREQ * getZImag());
                printf("Capacitor: %.3f nF\n\r", result);    
            }
            
            else if ((theta <= -4.0) && (theta > -176.0))
            {
                component = INDUCTOR;
                result = -1000.0;
                result = (result * getZImag())/(2 * PI * FREQ);
                Q = getZImag() / getZReal();
                printf("Inductor: %.3f mF\n\r", result);
            }
            
            else
            {
                component = RESISTOR;
                result = getZReal();
                printf("Resistor: %.3f Ohm\n\r", getZReal());
            }
            printf("\n\r\n\r");
             
            results_buffer[buffer_index++] = result;
            buffer_index %= BUFFER_NO;
            
            if(buffer_index == 0)
            {
                buffer_full = true;
            }
            
            if(buffer_full)
            {
                double mean_result = 0.0;
                for(uint8_t i = 0; i < BUFFER_NO; i++)
                {
                    mean_result += results_buffer[i];
                }
                
                result = mean_result / BUFFER_NO;
            }
            
            if(isComponent)
            {
                Display_Result(component, result, Q, getzMod(), theta);
            }
        }
    }          
}