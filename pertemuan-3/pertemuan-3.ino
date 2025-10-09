#define pinButton 2
#define pinLed 3

#define pinPotensio A0
#define pinLed2 11

void setup() {
  Serial.begin(9600);

  Serial.println("Push Button & Potensiometer");

  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
  pinMode(pinLed2, OUTPUT);
}

void loop() {
//  Serial.print("Nilai Push Button : ");
//  Serial.println(digitalRead(pinButton));

  if (digitalRead(pinButton) == LOW) {
    Serial.println("LED ON");
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
    Serial.println("LED OFF");
  }

  int valuePotensio = analogRead(pinPotensio);
  Serial.print("Nilai Potensio : ");
  Serial.println(valuePotensio);

  analogWrite(pinLed2, valuePotensio / 4);
  
  Serial.println();

  delay(400);
}
