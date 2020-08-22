// rotEncoder.h

#ifndef _ROTENCODER_h
#define _ROTENCODER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class RotEncoder
{
 private:
	 byte _switchPin, _clkPin, _dtPin;
	 int32_t encoderPos = 0;
	 boolean dtPinLast, dtVal;

	 unsigned long _timerSw, _timerNc, prev_timerNc, counterResetTmr;
	 boolean _swStatus = 0;
	 boolean _changeNumFlag = 0;
	 boolean swStatus = 0;
	 boolean swOn = 0;
	 uint8_t _i = 0;
	
 public:
	 RotEncoder(byte swPin , byte clkPin , byte dtPin );
	 unsigned long pushTime();
	 uint16_t pushCounter();
	 int32_t rotVal();
	 void setEncoderPos(int32_t inVal = 0);

	 void pushCounterResetTimer(uint16_t resetTime = 2000);
	 void pushCounterReset();

	 unsigned long setTimerSw2Millis();
	 void resetTimerNc();
	 int8_t pushTimerReset();
};

//extern RotEncoder RotEncoder;

#endif

