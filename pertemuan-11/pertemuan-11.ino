#define pinLdr A0
#define pinSensorHujan A1

#include <Servo.h>

Servo motorServo;
#define pinMotorServo 3

#define pinLed 4

void setup()
{
  Serial.begin(9600);

  motorServo.attach(pinMotorServo);
  motorServo.write(0);

  pinMode(pinLed, OUTPUT);
  Serial.println("KELAS 3C");
}

void loop()
{
  int nilaiLdr = analogRead(pinLdr);
  nilaiLdr = map(nilaiLdr, 0, 1023, 100, 0);

  int nilaiSensorHujan = analogRead(pinSensorHujan);
  nilaiSensorHujan = map(nilaiSensorHujan, 0, 1023, 100, 0);
  
  Serial.println("Nilai LDR : " + (String) nilaiLdr);
  Serial.println("Nilai Sensor Hujan : " + (String) nilaiSensorHujan);
  
  if (nilaiLdr < 25) {
    // .....
  } else {
    // .....
  }

  if (nilaiSensorHujan > 50) {
    // ....
  } else {
    // ....
  }
  
  Serial.println();
  delay(1000);
}
