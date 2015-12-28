const int dPin = 13;  //digitalWrite Pin(blink led) 
const int aPin = 11;  //analogWrite Pin(fading led)

void setup()
{
  blink_setup();
  fading_setup();
}

void loop()
{
  blink_loop();
  fading_loop();
}

//set variables for blink led
int ledState = LOW; 
long previousMillis = 0;
long interval=1000;

void blink_setup()
{
   pinMode(dPin, OUTPUT); 
}

void blink_loop()
{
  unsigned long currentMillis=millis();
  
  if(currentMillis-previousMillis>=interval){
   previousMillis=currentMillis;
  
  if(ledState==LOW)
     ledState=HIGH;
  else
     ledState=LOW;
  digitalWrite(dPin, ledState);     
  }
}

//set variables for fading led
int fadeValue=0;
int fadeDir=1;
long fading_previousMillis=0;
long fading_interval=30;

void fading_setup()
{
  
}

void fading_loop()
{
  unsigned long currentMillis=millis();

  if(currentMillis-fading_previousMillis>=fading_interval)
  {
  fading_previousMillis=currentMillis;

  if(fadeDir==1){
	if(fadeValue<=255){
		fadeValue+=5;
		if(fadeValue>255){
			fadeValue=255;
			fadeDir=0;
			}
		}  
	 } else{
	 if(fadeValue>=0){
		fadeValue-=5;
		if(fadeValue<0){
		fadeValue=0;
		fadeDir=1;
		}
	   }	 
	 }
	 analogWrite(aPin, fadeValue);
  }
}

