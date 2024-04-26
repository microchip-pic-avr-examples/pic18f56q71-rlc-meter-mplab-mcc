/*
 * File:   display.c
 * Author: M75512
 *
 * Created on April 12, 2024, 11:48 AM
 */


#include "display.h"

static enum COMPONENT displayed_component = CAPACITOR; 

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
    Paint_DrawString_EN(column, row, buffer, &Font24, BLACK, WHITE);
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
    
    Paint_DrawString_EN(COLUMN1, ROW3, "Z  ", &Font24, BLACK, YELLOW);
    Paint_DrawString_EN(COLUMN4, ROW3, "Ohm", &Font24, BLACK, YELLOW);
    Paint_DrawString_EN(COLUMN1, ROW4, "Th ", &Font24, BLACK, YELLOW);
}

void Display_Result(enum COMPONENT component, float result, float Q, float z, float theta)
{   
    if(component != displayed_component)
    {
        displayed_component = component;
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
    Paint_DrawString_EN(COLUMN2, ROW1, buffer, &Font24, BLACK, WHITE);
    if(displayed_component != RESISTOR)
    {
        sprintf(buffer, " ----    ");
        Paint_DrawString_EN(COLUMN2, ROW2, buffer, &Font24, BLACK, WHITE);
        sprintf(buffer, " ----  ");
    }
    Paint_DrawString_EN(COLUMN2, ROW3, buffer, &Font24, BLACK, WHITE);
    Paint_DrawString_EN(COLUMN2, ROW4, buffer, &Font24, BLACK, WHITE);
}

void Display_Component(void)
{
    if(displayed_component == CAPACITOR)
    {
        Paint_DrawString_EN(COLUMN1, ROW1, "Cs ", &Font24, BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN4, ROW1, "F  ", &Font24, BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN1, ROW2, "Q  ", &Font24, BLACK, YELLOW);
    }
    else if(displayed_component == INDUCTOR)
    {
        Paint_DrawString_EN(COLUMN1, ROW1, "Ls ", &Font24, BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN4, ROW1, "H  ", &Font24, BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN1, ROW2, "Q  ", &Font24, BLACK, YELLOW);
    }
    else {
        Paint_DrawString_EN(COLUMN1, ROW1, "Rs ", &Font24, BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN4, ROW1, "Ohm", &Font24, BLACK, YELLOW);
        Paint_DrawString_EN(COLUMN1, ROW2, "             ", &Font24, BLACK, YELLOW);
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
    
    if(displayed_component == CAPACITOR)
    {
        if(multiplicator == 0)
        {
            Paint_DrawString_EN(COLUMN3, ROW1, "n", &Font24, BLACK, YELLOW);
        }
        else
        {
            Paint_DrawString_EN(COLUMN3, ROW1, "u", &Font24, BLACK, YELLOW);
        }
    }
    else if(displayed_component == INDUCTOR)
    {
        if(multiplicator == 0)
        {
            Paint_DrawString_EN(COLUMN3, ROW1, "m", &Font24, BLACK, YELLOW);
        }
        else
        {
            Paint_DrawString_EN(COLUMN3, ROW1, " ", &Font24, BLACK, YELLOW);
        }
    }
    else if(displayed_component == RESISTOR)
    {
        if(multiplicator == 0)
        {
            Paint_DrawString_EN(COLUMN3, ROW1, " ", &Font24, BLACK, YELLOW);
        }
        else if(multiplicator == 1)
        {
            Paint_DrawString_EN(COLUMN3, ROW1, "K", &Font24, BLACK, YELLOW);
        }
        else
        {
            Paint_DrawString_EN(COLUMN3, ROW1, "M", &Font24, BLACK, YELLOW);
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
        Paint_DrawString_EN(COLUMN3, ROW3, " ", &Font24, BLACK, YELLOW);
    }
    else if(multiplicator == 1)
    {
        Paint_DrawString_EN(COLUMN3, ROW3, "K", &Font24, BLACK, YELLOW);
    }
    else
    {
        Paint_DrawString_EN(COLUMN3, ROW3, "M", &Font24, BLACK, YELLOW);
    }
}

void Display_Q(float result)
{
    if(displayed_component != RESISTOR)
    {
        Print_Float_Number(ROW2, COLUMN2, result);
    }
}

void Display_Theta(float result) 
{
    Print_Float_Number(ROW4, COLUMN2, result);
}