#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2);

// SCL --> D15
// SDA --> D14

#include "DHT.h"

#define DHTPIN D5

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  
  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print("KELAS 3C");

  Serial.println("Program Sensor DHT");

  delay(1000);
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();
  // suhu dalam fahrenheit
//  float f = dht.readTemperature(true);
  
  if (isnan(suhu) || isnan(kelembapan)) {
    Serial.println("Failed to read from DHT sensor!");
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("FAILED READ DHT");
  } else {
    Serial.println("SUHU : " + (String) suhu);
    Serial.println("Kelembapan : " + (String) kelembapan);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SUHU : ");
    lcd.setCursor(7, 0);
    lcd.print(suhu);
    lcd.setCursor(0, 1);
    lcd.print("KELEMBAPAN : ");
    lcd.setCursor(13, 1);
    lcd.print(kelembapan);
  }

  Serial.println();
  delay(1000);
}
