#pragma once

#include <Pin.h>

class Plotter
{
private:
  Pin XAxisClockPin;
  Pin XAxisCounterClockPin;
  Pin YAxisClockPin;
  Pin YAxisCounterClockPin;
  Pin modulateYAxisPin;
  Pin modulateXAxisPin;

public:
  Plotter(Pin XAxisClockPin,
          Pin XAxisCounterClockPin,
          Pin YAxisClockPin,
          Pin YAxisCounterClockPin,
          Pin modulateYAxisPin,
          Pin modulateXAxisPin);

  void stop();

  void stopX();

  void stopY();

  void stopXClock();

  void stopYClock();

  void stopXCounterClock();

  void stopYCounterClock();

  void moveXClock();

  void moveYClock();

  void moveXCounterClock();

  void moveYCounterClock();

  void setXSpeed(float relativeValue);

  void setYSpeed(float relativeValue);
};