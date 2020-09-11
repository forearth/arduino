//블루투스 모듈 설정
#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11); // TX | RX

#define LED 13

void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");

  // HC-06 default serial speed is 9600
  BTserial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  //led 상태변수
  char status;
  // 블루투스 모듈로 부터 메시지가 오는 경우 시리얼에 메시지 출력하기
  if (BTserial.available())
  {
    status = BTserial.read();
    Serial.print(status);

    if (status == '1')
    {
      digitalWrite(LED, HIGH);
    } else if (status == '0') {
      digitalWrite(LED, LOW);
    }
  }

  //컴퓨터에서 메시지를 보내는 경우 블루투스 모듈로 메시지 보내기
  if (Serial.available())
  {
    BTserial.write(Serial.read());
  }
}
