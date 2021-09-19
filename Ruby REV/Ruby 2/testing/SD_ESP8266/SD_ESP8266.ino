//biblioteca responsável pela comunicação com o Cartão SD
#include <SD.h>
//biblioteca responsável pela comunicação com o sensor DHT22

//pino ligado ao CS do módulo SD Card
#define CS_PIN  D8

void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD Card...");
 

   
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
