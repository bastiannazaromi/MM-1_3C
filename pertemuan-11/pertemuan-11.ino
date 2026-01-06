#define pinLdr A0
#define pinSensorHujan A1

void setup()
{
  Serial.begin(9600);

  Serial.println("KELAS 3C");
}

void loop()
{
  int nilaiLdr = analogRead(pinLdr);
  // nilaiLdr = map(value, 0, 1023, 0, 100);

  int nilaiSensorHujan = analogRead(pinSensorHujan);
  // nilaiSensorHujan = map(value, 0, 1023, 0, 100);
  
  Serial.println("Nilai LDR : " + (String) nilaiLdr);
  Serial.println("Nilai Sensor Hujan : " + (String) nilaiSensorHujan);
  
  delay(200);
}
