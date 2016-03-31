//초음파센서 핀번호
int trig = 2;
int echo = 3;

//LED 핀번호
int redled=7;

void setup()
{
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(redled, OUTPUT);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int distance = pulseIn(echo, HIGH) * 17 / 1000;
  Serial.print("thingspeak:key=???&field1=");
  Serial.print(distance);
  Serial.println("[*]");

  if(distance<100){
    digitalWrite(redled, HIGH);
  }
  else{
    digitalWrite(redled, LOW);
  }  
  delay(1000);
}

