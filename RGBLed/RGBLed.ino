#define RED 9
#define GREEN 10
#define BLUE 11
 
void setup()
{
 pinMode(RED, OUTPUT);
 pinMode(GREEN, OUTPUT);
 pinMode(BLUE, OUTPUT); 
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
  analogWrite(RED, 255-red);
  analogWrite(GREEN, 255-green);
  analogWrite(BLUE, 255-blue); 
}
