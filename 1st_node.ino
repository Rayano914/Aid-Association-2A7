#include <SPI.h> // SPI // biblioteque comminication 
#include <MFRC522.h> // RFID

#define SS_PIN 10 //defini 2 pin 
#define RST_PIN 9

// Déclaration
MFRC522 rfid(SS_PIN, RST_PIN); //declaration les classe (rfid)

// Tableau contentent l'ID
byte nuidPICC; // variable inclu des donner 

void setup()
{
  
  Serial.begin(9600);// initialisation serial boudraytt 9600

  // Init SPI bus
  SPI.begin(); 

  // Init MFRC522
  rfid.PCD_Init();
}

void loop()
{
  

   
  if ( !rfid.PICC_IsNewCardPresent())// rechercher le carte 
    {return;}

  
 if ( !rfid.PICC_ReadCardSerial())// lire le donner d'une carte 
    {return;}
      rfid.PICC_DumpToSerial(&(rfid.uid));
 nuidPICC = rfid.uid.uidByte[0];//tretment de donner  une seule tramm 
Serial.println(nuidPICC);



  // Re-Init RFID
  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD
}
