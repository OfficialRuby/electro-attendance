// Program libraries
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

#define TX_Pin (14) //D5
#define RX_Pin (12) //D6
#define BAUD_RATE 57600


SoftwareSerial mySerial;

mySerial.begin(BAUD_RATE, SWSERIAL_8N1, D5, D6, false, 95, 11);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);




// Program Setup

finger.begin(BAUD_RATE);




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
      Serial.println("Unknown error");
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
      Serial.println("Unknown error");
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







// If fingerprint sensor is connected.
  if (finger.verifyPassword()) {
    Serial.println("Finger prnt sensor connected");
  } else {
    Serial.println("Can not detect the fingerprint sensor");
  }
// Get the numbers of people enrolled
 finger.getTemplateCount();
  if (finger.templateCount == 0) {
    Serial.print("Fingerprint databases contains no data");
    Serial.println("Please enroll a user");
  }
    else {
    Serial.println("Waiting for valid finger...");
    }



//Function to create file
void createFile(fs::FS &fs, const char* filePath, const char* dataLogged){
    File data = fs.open(filePath, FILE_WRITE);
    if(!data){
        Serial.println("File creation failed")
    }
}


// Function to Append to existing fil
void appendToFile(fs::FS &fs, const char* filePath, const char* dataLogged){
    File data = fs.open(filePath, FILE_APPEND);
    if (!data){
        Serial.println("Writing to file failed")
    }
}

// Function to get datetime
void getDateTime(){

    timeClient.update();
    if(!timeClient.update(){
        timeClient.forceUpdate();
    })
    dateTime = timeClient.getFormattedDate();
}

// Function to log data to SD card
void logData(String userInfo, filePath){
    File attendance = SD.open(filePath);
    if (!attendance){ // If the attendance file is not available, create one
    Serial.println("The attendance file doesn\'t exist")
    createFile(SD, filePath userInfo);
    } 
    else{
        appendToFile(SD, filePath, userInfo);
    }
}