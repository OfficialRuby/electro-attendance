// Libraries for SD card
#include <FS.h>
#include <SD.h>
#include <SPI.h>
// Libraries to get time from NTP Server
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
String formattedDate, dayStamp, ID,dateStamp,fullname,timeStamp;
#define SD_CS  D8
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP,"pool.ntp.org");

const char *ssid     = "LAB WLAN";
const char *password = "qwertyuiop";


void setup(){
     // Connect to Wi-Fi
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }


    timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(3600);
  
Serial.println("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("ERROR - SD card initialization failed!");
    return;    // init failed
  }


  // Create a file on the SD card and write the data labels
  File attendance = SD.open("/attendance.csv");
  if(!attendance) {
    Serial.println("File doens't exist");
    Serial.println("Creating file...");
    writeFile( "/attendance.csv", " ID, Fullname, Date, Time \r\n");
  }
  else {
    Serial.println("File already exists");  
  }
  attendance.close();
}



  String fetchTime() {
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }

  String formattedTime = timeClient.getFormattedTime();
  return formattedTime;
}

String fetchDate() {
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }
  formattedDate = timeClient.getFormattedDate();
  Serial.println(formattedDate);

  // Extract date
  int splitT = formattedDate.indexOf("T");
  String dateStamp = formattedDate.substring(0, splitT);
  Serial.println(dayStamp);
  return dateStamp;

}
void loop(){
  
}



void logData() {
  String dataMessage = String(ID) + "," + String(fullname) + "," + String(dateStamp) + "," + 
                String(timeStamp) + "\r\n";
  Serial.print("Save data: ");
  Serial.println(dataMessage);
  writeFile( "/attendance.csv", dataMessage.c_str());
}




// Write to the SD card (DON'T MODIFY THIS FUNCTION)
void writeFile(const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);

  File file = SD.open(path, FILE_WRITE);
  if(file) {
    Serial.println("File logged");
    file.println(message);
  }
  else {
    Serial.println("Write failed");
  }
  file.close();
}
