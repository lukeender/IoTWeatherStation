#include <ESP8266WiFi.h>
#include <SFE_BMP180.h>
#include "DS18B20.h"
extern SFE_BMP180 sensor;
 
// replace with your channel’s thingspeak API key and your SSID and password
String apiKey = "RFBCQHJY18B1FEDS";
const char* ssid = "ZaneBridge";
const char* password = "Homestead4";
const char* server = "api.thingspeak.com";
WiFiClient client;
 
void wifisetup(){
WiFi.begin(ssid, password);
}
 
void thingspeak(float &outsideTemp, double &insideTemp, double &pressure, float &humidity){
if (client.connect(server,80)) {
String postStr = apiKey;
postStr +="&field1=";
postStr += String(humidity);
postStr +="&field2=";
postStr += String(outsideTemp);
postStr +="&field3=";
postStr += String(insideTemp);
postStr +="&field4=";
postStr += String(pressure);
postStr += "\r\n\r\n";
client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(postStr.length());
client.print("\n\n");
client.print(postStr);
}
client.stop();
}

