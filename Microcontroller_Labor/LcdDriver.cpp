/* 
* LcdDriver.cpp
*
* Created: 22.10.18 23:24:24
* Author: Clemens Zuzan, Klemens Svetitsch
*/


#include "LcdDriver.h"
#include <util/delay.h>

// default constructor
LcdDriver::LcdDriver()
{
	LCD_DDR = 0xFF; // set lcd port to write
} //LcdDriver

// default destructor
LcdDriver::~LcdDriver()
{
} //~LcdDriver

void LcdDriver::init()
{
	_delay_ms(15); // wait 15ms
	
	send(0x03); // init 1
	_delay_ms(5); // wait 5ms
	
	send(0x03); // init 2
	_delay_us(200); // wait 200us
	
	send(0x03); // init 3
	_delay_us(LCD_DELAY_COMMAND); // wait 40us
	
	send((LCD_I_FUNCTION_SET | LCD_FUNCTION_SET_DL4) >> 4); // set function set to 4 bits
	_delay_us(LCD_DELAY_COMMAND); // wait 40us for function set command
	
	// set lines
	send_command( LCD_I_FUNCTION_SET | LCD_FUNCTION_SET_DL4 | LCD_FUNCTION_SET_2LINE | LCD_FUNCTION_SET_5x10);
	
	clear_display();
}


void LcdDriver::send(uint8_t data)
{
	if (this->FourBitMode) {
		// in 4 bit mode we only send the lower 4 bits
		data &= 0x0F;
	}
	
	LCD_PORT &= ~(0x0F << LCD_PIN_DB_START); // delete the port bits that we want to write
	LCD_PORT |= data << LCD_PIN_DB_START; // write the data bits to the port, move them to the location of the DB connections
	
	send_enable_pulse();
}

void inline LcdDriver::send_enable_pulse()
{
	LCD_PORT |= (1 << LCD_PIN_E);
	_delay_us(LCD_DELAY_PULSE);
	LCD_PORT &= ~(1 << LCD_PIN_E);
}

void LcdDriver::send_command(uint8_t command_8bit)
{
	LCD_PORT &= ~(1 << LCD_PIN_RS);    // set RS to IR (RS = 0)
	
	send(command_8bit >> 4); //send upper nibble X0
	send(command_8bit); // send lower nibble 0X
	
	//_delay_us( LCD_DELAY_COMMAND ); // min 37 uS
}

void LcdDriver::send_data(uint8_t data_8bit)
{
	LCD_PORT |= (1 << LCD_PIN_RS);    // set RS to DR (RS = 1)
	
	send(data_8bit >> 4); //send upper nibble X0
	send(data_8bit); // send lower nibble 0X
	
	//_delay_us( LCD_DELAY_COMMAND ); // min 37 uS
}

void LcdDriver::print(const char* text)
{
	for(; *text != '\0'; *(text++)) {
		this->send(*text);
	}
}

void LcdDriver::clear_display()
{
	send_command(LCD_I_CLEAR);
	_delay_ms(LCD_DELAY_LONG_COMMAND);
}

void LcdDriver::return_home()
{
	send_command(LCD_I_HOME);
	_delay_ms(LCD_DELAY_LONG_COMMAND);
}
