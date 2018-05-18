#define TRIG 2
#define ECHO 3

void setup() {
 //set serial
 Serial.begin(9600);
 
 //set ultrasonic
 pinMode(TRIG, OUTPUT);
 pinMode(ECHO, INPUT); 
}

void loop() {
 digitalWrite(TRIG, HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG, LOW);
 long distance=pulseIn(ECHO, HIGH)*340/2/10000;  //pulseIn 명령어를 통해 Echo핀에 초음파가 들어오는 시간계산
 Serial.println(distance);
 delay(50); 
}
