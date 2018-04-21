void setup() {
  Serial.begin(115200);
  //pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  while (Serial.available() != 0) {
    Serial.println("Hello, World!, Hello, World!, Hello, World!, Hello, World!, Hello, World!, Hello, World!, Hello, World!, Hello, World!, Hello, World!, Hello, World!, ");
    delay(100);
  }
//  else {
//    //    digitalWrite(LED_BUILTIN, HIGH);
//    //    delay(100);
//    //    digitalWrite(LED_BUILTIN, LOW);
//    //    delay(100);
//  }
}
