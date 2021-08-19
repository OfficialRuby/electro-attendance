#include <ESP8266WiFi.h> // Required library for WiFi connection
#include <ESP8266HTTPClient.h> // Required library for making http request
#include <ArduinoJson.h> // Library to parse JSON response

// Define the Wifi name and password 
const char* ssid = "LAB WLAN";
const char* passphase = "qwertyuiop";

// define the API key hostname 

const char* dateTime = "http://worldtimeapi.org/api/timezone/Africa/Lagos";
//const char* timeAPI = "https://script.google.com/macros/s/AKfycbyd5AcbAnWi2Yn0xhFRbyzS4qMq1VucMVgVvhul5XqS9HkAyJY/exec?tz=Africa/Lagos";

void setup() 
{
  // Start the serial monitor
  Serial.begin(115200);
  // Connect to a network
  WiFi.begin(ssid, passphase);
  Serial.print("Connecting to a network");
  // Check the the network connection status
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
//char region = "Africa/Lagos";

  Serial.print("Connected to ");
  Serial.print(ssid);
  Serial.print(" with the IP address :");
  Serial.println(WiFi.localIP());
}


void loop ()
{
  // Initialize the request object
  HTTPClient request;
  
// Make a http request
  request.begin(dateTime);
  delay(2000);

  // Check the request status code.
int  responseCode = request.GET(); //Get the api host response code.
  Serial.print("Response code is: ");
  Serial.println(responseCode);
  if (responseCode == 200); // If the server returned OK
  {
      String responseData = request.getString();
      Serial.println("Response from the server is:");
      Serial.println(responseData);
        // Deserialize the JSON response data
       StaticJsonDocument<715> result; // Declare data storage to stack
      
      //Check for error during data deserialization
      DeserializationError error = deserializeJson(result, responseData);
      
      if (error) 
      {
        Serial.print(F("Response deserialization failed with reason: "));
        Serial.println(error.f_str());
        return;
      }

      else
      {
//       const char* abbreviation = result["abbreviation"];  // Returns the current time zone abbreviation
//       const char* timezone = result["timezone"]; // Returns the current time zone 
       const char* datetime = result["datetime"]; // "2021-03-12T17:04:0
       
       char temp[strlen(datetime)+1];
       
        strcpy(temp, datetime);
        const char T = strchr(temp, 'T');
        T = 0;
           
                
//        Serial.print("Current time is ");
//        Serial.print(datetime);
//        Serial.print(" ");
//        Serial.print(abbreviation);
//        Serial.print(" "); 
//        Serial.println(timezone);
//        delay(2000);
      }
      
  }

}
