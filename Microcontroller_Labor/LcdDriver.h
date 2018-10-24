/* 
* LcdDriver.h
*
* Created: 22.10.18 23:24:24
* Author: Clemens Zuzan, Klemens Svetitsch
*/

#ifndef __LCDDRIVER_H__
#define __LCDDRIVER_H__

#include <avr/io.h>

#define LCD_PORT PORTB
#define LCD_DDR DDRB

// DELAYS
#define LCD_DELAY_PULSE 50
#define LCD_DELAY_COMMAND 40
#define LCD_DELAY_LONG_COMMAND 1.5

#define LCD_PIN_RS PB0
#define LCD_PIN_RW PB1
#define LCD_PIN_E PB3
#define LCD_PIN_DB_START PB4

// INSTRUCTIONS
#define LCD_I_CLEAR				0b00000001
#define LCD_I_HOME				0b00000010
#define LCD_I_ENTRY_MODE		0b00000100
#define LCD_I_DISPLAY_CONTROL	0b00001000

#define LCD_I_FUNCTION_SET		0b00100000

#define LCD_FUNCTION_SET_DL8	0b00010000
#define LCD_FUNCTION_SET_DL4	0b00000000

#define LCD_FUNCTION_SET_2LINE  0b00001000
#define LCD_FUNCTION_SET_2LINE  0b00000000

#define LCD_FUNCTION_SET_5x10	0b00000100
#define LCD_FUNCTION_SET_5x8	0b00000000


class LcdDriver
{
//variables
public:
protected:
private:
	bool FourBitMode;

//constants
private:
	

//functions
public:
	LcdDriver();
	~LcdDriver();
	void init();
	void print(const char* text);
	void clear_display();
	void return_home();
	
protected:
private:
	void send_enable_pulse();
	void send(uint8_t data);
	void send_command(uint8_t command_8bit);
	void send_data(uint8_t data_8bit);

}; //LcdDriver

#endif //__LCDDRIVER_H__
