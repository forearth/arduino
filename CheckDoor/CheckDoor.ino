#include <Adafruit_NeoPixel.h>

#define lightPin A0
#define ledVccPin 8
#define ledDataPin 9
#define numPixel 1
#define TRIG 2
#define ECHO 3

Adafruit_NeoPixel pixels=Adafruit_NeoPixel(numPixel, ledDataPin, NEO_GRB+NEO_KHZ800);

void setup() {
  //set serial
  Serial.begin(9600);

  //set led
  pinMode(ledVccPin, OUTPUT);
  pinMode(ledDataPin, OUTPUT);
  pixels.begin();
  
  //set ultrasonic
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);  
}

void loop() {
  //set light sensor scope
  int light_value;
  light_value=map(analogRead(lightPin), 0, 1023, 0, 255);
  Serial.println(light_value); 

  //화장실에 불이 켜지면, 초음파 센서를 작동해서 아이가 있는지 확인  
      if(light_value > 200){
    //초음파 발사 코드
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    //pulseIn 명령어를 통해 Echo핀에 초음파가 들어오는 시간계산
    //pulseIn에서 반환된 값에 58.2를 나눈이유는 시간을 cm로 변화하기 위해서임
    //음파속도가 340m/s 정도임
    long distance=pulseIn(ECHO, HIGH)/58.2;

    if(distance < 50){
      digitalWrite(ledVccPin, HIGH);    
      //set led color
      pixels.setPixelColor(0, pixels.Color(0, 200, 0));
      pixels.show();
    } else{
      digitalWrite(ledVccPin, HIGH);    
      //set led color
      pixels.setPixelColor(0, pixels.Color(250, 0, 0));
      pixels.show();
    }
  } else{
    digitalWrite(ledVccPin, LOW);    
  }
}
