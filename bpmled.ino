//#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   
//#include <SoftwareSerial.h>
#include <stdlib.h>
//SoftwareSerial blue(7,8);
int PulseSensorPurplePin = 0;
int LED = 13;
int Signal;
int Threshold = 550;
void setup() {
pinMode(LED,OUTPUT);
Serial.begin(9600);

}

void loop() {
 Signal = analogRead(PulseSensorPurplePin);

Serial.println(Signal);
delay(50);
  if(Signal > Threshold)
  {
    digitalWrite(LED,HIGH);
    }
    else
    {
      digitalWrite(LED,LOW);
      }

}
