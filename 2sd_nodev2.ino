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
    lcd.print("Pass Card");
    lcd.setCursor(4, 1);
    lcd.print("please");
  // initialize serial:
  Serial.begin(9600);
 
 

}

void loop() {
  /*if (Serial.available()> 0) {//na9raw biha donnee
   
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
  }*/
    if(Serial.available()) {
     //const int val = Serial.parseInt();
      inputString = Serial.readString();
      data += inputString;


       
         data += inputString;//7attena donner elli 9renehom fel base de donnee
    lcd.clear();
    lcd.setCursor(0, 0);//curseur ecran
    lcd.print("new member adedd");
    delay(2000);// 20000 time avec second 
  
     /*if(val ==2) {
        //digitalWrite(led,HIGH);
        lcd.clear();
    lcd.setCursor(0, 0);//curseur ecran
    lcd.print("Rayan");
    delay(2000);// 20000 time avec second
        delay(1000);
        Serial.write("Ok");
     } else {
        lcd.clear();
    lcd.setCursor(0, 0);//curseur ecran
    lcd.print("AAAAAAAA");
    delay(2000);// 20000 time avec second
        Serial.write("Not Ok");
     }*/

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
  
  //if (data.indexOf(sdata, 0)!=-1) {//verifier les donner esq dans la base de donner ou non 
   /* if(inputString==sdata)
    {
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
  }*/

    String content= "";
  byte letter;

  for (byte i = 0; i < rfid.uid.size; i++) 
  {
    lcd.setCursor(0, 1);
     lcd.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
     lcd.print(rfid.uid.uidByte[i], HEX);
     content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(rfid.uid.uidByte[i], HEX));
  }
 // content.concat(String(rfid.uid.uidByte[0] < 0x10 ? " 0" : " "));
  //content.concat(String(rfid.uid.uidByte[0], DEC));
lcd.clear();
lcd.setCursor(0, 0);
content.substring(1);
 //lcd.print("Message : ");
 content.toUpperCase();
 //content.substring(1);
  //lcd.print(content.substring(1));
  //lcd.setCursor(3, 0);
   // lcd.print(inputString);
    
  if (content.substring(1) == "FF 44 3B D9" ) //Plz change to your cards UID

  {
  lcd.clear();
    lcd.setCursor(0, 0);
    
    lcd.print("welcome");
    lcd.setCursor(0, 1);
    lcd.print("access approved");
    delay(2000);// par temps d'affichage 
    lcd.clear();
    lcd.setCursor(3, 0);
   //lcd.clear();
    setup();
  }
 
 else   {
  lcd.setCursor(0, 1);
    lcd.print(" Access denied");
    delay(3000);
    lcd.clear();
      setup();
      }

  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD


}
