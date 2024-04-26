/*****************************************************************************
* | File        :   LCD_Driver.c
* | Author      :   Waveshare team
* | Function    :   Electronic paper driver
* | Info        :
*----------------
* | This version:   V1.0
* | Date        :   2023-03-15
* | Info        :   
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "LCD_Driver.h"
#include "mcc_generated_files/system/system.h"

/*******************************************************************************
function:
  Hardware reset
*******************************************************************************/
static void LCD_Reset(void)
{
    LCD_CS_SetLow();
    __delay_ms(20);
    LCD_RST_SetLow();
    __delay_ms(20);
    LCD_RST_SetHigh();
    __delay_ms(20);
}

/*******************************************************************************
function:
  Setting backlight
parameter :
    value : Range 0~255   Duty cycle is value/255
*******************************************************************************/
void LCD_SetBacklight()
{
    LCD_BL_SetHigh();
}

/*******************************************************************************
function:
    Write register address and data
*******************************************************************************/
void LCD_WriteData_Byte(uint8_t data) 
{
    if (!SPI1_Open(HOST_CONFIG)) {
		return;
	}
    
    LCD_CS_SetLow();
    LCD_DC_SetHigh();

	SPI1_ByteWrite(data);
    while(!SPI1_IsTxReady());
    
    SPI1_Close();
    
    LCD_CS_SetHigh();
}  

 void LCD_WriteData_Word(uint16_t data)
{
    if (!SPI1_Open(HOST_CONFIG)) {
        return;
	}
     
    uint8_t data_h = (uint8_t)((data >> 8) & 0xff);
     
    LCD_CS_SetLow();
    LCD_DC_SetHigh();
    
    SPI1_ByteWrite(data_h);
    while(!SPI1_IsTxReady());
    SPI1_ByteWrite((uint8_t)(data & 0xff));
    while(!SPI1_IsTxReady());
    
    SPI1_Close();
    
    LCD_CS_SetHigh();
}

void LCD_WriteReg(uint8_t data)  
{ 
    if (!SPI1_Open(HOST_CONFIG)) {
		return;
	}
    
    LCD_CS_SetLow();
    LCD_DC_SetLow();

	SPI1_ByteExchange(data);
    
    SPI1_Close();
    
    LCD_CS_SetHigh();
}

/******************************************************************************
function: 
    Common register initialization
******************************************************************************/
void LCD_Init(void)
{
    LCD_Reset();

    //************* Start Initial Sequence **********// 
    
    LCD_WriteReg(0x36);
    if (VERTICAL)
        LCD_WriteData_Byte(0x00);
    else
        LCD_WriteData_Byte(0x70);

    LCD_WriteReg(0x3A);
    LCD_WriteData_Byte(0x05);

    LCD_WriteReg(0xB2);
    LCD_WriteData_Byte(0x0B);
    LCD_WriteData_Byte(0x0B);
    LCD_WriteData_Byte(0x00);
    LCD_WriteData_Byte(0x33);
    LCD_WriteData_Byte(0x35);

    LCD_WriteReg(0xB7);
    LCD_WriteData_Byte(0x11);

    LCD_WriteReg(0xBB);
    LCD_WriteData_Byte(0x35);

    LCD_WriteReg(0xC0);
    LCD_WriteData_Byte(0x2C);

    LCD_WriteReg(0xC2);
    LCD_WriteData_Byte(0x01);

    LCD_WriteReg(0xC3);
    LCD_WriteData_Byte(0x0D);

    LCD_WriteReg(0xC4);
    LCD_WriteData_Byte(0x20);

    LCD_WriteReg(0xC6);
    LCD_WriteData_Byte(0x13);

    LCD_WriteReg(0xD0);
    LCD_WriteData_Byte(0xA4);
    LCD_WriteData_Byte(0xA1);

    LCD_WriteReg(0xD6);
    LCD_WriteData_Byte(0xA1);

    LCD_WriteReg(0xE0);
    LCD_WriteData_Byte(0xF0);
    LCD_WriteData_Byte(0x06);
    LCD_WriteData_Byte(0x0B);
    LCD_WriteData_Byte(0x0A);
    LCD_WriteData_Byte(0x09);
    LCD_WriteData_Byte(0x26);
    LCD_WriteData_Byte(0x29);
    LCD_WriteData_Byte(0x33);
    LCD_WriteData_Byte(0x41);
    LCD_WriteData_Byte(0x18);
    LCD_WriteData_Byte(0x16);
    LCD_WriteData_Byte(0x15);
    LCD_WriteData_Byte(0x29);
    LCD_WriteData_Byte(0x2D);

    LCD_WriteReg(0xE1);
    LCD_WriteData_Byte(0xF0);
    LCD_WriteData_Byte(0x04);
    LCD_WriteData_Byte(0x08);
    LCD_WriteData_Byte(0x08);
    LCD_WriteData_Byte(0x07);
    LCD_WriteData_Byte(0x03);
    LCD_WriteData_Byte(0x28);
    LCD_WriteData_Byte(0x32);
    LCD_WriteData_Byte(0x40);
    LCD_WriteData_Byte(0x3B);
    LCD_WriteData_Byte(0x19);
    LCD_WriteData_Byte(0x18);
    LCD_WriteData_Byte(0x2A);
    LCD_WriteData_Byte(0x2E);

    LCD_WriteReg(0xE4);
    LCD_WriteData_Byte(0x25);
    LCD_WriteData_Byte(0x00);
    LCD_WriteData_Byte(0x00);

    LCD_WriteReg(0x21);

    LCD_WriteReg(0x11);
    __delay_ms(120);
    LCD_WriteReg(0x29); 
} 

