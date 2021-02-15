// Typing Text depend on DIP Switch 3 Position (8 Condition) when insert a BadUSB
#include "DigiKeyboard.h"

#define KEYSTROKE_DELAY 1000

char *myTexts[] = {
  "This is string from 0000",
  "This is string from 1000",
  "This is string from 0100",
  "This is string from 0010",
  "This is string from 0001",
  "This is string from 1111"
};
                    
bool isSend = true;

void setup()
{
   int i;
   for(i=0; i<=3; i++){
     pinMode(i, INPUT);
     digitalWrite(i, HIGH);
   }
}

void loop()
{
  if (digitalRead(0)==HIGH && digitalRead(1)==LOW && digitalRead(2)==LOW && digitalRead(3)==LOW)
    printText(1);
  else if (digitalRead(0)==LOW && digitalRead(1)==HIGH && digitalRead(2)==LOW && digitalRead(3)==LOW)
    printText(2);
  else if (digitalRead(0)==LOW && digitalRead(1)==LOW && digitalRead(2)==HIGH && digitalRead(3)==LOW)
    printText(3);
  else if (digitalRead(0)==LOW && digitalRead(1)==LOW && digitalRead(2)==LOW && digitalRead(3)==HIGH)
    printText(4);
  else if (digitalRead(0)==HIGH && digitalRead(1)==HIGH && digitalRead(2)==HIGH && digitalRead(3)==HIGH)
    printText(5);
  else {
    printText(0);
//    isSend = true;
  }
  Serial.println(digitalRead(0));
  Serial.println(digitalRead(1));
  Serial.println(digitalRead(2));
  Serial.println(digitalRead(3));
}

void printText(int x) {
  DigiKeyboard.sendKeyStroke(0);
  if (isSend) {
      DigiKeyboard.print(myTexts[x]);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(KEYSTROKE_DELAY);      
//      isSend = false;
  }
}
