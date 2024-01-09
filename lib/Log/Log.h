#pragma once

#include <Arduino.h>

template <typename SerialMessage>
inline void log(SerialMessage message, bool omitNewLine = false)
{
  if (!omitNewLine)
    Serial.print("\n");
  Serial.print(message);
}

inline void logEmptyLine()
{
  Serial.print("\n");
}

inline void initLog(unsigned long baudRate = 9600)
{
  Serial.begin(baudRate);
}