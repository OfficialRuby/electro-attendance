// Required Libraries
#include <Adafruit_ST7735.h> 
#include <Adafruit_Fingerprint.h>
#include <Adafruit_GFX.h>       
#include <SPI.h>
#include <SoftwareSerial.h>


//Custom font
//#include <Fonts/FreeSans9pt7b.h>
//#include <Fonts/Oswald/regular/OswaldRegular7pt7b.h>
#include <Fonts/Oswald/regular/OswaldRegular12pt7b.h>
// Libraries for SD card
#include <SD.h>
// Libraries to get time from NTP Server
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
String formattedDate, dayStamp, ID,dateStamp,fullname,timeStamp,dataMessage;
#define SD_CS  15
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP,"pool.ntp.org");
// Network connections
const char *ssid     = "LAB WLAN";
const char *password = "qwertyuiop";
// color definitions
const uint16_t  Black        = 0x0000;
const uint16_t  Blue         = 0x001F;
const uint16_t  Red          = 0xF800;
const uint16_t  Green        = 0x07E0;
const uint16_t  Cyan         = 0x07FF;
const uint16_t  Magenta      = 0xF81F;
const uint16_t  Yellow       = 0xFFE0;
const uint16_t  White        = 0xFFFF;


uint8_t id;
uint8_t userID;

//ESP8266 Serial
SoftwareSerial mySerial;


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);


// Display pin configuration
#define TFT_CS         4
#define TFT_RST        16                                            
#define TFT_DC         5
#define TFT_MOSI       13
#define TFT_SCLK       14


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

#define  TX_PIN   2
#define  RX_PIN   0




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




void setup()
{
  Serial.begin(9600);
  mySerial.begin(57600, SWSERIAL_8N1, TX_PIN, RX_PIN, false, 95, 11);
  finger.begin(57600);
    
//  Setup display
  tft.initR(INITR_GREENTAB);
  tft.fillScreen(Blue);
  tft.setFont(&OswaldRegular12pt7b);
  tft.setTextSize(1);
  tft.setTextColor(White);
  tft.setCursor(15,20);
  tft.println("Project by");
  tft.println("Nweke Chisom");
  tft.println("       And");
  tft.println(" Ezeala Ogechi"); 
  delay(500);
  
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
  

void loop()                     // run over and over again
{
  Serial.println("Loop Begins");
  tft.fillScreen(Black);
  
  uint8_t p = finger.getImage();
  if (p == FINGERPRINT_OK){  // Fingerprint is placed on device
    tft.setFont(&OswaldRegular12pt7b);
    getUser();
    tft.fillScreen(Blue);
    
    
  }
  else{
//    tft.drawBitmap(0, 0, Fingerprint, 128, 64, Green);
    tft.setFont(&OswaldRegular12pt7b);
    tft.setTextSize(1);
    tft.setCursor(10,30);
    tft.println("Please place");
    tft.println(" your finger on");
    tft.println("  the scanner");
    
  }
  

}


void getUser(void){
  userID = getFingerprintID();
  switch (userID){
    case 1:
    tft.setCursor(10, 40);
    tft.fillScreen(Blue);
    fullname = "User One";
    tft.println(fullname);
    tft.println("Confidence: ");
    tft.println(finger.confidence);
    ID = userID;
    dateStamp = fetchDate();
    timeStamp = fetchTime();
    
    dataMessage = String(ID) + "," + String(fullname) + "," + String(dateStamp) + "," + String(timeStamp) + "\r\n"; 
    writeFile( "/attendance.csv", dataMessage.c_str());
     delay(3000);
    break;
    case 2:
    tft.setCursor(10, 40);
    tft.fillScreen(Blue);
    tft.println("User Two");
    tft.println("Confidence: ");
    tft.println(finger.confidence);
    delay(3000);
    break;
    case 3:
    tft.setCursor(10, 40);
    tft.fillScreen(Blue);
    tft.println("User Three");
    tft.println("Confidence: ");
    tft.println(finger.confidence);
    delay(3000);
    break;
    case 4:
    tft.setCursor(10, 40);
    tft.fillScreen(Blue);
    tft.println("User Four");
    tft.println("  Confidence: ");
    tft.setCursor(50,110);
    tft.println(finger.confidence);
      delay(3000);
    break;
    case 5:
    tft.setCursor(10, 40);
    tft.fillScreen(Blue);
    tft.println("User Five");
    tft.println("Confidence: ");
    tft.println(finger.confidence);
    delay(3000);
    break;
    case 6:
    tft.setCursor(10, 40);
    tft.println("Hello Armani 2");
    tft.println("Confidence: ");
    tft.println(finger.confidence);
    delay(3000);
    break;
    case 7:
    tft.setCursor(10, 40);
    tft.println("Hello Armani 1");
    tft.println("Confidence: ");
    tft.setCursor(40,90);
    tft.println(finger.confidence);
    delay(3000);
    break;
    default:
    tft.println("Unkwon User");
    delay(3000);
    break;
  }

}



uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      tft.println("Remove your finger");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      tft.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}




void logData() {
  String dataMessage = String(ID) + "," + String(fullname) + "," + String(dateStamp) + "," + String(timeStamp) + "\r\n";               
  Serial.print("Save data: ");
  Serial.println(dataMessage);
  writeFile( "/attendance.csv", dataMessage.c_str());
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
