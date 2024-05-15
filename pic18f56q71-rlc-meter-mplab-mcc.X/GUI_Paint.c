/*****************************************************************************
  | File        :   GUI_Paint.c
  | Author      :   Waveshare team
  | Function    : Achieve drawing: draw points, lines, boxes, circles and
                    their size, solid dotted line, solid rectangle hollow
                    rectangle, solid circle hollow circle.
  | Info        :
    Achieve display characters: Display a single character, string, number
    Achieve time display: adaptive size display time minutes and seconds
  ----------------
  | This version:   V1.0
  | Date        :   2018-11-15
  | Info        :

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to  whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.

******************************************************************************/
#include "GUI_Paint.h"
#include "font.h"
#include "mcc_generated_files/spi/spi1.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h> //memset()
#include <math.h>

volatile PAINT Paint;

/******************************************************************************
  function: Create Image
  parameter:
    image   :   Pointer to the image cache
    width   :   The width of the picture
    Height  :   The height of the picture
    Color   :   Whether the picture is inverted
******************************************************************************/
void Paint_NewImage(uint16_t Width, uint16_t Height, uint16_t Rotate, uint16_t Color)
{
  Paint.WidthMemory = Width;
  Paint.HeightMemory = Height;
  Paint.Color = Color;
  Paint.WidthByte = Width;
  Paint.HeightByte = Height;
  
  Paint.Rotate = Rotate;
  Paint.Mirror = MIRROR_NONE;

  if (Rotate == ROTATE_0 || Rotate == ROTATE_180) {
    Paint.Width = Width;
    Paint.Height = Height;
  } else {
    Paint.Width = Height;
    Paint.Height = Width;
  }
}

/******************************************************************************
  function: Select Image Rotate
  parameter:
    Rotate   :   0,90,180,270
******************************************************************************/
void Paint_SetRotate(uint16_t Rotate)
{
  if (Rotate == ROTATE_0 || Rotate == ROTATE_90 || Rotate == ROTATE_180 || Rotate == ROTATE_270) {
    Paint.Rotate = Rotate;
  } else {
    printf("rotate = 0, 90, 180, 270\r\n");
    exit(0);
  }
}

/******************************************************************************
  function: Select Image mirror
  parameter:
    mirror   :       Not mirror,Horizontal mirror,Vertical mirror,Origin mirror
******************************************************************************/
void Paint_SetMirroring(uint8_t mirror)
{
  if (mirror == MIRROR_NONE || mirror == MIRROR_HORIZONTAL ||
      mirror == MIRROR_VERTICAL || mirror == MIRROR_ORIGIN) {
    printf("mirror image x:%s, y:%s\r\n", (mirror & 0x01) ? "mirror" : "none", ((mirror >> 1) & 0x01) ? "mirror" : "none");
    Paint.Mirror = mirror;
  } else {
    printf("mirror should be MIRROR_NONE, MIRROR_HORIZONTAL, MIRROR_VERTICAL or MIRROR_ORIGIN\r\n");
    exit(0);
  }
}

/******************************************************************************
  function: Draw Pixels
  parameter:
    Xpoint  :   At point X
    Ypoint  :   At point Y
    Color   :   Painted colors
******************************************************************************/
void Paint_SetPixel(uint16_t Xpoint, uint16_t Ypoint, uint16_t Color)
{
  if (Xpoint > Paint.Width || Ypoint > Paint.Height) {
    printf("Exceeding display boundaries\r\n");
    return;
  }
  uint16_t X, Y;

  switch (Paint.Rotate) {
    case 0:
      X = Xpoint;
      Y = Ypoint;
      break;
    case 90:
      X = Paint.WidthMemory - Ypoint - 1;
      Y = Xpoint;
      break;
    case 180:
      X = Paint.WidthMemory - Xpoint - 1;
      Y = Paint.HeightMemory - Ypoint - 1;
      break;
    case 270:
      X = Ypoint;
      Y = Paint.HeightMemory - Xpoint - 1;
      break;

    default:
      return;
  }

  switch (Paint.Mirror) {
    case MIRROR_NONE:
      break;
    case MIRROR_HORIZONTAL:
      X = Paint.WidthMemory - X - 1;
      break;
    case MIRROR_VERTICAL:
      Y = Paint.HeightMemory - Y - 1;
      break;
    case MIRROR_ORIGIN:
      X = Paint.WidthMemory - X - 1;
      Y = Paint.HeightMemory - Y - 1;
      break;
    default:
      return;
  }

  if (X > Paint.WidthMemory || Y > Paint.HeightMemory) {
    printf("Exceeding display boundaries\r\n");
    return;
  }

  // uint32_t Addr = X / 8 + Y * Paint.WidthByte;
  LCD_SetWORD(X, Y, Color);
}

