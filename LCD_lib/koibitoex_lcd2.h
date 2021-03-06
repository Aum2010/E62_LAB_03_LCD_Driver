#include "stdint.h"

/* Include guard, Macro guard */
/* https://en.wikipedia.org/wiki/Include_guard */
#ifndef KOIBITOEX_LCD2_H
#define KOIBITOEX_LCD2_H

#define LCD_LINE_1					0
#define LCD_LINE_2					1

#define LCD_CURSOR_OFF			0
#define LCD_CURSOR_ON				1

#define LCD_BACKLIGHT_OFF		0
#define LCD_BACKLIGHT_ON		1

#define LCD_CLS_ALL					0
#define LCD_CLS_LINE_1			1
#define LCD_CLS_LINE_2			2

void LcdInit(void);
void LcdCls(uint8_t status);
void LcdSetCursor(uint8_t status);
void LcdSetBackLight(uint8_t status);
void LcdSetPosition(uint8_t line, uint8_t pos);
void LcdPutCh(uint8_t c);
void LcdPutS(char *s);

#endif /* KOIBITOEX_LCD2_H */

/*********************************END OF FILE**********************************/
