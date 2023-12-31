/*
 * API_SSD1306_Fonts.h
 *
 *  Created on: Aug 05, 2023
 *      Author: Lautaro Quarin
 */

#ifndef API_INC_API_SSD1306_FONTS_H_
#define API_INC_API_SSD1306_FONTS_H_

#include <stdint.h>

typedef struct {
	const uint8_t FontWidht;
	uint8_t FontHeight;
	const uint16_t *data;
}FontDef;


extern FontDef Font_7x10;


#endif /* API_INC_API_SSD1306_FONTS_H_ */
