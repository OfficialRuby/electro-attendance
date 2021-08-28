#include <SD.h>
// Libraries for SD card
//#include "FS.h"/
//#include "SD.h"
#include <SPI.h>
// Libraries to get time from NTP Server
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define SD_CS  D8
void setup(){
  
Serial.println("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("ERROR - SD card initialization failed!");
    return;    // init failed
  }

  // If the data.txt file doesn't exist
  // Create a file on the SD card and write the data labels
  File attendance = SD.open("/attendance.csv");
  if(!attendance) {
    Serial.println("File doens't exist");
    Serial.println("Creating file...");
    writeFile(SD, "/attendance.csv", " ID, Fullname, Date, Time \r\n");
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
  return dateStamp

}
void loop(){
  
}
// Append data to the SD card (DON'T MODIFY THIS FUNCTION)
void appendFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Appending to file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if(!file) {
    Serial.println("Failed to open file for appending");
    return;
  }
  if(file.print(message)) {
    Serial.println("Message appended");
  } else {
    Serial.println("Append failed");
  }
  file.close();
}

void logData() {
  String dataMessage = String(ID) + "," + String(fullname) + "," + String(dateStamp) + "," + 
                String(timeStamp) + "\r\n";
  Serial.print("Save data: ");
  Serial.println(dataMessage);
  appendFile(SD, "/attendance.csv", dataMessage.c_str());
}



// Write to the SD card (DON'T MODIFY THIS FUNCTION)
void writeFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if(!file) {
    Serial.println("Failed to open file for writing");
    return;
  }
  if(file.print(message)) {
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
  file.close();
}