/******************************************************************************
function: Set the cursor position
parameter :
    Xstart:   Start uint16_t x coordinate
    Ystart:   Start uint16_t y coordinate
    Xend  :   End uint16_t coordinates
    Yend  :   End uint16_t coordinatesen
******************************************************************************/
void LCD_SetCursor(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t  Yend)
{ 
    if (HORIZONTAL) {
        // set the X coordinates
        LCD_WriteReg(0x2A);
        LCD_WriteData_Byte((Xstart+20) >> 8);
        LCD_WriteData_Byte(Xstart+20);
        LCD_WriteData_Byte((Xend+20)>> 8);
        LCD_WriteData_Byte(Xend+20);
        
        // set the Y coordinates
        LCD_WriteReg(0x2B);
        LCD_WriteData_Byte(Ystart >> 8);
        LCD_WriteData_Byte(Ystart);
        LCD_WriteData_Byte((Yend) >> 8);
        LCD_WriteData_Byte(Yend);
    }
    else {
        // set the X coordinates
        LCD_WriteReg(0x2A);
        LCD_WriteData_Byte(Xstart >> 8);
        LCD_WriteData_Byte(Xstart);
        LCD_WriteData_Byte((Xend) >> 8);
        LCD_WriteData_Byte(Xend);
        // set the Y coordinates
        LCD_WriteReg(0x2B);
        LCD_WriteData_Byte((Ystart+20)>> 8);
        LCD_WriteData_Byte(Ystart+20);
        LCD_WriteData_Byte((Yend+20)>> 8);
        LCD_WriteData_Byte(Yend+20);
    }

    LCD_WriteReg(0X2C);
}

/******************************************************************************
function: Clear screen function, refresh the screen to a certain color
parameter :
    Color :   The color you want to clear all the screen
******************************************************************************/
void LCD_Clear(uint16_t Color)
{
    LCD_SetCursor(0, 0, LCD_WIDTH, LCD_HEIGHT);
    for(uint16_t i = 0; i < LCD_WIDTH; i++) {
        for(uint16_t j = 0; j < LCD_HEIGHT; j++) {
            LCD_WriteData_Word(Color);
        }
    }
}

/******************************************************************************
function: Refresh a certain area to the same color
parameter :
    Xstart:   Start uint16_t x coordinate
    Ystart:   Start uint16_t y coordinate
    Xend  :   End uint16_t coordinates
    Yend  :   End uint16_t coordinates
    color :   Set the color
******************************************************************************/
void LCD_ClearWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t Color)
{           
    LCD_SetCursor(Xstart, Ystart, Xend, Yend);
    for(uint16_t i = Ystart; i < Yend; i++) {                                
        for(uint16_t j = Xstart; j < Xend; j++) {
            LCD_WriteData_Word(Color);
        }
    }
}

/******************************************************************************
function: Set the color of an area
parameter :
    Xstart:   Start uint16_t x coordinate
    Ystart:   Start uint16_t y coordinate
    Xend  :   End uint16_t coordinates
    Yend  :   End uint16_t coordinates
    Color :   Set the color
******************************************************************************/
void LCD_SetWindowColor(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend,uint16_t  Color)
{
    LCD_SetCursor(Xstart, Ystart, Xend, Yend);
    LCD_WriteData_Word(Color);      
}

/******************************************************************************
function: Draw a uint16_t
parameter :
    X     :   Set the X coordinate
    Y     :   Set the Y coordinate
    Color :   Set the color
******************************************************************************/
void LCD_SetWORD(uint16_t x, uint16_t y, uint16_t Color)
{
    LCD_SetCursor(x,y,x,y);
    LCD_WriteData_Word(Color);      
} 
