#include <Arduino.h>
#include <Pin.h>
#include <Joystick.h>
#include <Plotter.h>

Pin joystickTiltXPin(A0);
Pin joystickTiltYPin(A1);
Pin joystickPressPin(2);

Pin XAxisClockPin(13);
Pin XAxisCounterClockPin(12);
Pin YAxisClockPin(10);
Pin YAxisCounterClockPin(9);
Pin modulateYAxisPin(6);
Pin modulateXAxisPin(5);

Joystick joystick(joystickTiltXPin,
                  joystickTiltYPin,
                  joystickPressPin);
Plotter plotter(XAxisClockPin,
                XAxisCounterClockPin,
                YAxisClockPin,
                YAxisCounterClockPin,
                modulateYAxisPin,
                modulateXAxisPin);

bool joystickLastPressedState = false;

void toggleJoystickEnabled()
{
  joystick.enabled = !joystick.enabled;
  if (!joystick.enabled)
    plotter.stop();
}

void updateJoistickEnabledState()
{
  const bool joystickPressedState = joystick.getPressedState();
  if (joystickLastPressedState != joystickPressedState && joystickPressedState)
    toggleJoystickEnabled();
  joystickLastPressedState = joystickPressedState;
}

void controlPlotterMotors()
{
  const float tiltX = joystick.getTiltX();
  const float tiltY = joystick.getTiltY();

  if (tiltX < 0)
    plotter.moveXClock();

  if (tiltX > 0)
    plotter.moveXCounterClock();

  if (tiltX == 0)
    plotter.stopX();

  plotter.setXSpeed(abs(tiltX));

  if (tiltY < 0)
    plotter.moveYClock();

  if (tiltY > 0)
    plotter.moveYCounterClock();

  if (tiltY == 0)
    plotter.stopY();

  plotter.setYSpeed(abs(tiltY));
}

void setup()
{
}

void loop()
{
  updateJoistickEnabledState();
  controlPlotterMotors();
}