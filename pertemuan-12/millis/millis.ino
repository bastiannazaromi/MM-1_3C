#define IR_MASUK 9
#define IR_KELUAR 10

#define LED_MASUK  2
#define LED_KELUAR 3

unsigned long lastCheckMasuk = 0;
unsigned long lastCheckKeluar = 0;
const unsigned long interval = 100;
const unsigned long interval_keluar = 500;

void setup() {
  Serial.begin(9600);

  pinMode(IR_MASUK, INPUT);
  pinMode(IR_KELUAR, INPUT);

  pinMode(LED_MASUK, OUTPUT);
  pinMode(LED_KELUAR, OUTPUT);

  digitalWrite(LED_MASUK, LOW);
  digitalWrite(LED_KELUAR, LOW);

  Serial.println("KELAS 3C");
}

void loop() {
  unsigned long now = millis();

  if (now - lastCheckMasuk >= interval) {
    lastCheckMasuk = now;

    if (digitalRead(IR_MASUK) == LOW) {
      digitalWrite(LED_MASUK, HIGH);
      Serial.println("Orang MASUK");
    } else {
      digitalWrite(LED_MASUK, LOW);
    }
  }

  if (now - lastCheckKeluar >= interval_keluar) {
    lastCheckKeluar = now;

    if (digitalRead(IR_KELUAR) == LOW) {
      digitalWrite(LED_KELUAR, HIGH);
      Serial.println("Orang KELUAR");
    } else {
      digitalWrite(LED_KELUAR, LOW);
    }
  }
}
