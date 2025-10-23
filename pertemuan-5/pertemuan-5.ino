#include <Servo.h>

Servo motorServo;
#define pinMotorServo 3

#define pinButton 4

void setup() {
  Serial.begin(9600);
  Serial.println("Program Motor Servo");

  motorServo.attach(pinMotorServo);

  motorServo.write(0);

  pinMode(pinButton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(pinButton) == HIGH) {
    Serial.println("Servo 180 Derajat");
    motorServo.write(180);
  } else {
    Serial.println("Servo 0 Derajat");
    motorServo.write(0);
  }
  
  delay(2000);
}
