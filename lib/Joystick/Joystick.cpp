#include <Joystick.h>

float Joystick::normalizeValue(int value)
{
  const float centeredValue = value - this->neutralRelativeVoltage;
  const float normalizedValue = centeredValue / this->neutralRelativeVoltage;
  if (abs(normalizedValue) < this->minAbsValue)
    return 0.0;
  return normalizedValue;
}

Joystick::Joystick(Pin tiltXPin, Pin tiltYPin,
                   Pin pressPin,
                   int neutralRelativeVoltage,
                   float minAbsValue) : tiltXPin(tiltXPin),
                                        tiltYPin(tiltYPin),
                                        pressPin(pressPin),
                                        neutralRelativeVoltage(neutralRelativeVoltage),
                                        minAbsValue(minAbsValue)
{
  tiltXPin.useAsInput();
  tiltYPin.useAsInput();
  pressPin.useAsInput();
  pressPin.writeHigh();
}

float Joystick::getTiltX()
{
  if (!this->enabled)
    return 0;
  const int voltage = this->tiltXPin.readAnalog();
  const float normalizedValue = this->normalizeValue(voltage);
  return normalizedValue;
}

float Joystick::getTiltY()
{
  if (!this->enabled)
    return 0;
  const int voltage = this->tiltYPin.readAnalog();
  const float normalizedValue = this->normalizeValue(voltage);
  return normalizedValue;
}

bool Joystick::getPressedState()
{
  const int value = this->pressPin.readDigital();
  return value == 0;
}