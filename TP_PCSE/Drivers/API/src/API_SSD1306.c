/*
 * API_SSD1306.c
 *
 *  Created on: Aug 05, 2023
 *      Author: Lautaro Quarin
 */


#include "API_SSD1306.h"
#include <stdlib.h>
#include <string.h>



// Screenbuffer
static uint8_t SSD1306_Buffer[SSD1306_BUFFER_SIZE];

// Screen object
static SSD1306_t SSD1306;


void ssd1306_WriteCommand(uint8_t byte)
{
	//HAL function information: HAL_I2C_Mem_Write(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size, Timeout);

	HAL_I2C_Mem_Write(&SSD1306_I2C_PORT, SSD1306_I2C_ADDR, SSD1306_COMMAND_STREAM, 1, &byte, 1, HAL_MAX_DELAY);

}

void ssd1306_WriteData(uint8_t* buffer, size_t buff_size)
{
	HAL_I2C_Mem_Write(&SSD1306_I2C_PORT, SSD1306_I2C_ADDR, SSD1306_DATA_STREAM, 1, buffer, buff_size, HAL_MAX_DELAY);
}

void ssd1306_Init()
{

	//Time delay for the screen boot
	HAL_Delay(100);

	//Init OLED
	ssd1306_SetDisplayOn(0);

	ssd1306_WriteCommand(SSD1306_MEMORY_ADDR_MODE); //0x20 set memory addressing mode
	ssd1306_WriteCommand(0x00); // 00b Horizontal addressing Mode, 01b Vertical addressing mode, 10b page addressing mode.

	ssd1306_WriteCommand(0xB0); // 0xB0 Set page Start Address for page addressing mode 0-7.

	ssd1306_WriteCommand(SSD1306_COM_SCAN_DIR_OP); //0xC8 Set COM Output Scan Direction

	ssd1306_WriteCommand(0x00); //0x0 set low column address
	ssd1306_WriteCommand(0x10); //0x10 set high column address

	ssd1306_WriteCommand(SSD1306_SET_START_LINE); // 0x40 set start line address

	//SetContrast(0xFF);
	ssd1306_WriteCommand(SSD1306_SET_CONTRAST);
	ssd1306_WriteCommand(0xFF);

	ssd1306_WriteCommand(SSD1306_SEG_REMAP_OP); //0xA1 set segment re-map 0 to 127

	ssd1306_WriteCommand(SSD1306_DIS_NORMAL); //0xA6 set normal color



	ssd1306_WriteCommand(SSD1306_SET_MUX_RATIO); //0xA8 set multiplex ratio to 1-64
	ssd1306_WriteCommand(0x3F); // Set multiplex ratio for 128px high

	ssd1306_WriteCommand(SSD1306_DIS_ENT_DISP_ON); //0xA4 Output follows RAM content.

	ssd1306_WriteCommand(SSD1306_DISPLAY_OFFSET); //0xD3 display offset
	ssd1306_WriteCommand(0x00);					//Not offset

	ssd1306_WriteCommand(SSD1306_SET_OSC_FREQ); //0xD5 set display clock divide ratio/oscilator freq
	ssd1306_WriteCommand(0xF0);		//Set divide ratio.

	ssd1306_WriteCommand(SSD1306_SET_PRECHARGE);	//0xD9 Set pre-charged period
	ssd1306_WriteCommand(0x22);	//Set period.

	ssd1306_WriteCommand(SSD1306_COM_PIN_CONF); //0xDA set com pins hardware config
	ssd1306_WriteCommand(0x12);	//64px height

    ssd1306_WriteCommand(SSD1306_VCOM_DESELECT); // set vcomh
    ssd1306_WriteCommand(0x20); //0x20,0.77xVcc

    ssd1306_WriteCommand(SSD1306_SET_CHAR_REG); //DC-DC ENABLE
    ssd1306_WriteCommand(0x14);
//Turn on display
    ssd1306_SetDisplayOn(1);
//Clear screen
ssd1306_Fill(Black);
//Update filling color
ssd1306_UpdateScreen();

//Set default values in coordinates(0;0)
SSD1306.CurrentX = 0;
SSD1306.CurrentY = 0;

//Change control parameter in structure.
SSD1306.Initialized = 1;

}

