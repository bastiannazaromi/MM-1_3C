int semester = 3;
String kelas = "C";
String matakuliah = "Microprocesor & Mikrokontroller";

boolean kondisi = false;

void setup() {
  // put your setup code here, to run once:
  // hanya diakses 1x ketika arduino itu berjalan

  Serial.begin(9600);

  // cara 1
//  Serial.print("Kelas : ");
//  Serial.println(kelas);

  Serial.println("Kelas : " + kelas);

  // cara 2
  Serial.println("Semester : " + (String) semester);

  /* operator matematika
  1. untuk membandingkan 2 nilai yang sama : == | ===
  2. kebalikan dari == : !=
  3. membandingkan nilai lebih besar : > | >=
  */
  
  if (kondisi == true) {
    Serial.println("Matakuliah hari ini : " + matakuliah);
  } else {
    Serial.println("Tidak ada perkuliahan hari ini");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // diakses berulang

  for (int i = 1; i <= 5; i++) {
    Serial.println("Angka : " + (String) i);
    delay(1000);
  }

  Serial.println();

  delay(3000);
}
