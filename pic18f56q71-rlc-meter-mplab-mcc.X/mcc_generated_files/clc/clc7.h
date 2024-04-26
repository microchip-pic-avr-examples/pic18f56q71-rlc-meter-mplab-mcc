/**
 * CLC7 Generated Driver API Header File.
 * 
 * @file clc7.h
 * 
 * @defgroup  clc7 CLC7
 * 
 * @brief This file contains the API prototypes for the CLC7 driver.
 *
 * @version CLC7 Driver Version 1.1.0
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

#ifndef CLC7_H
 #define CLC7_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define CLC7_Initialize  CLC7_Initialize
#define CLC7_Enable CLC7_Enable
#define CLC7_Disable CLC7_Disable
#define CLC7_ISR CLC7_ISR
#define CLC7_OutputStatusGet CLC7_OutputStatusGet
#define CLC7_CLCI_SetInterruptHandler CLC7_CLCI_SetInterruptHandler


/**
 * @ingroup clc7
 * @brief  Initializes the CLC7. This routine configures the CLC7 specific control registers.
 * @param None.
 * @return None.
 */
void CLC7_Initialize(void);

/**
 * @ingroup clc7
 * @brief Enables the CLC7 module.     
 * @param None.
 * @return None.
 */
void CLC7_Enable(void);

/**
 * @ingroup clc7
 * @brief Disables the CLC7 module.     
 * @param None.
 * @return None.
 */
void CLC7_Disable(void);


/**
 * @ingroup clc7
 * @brief Returns the output pin status of the CLC module.
 * @param  None.
 * @retval True - Output is 1.
 * @retval False - Output is 0.
 */
bool CLC7_OutputStatusGet(void); 

#endif  // CLC7_H
/**
 End of File
*/

