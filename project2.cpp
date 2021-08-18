// Program libraries
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

#define TX_Pin (14) //D5
#define RX_Pin (12) //D6
#define BAUD_RATE 57600

// Head section

String username;
SoftwareSerial mySerial;

mySerial.begin(BAUD_RATE, SWSERIAL_8N1, D5, D6, false, 95, 11);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);




// Program Setup

finger.begin(BAUD_RATE);

// If fingerprint sensor is connected.
  if (finger.verifyPassword()) {
    Serial.println("Finger print sensor connected");
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





//Program loop
currentFinger = finger.getImage();
if (currentFinger == FINGERPRINT_OK){ // Only triggers if there is a valid fingerprint on the sensor
    Serial.println("Valid fingerprint detected");
    
}
else {
    Serial.print("Place finger to scan")
}


//Program loop Ends

// Function to get the corresponding user with a specific ID 

String getUsername(){
    userID = getFingerprintID();
    switch (userID){
        case 1:
        String username = "User One";
        break;
        case 2:
        String username = "User Two";
        break;
        case 3:
        String username = "User Three";
        break;
        case 4:
        String username = "User Four";
        break;
        case 5:
        String username = "User Five";
        break;
        case 6:
        String username = "User Six";
        break;
        default:
        String username = "";  // This condition may not be true
    return username


    }
}





//Function to get the current user ID

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
    /*Get current finger ID
    Prepare the fingerprint for comparision
    Ask the sensor to convert image to feature template.*/

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

  // Will execute search if sensor converted image to feature template.
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