/******************************************************************************
  function: Clear the color of the picture
  parameter:
    Color   :   Painted colors
******************************************************************************/
void Paint_Clear(uint16_t Color)
{
  LCD_SetCursor(0, 0, Paint.WidthByte - 1, Paint.HeightByte - 1);
  for (uint16_t Y = 0; Y < Paint.HeightByte; Y++) {
    for (uint16_t X = 0; X < Paint.WidthByte; X++ ) {//8 pixel =  1 byte
      LCD_WriteData_Word(Color);
    }
  }
}

/******************************************************************************
  function: Clear the color of a window
  parameter:
    Xstart :   x starting point
    Ystart :   Y starting point
    Xend   :   x end point
    Yend   :   y end point
******************************************************************************/
void Paint_ClearWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t Color)
{
  uint16_t X, Y;
  for (Y = Ystart; Y < Yend; Y++) {
    for (X = Xstart; X < Xend; X++) {//8 pixel =  1 byte
      Paint_SetPixel(X, Y, Color);
    }
  }
}

/******************************************************************************
function:	Draw Point(Xpoint, Ypoint) Fill the color
parameter:
    Xpoint		:   The Xpoint coordinate of the point
    Ypoint		:   The Ypoint coordinate of the point
    Color		:   Set color
    Dot_Pixel	:	point size
******************************************************************************/
void Paint_DrawPoint( uint16_t Xpoint,       uint16_t Ypoint, uint16_t Color,
                      DOT_PIXEL Dot_Pixel,DOT_STYLE Dot_FillWay)
{
    if (Xpoint > Paint.Width || Ypoint > Paint.Height) {
        printf("Paint_DrawPoint Input exceeds the normal display range\r\n");
        return;
    }

    uint16_t XDir_Num , YDir_Num;
    if (Dot_FillWay == DOT_FILL_AROUND) {
        for (XDir_Num = 0; XDir_Num < 2*Dot_Pixel - 1; XDir_Num++) {
            for (YDir_Num = 0; YDir_Num < 2 * Dot_Pixel - 1; YDir_Num++) {
                if(Xpoint + XDir_Num - Dot_Pixel < 0 || Ypoint + YDir_Num - Dot_Pixel < 0)
                    break;
                // printf("x = %d, y = %d\r\n", Xpoint + XDir_Num - Dot_Pixel, Ypoint + YDir_Num - Dot_Pixel);
                Paint_SetPixel(Xpoint + XDir_Num - Dot_Pixel, Ypoint + YDir_Num - Dot_Pixel, Color);
            }
        }
    } else {
        for (XDir_Num = 0; XDir_Num <  Dot_Pixel; XDir_Num++) {
            for (YDir_Num = 0; YDir_Num <  Dot_Pixel; YDir_Num++) {
                Paint_SetPixel(Xpoint + XDir_Num - 1, Ypoint + YDir_Num - 1, Color);
            }
        }
    }
}

