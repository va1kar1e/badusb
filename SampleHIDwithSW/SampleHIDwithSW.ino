#include "DigiKeyboard.h"

#define inputPin 0
#define outputPin 1

char *myTexts[] = {
  "This is string from A00",
  "This is string from A01", 
  "This is string from A02",
  "This is string from A03",
  "This is string from A04",   
  "This is string from A05"
};

int i = 0;

void setup() {
  // Input
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin,HIGH);
  // Output
  pinMode(outputPin, OUTPUT);
  blinkIntro();
}

void loop() {
  blinkState();
  if (digitalRead(inputPin) == 0) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.println(myTexts[i]);
    DigiKeyboard.delay(1000);  
  }
 
  if (i >= 5) {
    i = 0;
    delay(1000);
    blinkIntro();
  }
  else {
    i += 1;
  }
}

void blinkIntro() {
  int i;
  for (i = 0; i < 5; i++) {
    digitalWrite(outputPin,HIGH);
    delay(200);
    digitalWrite(outputPin,LOW);
    delay(200);
  } 
  delay(750);
}

void blinkState() {
  digitalWrite(outputPin,HIGH);
  delay(500);
  digitalWrite(outputPin,LOW);
  delay(1000);
}
