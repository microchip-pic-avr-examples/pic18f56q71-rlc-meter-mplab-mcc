/*****************************************************************************
* | File        :   LCD_Driver.h
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

#include <stdint.h>

#ifndef __LCD_DRIVER_H
#define __LCD_DRIVER_H

#define LCD_WIDTH   240 // LCD width
#define LCD_HEIGHT  280 // LCD height

#define HORIZONTAL 0
#define VERTICAL   1

void LCD_WriteData_Byte(uint8_t data); 
void LCD_WriteData_Word(uint16_t data);
void LCD_WriteReg(uint8_t data);
void LCD_SetCursor(uint16_t x1, uint16_t y1, uint16_t x2,uint16_t y2);
void LCD_SetWORD(uint16_t x, uint16_t y, uint16_t Color);
void LCD_Init(void);
void LCD_SetBacklight(void);
void LCD_Clear(uint16_t Color);
void LCD_ClearWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t Color);

#endif
