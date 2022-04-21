#include <PulseSensorPlayground.h>
#define USE_ARDUINO_INTERRUPTS true  
#include <LiquidCrystal_I2C.h>
#include <stdlib.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
/*la broche SDA de l’afficheur LCD au PIN A4 de l’Arduino
la broche SCL de l’afficheur LCD au PIN A5 de l’Arduino
la broche GND de l’afficheur LCD à la broche GND  de l’Arduino
la broche VCC de l’afficheur LCD à la broche 5V de l’Arduino*/
#define sensorPintem A1
int PulseSensorPurplePin = 0;
#define LED1 13
#define LED2 12
int myBPM;
int Threshold = 550;
int son = 3;
String dataa;
int t=0;
int b=0;
void setup() {

lcd.init();
 lcd.backlight();
  Serial.begin(9600);
 
  pinMode(son, OUTPUT);
 pinMode(LED1,OUTPUT);
 pinMode(LED2,OUTPUT);


digitalWrite(son,LOW);
digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);
}
void loop() {
lcd.clear();

dataa=Serial.readString();

t=read_temp();
b=read_bpm();
Serial.print(t);

Serial.print(b);
Serial.println();
delay(1000);

}
int read_bpm()
{
  int myBPM= analogRead(PulseSensorPurplePin);
float sig= myBPM/7.2;
int bpm=round(sig);
lcd.setCursor(0,1);
lcd.print("BPM: ");
lcd. setCursor ( 4, 1 ) ;
lcd.print(bpm);
//lcd.clear();
//Serial.print("BPM: ");
//Serial.println(bpm);
if(bpm >120)
{
  digitalWrite(LED2,HIGH);
  digitalWrite(son,HIGH);
}/*else if(sig >130){
 digitalWrite(LED2,HIGH);
  digitalWrite(son,HIGH);
}*/else{
  digitalWrite(LED2,LOW);
  digitalWrite(son,LOW);
}
return bpm;
//delay(2000);
}
int read_temp()
{
    int reading = analogRead(sensorPintem);
 
float voltage = (reading / 1024.0) * 5000;
 
float temperature = voltage / 10;
 int temp=round(temperature);
 lcd.setCursor(0, 0);
 lcd.print("Temperature:");
lcd. setCursor ( 12, 0 ) ;
lcd. print ( temp ) ;
lcd.setCursor(7, 1);
 lcd.print(dataa);
delay( 1000 ) ;

//Serial.print("TEMPERATURE: ");
//Serial.println(temperature);
if(temperature >45)
{
  digitalWrite(LED1,HIGH);
  digitalWrite(son,HIGH);
}else{
  digitalWrite(LED1,LOW);
  digitalWrite(son,LOW);
}
return temp;
delay(1000);
}
