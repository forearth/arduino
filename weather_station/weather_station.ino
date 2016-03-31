//mlx9015 온도센서 변수 정의
unsigned char Re_buf[11],counter=0;
unsigned char sign=0;
float TO=0,TA=0;

//조도센서 상수 정의
const int cds = A1;
const int led = A0; 

//set rgb led
#include <Adafruit_NeoPixel.h>
#define PIN            2
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);  
  delay(1);    
  Serial.write(0XA5); 
  Serial.write(0X45);    
  Serial.write(0XEA);    
  
  //RGB LED setting
  pixels.begin(); // This initializes the NeoPixel library.  
}
 
void loop() {
  unsigned char i=0,sum=0;
  if(sign)
  {   
     sign=0;
     for(i=0;i<8;i++)
      sum+=Re_buf[i]; 
     if(sum==Re_buf[i] )       
     {           
           TO=(float)(Re_buf[4]<<8|Re_buf[5])/100;
           Serial.print("thingspeak:key=???&field1=");
           Serial.print(TO);  
           TA=(float)(Re_buf[6]<<8|Re_buf[7])/100;
           Serial.print("&field2=");
           Serial.print(TA);
             //조도센서값 가져오기
            int cdsValue=analogRead(cds);
            Serial.print("&field3=");
            Serial.print(cdsValue);
            Serial.println("[*]");
            if(TO>30)
            {
             //output RGB led
            pixels.setPixelColor(0, pixels.Color(0,215,0));
            pixels.show();
              if(cdsValue<100)
              {
                rainbow(20);
              }
            }
            else
            {
              pixels.setPixelColor(0, pixels.Color(0,0,215));
              pixels.show();
            }
            delay(200);
       }
    }
}

void serialEvent() {
  while (Serial.available()) {   
    Re_buf[counter]=(unsigned char)Serial.read();
    if(counter==0&&Re_buf[0]!=0x5A) return;          
    counter++;       
    if(counter==9)                
    {    
       counter=0;                 
       sign=1;
    }      
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
