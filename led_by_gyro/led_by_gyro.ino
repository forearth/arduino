
void setup()
{

}

void loop()
{
  int lightValue=map(analogRead(A0), 0, 1023, 0, 255);
  Serial.print(lightValue);
}

