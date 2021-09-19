//biblioteca responsável pela comunicação com o Cartão SD
#include <SD.h>
#include <Adafruit_GFX.h>       
#include <Adafruit_ST7735.h> 
#include <SPI.h>
//biblioteca responsável pela comunicação com o sensor DHT22

//pino ligado ao CS do módulo SD Card
#define CS_PIN  D8
// Display pin configuration
  #define TFT_CS         4
  #define TFT_RST        16                                            
  #define TFT_DC         5
  #define TFT_MOSI       13
  #define TFT_SCLK       14
  

    Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
  


void setup()
{
  
  Serial.begin(9600);
  Serial.print("Initializing SD Card...");
  tft.initR(INITR_GREENTAB);
    tft.fillScreen(ST77XX_BLACK);
//    tft.setFont(&OswaldRegular12pt7b);
    tft.setTextSize(1);
    tft.setTextColor(ST77XX_WHITE);
    tft.setCursor(15,20);
    tft.println("Project by");
    tft.println("Nweke Chisom");
    tft.println("       And");
    tft.println(" Ezeala Ogechi"); 
    delay(500);
 

   
  // verifica se o cartão SD está presente e se pode ser inicializado
  if (!SD.begin(CS_PIN)) {
    delay(500);
    Serial.println("Card Initialization failed");
    //programa encerrrado
    return;
  }
   
  //se chegou aqui é porque o cartão foi inicializado corretamente  
  Serial.println("SD card detected");
 
}

void loop(){
  
}
