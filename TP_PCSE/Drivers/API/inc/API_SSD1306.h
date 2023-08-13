/*
 * API_SSD1306.h
 *
 *  Created on: Aug 05, 2023
 *      Author: Lautaro Quarin
 */

#ifndef API_INC_API_SSD1306_H_
#define API_INC_API_SSD1306_H_

#include <stddef.h>
#include <_ansi.h>
#include "stm32f4xx_hal.h" // Needed for I2C.
#include "API_SSD1306_Fonts.h" //Needed for bit maps.
#include "main.h"
/*
 *	I2C configuration
 */
#define SSD1306_I2C_PORT hi2c1
#define SSD1306_I2C_ADDR (0x3C << 1) //Written on the back of the display.

extern I2C_HandleTypeDef SSD1306_I2C_PORT; //Already defined by ioc in main.c


/*
 *  OLED dimensions, colors, status and position
 */
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64
#define SSD1306_BUFFER_SIZE (SSD1306_WIDTH * SSD1306_HEIGHT / 8)

typedef enum {
	Black = 0x00,   //It's no pixel
	White = 0x01	//one point
} SSD1306_COLOR;

typedef struct {
	uint16_t CurrentX;
	uint16_t CurrentY;
	uint8_t Initialized;
	uint8_t DisplayOn;
}SSD1306_t;


/*
 *	DATASHEET COMMANDS (not all of them will be used in this project).
 */

  // Command definition
  // ------------------------------------------------------------------------------------
  #define SSD1306_COMMAND           0x80  // Continuation bit=1, D/C=0; 1000 0000
  #define SSD1306_COMMAND_STREAM    0x00  // Continuation bit=0, D/C=0; 0000 0000
  #define SSD1306_DATA              0xC0  // Continuation bit=1, D/C=1; 1100 0000
  #define SSD1306_DATA_STREAM       0x40  // Continuation bit=0, D/C=1; 0100 0000

  #define SSD1306_SET_MUX_RATIO     0xA8
  #define SSD1306_DISPLAY_OFFSET    0xD3
  #define SSD1306_DISPLAY_ON        0xAF
  #define SSD1306_DISPLAY_OFF       0xAE
  #define SSD1306_DIS_ENT_DISP_ON   0xA4
  #define SSD1306_DIS_IGNORE_RAM    0xA5
  #define SSD1306_DIS_NORMAL        0xA6
  #define SSD1306_DIS_INVERSE       0xA7
  #define SSD1306_DEACT_SCROLL      0x2E
  #define SSD1306_ACTIVE_SCROLL     0x2F
  #define SSD1306_SET_START_LINE    0x40
  #define SSD1306_MEMORY_ADDR_MODE  0x20
  #define SSD1306_SET_COLUMN_ADDR   0x21
  #define SSD1306_SET_PAGE_ADDR     0x22
  #define SSD1306_SEG_REMAP         0xA0
  #define SSD1306_SEG_REMAP_OP      0xA1
  #define SSD1306_COM_SCAN_DIR      0xC0
  #define SSD1306_COM_SCAN_DIR_OP   0xC8
  #define SSD1306_COM_PIN_CONF      0xDA
  #define SSD1306_SET_CONTRAST      0x81
  #define SSD1306_SET_OSC_FREQ      0xD5
  #define SSD1306_SET_CHAR_REG      0x8D
  #define SSD1306_SET_PRECHARGE     0xD9
  #define SSD1306_VCOM_DESELECT     0xDB

  // Clear Color
  // ------------------------------------------------------------------------------------
  #define CLEAR_COLOR               0x00

  // Init Status
  // ------------------------------------------------------------------------------------
  #define INIT_STATUS               0xFF


/*
 * Definitions
 */
void ssd1306_Init(void);
void ssd1306_Fill(SSD1306_COLOR color);
void ssd1306_UpdateScreen();
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color);
char ssd1306_WriteChar(char character, SSD1306_COLOR color);
char ssd1306_WriteString(char* string, SSD1306_COLOR color);
void ssd1306_SetCursor(uint8_t x, uint8_t y);

/*
 * Reusable code for various functions
 */

void ssd1306_SetDisplayOn(const uint8_t on);
void ssd1306_WriteCommand(uint8_t byte);
void ssd1306_WriteData(uint8_t* buffer, size_t buff_size);



#endif /* API_INC_API_SSD1306_H_ */