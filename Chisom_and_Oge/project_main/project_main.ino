#include <SD.h>

// import the connectivity libraries
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
// import file storage libraries
#include <SPI.h>
#include "FS.h"

// import required UART library
#include <SoftwareSerial.h>


 
SoftwareSerial swSer;

void setup() {
  Serial.begin(115200);
  swSer.begin(115200, SWSERIAL_8N1, D5, D6, false, 95, 11);



void setup()
{
  
}


void loop()
{
  
}
