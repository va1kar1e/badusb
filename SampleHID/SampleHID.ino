// Typing "Hello World" when insert a BadUSB
#include "DigiKeyboard.h"

#define KEYSTROKE_DELAY 1000
#define TEXT "Hello World"


bool isSend = true;

void setup()
{
  
}

void loop()
{
  DigiKeyboard.sendKeyStroke(0);
  
  if (isSend) {
      DigiKeyboard.print(TEXT);
      DigiKeyboard.delay(KEYSTROKE_DELAY);
      //DigiKeyboard.sendKeyStroke(KEY_ENTER);

      isSend = false;
  }
}
