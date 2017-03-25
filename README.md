# IoTWeatherStation
This is code for an ESP8266 Wemos-based IoT weather station developed using the Arduino IDE. It collects data from temperature, pressure, and humidity sensors, outputs them to a built-in LCD screen, and sends the data to ThingSpeak for data analysis and display. It also has a photoresistor voltage divider circiut in order to automatically turn off the backlight of the LCD screen in low-light conditions.

## Operation
Upon being powered on, the device connects to a wifi network and then directly enters the main loop which gets readings from the various sensors, displays them on the LCD screen, sends them to ThinkSpeak, and then enters a sub-loop which checks the voltage across the photoresistor every second for 60 seconds and then exits, restarting the main loop of the program. An interuptIn circiut using an op-amp to control the backlight would have been be a more elegant solution.

## Part list

* Wemos mini ESP8266 development board
* BMP180 Barometer breakout (communicating with I2C)
* DHT22 temperature and humidity sensor (communicating using single-wire interface)
* DS18B20 temperature probe (communicating via single-wire interface)
* Photoresistor and potentiometer with comparable resistance ranges
* 16x2 character parallel LCD screen with I2C controller

## Libraries used

* [LiquidCrystal_I2C](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) for the LCD screen
* [DHT sensor library](https://github.com/adafruit/DHT-sensor-library) for the DHT22 sensor
* SFE_BMP180 for the barometer
* OneWire for DHT and DS18B20 comms
* Dallas Temperature for the DS18B20
* ESP8266WiFi.h library included in ESP8266 Arduino IDE package

## Data viewer

If you are interested in the weather data inside my room and outside my window, you can view the live data [here](https://thingspeak.com/channels/214866)
