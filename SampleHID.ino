// Typing "Hello World" every 30 seconds when insert a BadUSB
#include "DigiKeyboard.h"

#define KEYSTROKE_DELAY 1000
#define TEXT "Hello World"

void setup() {

  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A     
  digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(1, LOW); 
}


void loop() {

  DigiKeyboard.sendKeyStroke(0);

  DigiKeyboard.println(TEXT);
  
  DigiKeyboard.delay(KEYSTROKE_DELAY);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(30000);
}
