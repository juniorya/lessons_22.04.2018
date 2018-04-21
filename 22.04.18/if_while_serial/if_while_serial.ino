
int LED=1;
void setup() {
  Serial.begin(115200);                 //Начинаем передачу на скорости 115200
  pinMode(LED, OUTPUT);       //№ ножки к которой подключен диод и выход
}

void loop() {
  if (Serial.available() != 0) {        //Если есть подключение по SERIAL, то
    Serial.println("Hello, World!");
    delay(100);
  }
  else {
    digitalWrite(LED,HIGH);
    delay(100);
    digitalWrite(LED,LOW);
    delay(100);
    }
}
