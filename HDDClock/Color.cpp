#include "Color.h"
#include "Arduino.h"

const byte Color::Red_Pin = 9;
const byte Color::Green_Pin = 10;
const byte Color::Blue_Pin = 11;

const Color Color::Red(true, false, false);
const Color Color::Green( false, true, false);
const Color Color::Blue(false, false, true);
const Color Color::White(true, true, true);
const Color Color::Black(false, false, false);
const Color Color::RG_Yellow(true, true, false);
const Color Color::RB_Purple(true, false, true);
const Color Color::GB_Cyan(false, true, true);

Color::Color():
  R(true), G(true), B(true) {}
  
void Color::setupHardware()
{
  pinMode(Color::Red_Pin, OUTPUT);
  pinMode(Color::Green_Pin, OUTPUT);
  pinMode(Color::Blue_Pin, OUTPUT);
}

void Color::updateColor(Color col)
{
  digitalWrite(Red_Pin, col.R ? HIGH : LOW);
  digitalWrite(Green_Pin, col.G ? HIGH : LOW);
  digitalWrite(Blue_Pin, col.B ? HIGH : LOW);
}

void Color::updateColor(const byte r, const byte g, const byte b)
{

  analogWrite(Red_Pin, constrain(r, 0, 255));
  analogWrite(Green_Pin, constrain(g, 0, 255));
  analogWrite(Blue_Pin, constrain(b, 0, 255));
}

Color::Color(bool _r, bool _g, bool _b):
  R(_r), G(_g), B(_b) {}
