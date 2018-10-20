/* 
* PortControl.h
*
* Created: 19.10.18 22:00:26
* Author: filmu
*/


#ifndef __PORTCONTROL_H__
#define __PORTCONTROL_H__

#include <avr/io.h>

class PortControl
{
//variables
public:
protected:
private:

//functions
public:
	PortControl();
	~PortControl();
	
	static volatile uint8_t* GetPortAddress(char port) {
		switch(port) {
			case 'a':
			case 'A':
				return &PORTA;

			case 'b':
			case 'B':
				return &PORTB;

			case 'c':
			case 'C':
				return &PORTC;

			case 'd':
			case 'D':
				return &PORTD;
		}
		return 0;
	}
	static bool IsPinSet(char port, int pin_number) {
		return (*GetPortAddress(port)) & (1 << pin_number);
	}
	static void SetPin(char port, int pin_number, bool value) {
		volatile uint8_t* port_bits = GetPortAddress(port);
		if (value) {
			*port_bits |= (1 << pin_number);
			} else {
			*port_bits &= ~(1 << pin_number);
		}
	}
	
protected:
private:

}; //PortControl

#endif //__PORTCONTROL_H__
