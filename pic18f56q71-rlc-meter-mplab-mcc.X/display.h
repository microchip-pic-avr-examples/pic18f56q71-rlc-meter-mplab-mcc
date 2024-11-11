/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DISPLAY_H
#define	DISPLAY_H
 
#include <stdio.h>
#include <string.h>
#include "OLEDC_Click.h"
#include "OLEDC_shapes.h"
#include "OLEDC_colors.h"

#define COMPONENT_LINE        0
#define Q_LINE                1
#define Z_LINE                2
#define TH_LINE               3
#define MESSAGE1_LINE         4
#define MESSAGE2_LINE         5

#define NAME_COLUMN           0
#define VALUE_COLUMN          3
#define MULTIPLIER_COLUMN     11
#define UNIT_COLUMN           12
#define MESSAGE_COLUMN        0

enum COMPONENT {CAPACITOR = 0, INDUCTOR = 1, RESISTOR = 2};

void Display_Init(void);
void Display_Interface(void);
void Display_Message(char *string1, char *string2);
void Display_Result(enum COMPONENT component, float result, float Q, float z, float theta);
void Display_No_Component(void);
void Display_Component(void);
void Display_Value(float result);
void Display_Impedance(float z);
void Display_Q(float q);
void Display_Theta(float theta);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* DISPLAY_H */

