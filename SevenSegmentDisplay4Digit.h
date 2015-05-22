#ifndef SevenSegmentDisplay4Digit_h
#define SevenSegmentDisplay4Digit_h

//#include <inttypes>

class SevenSegmentDisplay4Digit
{
public:
	SevenSegmentDisplay4Digit(int p_SCLK, int p_RCLK, int p_DIO);
	void refresh(void);
	void setNumber(int number);
	void setNumber(double number);
	void setDoubleScale(int scale);
	void setPointAt(int position);
	void increase();
	void decrease();

private:
	int SCLK;
	int RCLK;
	int DIO;
	void out(unsigned char X);
	unsigned char LED[4];
	int intNumber;
	double doubleNumber;
	int doubleScale;
	int pointPosition;
	void doSetNumber(int number);
	
};
#endif
