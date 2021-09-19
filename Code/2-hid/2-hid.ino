#include "DigiKeyboard.h"

#define outputPin 1
#define KEYSTROKE_DELAY 1000

char *myTexts[] = {
    "ABC",
    "DEF"};

int i = 0, lenMytexts = 2;
bool isSend = true;

void setup()
{
  // Output
  pinMode(outputPin, OUTPUT);
  blinkIntro(3);
}

void loop()
{
  delay(200);
  if (isSend)
  {
    blinkIntro(2);

    digitalWrite(outputPin, HIGH);
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.println(myTexts[i]);
    DigiKeyboard.delay(KEYSTROKE_DELAY);
    digitalWrite(outputPin, LOW);
    delay(50);
  }

  if (i >= lenMytexts - 1)
  {
    isSend = false;
    blinkIntro(10);
  }
  else
  {
    i += 1;
  }
}

void blinkIntro(int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    digitalWrite(outputPin, HIGH);
    delay(100);
    digitalWrite(outputPin, LOW);
    delay(100);
  }
  delay(500);
}
