/* 
* LedBarMeter.cpp
*
* Created: 18.10.18 23:36:22
* Author: Klemens Svetitsch
*/


#include "LedBarMeter.h"
#include <avr/io.h>

// default constructor
LedBarMeter::LedBarMeter()
{
} //LedBarMeter

// default destructor
LedBarMeter::~LedBarMeter()
{
} //~LedBarMeter

// https://msdn.microsoft.com/en-us/library/office/gg251651.aspxhttps://msdn.microsoft.com/de-de/library/87by589c.aspx
void LedBarMeter::SetBarMeter(int count)
{
	PORTA &= 0x0F; // set the upper nibble to all 0s
	
	if (count < 51) {
		//PORTA |= 0b0000 << 4;
		// no need to do anything, upper nibble is already 0
	}
	else if (count < 102) {
		PORTA |= 0b0001 << 4;
	}
	else if (count < 153) {
		PORTA |= 0b0011 << 4;
	}
	else if (count < 204) {
		PORTA |= 0b0111 << 4;
	}
	else {
		PORTA |= 0b1111 << 4;
	}
			
	/*for(int i = 0; i < 4; ++i) {
		PORTA &= ~(1 << i);
	}
	for(int i = 1; i <= led_cnt; ++i) {
		PORTA |= (1 << (i-1));
		}*/
}