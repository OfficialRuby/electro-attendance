// Required Libraries

#include <Adafruit_Fingerprint.h>
#include <Adafruit_GFX.h>       
#include <Adafruit_ST7735.h> 
#include <SPI.h>
#include <SoftwareSerial.h>
// color definitions
const uint16_t  Black        = 0x0000;
const uint16_t  Blue         = 0x001F;
const uint16_t  Red          = 0xF800;
const uint16_t  Green        = 0x07E0;
const uint16_t  Cyan         = 0x07FF;
const uint16_t  Magenta      = 0xF81F;
const uint16_t  Yellow       = 0xFFE0;
const uint16_t  White        = 0xFFFF;


//Custom font
//#include <Fonts/FreeSans9pt7b.h>

//#include <Fonts/Oswald/regular/OswaldRegular7pt7b.h>
#include <Fonts/Oswald/regular/OswaldRegular12pt7b.h>
uint8_t id;
int userID = 0;

//ESP8266 Serial
SoftwareSerial mySerial;

//mySerial.begin(BAUD_RATE, SWSERIAL_8N1, D4, D6, false, 95, 11);/

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

// Program Setup

//finger.begin(BAUD_RATE);

#define TX_PIN 2
#define RX_PIN 12

//Macro definitions
//#define mySerial Serial1/
//Initialize fingerprint sensor
//Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);/
//Initialize display module
  #define TFT_CS        4 //D2
  #define TFT_RST        16// RST // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         5 // D1
//  #define TFT_MOSI 13 //D7 //MOSI/
//  #define TFT_SCLK 21/

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup()
{
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
    tft.println("      And");
    tft.println(" Ezeala Ogechi"); 
    delay(500);
  Serial.begin(57600);


  // set the data rate for the sensor serial port
  finger.begin(57600);
  delay(5);
  finger.getTemplateCount();
  tft.fillScreen(Blue);

//  if (finger.templateCount == 0) {
//    tft.setCursor(10,15);
//    tft.print(finger.templateCount);
//    tft.println("Device doesn't contain any fingerprint data.");
//    
//    tft.println("Please enroll a user");
//  }
//  else {
//    tft.println("Initializing Device");
//      tft.print("Sensor contains "); 
//      tft.print(finger.templateCount); 
//      Serial.print(finger.templateCount);
//      tft.println(" users");
//      delay(3000);
//      tft.fillScreen(White);
//  }
}

void loop()                     // run over and over again
{
  Serial.println("Loop Begins");
  tft.println("Loop Begins");
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
  
  delay(1000);            //don't ned to run this at full speed.
}


void getUser(void){
  userID = getFingerprintID();
  switch (userID){
    case 1:
    tft.setCursor(10, 40);
    tft.fillScreen(Blue);
    tft.println("User One");
    tft.println("Confidence: ");
    tft.println(finger.confidence);
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
