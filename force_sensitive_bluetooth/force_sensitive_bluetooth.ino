//set to force_sensitive_resistor's pin no
int FSR_Pin = A0; //analog pin 0

void setup(){
  Serial.begin(9600);
}

void loop(){
  
  int FSRReading = analogRead(FSR_Pin); 
  //set to send the data for thingspeak
  //need to modify key and field value
  Serial.print("thingspeak:key=???&field1=");
  Serial.print(FSRReading);
  Serial.println("[*]");

  delay(1000); //just here to slow down the output for easier reading
}
