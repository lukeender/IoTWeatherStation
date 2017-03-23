#include "display_.h"
#include "DS18B20.h"


void updateDisplay(float &outsideTemp, double &insideTemp, double &pressure, float &humidity){
lcd.print("I:");
lcd.print(insideTemp,1);
lcd.print(" O:");
lcd.print(outsideTemp,1);
lcd.print(" ");
lcd.setCursor( 0, 1 );
lcd.print("P:");
lcd.print(pressure,1);
lcd.print(" H:");
lcd.print(humidity,1);
lcd.home();
}

