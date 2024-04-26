/**
 * OPA2 Generated Driver API Header File
 * 
 * @file opa2.h
 * 
 * @defgroup  opa2 OPA2
 * 
 * @brief This is the generated header file for the OPA2 driver.
 *
 * @version OPA2 Driver Version 1.0.0
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

#ifndef OPA2_H
#define OPA2_H

/**
  Section: Included Files
*/
#include <stdint.h>
#include <stdbool.h>

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_Initialize API
 */
#define OPA2_Initialize OPA2_Initialize

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_EnableChargePump API
 */
#define OPA2_EnableChargePump OPA2_EnableChargePump

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_DisableChargePump API
 */
#define OPA2_DisableChargePump OPA2_DisableChargePump

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_EnableSoftwareUnityGain API
 */
#define OPA2_EnableSoftwareUnityGain OPA2_EnableSoftwareUnityGain

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_DisableSoftwareUnityGain API
 */
#define OPA2_DisableSoftwareUnityGain OPA2_DisableSoftwareUnityGain

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_SetPositiveChannel API
 */
#define OPA2_SetPositiveChannel OPA2_SetPositiveChannel

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_SetPositiveSource API
 */
#define OPA2_SetPositiveSource OPA2_SetPositiveSource

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_SetNegativeChannel API
 */
#define OPA2_SetNegativeChannel OPA2_SetNegativeChannel

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_SetNegativeSource API
 */
#define OPA2_SetNegativeSource OPA2_SetNegativeSource

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_SetResistorLadder API
 */
#define OPA2_SetResistorLadder OPA2_SetResistorLadder

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_EnableHardwareOverride API
 */
#define OPA2_EnableHardwareOverride OPA2_EnableHardwareOverride

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_SetHardwareOverrideSource API
 */
#define OPA2_SetHardwareOverrideSource OPA2_SetHardwareOverrideSource

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_DisableHardwareOverride API
 */
#define OPA2_DisableHardwareOverride OPA2_DisableHardwareOverride

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_ManualInputOffsetCalibration API
 */
#define OPA2_ManualInputOffsetCalibration OPA2_ManualInputOffsetCalibration

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_StartAutomaticOffsetCalibration API
 */
#define OPA2_StartAutomaticOffsetCalibration OPA2_StartAutomaticOffsetCalibration

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_isAutomaticOffsetCalibrationDone API
 */
#define OPA2_isAutomaticOffsetCalibrationDone OPA2_isAutomaticOffsetCalibrationDone

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_StartPeakTroughReset API
 */
#define OPA2_StartPeakTroughReset OPA2_StartPeakTroughReset

/**
 * @ingroup  opa2
 * @brief    This macro defines the Custom Name for \ref OPA2_StopPeakTroughReset API
 */
#define OPA2_StopPeakTroughReset OPA2_StopPeakTroughReset

/**
 * @ingroup opa2
 * @enum OPA2_resistor_select
 * @brief Enumeration of R2/R1 resistor ratio
*/
typedef enum
{
    OPA2_R2byR1_is_0dp07,    /**<R2/R1 = 0.07*/
    OPA2_R2byR1_is_0dp14,    /**<R2/R1 = 0.14*/
    OPA2_R2byR1_is_0dp33,    /**<R2/R1 = 0.33*/
    OPA2_R2byR1_is_1,        /**<R2/R1 = 1*/
    OPA2_R2byR1_is_1dp67,    /**<R2/R1 = 1.67*/
    OPA2_R2byR1_is_3,        /**<R2/R1 = 3*/
    OPA2_R2byR1_is_7,        /**<R2/R1 = 7*/
    OPA2_R2byR1_is_15        /**<R2/R1 = 15*/
} OPA2_resistor_select;

/**
 * @ingroup opa2
 * @enum OPA2_posChannel_select
 * @brief Enumeration of available Positive Channels
*/
typedef enum
{
    OPA2_posChannel_Vss = 0x0,
    OPA2_posChannel_GSEL = 0x1,
    OPA2_posChannel_OPA2IN = 0x2,
    OPA2_posChannel_Vdd_by_2 = 0x3,
    OPA2_posChannel_DAC1 = 0x4,
    OPA2_posChannel_DAC2 = 0x5,
    OPA2_posChannel_DAC3 = 0x6
} OPA2_posChannel_select;

/**
 * @ingroup opa2
 * @enum OPA2_posSource_select
 * @brief Enumeration of available Positive Sources
*/
typedef enum
{
    OPA2_RB4_IN0_pos = 0x0,
    OPA2_RA1_IN1_pos = 0x1,
    OPA2_RB3_IN2_pos = 0x2,
    OPA2_RB2_IN3_pos = 0x3
} OPA2_posSource_select;

/**
 * @ingroup opa2
 * @enum OPA2_negChannel_select
 * @brief Enumeration of available Negative Channels
*/
typedef enum
{
    OPA2_negChannel_No_Connection = 0x0,
    OPA2_negChannel_GSEL = 0x1,
    OPA2_negChannel_OPA2IN = 0x2,
    OPA2_negChannel_DAC1 = 0x4,
    OPA2_negChannel_DAC2 = 0x5,
    OPA2_negChannel_DAC3 = 0x6
} OPA2_negChannel_select;

