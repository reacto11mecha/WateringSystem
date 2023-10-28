int soilPin = 5; // Pin sensor tanah
int waterPin = 6; // Pin unit pompa air

void setup() {
  pinMode(soilPin, INPUT); // Menetapkan pin untuk menerima input dari sensor tanah
  pinMode(waterPin, OUTPUT); // Menetapkan pin untuk memerintah relay

  // Inisialisasi komunikasi serial (DEBUGGING)
  Serial.begin(9600);
}

void loop() {
  // Mengecek apakah tanah kaya akan air
  int isWaterRich = digitalRead(soilPin);

  // Mengirim status air (DEBUGGING)
  Serial.println(isWaterRich);

  // Mengirim perintah ke relay.
  // Jika ada air dalam tanah, tidak perlu menyalakan pompa melalui relay,
  // Jika tidak ada air, maka pompa dinyalakan melalui relay
  digitalWrite(waterPin, isWaterRich == HIGH ? LOW : HIGH);
  
  // Delay 400 milidetik atau 0.4 detik
  delay(400);
}
