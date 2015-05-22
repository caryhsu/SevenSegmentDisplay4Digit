#include <SevenSegmentDisplay4Digit.h>

// SCLK = 3, RCLK = 4, DIO = 5
SevenSegmentDisplay4Digit display = SevenSegmentDisplay4Digit(3,4,5);

void setup()                    
{
}

void loop()
{
	display.setNumber(1234);
}
