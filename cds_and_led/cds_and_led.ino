#define LIGHT_PIN A0
#define LED 3

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);  
}
void loop()
{
  int val = 0;
  val = analogRead(LIGHT_PIN); 
  Serial.println(val);
  delay(1000);

  if(val>400){
    digitalWrite(LED, LOW);
  }else{
    digitalWrite(LED, HIGH);
  }  
}

