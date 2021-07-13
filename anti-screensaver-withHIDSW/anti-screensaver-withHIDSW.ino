// Digispark Random Mouse Move for anti-screensaver
// Author: shadowandy (shadowandy[dot]sg[at]gmail[dot]com)
// Web: www.shadowandy.net
 
#include "DigiMouse.h"
#include "DigiKeyboard.h"

#define inputPin 0
#define outputPin 1

char *myTexts[] = {
  "AAA",
  "BBB",
  "CCC"
};

int i = 0, lenMytexts = 3;

// Configurations for Random Mouse Move
// MOUSE_MOVE_L : Number of pixels to move (min)
// MOUSE_MOVE_H : Number of pixels to move (max)
// MOUSE_DELAY_L : Interval (milliseconds) to move the mouse (min)
// MOUSE_DELAY_H : Interval (milliseconds) to move the mouse (max)
 
#define MOUSE_MOVE_L 1000
#define MOUSE_MOVE_H 5000
#define MOUSE_DELAY_L 15000
#define MOUSE_DELAY_H 300000
 
// You really should not change anything below
 
#define MOUSE_UP 1
#define MOUSE_DN 2
#define MOUSE_LT 3
#define MOUSE_RT 4
 
unsigned int mouse_move_amount = 1;
unsigned int mouse_current = MOUSE_UP;
unsigned long mouse_time_current;
unsigned long mouse_time_movement;

void setup() {
  // Input
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin,HIGH);
  // Output
  pinMode(outputPin, OUTPUT);

  blinkIntro();
  
  DigiMouse.begin(); //start or reenumerate USB
  mouse_time_movement = millis() + random(MOUSE_DELAY_L, MOUSE_DELAY_H);
  mouse_move_amount = random(MOUSE_MOVE_L, MOUSE_MOVE_H);
}
 

 
void loop() {
  digitalWrite(outputPin,HIGH);
  delay(1000);
  if (digitalRead(inputPin) == 0) {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.println(myTexts[i]);
    DigiKeyboard.delay(1000);  
  } else {
    mouseRandam();
  }
  digitalWrite(outputPin,LOW);
  delay(250);
  if (i >= lenMytexts) {
    i = 0;
    blinkIntro();
  }
  else {
    i += 1;
  }
}

void mouseRandam() {
  DigiMouse.update(); // DigiMouse.update() at least every 50ms
  if (millis() > mouse_time_movement) {
      switch (mouse_current) {
          case MOUSE_UP :
          DigiMouse.moveY(-mouse_move_amount);
          break;
          case MOUSE_DN :
          DigiMouse.moveY(mouse_move_amount);
          break;
          case MOUSE_LT :
          DigiMouse.moveX(-mouse_move_amount);
          break;
          case MOUSE_RT :
          DigiMouse.moveX(mouse_move_amount);
          break;
          default :
          mouse_current = 1;
      }
      mouse_current = random(1,4);
      mouse_time_movement = millis() + random(MOUSE_DELAY_L, MOUSE_DELAY_H);
      mouse_move_amount = random(MOUSE_MOVE_L, MOUSE_MOVE_H);
  }
}

void blinkIntro() {
  int i;
  for (i = 0; i < 3; i++) {
    digitalWrite(outputPin,HIGH);
    delay(100);
    digitalWrite(outputPin,LOW);
    delay(100);
  } 
  delay(500);
}
