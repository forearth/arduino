#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); //RX, TX


#define fadeStar1 9
#define fadeStar2 10


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  mySerial.begin(9600);

}

void loop() {
  if (mySerial.available()) {
    byte data=mySerial.read();
    Serial.write(data);

    switch(data){
      case '1':
        star1();
        break;
      case '2':
        star2();
        break;
      case '3':
        star3();
        break;
      default:
        return;
    }

  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }

}

void star1(){
  for(int fadeValue=0; fadeValue<=255; fadeValue+=5){
    analogWrite(fadeStar1, fadeValue);
    delay(30);
  }
  for(int fadeValue=255; fadeValue>=0; fadeValue-=5){
    analogWrite(fadeStar1, fadeValue);
    delay(30);
  }  
}

void star2(){
  for(int fadeValue=0; fadeValue<=255; fadeValue+=5){
    analogWrite(fadeStar2, fadeValue);
    delay(30);
  }
  for(int fadeValue=255; fadeValue>=0; fadeValue-=5){
    analogWrite(fadeStar2, fadeValue);
    delay(30);
  }  
}

  void star3(){
    digitalWrite(fadeStar1, HIGH);
    digitalWrite(fadeStar2, HIGH);    
  }



