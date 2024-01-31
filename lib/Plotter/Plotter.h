#pragma once

#include <Pin.h>
#include <Report.h>

class Plotter
{
private:
  Pin XAxisClockPin;
  Pin XAxisCounterClockPin;
  Pin YAxisClockPin;
  Pin YAxisCounterClockPin;
  Pin modulateYAxisPin;
  Pin modulateXAxisPin;
  /*
  0 - No
  -1 - Clockwise
  1 - Counterclockwise
  */
  char XAxisDirection = 0;
  char YAxisDirection = 0;
  int XDirectionChangeDelayMs = 50;
  int YDirectionChangeDelayMs = 0;

public:
  Plotter(Pin XAxisClockPin,
          Pin XAxisCounterClockPin,
          Pin YAxisClockPin,
          Pin YAxisCounterClockPin,
          Pin modulateYAxisPin,
          Pin modulateXAxisPin,
          int XDirectionChangeDelayMs = 50,
          int YDirectionChangeDelayMs = 20);

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