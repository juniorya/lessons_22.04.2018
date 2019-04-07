#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED is ON");
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED is OFF");/**/
  delay(500);
}