#include <SoftwareSerial.h>

SoftwareSerial Beacon(2,3); // RX, TX

void setup() {
  //기본 통신속도는 9600 BAUD.
  Serial.begin(9600);
  Beacon.begin(9600);
}

void loop() {
  if (Beacon.available()) {
    Serial.write(Beacon.read());
  }
  if (Serial.available()) {
    Beacon.write(Serial.read());
  }
}
