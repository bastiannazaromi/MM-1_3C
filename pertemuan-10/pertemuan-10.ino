#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

// SCL --> A5
// SDA --> A4

#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10 // SDA
#define RST_PIN 9 // RST
MFRC522 mfrc522(SS_PIN, RST_PIN);

// SCK --> 13
// MOSI --> 11
// MISO --> 12
// 3.3V --> 3.3V

#define relayPin 2

void setup() {
  Serial.begin(9600);

  SPI.begin();
  mfrc522.PCD_Init();
  
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print("KELAS 3C");

  delay(2000);

  Serial.println("Program Module RFID");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPELKAN KARTU");

  delay(1000);
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  if (!mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  String content = "";
  
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  content.toUpperCase();

  Serial.print("UID: ");
  Serial.println(content.substring(1));

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("UID :");
  lcd.setCursor(0,1);
  lcd.print(content.substring(1));
  delay(1500);

  // cek jika UID / ID Kartu = BD 31 15 2B, (silahkan diganti sesuai dengan ID yg terbaca ya...
  if (content.substring(1) == "BD 31 15 2B") {
    Serial.println("Akses Diterima");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("AKSES DITERIMA");
    lcd.setCursor(0, 1);
    lcd.print("SILAHKAN MASUK");
  
    digitalWrite(relayPin, HIGH);
    delay(3000);
    digitalWrite(relayPin, LOW);
  } else {
    Serial.println("Akses Ditolak");

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("AKSES DITOLAK");
    lcd.setCursor(0,1);
    lcd.print("COBA LAGI");

    delay(3000);
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPELKAN KARTU");
  
  Serial.println();
  delay(200);
}
