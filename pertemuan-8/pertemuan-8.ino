#define triggerPin D8
#define echoPin D7

#define pinBuzzer D0

void setup() {
  Serial.begin(9600);
  
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(pinBuzzer, OUTPUT);

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

  if (jarak <= 5) {
    Serial.println("Buzzer berbunyi");
    digitalWrite(pinBuzzer, HIGH);
  } else {
    Serial.println("Buzzer mati");
    digitalWrite(pinBuzzer, LOW);
  }

  delay(1000);
}
