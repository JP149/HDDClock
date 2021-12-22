#ifndef StandardClock_h
#define StandardClock_h
#include "Arduino.h"

class StandardClock
{
  public:
    unsigned long secondsOffset=0;
    byte seconds = 0, minutes = 0, hours = 0;
    void UpdateClock(unsigned long _secondsOffset);
};

#endif
