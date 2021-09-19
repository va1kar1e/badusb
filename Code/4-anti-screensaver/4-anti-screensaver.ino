// Digispark Random Mouse Move for anti-screensaver
// Author: shadowandy (shadowandy[dot]sg[at]gmail[dot]com)
// Web: www.shadowandy.net
 
#include "DigiMouse.h"

#define inputPin 0
#define outputPin 1

// Configurations for Random Mouse Move
// MOUSE_MOVE_L : Number of pixels to move (min)
// MOUSE_MOVE_H : Number of pixels to move (max)
// MOUSE_DELAY_L : Interval (milliseconds) to move the mouse (min)
// MOUSE_DELAY_H : Interval (milliseconds) to move the mouse (max)
 
#define MOUSE_MOVE_L 1000
#define MOUSE_MOVE_H 5000
#define MOUSE_DELAY_L 2000
#define MOUSE_DELAY_H 5000
 
// You really should not change anything below
 
#define MOUSE_UP 1
#define MOUSE_DN 2
#define MOUSE_LT 3
#define MOUSE_RT 4
 
unsigned int mouse_move_amount = 1;
unsigned int mouse_current = MOUSE_UP;
unsigned long mouse_time_current;
unsigned long mouse_time_movement;

bool checkMouse = true;

void setup() {
  // Input
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin,HIGH);
  // Output
  pinMode(outputPin, OUTPUT);
  
  DigiMouse.begin(); //start or reenumerate USB
  mouse_time_movement = millis() + random(MOUSE_DELAY_L, MOUSE_DELAY_H);
  mouse_move_amount = random(MOUSE_MOVE_L, MOUSE_MOVE_H);
}
 

 
void loop() {
  if(digitalRead(inputPin) == 0) {
    checkMouse = !checkMouse;
  }
  
  if (checkMouse) {
    digitalWrite(outputPin,HIGH);
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
    delay(25);
  }
}