/******************************************************************************
function:	Draw a line of arbitrary slope
parameter:
    Xstart ：Starting Xpoint point coordinates
    Ystart ：Starting Xpoint point coordinates
    Xend   ：End point Xpoint coordinate
    Yend   ：End point Ypoint coordinate
    Color  ：The color of the line segment
******************************************************************************/
void Paint_DrawLine(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, 
                    uint16_t Color, DOT_PIXEL Line_width, LINE_STYLE Line_Style)
{
    if (Xstart > Paint.Width || Ystart > Paint.Height ||
        Xend > Paint.Width || Yend > Paint.Height) {
        printf("Paint_DrawLine Input exceeds the normal display range\r\n");
        return;
    }

    uint16_t Xpoint = Xstart;
    uint16_t Ypoint = Ystart;
    int dx = (int)Xend - (int)Xstart >= 0 ? Xend - Xstart : Xstart - Xend;
    int dy = (int)Yend - (int)Ystart <= 0 ? Yend - Ystart : Ystart - Yend;

    // Increment direction, 1 is positive, -1 is counter;
    int8_t XAddway = Xstart < Xend ? 1 : -1;
    int8_t YAddway = Ystart < Yend ? 1 : -1;

    //Cumulative error
    int Esp = dx + dy;
    char Dotted_Len = 0;

    for (;;) {
        Dotted_Len++;
        //Painted dotted line, 2 point is really virtual
        if (Line_Style == LINE_STYLE_DOTTED && Dotted_Len % 3 == 0) {
            printf("LINE_DOTTED\r\n");
            Paint_DrawPoint(Xpoint, Ypoint, IMAGE_BACKGROUND, Line_width, DOT_STYLE_DFT);
            Dotted_Len = 0;
        } else {
            Paint_DrawPoint(Xpoint, Ypoint, Color, Line_width, DOT_STYLE_DFT);
        }
        if (2 * Esp >= dy) {
            if (Xpoint == Xend)
                break;
            Esp += dy;
            Xpoint += XAddway;
        }
        if (2 * Esp <= dx) {
            if (Ypoint == Yend)
                break;
            Esp += dx;
            Ypoint += YAddway;
        }
    }
}

/******************************************************************************
function:	Draw a rectangle
parameter:
    Xstart ：Rectangular  Starting Xpoint point coordinates
    Ystart ：Rectangular  Starting Xpoint point coordinates
    Xend   ：Rectangular  End point Xpoint coordinate
    Yend   ：Rectangular  End point Ypoint coordinate
    Color  ：The color of the Rectangular segment
    Filled : Whether it is filled--- 1 solid 0：empty
******************************************************************************/
void Paint_DrawRectangle( uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, 
                          uint16_t Color, DOT_PIXEL Line_width, DRAW_FILL Filled )
{
    if (Xstart > Paint.Width || Ystart > Paint.Height ||
        Xend > Paint.Width || Yend > Paint.Height) {
        printf("Input exceeds the normal display range\r\n");
        return;
    }

    if (Filled ) {
        uint16_t Ypoint;
        for(Ypoint = Ystart; Ypoint < Yend; Ypoint++) {
            Paint_DrawLine(Xstart, Ypoint, Xend, Ypoint, Color ,Line_width, LINE_STYLE_SOLID);
        }
    } else {
        Paint_DrawLine(Xstart, Ystart, Xend, Ystart, Color ,Line_width, LINE_STYLE_SOLID);
        Paint_DrawLine(Xstart, Ystart, Xstart, Yend, Color ,Line_width, LINE_STYLE_SOLID);
        Paint_DrawLine(Xend, Yend, Xend, Ystart, Color ,Line_width, LINE_STYLE_SOLID);
        Paint_DrawLine(Xend, Yend, Xstart, Yend, Color ,Line_width, LINE_STYLE_SOLID);
    }
}

