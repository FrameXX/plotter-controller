#include <Pin.h>
#include <Arduino.h>

Pin::Pin(uint8_t target) : target(target) {}

void Pin::useAsOutput()
{
  pinMode(this->target, OUTPUT);
}

void Pin::useAsInput()
{
  pinMode(this->target, INPUT);
}

void Pin::changeTarget(uint8_t target)
{
  this->target = target;
}

void Pin::writeHigh()
{
  digitalWrite(this->target, HIGH);
}

void Pin::writeLow()
{
  digitalWrite(this->target, LOW);
}

int Pin::readAnalog()
{
  return analogRead(this->target);
}

int Pin::readDigital()
{
  return digitalRead(this->target);
}

void Pin::modulate(float dutyFactor)
{
  analogWrite(this->target, dutyFactor * 255);
}