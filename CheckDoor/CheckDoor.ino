//변수설정
int TRIG = 2;
int ECHO = 3;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
  //set serial
  Serial.begin(9600);

  //set led
   pinMode(redPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
   pinMode(bluePin, OUTPUT); 
  
  //set ultrasonic
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);  
}

void loop() {
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

  if(distance <70){
    setColor(255, 0, 0); // red
    } else{
      setColor(0, 255, 0); // green
    }
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, 255-red);
  analogWrite(greenPin, 255-green);
  analogWrite(bluePin, 255-blue); 
}
