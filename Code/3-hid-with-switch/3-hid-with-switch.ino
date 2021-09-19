#include "DigiKeyboard.h"

#define inputPin 0
#define outputPin 1

char *myTexts[] = {
    "ABC",
    "DEF",
    "GHI"};

int i = 0, lenMytexts = 3;

void setup()
{
  // Input
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin, HIGH);
  // Output
  pinMode(outputPin, OUTPUT);

  blinkIntro();
}

void loop()
{
  digitalWrite(outputPin, HIGH);
  delay(1000);
  if (digitalRead(inputPin) == 0)
  {
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.println(myTexts[i]);
    DigiKeyboard.delay(1000);
  }
  digitalWrite(outputPin, LOW);
  delay(250);
  if (i >= lenMytexts - 1)
  {
    i = 0;
    blinkIntro();
  }
  else
  {
    i += 1;
  }
}

void blinkIntro()
{
  int i;
  for (i = 0; i < 3; i++)
  {
    digitalWrite(outputPin, HIGH);
    delay(100);
    digitalWrite(outputPin, LOW);
    delay(100);
  }
  delay(500);
}
