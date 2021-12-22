#include "Color.h"
#include "ColorConfig.h"

ClockColorConfig::ClockColorConfig(StandardClock* _standardClock) 
{
  standardClock = _standardClock;
  }

Color ClockColorConfig::getColorAt(double currentPos)
{
  Color* color;
  double lowerBound, upperBound;
  byte hours = standardClock->hours;
  byte minutes = standardClock->minutes;
  byte seconds = standardClock->seconds;

  //hour marker
  lowerBound = 1.0 / 12.0 - 0.5 * hourMarkerWidth;
  upperBound = 0.5 * hourMarkerWidth;

  if (currentPos / 12.0 >= lowerBound & currentPos / 12.0 <= upperBound)
    color = &HourMarker;

  //hour hand
  lowerBound = hours / 12.0 + minutes / (12.0 * 60.0) - 0.5 * hoursWidth;
  upperBound = hours / 12.0 + minutes / (12.0 * 60.0) + 0.5 * hoursWidth;

  if (currentPos >= lowerBound & currentPos <= upperBound)
    color = &HoursHand;

  //minute hand
  lowerBound = minutes / 60.0 + seconds / 3600.0 - 0.5 * minutesWidth;
  upperBound = minutes / 60.0 + seconds / 3600.0 + 0.5 * minutesWidth;

  if (currentPos > lowerBound & currentPos < upperBound)
    color = &MinutesHand;

  //second hand
  lowerBound = seconds / 60.0 - 0.5 * secondsWidth;
  upperBound = seconds / 60.0 + 0.5 * secondsWidth;

  if (currentPos > lowerBound & currentPos < upperBound)
    color = &SecondsHand;

  return *color;
}
