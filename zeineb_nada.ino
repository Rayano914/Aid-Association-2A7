#include <Key.h>
#include <Keypad.h>


String dataard;
char data;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}
 
void loop(){
  char key = keypad.getKey();// Read the key
// Print if key pressed
  if (key){    
    Serial.print(key);
    }
if (Serial.available())
{
  data=Serial.read();
  if(data=='o')
  {
    digitalWrite(11,HIGH);
    delay(2000);
    digitalWrite(11,LOW);
     digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
  }
  else if (data=='f')
  {
    digitalWrite(12,HIGH);
       delay(2000);
    digitalWrite(12,LOW);
  }
}

  }
