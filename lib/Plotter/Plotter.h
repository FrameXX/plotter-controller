#pragma once

#include <Pin.h>
#include <Report.h>
#include <Amplify.h>

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
  int XAxisDirection = 0;
  int YAxisDirection = 0;
  int XDirectionChangeDelayMs;
  int YDirectionChangeDelayMs;
  int XModulationStart = 95;
  int YModulationStart = 85;
  int XModulationAmplifyExponent = 2;
  int YModulationAmplifyExponent = 2;

public:
  Plotter(Pin XAxisClockPin,
          Pin XAxisCounterClockPin,
          Pin YAxisClockPin,
          Pin YAxisCounterClockPin,
          Pin modulateYAxisPin,
          Pin modulateXAxisPin,
          int XDirectionChangeDelayMs = 20,
          int YDirectionChangeDelayMs = 100,
          int XModulationStart = 95,
          int YModulationStart = 85,
          int XModulationAmplifyExponent = 2,
          int YModulationAmplifyExponent = 2);

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

  void setXSpeed(int relativeValue);

  void setYSpeed(int relativeValue);
};