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
int pinIn=0;
int pinIny=4;
int pinOut=2;


void setup() {
  // Output
  pinMode(1, OUTPUT);
  pinMode(pinOut, OUTPUT);
  // Input
  pinMode(pinIn, INPUT);
}

void loop() {
  if (digitalRead(pinIn)==HIGH) {
    blink(1);
//    printText(1);
  }
  else if (digitalRead(pinIny)==HIGH) {
    blink(pinOut);
  } else {
//    digitalWrite(1,LOW);
//    isSend = true;
  }
}

void blink(int x) {
  digitalWrite(x,HIGH);
  delay(500);
  digitalWrite(x,LOW);
  delay(500);
}

void printText(int x) {
  DigiKeyboard.sendKeyStroke(0);
  if (isSend) {
    DigiKeyboard.print(myTexts[x]);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(KEYSTROKE_DELAY);
    isSend = false;
  }
}
