#include <DallasTemperature.h>
#include <OneWire.h>
#include "DS18B20.h"
OneWire ds(14);
DallasTemperature sensors(&ds);

float getOutsideTemp(){
  sensors.requestTemperatures();
  float outsideTemp = sensors.getTempCByIndex(0);
  return (outsideTemp);
}
 
 /*if ((MSB & 0x80) == 0x80){//-------------------
  negative = true;
  MSB = ~MSB; //(MSB & 0x07);
  byte temp = LSB; 
  temp = ~temp; // This sections of code I added in order to enable reading negative temperatures.
  temp = (temp & 0xF0);
  LSB = LSB & 0x0F;// See the data sheet for the absolutely bizzare way the bytes of negative temps
  LSB = LSB | temp;//are sent, everything but the least significant nibble is inversed.
 }//--------------------------------------------
  tempRead = ((MSB << 8) | LSB); //using two's compliment
  TemperatureSum = tempRead / 16;
  if (negative)//-------------------------------
    TemperatureSum = -TemperatureSum;
 //---------------------------------------------
 return TemperatureSum;*/

