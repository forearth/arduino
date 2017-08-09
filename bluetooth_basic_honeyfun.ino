#include <SoftwareSerial.h>
SoftwareSerial BTserial(3, 5); // TX | RX
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Enter AT commands:");
 
    // HC-06 default serial speed is 9600
    BTserial.begin(9600);  
}
 
void loop()
{ 
    // 블루투스 모듈로 부터 메시지가 오는 경우 시리얼에 메시지 출력하기
    if (BTserial.available())
    {  
        Serial.write(BTserial.read());
    }
 
    //컴퓨터에서 메시지를 보내는 경우 블루투스 모듈로 메시지 보내기
    if (Serial.available())
    {
        BTserial.write(Serial.read());
    }
}
