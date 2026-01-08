#define IRSensor 9
#define LED 2

void setup() {
  Serial.begin(9600);
  
  pinMode(IRSensor, INPUT);
  pinMode(LED, OUTPUT);

  Serial.println("KELAS 3C");
}

void loop() {
  int sensorStatus = digitalRead(IRSensor);
  if (sensorStatus == 1)
  {
    digitalWrite(LED, LOW);
    Serial.println("Terdeteksi");
  }
  else  {
    digitalWrite(LED, HIGH);
    Serial.println("Tidak ada pergerakan");
  }

  delay(500);
}
