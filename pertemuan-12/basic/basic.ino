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
  if (sensorStatus == LOW)
  {
    digitalWrite(LED, HIGH);
    Serial.println("Terdeteksi");
  }
  else  {
    digitalWrite(LED, LOW);
    Serial.println("Tidak ada pergerakan");
  }

  delay(500);
}
