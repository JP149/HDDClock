#ifndef ColorConfig_h
#define ColorConfig_h

#include "Arduino.h"
#include "Color.h"
#include "StandardClock.h"

class ColorConfig
{
  public:
    virtual Color getColorAt(double currentPos) = 0;
};

class ClockColorConfig: public ColorConfig
{
  public:
    ClockColorConfig(StandardClock* _standardClock);
    
    Color SecondsHand;
    Color MinutesHand;
    Color HoursHand;
    Color HourMarker;

    StandardClock* standardClock;
    float secondsWidth, minutesWidth, hoursWidth, hourMarkerWidth;

    Color getColorAt(double currentPos) override;
};

#endif
