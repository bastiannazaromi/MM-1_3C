//const int pinLed = 2;

// deklarasi pin led
#define pinLed 2
#define pinLed2 5

void setup() {
  Serial.begin(9600);

  Serial.println("Program LED");

  // mode dari led (OUTPUT atau INPUT)
  pinMode(pinLed, OUTPUT);
  pinMode(pinLed2, OUTPUT);

  // HIGH : 1, LOW : 0
  digitalWrite(pinLed, HIGH);
  digitalWrite(pinLed2, HIGH);
}

void loop() {
  digitalWrite(pinLed, HIGH);
  digitalWrite(pinLed2, HIGH);

  delay(3000);

  digitalWrite(pinLed, LOW);
  digitalWrite(pinLed2, LOW);

  delay(1000);
}
