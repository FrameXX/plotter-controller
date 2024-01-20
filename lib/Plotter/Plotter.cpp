#include <Plotter.h>

Plotter::Plotter(Pin XAxisClockPin,
                 Pin XAxisCounterClockPin,
                 Pin YAxisClockPin,
                 Pin YAxisCounterClockPin,
                 Pin modulateYAxisPin,
                 Pin modulateXAxisPin) : XAxisClockPin(XAxisClockPin),
                                         XAxisCounterClockPin(XAxisCounterClockPin),
                                         YAxisClockPin(YAxisClockPin),
                                         YAxisCounterClockPin(YAxisCounterClockPin),
                                         modulateYAxisPin(modulateYAxisPin),
                                         modulateXAxisPin(modulateXAxisPin)
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
}

void Plotter::stopYClock()
{
  this->YAxisClockPin.writeLow();
}

void Plotter::stopXCounterClock()
{
  this->XAxisCounterClockPin.writeLow();
}

void Plotter::stopYCounterClock()
{
  this->YAxisCounterClockPin.writeLow();
}

void Plotter::moveXClock()
{
  this->stopXCounterClock();
  this->XAxisClockPin.writeHigh();
}

void Plotter::moveYClock()
{
  this->stopYCounterClock();
  this->YAxisClockPin.writeHigh();
}

void Plotter::moveXCounterClock()
{
  this->stopXClock();
  this->XAxisCounterClockPin.writeHigh();
}

void Plotter::moveYCounterClock()
{
  this->stopYClock();
  this->YAxisCounterClockPin.writeHigh();
}

void Plotter::setXSpeed(float relativeValue)
{
  this->modulateXAxisPin.modulate(relativeValue);
}

void Plotter::setYSpeed(float relativeValue)
{
  this->modulateYAxisPin.modulate(relativeValue);
}