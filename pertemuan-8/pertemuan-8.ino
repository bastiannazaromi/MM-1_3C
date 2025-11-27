#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

// SCL --> D1
// SDA --> D2

#define triggerPin D8
#define echoPin D7

#define pinBuzzer D0

void setup() {
  Serial.begin(9600);
  
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(pinBuzzer, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print("KELAS 3C");

  Serial.println("Program Sensor Ultrasonik");

  delay(1000);
}

void loop() {
  long duration, jarak;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  jarak = (duration/2) / 29.1;
  
  Serial.println("jarak :");
  Serial.print(jarak);
  Serial.println(" cm");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("JARAK : ");
  lcd.setCursor(8, 0);
  lcd.print(jarak);
  lcd.setCursor(13, 0);
  lcd.print("CM");

  if (jarak <= 5) {
    Serial.println("Buzzer berbunyi");
    digitalWrite(pinBuzzer, HIGH);
  } else {
    Serial.println("Buzzer mati");
    digitalWrite(pinBuzzer, LOW);
  }

  delay(1000);
}