/**
 * @ingroup opa2
 * @enum OPA2_negSource_select
 * @brief Enumeration of available Negative Sources
*/
typedef enum
{
    OPA2_RB4_IN0_neg = 0x0,   
    OPA2_RA1_IN1_neg = 0x1,   
    OPA2_RB3_IN2_neg = 0x2,   
    OPA2_RB2_IN3_neg = 0x3,   
    OPA2_Vss = 0x7   
} OPA2_negSource_select;

/**
 * @ingroup opa2
 * @brief This routine initializes the OPA2 and must be called before any other OPA2 routine is called.
 * This routine should only be called once during system initialization.
 * @param None
 * @return None
*/
void OPA2_Initialize(void);

/**
 * @ingroup opa2
 * @brief Enables the OPA2 Charge Pump
 * @pre opa2 should be initialized with OPA2_Initialize() before calling this API.
 * @param None
 * @return None
*/
inline void OPA2_EnableChargePump(void);

/**
 * @ingroup opa2
 * @brief Disables the OPA2 Charge Pump
 * @param None
 * @return None
*/
inline void OPA2_DisableChargePump(void);

/**
 * @ingroup opa2
 * @brief Enables OPA2 to operate with unity gain
 * @param None
 * @return None
*/
inline void OPA2_EnableSoftwareUnityGain(void);

/**
 * @ingroup opa2
 * @brief Disables unity gain in OPA2 
 * @param None
 * @return None
*/
inline void OPA2_DisableSoftwareUnityGain(void);

/**
 * @ingroup opa2
 * @brief Sets the positive channel as per user selection
 * @param Desired positive channel. For available positive channels refer OPA2_posChannel_select enum from opa2.h file
 * @return None
*/
inline void OPA2_SetPositiveChannel(OPA2_posChannel_select posChannel);

/**
 * @ingroup opa2
 * @brief Sets the positive source as per user selection
 * @param Desired positive source. For available positive sources refer OPA2_posSource_select enum from opa2.h file
 * @return None
*/
inline void OPA2_SetPositiveSource(OPA2_posSource_select posSource);

/**
 * @ingroup opa2
 * @brief Sets the negative channel as per user selection
 * @param Desired negative channel. For available negative channels refer OPA2_negChannel_select enum from opa2.h file
 * @return None
*/
inline void OPA2_SetNegativeChannel(OPA2_negChannel_select negChannel);

/**
 * @ingroup opa2
 * @brief Sets the negative source as per user selection
 * @param Desired negative source. For available negative sources refer OPA2_negSource_select enum from opa2.h file
 * @return None
*/
inline void OPA2_SetNegativeSource(OPA2_negSource_select negSource);

/**
 * @ingroup opa2
 * @brief Sets the R1 and R2 values of internal resistor ladder as per user selection
 * @param Desired resistor selection. For available resistor values refer OPA2_resistor_sel enum from opa2.h file
 * @return None
*/
void OPA2_SetResistorLadder(OPA2_resistor_select resistorSelection);

/**
 * @ingroup opa2
 * @brief Enables hardware override by setting the override enable bit
 * @param None
 * @return None
*/
inline void OPA2_EnableHardwareOverride(void);

/**
 * @ingroup opa2
 * @brief Selects the Hardware Override Source and polarity
 * @pre The OPA2_EnableHardwareOverride() routine must be called before this routine
 * @param Desired hardware override source and source polarity
 * @return None
*/
void OPA2_SetHardwareOverrideSource(uint8_t overrideSource, uint8_t polarity);

/**
 * @ingroup opa2
 * @brief Disables the hardware override by clearing the override enable bit
 * @param None
 * @return None
*/
inline void OPA2_DisableHardwareOverride(void);

/**
 * @ingroup opa2
 * @brief Sets the input offset calibration
 * @param Desired input offset based on calibration
 * @return None
*/
inline void OPA2_ManualInputOffsetCalibration(uint8_t offset);

/**
 * @ingroup opa2
 * @brief Starts the automatic input offset calibration
 * @param None
 * @return None
*/
void OPA2_StartAutomaticOffsetCalibration(void);

/**
 * @ingroup opa2
 * @brief Checks if the automatic input offset calibration has been completed
 * @pre The OPA2_StartAutomaticOffsetCalibration() routine must be called before this routine
 * @param None
 * @return true or false
*/
inline bool OPA2_isAutomaticOffsetCalibrationDone(void);

/**
 * @ingroup opa2
 * @brief Initiate peak or trough reset
 * @pre The hardware control configuration registers must be set appropriately
 * @param None
 * @return None
*/
inline void OPA2_StartPeakTroughReset(void);

/**
 * @ingroup opa2
 * @brief Stop peak or trough reset
 * @pre The hardware control configuration registers must be set appropriately
 * @param None
 * @return None
*/
inline void OPA2_StopPeakTroughReset(void);

#endif //OPA2_H