#include <Adafruit_GFX.h>       
#include <Adafruit_ST7735.h> 
#include <SPI.h>

// Display pin configuration
  #define TFT_CS         4
  #define TFT_RST        16                                            
  #define TFT_DC         5

    Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST); //Those things are for the display
  

  void setup(){
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
 

  }

  void loop(){
      
  }