/******************************************************************************
function:	Use the 8-point method to draw a circle of the
            specified size at the specified position->
parameter:
    X_Center  ：Center X coordinate
    Y_Center  ：Center Y coordinate
    Radius    ：circle Radius
    Color     ：The color of the ：circle segment
    Filled    : Whether it is filled: 1 filling 0：Do not
******************************************************************************/
void Paint_DrawCircle(  uint16_t X_Center, uint16_t Y_Center, uint16_t Radius, 
                        uint16_t Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill )
{
    if (X_Center > Paint.Width || Y_Center >= Paint.Height) {
        printf("Paint_DrawCircle Input exceeds the normal display range\r\n");
        return;
    }

    //Draw a circle from(0, R) as a starting point
    uint16_t XCurrent, YCurrent;
    XCurrent = 0;
    YCurrent = Radius;

    //Cumulative error,judge the next point of the logo
    int16_t Esp = 3 - (Radius << 1 );

    int16_t sCountY;
    if (Draw_Fill == DRAW_FILL_FULL) {
        while (XCurrent <= YCurrent ) { //Realistic circles
            for (sCountY = XCurrent; sCountY <= YCurrent; sCountY ++ ) {
                Paint_DrawPoint(X_Center + XCurrent, Y_Center + sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//1
                Paint_DrawPoint(X_Center - XCurrent, Y_Center + sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//2
                Paint_DrawPoint(X_Center - sCountY, Y_Center + XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//3
                Paint_DrawPoint(X_Center - sCountY, Y_Center - XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//4
                Paint_DrawPoint(X_Center - XCurrent, Y_Center - sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//5
                Paint_DrawPoint(X_Center + XCurrent, Y_Center - sCountY, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//6
                Paint_DrawPoint(X_Center + sCountY, Y_Center - XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);//7
                Paint_DrawPoint(X_Center + sCountY, Y_Center + XCurrent, Color, DOT_PIXEL_DFT, DOT_STYLE_DFT);
            }
            if (Esp < 0 )
                Esp += 4 * XCurrent + 6;
            else {
                Esp += 10 + 4 * (XCurrent - YCurrent );
                YCurrent --;
            }
            XCurrent ++;
        }
    } else { //Draw a hollow circle
        while (XCurrent <= YCurrent ) {
            Paint_DrawPoint(X_Center + XCurrent, Y_Center + YCurrent, Color, Line_width, DOT_STYLE_DFT);//1
            Paint_DrawPoint(X_Center - XCurrent, Y_Center + YCurrent, Color, Line_width, DOT_STYLE_DFT);//2
            Paint_DrawPoint(X_Center - YCurrent, Y_Center + XCurrent, Color, Line_width, DOT_STYLE_DFT);//3
            Paint_DrawPoint(X_Center - YCurrent, Y_Center - XCurrent, Color, Line_width, DOT_STYLE_DFT);//4
            Paint_DrawPoint(X_Center - XCurrent, Y_Center - YCurrent, Color, Line_width, DOT_STYLE_DFT);//5
            Paint_DrawPoint(X_Center + XCurrent, Y_Center - YCurrent, Color, Line_width, DOT_STYLE_DFT);//6
            Paint_DrawPoint(X_Center + YCurrent, Y_Center - XCurrent, Color, Line_width, DOT_STYLE_DFT);//7
            Paint_DrawPoint(X_Center + YCurrent, Y_Center + XCurrent, Color, Line_width, DOT_STYLE_DFT);//0

            if (Esp < 0 )
                Esp += 4 * XCurrent + 6;
            else {
                Esp += 10 + 4 * (XCurrent - YCurrent );
                YCurrent --;
            }
            XCurrent ++;
        }
    }
}

/******************************************************************************
  function: Show English characters
  parameter:
    Xpoint           ：X coordinate
    Ypoint           ：Y coordinate
    Acsii_Char       ：To display the English characters
    Font             ：A structure pointer that displays a character size
    Color_Background : Select the background color of the English character
    Color_Foreground : Select the foreground color of the English character
******************************************************************************/
void Paint_DrawChar(uint16_t Xpoint, uint16_t Ypoint, const char Acsii_Char,
                    uint16_t Color_Background, uint16_t Color_Foreground)
{

  int16_t Page, Column;

  if (Xpoint > Paint.Width || Ypoint > Paint.Height) {
    printf("Paint_DrawChar Input exceeds the normal display range\r\n");
    return;
  }
  uint32_t Char_Offset = (Acsii_Char - ' ') * FONT_HEIGHT * (FONT_WIDTH / 8 + (FONT_WIDTH % 8 ? 1 : 0));
  const unsigned char *ptr = &font_table[Char_Offset];
  
  for ( Page = 0; Page < 2 * FONT_HEIGHT; Page += 2 ) {
    for ( Column = 2 * FONT_WIDTH - 2; Column >= 0; Column -= 2 ) {

      //To determine whether the font background color and screen background color is consistent
      if (FONT_BACKGROUND == Color_Background) { //this process is to speed up the scan
        if ((*ptr) & (0x80 >> (Column/2 % 8)))
            Paint_DrawPoint(Xpoint + Page, Ypoint + Column, Color_Foreground, DOT_PIXEL_2X2, DOT_STYLE_DFT);
      } else {
        if ((*ptr) & (0x80 >> (Column/2 % 8))) {
            Paint_DrawPoint(Xpoint + Page, Ypoint + Column, Color_Foreground, DOT_PIXEL_2X2, DOT_STYLE_DFT);
        } else {
            Paint_DrawPoint(Xpoint + Page, Ypoint + Column, Color_Background, DOT_PIXEL_2X2, DOT_STYLE_DFT);
        }
      }
      //One pixel is 8 bits
      if (Page % 8 == 7) {
        ptr++;
      }
    }/* Write a line */
    if (FONT_HEIGHT % 8 != 0) {
      ptr++;
    }
  }/* Write all */
}

/******************************************************************************
  function: Display the string
  parameter:
    Xstart           ：X coordinate
    Ystart           ：Y coordinate
    pString          ：The first address of the English string to be displayed
    Font             ：A structure pointer that displays a character size
    Color_Background : Select the background color of the English character
    Color_Foreground : Select the foreground color of the English character
******************************************************************************/
void Paint_DrawString_EN(uint16_t Xstart, uint16_t Ystart, const char * pString,
                         uint16_t Color_Background, uint16_t Color_Foreground )
{
  uint16_t Xpoint = Xstart;
  uint16_t Ypoint = Ystart;

  if (Xstart > Paint.Width || Ystart > Paint.Height) {
    printf("Paint_DrawString_EN Input exceeds the normal display range\r\n");
    return;
  }

  while (* pString != '\0') {
    //if X direction filled , reposition to(Xstart,Ypoint),Ypoint is Y direction plus the Height of the character
    if ((Xpoint + FONT_WIDTH ) > Paint.Width ) {
      Xpoint = Xstart;
      Ypoint += FONT_HEIGHT;
    }

    // If the Y direction is full, reposition to(Xstart, Ystart)
    if ((Ypoint  + FONT_HEIGHT ) > Paint.Height ) {
      Xpoint = Xstart;
      Ypoint = Ystart;
    }
    Paint_DrawChar(Xpoint, Ypoint, * pString, Color_Background, Color_Foreground);

    //The next character of the address
    pString ++;

    //The next word of the abscissa increases the font of the broadband
    Xpoint += 2 * FONT_WIDTH;
  }
}

/******************************************************************************
  function: Display nummber
  parameter:
    Xstart           ：X coordinate
    Ystart           : Y coordinate
    Nummber          : The number displayed
    Font             ：A structure pointer that displays a character size
    Color_Background : Select the background color of the English character
    Color_Foreground : Select the foreground color of the English character
******************************************************************************/
#define  ARRAY_LEN 50
void Paint_DrawNum(uint16_t Xpoint, uint16_t Ypoint, int32_t Nummber,
                   uint16_t Color_Background, uint16_t Color_Foreground )
{

  int16_t Num_Bit = 0, Str_Bit = 0;
  uint8_t Str_Array[ARRAY_LEN] = {0}, Num_Array[ARRAY_LEN] = {0};
  uint8_t *pStr = Str_Array;

  if (Xpoint > Paint.Width || Ypoint > Paint.Height) {
    printf("Paint_DisNum Input exceeds the normal display range\r\n");
    return;
  }

  //Converts a number to a string
  do{
    Num_Array[Num_Bit] = Nummber % 10 + '0';
    Num_Bit++;
    Nummber /= 10;
  }while (Nummber);

  //The string is inverted
  while (Num_Bit > 0) {
    Str_Array[Str_Bit] = Num_Array[Num_Bit - 1];
    Str_Bit ++;
    Num_Bit --;
  }

  //show
  Paint_DrawString_EN(Xpoint, Ypoint, (const char*)pStr, Color_Background, Color_Foreground);
}
/******************************************************************************
function:	Display float number
parameter:
    Xstart           ：X coordinate
    Ystart           : Y coordinate
    Nummber          : The float data that you want to display
	Decimal_Point	 : Show decimal places
    Font             ：A structure pointer that displays a character size
    Color            : Select the background color of the English character
******************************************************************************/
void Paint_DrawFloatNum(uint16_t Xpoint, uint16_t Ypoint, double Nummber,  uint8_t Decimal_Point, 
                        uint16_t Color_Background, uint16_t Color_Foreground)
{
  char Str[ARRAY_LEN] = {0};
  char * pStr= (char *)malloc((strlen(Str))*sizeof(char));
  memcpy(pStr,Str,(strlen(Str)-2));
  * (pStr+strlen(Str)-1)='\0';
  if((*(pStr+strlen(Str)-3))=='.')
  {
	*(pStr+strlen(Str)-3)='\0';
  }
  //show
  Paint_DrawString_EN(Xpoint, Ypoint, (const char*)pStr, Color_Foreground, Color_Background);
  free(pStr);
  pStr=NULL;
}

/******************************************************************************
  function: Display time
  parameter:
    Xstart           ：X coordinate
    Ystart           : Y coordinate
    pTime            : Time-related structures
    Font             ：A structure pointer that displays a character size
    Color            : Select the background color of the English character
******************************************************************************/
void Paint_DrawTime(uint16_t Xstart, uint16_t Ystart, PAINT_TIME *pTime,
                    uint16_t Color_Background, uint16_t Color_Foreground)
{
  uint8_t value[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  uint16_t Dx = FONT_WIDTH;

  //Write data into the cache
  Paint_DrawChar(Xstart                           , Ystart, value[pTime->Hour / 10], Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx                      , Ystart, value[pTime->Hour % 10], Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx  + Dx / 4 + Dx / 2   , Ystart, ':'                    , Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx * 2 + Dx / 2         , Ystart, value[pTime->Min / 10] , Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx * 3 + Dx / 2         , Ystart, value[pTime->Min % 10] , Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx * 4 + Dx / 2 - Dx / 4, Ystart, ':'                    , Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx * 5                  , Ystart, value[pTime->Sec / 10] , Color_Background, Color_Foreground);
  Paint_DrawChar(Xstart + Dx * 6                  , Ystart, value[pTime->Sec % 10] , Color_Background, Color_Foreground);
}

/******************************************************************************
  function: Display image
  parameter:
    image            ：Image start address
    xStart           : X starting coordinates
    yStart           : Y starting coordinates
    xEnd             ：Image width
    yEnd             : Image height
******************************************************************************/
void Paint_DrawImage(const unsigned char *image, uint16_t xStart, uint16_t yStart, uint16_t W_Image, uint16_t H_Image)
{
  int i, j;
  for (j = 0; j < H_Image; j++) {
    for (i = 0; i < W_Image; i++) {
      if (xStart + i < LCD_WIDTH  &&  yStart + j < LCD_HEIGHT) //Exceeded part does not display
        Paint_SetPixel(xStart + i, yStart + j, (*(image + j * W_Image * 2 + i * 2 + 1)) << 8 | (*(image + j * W_Image * 2 + i * 2)));
      //Using arrays is a property of sequential storage, accessing the original array by algorithm
      //j*W_Image*2          Y offset
      //i*2                  X offset
    }
  }

}