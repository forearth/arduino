#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // 소프트웨어 시리얼 설정(* RX, TX 보드에 연결할때는 반대)

//모터A 컨트롤
int motorA1=7;
int motorA2=6;
int speedPinA=9;
 
//모터B 컨트롤
int motorB1=5;
int motorB2=4;
int speedPinB=10;
int vSpeed=255;     // Default speed, from 0 to 255


void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    
  motorStop();
}

void loop() { // run over and over
  if (BTSerial.available()) {  //블루투스로 데이터 수신
    
    byte data=BTSerial.read(); //수신 받은 데이터 저장
    Serial.write(data);  //수신된 데이터 출력

    analogWrite(speedPinA, vSpeed);
    analogWrite(speedPinB, vSpeed);

  switch(data){
    case 'F':
      motorGo();
      break;
    case 'B':
      motorBack();
      break;
    case 'G':
      motorRightGo();
      break;
    case 'I':
      motorLeftGo();
      break;
    case 'H':
      motorRightBack();
      break;
    case 'J':
      motorLeftBack();
      break;
    case 'S':
      motorStop();
      break;
    default:
      return;
    }
  }
}

  void motorGo() {
    digitalWrite(motorA1, HIGH); 
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW); 
}
void motorBack() {
    digitalWrite(motorA1, LOW); 
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW); 
}
void motorRightGo() {
    digitalWrite(motorA1, HIGH); 
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW); 
}
void motorLeftGo() {
    digitalWrite(motorA1, HIGH); 
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH); 
}
void motorRightBack() {
    digitalWrite(motorA1, LOW); 
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW); 
}
void motorLeftBack() {
    digitalWrite(motorA1, LOW); 
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH); 
}
void motorStop() {
    digitalWrite(motorA1, LOW); 
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW); 
}



