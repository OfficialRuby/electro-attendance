// Required Libraries
#include <Adafruit_ST7735.h> 
#include <Adafruit_Fingerprint.h>
#include <Adafruit_GFX.h>       
#include <SPI.h>
#include <SoftwareSerial.h>

// Libraries for SD card
#include <SdFat.h>
SdFat sd;
SdFile attendance;

//Custom font
#include <Fonts/Oswald/regular/OswaldRegular12pt7b.h>


char  timeStamp;
char fullname;
#define SD_CS  4


// color definitions
//const uint16_t  Black        = 0x0000;
const uint16_t  Blue         = 0x001F;
//const uint16_t  Red          = 0xF800;
//const uint16_t  Green        = 0x07E0;
//const uint16_t  Cyan         = 0x07FF;
//const uint16_t  Magenta      = 0xF81F;
//const uint16_t  Yellow       = 0xFFE0;
const uint16_t  White        = 0xFFFF;


uint8_t id;
uint8_t userID;
#define  TX_PIN   3
#define  RX_PIN   2

SoftwareSerial mySerial(TX_PIN,RX_PIN);


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);


// Display pin configuration
#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8
#define TFT_MOSI       11
#define TFT_SCLK       13


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void writeFile( const char * message) {
  Serial.println("Writing file to SD");

  if(attendance.open("/logs.csv", O_CREAT)) {
    attendance.println(message);
     Serial.println("File logged");
  }
  else {
    Serial.println("Write failed");
  }
  attendance.close();
}

void logFile( const char * message) {
  Serial.println("Writing file to SD");

  if(attendance.open("/logs.csv", O_WRITE)) {
      attendance.println(message);
     Serial.println("File logged");
  }
  else {
    Serial.println("Write failed");
  }
  attendance.close();
}



void setup()
{
  Serial.begin(9600);
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

  Serial.println("Initializing SD card...");
  if (!sd.begin(SD_CS, SPI_HALF_SPEED)){
        Serial.println("ERROR - SD card initialization failed!");
    return;    // init failed 
  }
  
  // Create a file on the SD card and write the data labels
  if (!attendance.open("/attendance.csv", O_READ)) {
    Serial.println(F("File doens't exist"));
    Serial.println(F("Creating file..."));
    writeFile("\tID, \tFullname, \tTime \r\n");
    Serial.println(F("File Created"));
  }

  else {
    Serial.println(F("File already exists"));  
  }
  attendance.close();
}

void loop(){
  // DO NOTHING
}

void looop()                     // run over and over again
{

  
  uint8_t p = finger.getImage();
    Serial.println(p);
  if (p == 2){  // Fingerprint is placed on device
    getUser();
    tft.fillScreen(Blue);
    
    
  }
  else{
//    tft.drawBitmap(0, 0, Fingerprint, 128, 64, Green);
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
    fullname = "User      Onee";
    tft.println(fullname);
    tft.println("Confidence: ");
    tft.println(finger.confidence);
    timeStamp = getUpTime();
    
    String dataMessage = uint8_t(userID) + ',' + char(fullname) + ',' + char(timeStamp) + "\r\n"; 
    writeFile( dataMessage.c_str());
     delay(3000);
    break;
    case 2:
    tft.setCursor(10, 40);
    tft.fillScreen(Blue);
    tft.println("User       Two");
    tft.println("Confidence: ");
    tft.println(finger.confidence);
    delay(3000);
    break;
    default:
    tft.println("Unknown User");
    delay(3000);
    break;
  }

}



uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
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




char getUpTime() {

    // calculate seconds, truncated to the nearest whole second
    unsigned long upSeconds = millis() / 1000;

    // calculate days, truncated to nearest whole day
    unsigned long days = upSeconds / 86400;

    // the remaining hhmmss are
    upSeconds = upSeconds % 86400;

    // calculate hours, truncated to the nearest whole hour
    unsigned long hours = upSeconds / 3600;

    // the remaining mmss are
    upSeconds = upSeconds % 3600;

    // calculate minutes, truncated to the nearest whole minute
    unsigned long minutes = upSeconds / 60;

    // the remaining ss are
    upSeconds = upSeconds % 60;
    
    // construct the string representation
    String upTime = String (hours) + ":" + String(minutes)+ ":" +String(upSeconds);
    return upTime.c_str();
          
}
