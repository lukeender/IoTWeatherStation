#ifndef DISPLAY_H
  #define DISPLAY_H
#include <SFE_BMP180.h>
#include <LiquidCrystal_I2C.h>
extern SFE_BMP180 BMP180;
extern LiquidCrystal_I2C lcd;
void updateDisplay(float &outsideTemp, double &insideTemp, double &pressure, float &humidity);
#endif
