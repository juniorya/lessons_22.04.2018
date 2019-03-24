#include <Arduino.h>

void setup() {
 Serial.begin(9600);
}

void loop() {
  int i=1;
  for(i = 0; i < 50; i++)
  {
  Serial.print(i);
  Serial.print("Hello_World");
  //Serial.print('\n');
  delay(100);
  }
  exit(0);
}