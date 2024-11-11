/**
 * Display File
 * 
 * @file display.c
 * 
 * @ingroup display
 * 
 * @brief  This file contains the implementation of the display functions
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

#include "display.h"

const char* componentsLUT[3] = {"Cs", "Ls", "Rs"};
const char* unitsLUT[3] = {"F", "H", "Ohm"};

static enum COMPONENT displayedComponent = CAPACITOR;
static enum COMPONENT oldComponent = CAPACITOR;

static float oldValue;
static float oldQ;
static float oldZ;
static float oldTheta;
static char oldMultiplier[2];
static char oldZMultiplier[2];

static void Print_Float_Number(float number, uint16_t line, uint16_t column, uint16_t color)
{
    char buffer[10];
    
    if(number < 0)
    {
        sprintf(buffer,"%-8.2f", number);
    }
    else
    {
        sprintf(buffer,"% -8.2f", number);
    }
    
    oledC_printString(buffer, line, column, color);
}

void Display_Init(void)
{
    oledC_setup();
    oledC_clearScreen();
}

void Display_Interface(void)
{
    Display_Component();
    
    oledC_printString("Q", Q_LINE, NAME_COLUMN, OLEDC_COLOR_YELLOW);
    oledC_printString("Z", Z_LINE, NAME_COLUMN, OLEDC_COLOR_YELLOW);
    oledC_printString("Th", TH_LINE, NAME_COLUMN, OLEDC_COLOR_YELLOW);
    oledC_printString("Ohm", Z_LINE, UNIT_COLUMN, OLEDC_COLOR_YELLOW);
}

void Display_Message(char *string1, char *string2)
{
    static char oldString1[17];
    static char oldString2[17];
    
    // Delete old string
    oledC_printString(oldString1, MESSAGE1_LINE, MESSAGE_COLUMN, OLEDC_COLOR_BLACK);
    oledC_printString(oldString2, MESSAGE2_LINE, MESSAGE_COLUMN, OLEDC_COLOR_BLACK);
    
    // Write new string
    oledC_printString(string1, MESSAGE1_LINE, MESSAGE_COLUMN, OLEDC_COLOR_WHITE);
    oledC_printString(string2, MESSAGE2_LINE, MESSAGE_COLUMN, OLEDC_COLOR_WHITE);
    
    strcpy(oldString1, string1);
    strcpy(oldString2, string2);
}

void Display_Result(enum COMPONENT component, float result, float Q, float z, float theta)
{   
    if(component != displayedComponent)
    {
        oldComponent = displayedComponent;
        displayedComponent = component;
        Display_Component();
    }
    
    Display_Value(result);
    
    Display_Q(Q);
    
    Display_Impedance(z);
    
    Display_Theta(theta);
}

void Display_No_Component(void)
{   
    Print_Float_Number(oldValue, COMPONENT_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
    oledC_printString(" ----  ", COMPONENT_LINE, VALUE_COLUMN, OLEDC_COLOR_WHITE);
    
    if(displayedComponent != RESISTOR)
    {
        Print_Float_Number(oldQ, Q_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
        oledC_printString(" ----  ", Q_LINE, VALUE_COLUMN, OLEDC_COLOR_WHITE);
    }
    
    Print_Float_Number(oldZ, Z_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
    oledC_printString(" ----  ", Z_LINE, VALUE_COLUMN, OLEDC_COLOR_WHITE);
    
    Print_Float_Number(oldTheta, TH_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
    oledC_printString(" ----  ", TH_LINE, VALUE_COLUMN, OLEDC_COLOR_WHITE);
}

void Display_Component(void)
{
    oledC_printString(componentsLUT[oldComponent], COMPONENT_LINE, NAME_COLUMN, OLEDC_COLOR_BLACK);
    oledC_printString(componentsLUT[displayedComponent], COMPONENT_LINE, NAME_COLUMN, OLEDC_COLOR_YELLOW);
    
    oledC_printString(unitsLUT[oldComponent], COMPONENT_LINE, UNIT_COLUMN, OLEDC_COLOR_BLACK);
    oledC_printString(unitsLUT[displayedComponent], COMPONENT_LINE, UNIT_COLUMN, OLEDC_COLOR_YELLOW);
    
    oledC_printString("Q", Q_LINE, NAME_COLUMN, OLEDC_COLOR_BLACK);
    if(displayedComponent != RESISTOR)
    {
        oledC_printString("Q", Q_LINE, NAME_COLUMN, OLEDC_COLOR_YELLOW);
    }
}

void Display_Value(float value)
{
    
    /*
     * Default measurement units
     * C -> nF
     * L -> mH
     * R -> Ohm
     */
    
    uint8_t multiplier = 0;
    
    while(value > 1000.0)
    {
        multiplier++;
        value /= 1000.0;
    }
    
    oledC_printString(" ----  ", COMPONENT_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
    Print_Float_Number(oldValue, COMPONENT_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
    
    Print_Float_Number(value, COMPONENT_LINE, VALUE_COLUMN, OLEDC_COLOR_WHITE);
    
    oldValue = value;
    
        oledC_printString(oldMultiplier, COMPONENT_LINE, MULTIPLIER_COLUMN, OLEDC_COLOR_BLACK);
        
        switch(displayedComponent)
        {
            case CAPACITOR:
            {
                if(multiplier == 0)
                {
                    oledC_printString("n", COMPONENT_LINE, MULTIPLIER_COLUMN, OLEDC_COLOR_YELLOW);
                    strcpy(oldMultiplier, "n");
                }
                
                else
                {
                    oledC_printString("u", COMPONENT_LINE, MULTIPLIER_COLUMN, OLEDC_COLOR_YELLOW);
                    strcpy(oldMultiplier, "u");
                }
                
                break;
            }
            
            case INDUCTOR:
            {
                oledC_printString("m", COMPONENT_LINE, MULTIPLIER_COLUMN, OLEDC_COLOR_YELLOW);
                strcpy(oldMultiplier, "m");
                
                break;
            }
            
            case RESISTOR:
            {
                if(multiplier == 1)
                {
                    oledC_printString("K", COMPONENT_LINE, MULTIPLIER_COLUMN, OLEDC_COLOR_YELLOW);
                    strcpy(oldMultiplier, "K");
                }
                
                else if(multiplier == 2)
                {
                    oledC_printString("M", COMPONENT_LINE, MULTIPLIER_COLUMN, OLEDC_COLOR_YELLOW);
                    strcpy(oldMultiplier, "M");
                }
                
                break;
            }
            
            default:
            {
                break;
            }
        }
}

void Display_Impedance(float z)
{
    
    /*
     * Default measurement unit -> Ohm
     */
    
    uint8_t multiplier = 0;
    
    while(z > 1000.0)
    {
        multiplier++;
        z /= 1000.0;
    }
    
    oledC_printString(" ----  ", Z_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
    Print_Float_Number(oldZ, Z_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
    Print_Float_Number(z, Z_LINE, VALUE_COLUMN, OLEDC_COLOR_WHITE);
    
    oldZ = z;
    
    oledC_printString(oldZMultiplier, Z_LINE, MULTIPLIER_COLUMN, OLEDC_COLOR_BLACK);
    
    if(multiplier == 1)
    {
        oledC_printString("K", Z_LINE, MULTIPLIER_COLUMN, OLEDC_COLOR_YELLOW);
        strcpy(oldZMultiplier, "K");
    }
    
    else if(multiplier == 2)
    {
        oledC_printString("M", Z_LINE, MULTIPLIER_COLUMN, OLEDC_COLOR_YELLOW);
        strcpy(oldZMultiplier, "M");
    }
}

void Display_Q(float q)
{
    oledC_printString(" ----  ", Q_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
    
    if(displayedComponent != RESISTOR)
    {
        Print_Float_Number(oldQ, Q_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
        Print_Float_Number(q, Q_LINE, VALUE_COLUMN, OLEDC_COLOR_WHITE);
    
        oldQ = q;
    }
}

void Display_Theta(float theta) 
{
    oledC_printString(" ----  ", TH_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
    Print_Float_Number(oldTheta, TH_LINE, VALUE_COLUMN, OLEDC_COLOR_BLACK);
    Print_Float_Number(theta, TH_LINE, VALUE_COLUMN, OLEDC_COLOR_WHITE);
    
    oldTheta = theta;
}