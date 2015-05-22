#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "SevenSegmentDisplay4Digit.h"
#include <math.h>
SevenSegmentDisplay4Digit::SevenSegmentDisplay4Digit(int p_SCLK, int p_RCLK, int p_DIO) 
{
	SCLK = p_SCLK;
	RCLK = p_RCLK;
	DIO = p_DIO;
	
	pinMode(SCLK, OUTPUT);
	pinMode(RCLK, OUTPUT);
	pinMode(DIO, OUTPUT); 
	intNumber = 0;
}
	
void SevenSegmentDisplay4Digit::refresh(void)
{
	unsigned char LED_0F[] =
	{// 0	 1	  2	   3	4	 5	  6	   7	8	 9	  A	   b	C    d	  E    F    -
		0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x8C, 0xBF, 0xC6, 0xA1, 0x86, 0xFF, 0xbf
	};

	unsigned char number;
	
	// first digit 
	number = LED_0F[LED[0]];
	if (pointPosition == 0) number = number - 128;
	out(number);
	out(0x01);
	digitalWrite(RCLK, LOW);
	digitalWrite(RCLK, HIGH);
	
	// second digit
	number = LED_0F[LED[1]];
	if (pointPosition == 1) number = number - 128;
	out(number);
	out(0x02);
	digitalWrite(RCLK, LOW);
	digitalWrite(RCLK, HIGH);
	
	// third digit
	number = LED_0F[LED[2]];
	if (pointPosition == 2) number = number - 128;
	out(number);
	out(0x04);
	digitalWrite(RCLK, LOW);
	digitalWrite(RCLK, HIGH);
	
	// forth digit
	number = LED_0F[LED[3]];
	if (pointPosition == 3) number = number - 128;
	out(number);
	out(0x08);
	digitalWrite(RCLK, LOW);
	digitalWrite(RCLK, HIGH);
}

void SevenSegmentDisplay4Digit::out(unsigned char X)
{
	unsigned char i;
	for (i = 8; i >= 1; i--)
	{
		if (X & 0x80)
		{
			digitalWrite(DIO, HIGH);
		}
		else
		{
			digitalWrite(DIO, LOW);
		}
		X <<= 1;
		digitalWrite(SCLK, LOW);
		digitalWrite(SCLK, HIGH);
	}
}

void SevenSegmentDisplay4Digit::setNumber(int p_number)
{
	p_number = p_number % 10000;
	if (p_number < 0) p_number = p_number + 10000;
	doSetNumber(p_number);
	intNumber = p_number;
	refresh();
}

void SevenSegmentDisplay4Digit::doSetNumber(int p_number)
{
	p_number = p_number % 10000;
	if (p_number < 0) p_number = p_number + 10000;
	LED[3] = p_number / 1000;
	p_number %= 1000;
	LED[2] = p_number / 100;
	p_number %= 100;
	LED[1] = p_number / 10;
	LED[0] = p_number % 10;
}

void SevenSegmentDisplay4Digit::setPointAt(int position)
{
	pointPosition = position;
}

void SevenSegmentDisplay4Digit::increase()
{
	setNumber(intNumber + 1);
}

void SevenSegmentDisplay4Digit::decrease()
{
	setNumber(intNumber - 1);
}
