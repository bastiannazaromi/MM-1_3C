#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print("KELAS 3C");

  delay(3000);

  lcd.clear();
}

void loop() {
  int suhu = 30;
  int kelembapan = 75;
  
  lcd.setCursor(0, 0);
  lcd.print("SUHU : ");
  lcd.setCursor(7, 0);
  lcd.print(suhu);

  lcd.setCursor(0, 1);
  lcd.print("KELEMBAPAN : ");
  lcd.setCursor(13, 1);
  lcd.print(kelembapan);

  delay(500);

  lcd.clear();
}
