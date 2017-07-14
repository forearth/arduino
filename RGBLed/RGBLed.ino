int redPin = 9;
int greenPin = 10;
int bluePin = 11;
 
void setup()
{
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT); 
}
 
void loop()
{
  setColor(255, 0, 0); // red
  delay(2000);
  setColor(0, 255, 0); //green
  delay(2000);
  setColor(0, 0, 255); // blue
  delay(2000);
}
 
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, 255-red);
  analogWrite(greenPin, 255-green);
  analogWrite(bluePin, 255-blue); 
}