void ssd1306_Fill(SSD1306_COLOR color)
{
	uint32_t index;

	for (index = 0; index < sizeof(SSD1306_Buffer); index++)
	{
		SSD1306_Buffer[index] = (color == Black) ? 0x00 : 0xFF; //if we fill the buffer with 0x00 we set all bits on 0 (px off = white)
																//If we fill the buffer with 0xFF we set all bits on 1 (pixels on = black)
	}
}

void ssd1306_UpdateScreen()
{
	//must write data to each page of RAM. Screen height is 128px, according to data sheet thats equivalent to 16 pages.
	uint8_t index;
	for(index = 0; index < SSD1306_HEIGHT/8; index++ )
	{
		ssd1306_WriteCommand(0xB0 + index); //Set the curren RAM page address.
		ssd1306_WriteCommand(0x00);			//Set column address to 0 (No X offset)
		ssd1306_WriteCommand(0x10);			//Set higher nibble of column address to 0
		ssd1306_WriteData(&SSD1306_Buffer[SSD1306_WIDTH*index],SSD1306_WIDTH);

	}

}


void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color)
{
	//Check if coordinates (x,y) are inside limits.
	if(x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT)
	{
		return;
	}

	//We have 8 pixeles in evert byte of the buffer, it means that every byte represents 8 vertical pixels on the screen.
	//(y/8) gives us the number of the column. *WIDHT gives the position on the buffer. x gives us the horizontal coordinate. (we move exactly to the coord(x,y).
	if(color == White)
	{
		SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] |= 1 << (y % 8); // (y/8) divides "y" by 8 since each byte stores 8 vertical pixels.
																	//It uses the residue (y&8) to determinate which bit inside the byte corresponds to the pixel in "y".
																	//|= turns the bit in 1, turns it on.
	}else
	{
		SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] &= ~(1 << (y % 8)); //(1<< (y&8)) creates a mask with a bit in the correct position.
																		// &= turns of the bit on the byte.
	}
}

char ssd1306_WriteChar(char character, SSD1306_COLOR color)
{
	uint32_t i,b,j;

	//Check if it's valid:
	if(character < 32 || character > 126)
	{
		return 0;
	}
	//Check space in current line:
	if(SSD1306_WIDTH < (SSD1306.CurrentX + Font_7x10.FontWidht) || SSD1306_HEIGHT < (SSD1306.CurrentY + Font_7x10.FontHeight) )
	{
		return 0;
	}

//Lets write:
	for(i = 0; i < Font_7x10.FontHeight; i++)
	{
		b = Font_7x10.data[(character - 32) * Font_7x10.FontHeight + i];
		for(j=0; j<Font_7x10.FontWidht; j++)
		{
			if ((b<<j) & 0x8000)
			{
				ssd1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR) color);
			} else
			{
				ssd1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR)!color);
			}
		}
	}

//Move the cursor:
	SSD1306.CurrentX += Font_7x10.FontWidht;

//Return written char for validation
	return character;

}

char ssd1306_WriteString(char* string, SSD1306_COLOR color)
{
	while(*string)
	{
		if(ssd1306_WriteChar(*string, color) != *string)
		{
			return *string; //Char could not be written.
		}

		string++;
	}
	return *string;
}


//Not ready yet.
void ssd1306_SetCursor(uint8_t x, uint8_t y){
	SSD1306.CurrentX = x;
	SSD1306.CurrentY = y;
}

void ssd1306_SetDisplayOn(const uint8_t on)
{
	uint8_t command;
	if(on)
	{
		//Display on
		SSD1306.DisplayOn = 1;
		command = SSD1306_DISPLAY_ON; //0xAF
	} else
	{
		//Display off
		SSD1306.DisplayOn = 0;
		command = SSD1306_DISPLAY_OFF; //0xAE
	}
	ssd1306_WriteCommand(command);
}