
/*
 *  ForbiddenBit.com
 *  
 *  NodeMCU and Display ST7735
 */

//  --------  Libraries required to use the Display  ---------------
#include <Adafruit_GFX.h>       
#include <Adafruit_ST7735.h> 
#include <SPI.h>

// -----------  Display pins  --------------------------------------
#define TFT_CS         15      
#define TFT_RST        0
#define TFT_DC         2

void setup() {
  
  Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST); //Those things are for the display
  tft.initR(INITR_GREENTAB);



 // --------  TEST TEXT  -------------------------------------------
   tft.fillScreen(ST77XX_BLACK);
  tft.setTextWrap(false);
  tft.setCursor(45, 5);    //Horiz/Vertic
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_YELLOW);
  tft.print("USA");

  tft.setCursor(15, 25);    //Horiz/Vertic
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  tft.print("COVID-19 Tracker");

  tft.setCursor(5, 45);    //Horiz/Vertic
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_BLUE);
  tft.print("Cases:");
  tft.setCursor(10, 65);
  tft.print("929,637");  

  tft.setCursor(5, 93);    //Horiz/Vertic
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_GREEN);
  tft.print("RECOVERED:");
  tft.setCursor(15, 115);
  tft.setTextColor(ST77XX_WHITE);
  tft.print("110,504"); 


  tft.fillRect(0, 138 , 48, 10, ST77XX_WHITE); 
  tft.setCursor(7, 140);    //Horiz/Vertic
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_BLACK);
  tft.print("DEATHS:  ");
  tft.setCursor(55, 140);
  tft.setTextColor(ST77XX_WHITE);
  tft.print("52,838");
} 

void loop() {
 
}
