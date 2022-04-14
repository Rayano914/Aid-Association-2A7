#include <SPI.h> // SPI
#include <MFRC522.h> // RFID

#define SS_PIN 10
#define RST_PIN 9
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);// initialisation de dimension d'un ecran lc02
String inputString = "";//declaration variable ta9ra messerial
String data = "";// base donnee

MFRC522 rfid(SS_PIN, RST_PIN);
byte nuidPICC;
void setup() {
  SPI.begin();

  // Init MFRC522
  rfid.PCD_Init();// initialisation de rfid
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  
  lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("pass card");
    lcd.setCursor(4, 1);
    lcd.print("please");
  // initialize serial:
  Serial.begin(9600);
 
 

}

void loop() {
  while (Serial.available() > 0) {//na9raw biha donnee
   
    inputString = Serial.readString();//fonction ta9ra donnnee
    data += inputString;//7attena donner elli 9renehom fel base de donnee
    lcd.clear();
    lcd.setCursor(0, 0);//curseur ecran
    lcd.print("new member adedd");
    delay(2000);// 20000 time avec second 
  
    lcd.clear();
    lcd.setCursor(3, 0);// cuerseur d'affichage dans l'ecran 
    lcd.print("pass card");
    lcd.setCursor(4, 1);
    lcd.print("please");
  }
  if ( !rfid.PICC_IsNewCardPresent())
  {
    return;
  }


  if ( !rfid.PICC_ReadCardSerial())
  {
    return;
  }
  nuidPICC = rfid.uid.uidByte[0];
  String sdata = (String)nuidPICC;//tretment data 
  if (data.indexOf(sdata, 0)!=-1) {//verifier les donner esq dans la base de donner ou non 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("welcome");
    lcd.setCursor(0, 1);
    lcd.print("access approved");
    delay(2000);// par temps d'affichage 
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("pass card");
    lcd.setCursor(4, 1);
    lcd.print("please");
  }
  else{
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("access denied");
    delay(2000);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("pass card");
    lcd.setCursor(4, 1);
    lcd.print("please");
  }

  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD


}
