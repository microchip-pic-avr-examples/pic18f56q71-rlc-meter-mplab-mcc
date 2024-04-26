/**
 * CLC6 Generated Driver API Header File.
 * 
 * @file clc6.h
 * 
 * @defgroup  clc6 CLC6
 * 
 * @brief This file contains the API prototypes for the CLC6 driver.
 *
 * @version CLC6 Driver Version 1.1.0
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

#ifndef CLC6_H
 #define CLC6_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define CLC6_Initialize  CLC6_Initialize
#define CLC6_Enable CLC6_Enable
#define CLC6_Disable CLC6_Disable
#define CLC6_ISR CLC6_ISR
#define CLC6_OutputStatusGet CLC6_OutputStatusGet
#define CLC6_CLCI_SetInterruptHandler CLC6_CLCI_SetInterruptHandler


/**
 * @ingroup clc6
 * @brief  Initializes the CLC6. This routine configures the CLC6 specific control registers.
 * @param None.
 * @return None.
 */
void CLC6_Initialize(void);

/**
 * @ingroup clc6
 * @brief Enables the CLC6 module.     
 * @param None.
 * @return None.
 */
void CLC6_Enable(void);

/**
 * @ingroup clc6
 * @brief Disables the CLC6 module.     
 * @param None.
 * @return None.
 */
void CLC6_Disable(void);


/**
 * @ingroup clc6
 * @brief Returns the output pin status of the CLC module.
 * @param  None.
 * @retval True - Output is 1.
 * @retval False - Output is 0.
 */
bool CLC6_OutputStatusGet(void); 

#endif  // CLC6_H
/**
 End of File
*/

