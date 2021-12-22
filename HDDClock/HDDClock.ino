#include <Servo.h>
#include "Color.h"
#include "StandardClock.h"
#include "ColorConfig.h"

const byte servoPin = 3;
Servo escServo;

const byte periodOffsetPin = A3;
const byte clockOffsetPin = A2;
const byte hallPin = 2;

volatile unsigned long previousMicros = 0;
volatile unsigned long period = 250000;

StandardClock standardClock;
ClockColorConfig* colorConfig = new ClockColorConfig(&standardClock);

void hall_ISR()
{
  period = micros() - previousMicros;
  previousMicros = micros();
}

void armESC()
{
  escServo.attach(servoPin);
  escServo.writeMicroseconds(1000);
  delay(2000);
}

void speedESC(int outputESC)
{
  int oESC = constrain(outputESC, 1000, 2000);
  escServo.writeMicroseconds(oESC);
}

void setup() {

  //Arm the ESC
  armESC();
  speedESC(1200);

  //Hall Effect Interrupt
  pinMode(hallPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(hallPin), hall_ISR, RISING);

  Color::setupHardware();
  pinMode(periodOffsetPin, INPUT);
  pinMode(clockOffsetPin, INPUT);
  
  Serial.begin(9600);
}

unsigned int colorCount = 0;
unsigned long lastUpdateTime = 0;
void loop() {

  unsigned int periodOffsetInt = 0;
  unsigned long periodOffset = 0;
  unsigned int clockOffsetInt = 0;
  unsigned long clockOffset = 0;
  
  if (millis() - lastUpdateTime > 1000)
  {
    periodOffsetInt = analogRead(periodOffsetPin);
    periodOffset = map(periodOffsetInt, 0, 1023, 0 , period);
    
    clockOffsetInt = analogRead(clockOffsetPin);
    clockOffset = map(clockOffsetPin, 0, 1023, 0, 12 * 60 * 60);
    
    standardClock.UpdateClock(clockOffset);
    
    lastUpdateTime = millis();
  }

  unsigned long currentPos = micros() - previousMicros + periodOffset;

  if (currentPos > period)
    currentPos = currentPos - ((int)(currentPos / (double) period)) * period;

  Color nextColor = colorConfig->getColorAt(currentPos);
  Color::updateColor(nextColor);
}
