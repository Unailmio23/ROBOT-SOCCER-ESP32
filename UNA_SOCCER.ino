//Robot Soccer
//by anonymous
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int kiri_mundur = 15;
const int kiri_maju = 4;
const int kanan_mundur = 19;
const int kanan_maju = 5;
const int ledPin = 2; 
char data;

void setup() {
  pinMode(kiri_mundur, OUTPUT);
  pinMode(kiri_maju, OUTPUT);
  pinMode(kanan_mundur, OUTPUT);
  pinMode(kanan_maju, OUTPUT);
  pinMode(ledPin, OUTPUT);

  SerialBT.begin("ESP32_KML"); // Nama perangkat Bluetooth
  Serial.begin(9600); 

  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
}

void maju() {
  digitalWrite(kiri_mundur, LOW);
  digitalWrite(kiri_maju, HIGH);
  digitalWrite(kanan_mundur, LOW);
  digitalWrite(kanan_maju, HIGH);
  digitalWrite(ledPin, HIGH); // LED menyala saat maju
}

void mundur() {
  digitalWrite(kiri_mundur, HIGH);
  digitalWrite(kiri_maju, LOW);
  digitalWrite(kanan_mundur, HIGH);
  digitalWrite(kanan_maju, LOW);
  digitalWrite(ledPin, HIGH); // LED menyala saat mundur
}

void kanan() {
  digitalWrite(kiri_mundur, LOW);
  digitalWrite(kiri_maju, HIGH);
  digitalWrite(kanan_mundur, LOW);
  digitalWrite(kanan_maju, LOW);
  digitalWrite(ledPin, HIGH); // LED menyala saat berbelok kanan
}

void kiri() {
  digitalWrite(kiri_mundur, LOW);
  digitalWrite(kiri_maju, LOW);
  digitalWrite(kanan_mundur, LOW);
  digitalWrite(kanan_maju, HIGH);
  digitalWrite(ledPin, HIGH); // LED menyala saat berbelok kiri
}

void berhenti() {
  digitalWrite(kiri_mundur, LOW);
  digitalWrite(kiri_maju, LOW);
  digitalWrite(kanan_mundur, LOW);
  digitalWrite(kanan_maju, LOW);
  digitalWrite(ledPin, LOW); // LED mati saat berhenti
}

void loop() {
  if (SerialBT.available()) {
    data = SerialBT.read(); 
    Serial.println(data); 
  }

  switch (data) {
    case 'w':
      maju();
      break;
    case 's':
      mundur();
      break;
    case 'd':
      kanan();
      break;
    case 'a':
      kiri();
      break;
    case 'f':
      berhenti();
      break;
    default:
      // Tidak ada aksi untuk karakter lain
      break;
  }
}