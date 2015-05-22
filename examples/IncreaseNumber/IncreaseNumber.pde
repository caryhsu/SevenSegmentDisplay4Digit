#include <SevenSegmentDisplay4Digit.h>

// SCLK = 3, RCLK = 4, DIO = 5
SevenSegmentDisplay4Digit display = SevenSegmentDisplay4Digit(3,4,5);

int value = 0;
unsigned long startTime;
void setup()                    
{
	startTime = millis();
}

void loop()
{
	unsigned long currentTime = millis();
	if (currentTime - startTime > 1000) {
		value ++;
		startTime = currentTime;
	}
	display.setNumber(value);
}
