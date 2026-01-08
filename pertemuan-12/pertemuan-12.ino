#define IR_MASUK 9
#define IR_KELUAR 10

#define LED_MASUK 2
#define LED_KELUAR 3

unsigned long lastCheckMasuk = 0;
unsigned long lastCheckKeluar = 0;
const unsigned long interval = 100;

int jumlahOrang = 0;

int lastMasukState = LOW;
int lastKeluarState = LOW;

void setup() {
  Serial.begin(9600);

  pinMode(IR_MASUK, INPUT);
  pinMode(IR_KELUAR, INPUT);

  pinMode(LED_MASUK, OUTPUT);
  pinMode(LED_KELUAR, OUTPUT);

  Serial.println("KELAS 3C");
}

void loop() {
  unsigned long now = millis();

  if (now - lastCheckMasuk >= interval) {
    lastCheckMasuk = now;

    int currentMasuk = digitalRead(IR_MASUK);

    if (currentMasuk == LOW && lastMasukState == HIGH) {
      jumlahOrang++;
      Serial.print("MASUK | Jumlah orang: ");
      Serial.println(jumlahOrang);
    }

    digitalWrite(LED_MASUK, currentMasuk);
    lastMasukState = currentMasuk;
  }

  if (now - lastCheckKeluar >= interval) {
    lastCheckKeluar = now;

    int currentKeluar = digitalRead(IR_KELUAR);

    if (currentKeluar == LOW && lastKeluarState == HIGH) {
      if (jumlahOrang > 0) 
      {
        jumlahOrang--;
      }
      Serial.print("KELUAR | Jumlah orang: ");
      Serial.println(jumlahOrang);
    }

    digitalWrite(LED_KELUAR, currentKeluar);
    lastKeluarState = currentKeluar;
  }
}
