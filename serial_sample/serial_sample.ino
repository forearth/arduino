//시작할 때 한번실행. 초기화 파트
void setup() {
  Serial.begin(9600);
}

//반복실행 파트
void loop() {
  Serial.println("안녕하세요. 시작합니다.");
  for(int i=0; i<=3; i++){
    Serial.print("hello");
    Serial.println(i);
    delay(1000);    
  }  
}
