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

static enum COMPONENT displayedComponent = CAPACITOR; 

static void Print_Float_Number(uint16_t row, uint16_t column, float number)
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
    Paint_DrawString_EN(column, row, buffer, BLACK, WHITE);
}

void Display_Init(void)
{
    LCD_Init();
    LCD_SetBacklight();
    
    Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 270, BLACK);
    Paint_Clear(BLACK);
}

void Display_Interface(void)
{
    Display_Component();
    
    Paint_DrawLine(0, 65, 280, 65, YELLOW, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    
    Paint_DrawString_EN(COLUMN1, ROW3, "Z  ", BLACK, YELLOW);
    Paint_DrawString_EN(COLUMN4, ROW3, "Ohm", BLACK, YELLOW);
    Paint_DrawString_EN(COLUMN1, ROW4, "Th ", BLACK, YELLOW);
}

void Display_Result(enum COMPONENT component, float result, float Q, float z, float theta)
{   
    if(component != displayedComponent)
    {
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
    char buffer[10] = " ----  ";
    Paint_DrawString_EN(COLUMN2, ROW1, buffer, BLACK, WHITE);
    if(displayedComponent != RESISTOR)
    {
        sprintf(buffer, " ----    ");
        Paint_DrawString_EN(COLUMN2, ROW2, buffer, BLACK, WHITE);
        sprintf(buffer, " ----  ");
    }
    Paint_DrawString_EN(COLUMN2, ROW3, buffer, BLACK, WHITE);
    Paint_DrawString_EN(COLUMN2, ROW4, buffer, BLACK, WHITE);
}

void Display_Component(void)
{
    if(displayedComponent == CAPACITOR)
    {
        Paint_DrawString_EN(COLUMN1, ROW1, "Cs ", BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN4, ROW1, "F  ", BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN1, ROW2, "Q  ", BLACK, YELLOW);
    }
    else if(displayedComponent == INDUCTOR)
    {
        Paint_DrawString_EN(COLUMN1, ROW1, "Ls ", BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN4, ROW1, "H  ", BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN1, ROW2, "Q  ", BLACK, YELLOW);
    }
    else {
        Paint_DrawString_EN(COLUMN1, ROW1, "Rs ", BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN4, ROW1, "Ohm", BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN1, ROW2, "Q  ", BLACK, BLACK);
        Paint_DrawString_EN(COLUMN2, ROW2, " ----  ", BLACK, BLACK);
    }
}

void Display_Value(float result)
{
    
    /*
     * Default measurement units
     * C -> nF
     * L -> mH
     * R -> Ohm
     */
    
    uint8_t multiplicator = 0;
    
    while(result > 1000.0)
    {
        multiplicator++;
        result /= 1000.0;
    }
    
    Print_Float_Number(ROW1, COLUMN2, result);
    
    if(displayedComponent == CAPACITOR)
    {
        if(multiplicator == 0)
        {
            Paint_DrawString_EN(COLUMN3, ROW1, "n", BLACK, YELLOW);
        }
        else
        {
            Paint_DrawString_EN(COLUMN3, ROW1, "u", BLACK, YELLOW);
        }
    }
    else if(displayedComponent == INDUCTOR)
    {
        if(multiplicator == 0)
        {
            Paint_DrawString_EN(COLUMN3, ROW1, "m", BLACK, YELLOW);
        }
        else
        {
            Paint_DrawString_EN(COLUMN3, ROW1, " ", BLACK, YELLOW);
        }
    }
    else if(displayedComponent == RESISTOR)
    {
        if(multiplicator == 0)
        {
            Paint_DrawString_EN(COLUMN3, ROW1, " ", BLACK, YELLOW);
        }
        else if(multiplicator == 1)
        {
            Paint_DrawString_EN(COLUMN3, ROW1, "K", BLACK, YELLOW);
        }
        else
        {
            Paint_DrawString_EN(COLUMN3, ROW1, "M", BLACK, YELLOW);
        }
    }
}

void Display_Impedance(float result)
{
    
    /*
     * Default measurement unit -> Ohm
     */
    
    uint8_t multiplicator = 0;
    
    while(result > 1000.0)
    {
        multiplicator++;
        result /= 1000.0;
    }
    
    Print_Float_Number(ROW3, COLUMN2, result);
    
    if(multiplicator == 0)
    {
        Paint_DrawString_EN(COLUMN3, ROW3, " ", BLACK, YELLOW);
    }
    else if(multiplicator == 1)
    {
        Paint_DrawString_EN(COLUMN3, ROW3, "K", BLACK, YELLOW);
    }
    else
    {
        Paint_DrawString_EN(COLUMN3, ROW3, "M", BLACK, YELLOW);
    }
}

void Display_Q(float result)
{
    if(displayedComponent != RESISTOR)
    {
        Print_Float_Number(ROW2, COLUMN2, result);
    }
}

void Display_Theta(float result) 
{
    Print_Float_Number(ROW4, COLUMN2, result);
}