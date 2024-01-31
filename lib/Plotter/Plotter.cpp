#include <Plotter.h>

Plotter::Plotter(Pin XAxisClockPin,
                 Pin XAxisCounterClockPin,
                 Pin YAxisClockPin,
                 Pin YAxisCounterClockPin,
                 Pin modulateYAxisPin,
                 Pin modulateXAxisPin,
                 int XDirectionChangeDelayMs,
                 int YDirectionChangeDelayMs) : XAxisClockPin(XAxisClockPin),
                                                XAxisCounterClockPin(XAxisCounterClockPin),
                                                YAxisClockPin(YAxisClockPin),
                                                YAxisCounterClockPin(YAxisCounterClockPin),
                                                modulateYAxisPin(modulateYAxisPin),
                                                modulateXAxisPin(modulateXAxisPin),
                                                XDirectionChangeDelayMs(XDirectionChangeDelayMs),
                                                YDirectionChangeDelayMs(YDirectionChangeDelayMs)
{
  XAxisClockPin.useAsOutput();
  XAxisCounterClockPin.useAsOutput();
  YAxisClockPin.useAsOutput();
  YAxisCounterClockPin.useAsOutput();
  modulateYAxisPin.useAsOutput();
  modulateXAxisPin.useAsOutput();
}

void Plotter::stop()
{
  this->stopX();
  this->stopY();
}

void Plotter::stopX()
{
  this->stopXClock();
  this->stopXCounterClock();
}

void Plotter::stopY()
{
  this->stopYClock();
  this->stopYCounterClock();
}

void Plotter::stopXClock()
{
  this->XAxisClockPin.writeLow();
  this->XAxisDirection = 0;
}

void Plotter::stopYClock()
{
  this->YAxisClockPin.writeLow();
  this->YAxisDirection = 0;
}

void Plotter::stopXCounterClock()
{
  this->XAxisCounterClockPin.writeLow();
  this->XAxisDirection = 0;
}

void Plotter::stopYCounterClock()
{
  this->YAxisCounterClockPin.writeLow();
  this->YAxisDirection = 0;
}

void Plotter::moveXClock()
{
  report("move x -");
  const bool changingDirection = this->XAxisDirection == 1;
  if (changingDirection)
  {
    report("X dir change");
    this->stopXCounterClock();
    delay(this->XDirectionChangeDelayMs);
  }

  this->XAxisClockPin.writeHigh();
  this->XAxisDirection = -1;
}

void Plotter::moveYClock()
{
  report("move y -");
  const bool changingDirection = this->YAxisDirection == 1;
  if (changingDirection)
  {
    report("Y dir change");
    this->stopYCounterClock();
    delay(this->YDirectionChangeDelayMs);
  }

  this->YAxisClockPin.writeHigh();
  this->YAxisDirection = -1;
}

void Plotter::moveXCounterClock()
{
  report("move x +");
  const bool changingDirection = this->XAxisDirection == -1;
  if (changingDirection)
  {
    report("X dir change");
    this->stopXClock();
    delay(this->XDirectionChangeDelayMs);
  }

  this->XAxisCounterClockPin.writeHigh();
  this->XAxisDirection = 1;
}

void Plotter::moveYCounterClock()
{
  report("move y +");
  const bool changingDirection = this->YAxisDirection == -1;
  if (changingDirection)
  {
    report("Y dir change");
    this->stopYClock();
    delay(this->YDirectionChangeDelayMs);
  }

  this->YAxisCounterClockPin.writeHigh();
  this->YAxisDirection = 1;
}

void Plotter::setXSpeed(float relativeValue)
{
  this->modulateXAxisPin.modulate(relativeValue);
}

void Plotter::setYSpeed(float relativeValue)
{
  this->modulateYAxisPin.modulate(relativeValue);
}