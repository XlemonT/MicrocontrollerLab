/*
 * Microcontroller_Labor.cpp
 *
 * Created: 16.10.18 10:23:23
 * Author : Clemens Zuzan, Klemens Svetitsch
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include "PortControl.h"
#include "LedBarMeter.h"


int main(void)
{
	// set LEDs to output
	DDRA = 0xF0; // set upper nibble to write, lower nibble to read
	//PORTA |= (1 << PA0); // set Port A's Pin 0 to read
	
	LedBarMeter led_bar = LedBarMeter();
	PORTA |= (1 << 2); // make LED 3 light up to prove that LED bar does not interfere with lower nibble (upper LED bar)
	
    uint8_t count = 0;
	//uint8_t pot_value = 0;
    while(1)
    {
		led_bar.SetBarMeter(count);
	    count += 1;
	    _delay_ms(10);
    }
}

