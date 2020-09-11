//블루투스 모듈 설정
#include <SoftwareSerial.h>
#include "Keyboard.h"

SoftwareSerial BTserial(10, 11); // TX | RX

void setup()
{
  // HC-06 default serial speed is 9600
  BTserial.begin(9600);
  // 키보드 초기화
  Keyboard.begin();
}

void loop()
{
  //페이지 제어 명령
  char ctrlPage;
  
  // 블루투스 모듈로 부터 메시지가 오는 경우 시리얼에 메시지 출력하기
  if (BTserial.available())
  {
    ctrlPage=BTserial.read();
    if(ctrlPage=='r'){
      Keyboard.press(KEY_RIGHT_ARROW);
      delay(100);
      Keyboard.releaseAll();
    }else if(ctrlPage=='l'){
      Keyboard.press(KEY_LEFT_ARROW);
      delay(100);
      Keyboard.releaseAll();
    }   
  }

  //컴퓨터에서 메시지를 보내는 경우 블루투스 모듈로 메시지 보내기
  if (Serial.available())
  {
    BTserial.write(Serial.read());
  }
}
