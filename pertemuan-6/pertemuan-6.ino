#define in1 2
#define in2 3

void setup() {
  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  Serial.println("Motor DC");
}

void loop() {
  maju();
  delay(3000);
  berhenti();
  delay(1000);
  mundur();
  delay(3000);
}

void maju() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void mundur() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void berhenti() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
