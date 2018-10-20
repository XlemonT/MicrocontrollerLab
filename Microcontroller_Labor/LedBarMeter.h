/* 
* LedBarMeter.h
*
* Created: 18.10.18 23:36:23
* Author: Klemens Svetitsch
*/


#ifndef __LEDBARMETER_H__
#define __LEDBARMETER_H__


/**
Controller Class for the LED Bar
*/
class LedBarMeter
{
//variables
public:
protected:
private:

//functions
public:
	LedBarMeter();
	~LedBarMeter();
	
	/**
	makes a specific number of LEDs light up, depending on the number passed to the function
	*/
	void SetBarMeter(int count);
protected:

}; //LedBarMeter

#endif //__LEDBARMETER_H__
