#include <SoftwareSerial.h>  
SoftwareSerial BTSerial(3, 5); // SoftwareSerial(RX, TX)  

//변수선언
int led1=6;
int led2=9;
int light_sensor=0;

//값 버퍼설정
char buffer[20];               //통신을 할때 buffer배열에 전송받은 데이터 입력
char bufferIndex = 0; 

//아두이노 초기화
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello!");  
  BTSerial.begin(9600);
}
  
void loop() {
  //임의 값 설정하기
  int standard_val = 120;

  //조도센서 값 읽어오기
  int val = 0;
  val = analogRead(light_sensor); 
  Serial.println(val);
  delay(1000);

  //조도센서 값이 임의값보다 작을 경우 led1 불켜기 
  if(val<standard_val){
    digitalWrite(led1, HIGH);
  }else{
    digitalWrite(led1, LOW);
  }

  // 스마트폰으로부터 메시지가 올 경우
  while (BTSerial.available()) {   
    buffer[bufferIndex]  = BTSerial.read();   //시리얼 통신으로 버퍼배열에 데이터 수신
    bufferIndex++;                            //데이터 수신 후 버퍼 인덱스 1 증가
  }  
  int gamer_sense_value = atoi(buffer);       //atoi()함수로 문자값(char)을 숫자형(int)으로 변환
  Serial.print("BT:");
  Serial.println(gamer_sense_value);
  
  if(gamer_sense_value == standard_val){
    digitalWrite(led2, HIGH);
    BTSerial.write("Congratulation!!!"); // 스마트폰으로 축하메시지 보내기
    delay(5000);                         // 5초간 불켜기
  }else{
    digitalWrite(led2, LOW);
    if(val>standard_val){
       BTSerial.write("Down!!!\n"); // 스마트폰으로 힌트메시지 보내기
    }else{
       BTSerial.write("Up!!!\n"); // 스마트폰으로 힌트메시지 보내기      
    }   
  }
  
  //버퍼 초기화
  for(int a=0;a<21;a++) {
    buffer[a] = NULL;
  }
  bufferIndex = 0;

  //컴퓨터에서 입력한 값을 폰으로 보내기
  while (Serial.available()) { // if Serial has input(from serial monitor)  
    byte data = Serial.read();  
    BTSerial.write(data); // write it to BT  
  }  
}
