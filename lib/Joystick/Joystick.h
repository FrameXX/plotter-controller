#pragma once

#include <Pin.h>

class Joystick
{
private:
  Pin tiltXPin;
  Pin tiltYPin;
  Pin pressPin;
  float minAbsValue;
  int neutralRelativeVoltage;

  float normalizeValue(int value);

public:
  bool enabled = true;

  Joystick(Pin tiltXPin,
           Pin tiltYPin,
           Pin pressPin,
           int neutralRelativeVoltage = 525,
           float minAbsValue = 0.05);

  float getTiltX();

  float getTiltY();

  bool getPressedState();
};