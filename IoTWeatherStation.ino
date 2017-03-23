#include <Wire.h>
#include <SFE_BMP180.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include "wifi.h"
#include "display_.h"
#include "DS18B20.h"


LiquidCrystal_I2C  lcd(0x27,16,2);
SFE_BMP180 BMP180;
DHT dht(D3, DHT22);
float outsideTemp = 0;
double insideTemp = 0;
double pressure = 0;
float humidity = 0;
int counter = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  BMP180.begin();
  dht.begin();
  lcd.begin();
  lcd.home();
  lcd.print("Connecting...");
  wifisetup();
  lcd.clear();
  lcd.print("Connected!");
  lcd.home();
  getdata();
  delay(200);
}

void loop() {
  getdata();
  updateDisplay(outsideTemp,insideTemp,pressure,humidity);
  thingspeak(outsideTemp,insideTemp,pressure,humidity);
    counter = 0;
    while (counter < 60){
      if (analogRead(A0) > 1000){
        lcd.noBacklight();
      }
      else
      {
        lcd.backlight();
      }
      delay(1000);
      counter++;
    }
    
}


void getdata(){
  BMP180.startTemperature();
  delay(100);
  BMP180.getTemperature(insideTemp);
  delay(100);
  BMP180.startPressure(0);
  delay(100);
  BMP180.getPressure(pressure,insideTemp);
  outsideTemp = getOutsideTemp();
  insideTemp = dht.readTemperature();
  humidity = dht.readHumidity();
}

