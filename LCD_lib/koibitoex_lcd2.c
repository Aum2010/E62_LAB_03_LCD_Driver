#include "stm32f3xx_hal.h"
#include "koibitoex_lcd2.h"

#define LCD_DATA_PORT		GPIOC
#define LCD_DB_7				GPIO_PIN_3
#define LCD_DB_6				GPIO_PIN_2
#define LCD_DB_5				GPIO_PIN_1
#define LCD_DB_4				GPIO_PIN_0

#define LCD_CTL_PORT		GPIOB
#define LCD_E						GPIO_PIN_2
#define LCD_RW					GPIO_PIN_1
#define LCD_RS					GPIO_PIN_0

#define LCD_BKL_PORT		GPIOE
#define LCD_BKL					GPIO_PIN_7

static void LcdWriteNibble(uint8_t lcdData);
static void LcdWriteCmd(uint8_t lcdCmd);
static void LcdWriteData(uint8_t lcdData);

void LcdInit(void)
{

	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,GPIO_PIN_SET);

	HAL_Delay(15);

	LcdWriteNibble(0x30);
	HAL_Delay(5);

	LcdWriteNibble(0x30);
	delay_us(100);
	//HAL_Delay(1);

	LcdWriteNibble(0x30);
	delay_us(100);
	//HAL_Delay(1);

	LcdWriteNibble(0x20);
	delay_us(100);
	//HAL_Delay(1);

	LcdWriteCmd(0x28);
	delay_us(39);
	//HAL_Delay(1);

	LcdWriteCmd(0x0F);
	delay_us(39);
	//HAL_Delay(1);

	LcdWriteCmd(0x01);
	HAL_Delay(2);

	LcdWriteCmd(0x06);
	delay_us(39);
}

void LcdCls(uint8_t status)
{
	int i = 17;

	if( status == LCD_CLS_LINE_1 ) {
		LcdSetPosition( LCD_LINE_1 , i );
		while(i != 0) {
			LcdPutCh(' ');
			delay_us(43);
			LcdSetPosition( LCD_LINE_1 , i );
			i--;
		}

		LcdSetPosition( LCD_LINE_1 , 0 );

	}else if(status == LCD_CLS_LINE_2){
		LcdSetPosition( LCD_LINE_2 , i );
		while(i != 0) {
			LcdPutCh(' ');
			delay_us(43);
			LcdSetPosition( LCD_LINE_2 , i );
			i--;
		}

		LcdSetPosition( LCD_LINE_2 , 0 );

	}else if(status == LCD_CLS_ALL){
		LcdWriteCmd(0x01);
		HAL_Delay(2);
	}


}

void LcdSetCursor(uint8_t status)
{
	status == LCD_CURSOR_ON ? LcdWriteCmd(0x0F) : LcdWriteCmd(0x0E) ;
	//LcdWriteCmd(0x0F);
	delay_us(39);
}

void LcdSetBackLight(uint8_t status)
{
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,status == LCD_BACKLIGHT_ON ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void LcdSetPosition(uint8_t line, uint8_t pos)
{
	if( line == LCD_LINE_1 )
	{
		line = 0x00 ;
	}
	else if( line == LCD_LINE_2 )
	{
		line = 0x40 ;
	}

	pos = pos % 16 ;

	uint8_t cmd = line & 0xF0 | pos & 0x0F ;
	LcdWriteCmd(cmd | 0x80);
	delay_us(39);
}

void LcdPutCh(uint8_t c)
{
	LcdWriteData(c);
	delay_us(43);
}

void LcdPutS(char *s)
{
	int i = 0;
	while(s[i] != '\0'){
		LcdWriteData(s[i]);
		delay_us(43);
		i++;
	}
}

static void LcdWriteNibble(uint8_t data)
{
	int i[6] = {0,0,0,0,0,0};

	i[0] = (data & 0x80) >> 7;
	i[1] = (data & 0x40) >> 6;
	i[2] = (data & 0x20) >> 5;
	i[3] = (data & 0x10) >> 4;


	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,i[0] ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,i[1] ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,i[2] ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,i[3] ? GPIO_PIN_SET : GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
}

static void LcdWriteCmd(uint8_t cmd)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);

	LcdWriteNibble(cmd & 0xF0);
	LcdWriteNibble(cmd << 4);

}

static void LcdWriteData(uint8_t data)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
	LcdWriteNibble(data & 0xF0);
	LcdWriteNibble(data << 4);
	delay_us(43);
}


/*********************************END OF FILE**********************************/
