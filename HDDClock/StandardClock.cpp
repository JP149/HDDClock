#include "StandardClock.h"
#include "Arduino.h"

void StandardClock::UpdateClock(unsigned long _secondsOffset)
{
  secondsOffset = _secondsOffset;
  
  unsigned long clockTime = millis() / 1000;//seconds
  clockTime = clockTime + secondsOffset;
  
  seconds = clockTime % 60;

  clockTime /= 60; //minutes
  minutes = clockTime % 60;

  clockTime /=60;  //hours
  hours = clockTime%12;
}
