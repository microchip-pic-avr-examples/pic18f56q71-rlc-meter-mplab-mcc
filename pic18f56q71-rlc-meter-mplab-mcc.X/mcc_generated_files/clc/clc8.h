/**
 * CLC8 Generated Driver API Header File.
 * 
 * @file clc8.h
 * 
 * @defgroup  clc8 CLC8
 * 
 * @brief This file contains the API prototypes for the CLC8 driver.
 *
 * @version CLC8 Driver Version 1.1.0
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

#ifndef CLC8_H
 #define CLC8_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define CLC8_Initialize  CLC8_Initialize
#define CLC8_Enable CLC8_Enable
#define CLC8_Disable CLC8_Disable
#define CLC8_ISR CLC8_ISR
#define CLC8_OutputStatusGet CLC8_OutputStatusGet
#define CLC8_CLCI_SetInterruptHandler CLC8_CLCI_SetInterruptHandler


/**
 * @ingroup clc8
 * @brief  Initializes the CLC8. This routine configures the CLC8 specific control registers.
 * @param None.
 * @return None.
 */
void CLC8_Initialize(void);

/**
 * @ingroup clc8
 * @brief Enables the CLC8 module.     
 * @param None.
 * @return None.
 */
void CLC8_Enable(void);

/**
 * @ingroup clc8
 * @brief Disables the CLC8 module.     
 * @param None.
 * @return None.
 */
void CLC8_Disable(void);


/**
 * @ingroup clc8
 * @brief Returns the output pin status of the CLC module.
 * @param  None.
 * @retval True - Output is 1.
 * @retval False - Output is 0.
 */
bool CLC8_OutputStatusGet(void); 

#endif  // CLC8_H
/**
 End of File
*/

