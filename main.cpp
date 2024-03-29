 
 #include <SPI.h>  
 #include <Wire.h>  
 #include <Adafruit_GFX.h>  
 #include <Adafruit_SSD1306.h>  
 #include <SimpleDHT.h>  
#include "SevSeg.h"
// using React app to d

 #define I2C_SEGMENT_DISP0 7
 #define DHT_READ_TIME 1000
SevSeg sevseg;
 byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true;
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);



 //   for DHT11,   
 //   VCC: 5V or 3V  
 //   GND: GND  
 //   DATA: 2  
 int pinDHT11 = 3;  
 SimpleDHT11 dht11(pinDHT11);  

 void setup ()  
 {  
     Serial.begin(9600);
   Serial.println("TEMPERATURE AND HUMIDITY");
    pinMode(I2C_SEGMENT_DISP0, OUTPUT);
    digitalWrite(I2C_SEGMENT_DISP0, LOW);

 }  
 void loop ()  
 {  
  byte temperature = 0;  
  byte humidity = 0;  
  int err = SimpleDHTErrSuccess;  
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {  
   Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);  
   return;  
  }  
  Serial.print((int)temperature); Serial.print(" *C, ");   
  Serial.print((int)humidity); Serial.println(" H");  
  // DHT11 sampling rate is 1HZ.  
 sevseg.setNumber(4999, 3);
    sevseg.refreshDisplay();
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
   Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
   return;
  }
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" H");
  // DHT11 sampling rate is 1HZ.
  delay(DHT_READ_TIME);
 }  
