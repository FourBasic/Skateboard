#include "Arduino.h"
#define iX A1
#define ENA 3

int rawX;
int calcX;

void setup()
{
  Serial.begin(9600);
  pinMode(iX, INPUT);
  pinMode(ENA, OUTPUT);  
  analogWrite(ENA, 0);
  delay(5000); 
}
void loop()
{  
  rawX = analogRead(iX);
  //700-1000
  if (rawX < 700) {
    rawX = 0;
  } else {
    rawX = rawX - 700;
    if (rawX > 255) {
      rawX = 255;
    }
  }  
  Serial.println(rawX);
  analogWrite(ENA, rawX);// motor speed
}