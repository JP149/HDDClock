#ifndef Color_h
#define Color_h

#include "Arduino.h"

class Color
{
  public:
    Color();
    Color(bool R, bool G, bool B);

    const bool R, G, B;

    String toString();

    static const byte Red_Pin, Green_Pin, Blue_Pin;
    static const Color Red,
           Green,
           Blue,
           White,
           Black,
           RG_Yellow,
           RB_Purple,
           GB_Cyan;

    static void setupHardware();
    static void updateColor(Color col);
    static void updateColor(const byte r, const byte g, const byte b);
};

#endif
