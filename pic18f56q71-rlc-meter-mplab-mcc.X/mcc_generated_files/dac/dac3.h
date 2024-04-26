/**
 * DAC3 Generated Driver API Header File
 * 
 * @file dac3.h
 * 
 * @defgroup  dac3 DAC3
 * 
 * @brief This is the generated header file for the DAC3 driver using PIC10/12/16/18 MCUs
 *
 * @version DAC3 Driver Version 2.1.1
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

#ifndef DAC3_H
#define DAC3_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

/**
  Section: DAC3 APIs
*/

/**
 * @ingroup dac3
 * @brief  Initializes the DAC1 module. This routine is called only once during system initialization, before calling other APIs.
 * @param None.
 * @return None.
 */ 
void DAC3_Initialize(void);


/**
 * @ingroup dac3
 * @brief  Passes the digital input data into the DAC3 Voltage Reference Control register.
 * @param inputData - 8-bit digital data passed to DAC3
 * @return None.
 */
void DAC3_SetOutput(uint8_t inputData);

/**
 * @ingroup dac3
 * @brief  Reads the digital input data sent to the DAC3 Voltage Reference Control register.
 * @param None.
 * @return uint8_t inputData - Digital data sent to the DAC3
 */
uint8_t DAC3_GetOutput(void);

#endif // DAC3_H
/**
 End of File
*/
