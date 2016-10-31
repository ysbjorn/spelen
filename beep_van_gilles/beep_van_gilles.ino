void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  beep(50,50);
  beep(50,50);
  beep(50,50);

  tone(9, 50, 50);
  delay(1000);
}

void beep(unsigned int delayms, unsigned int delayafterms) {
  analogWrite(9,6);
  delay(delayms);
  analogWrite(9, 0);
  delay(delayafterms);
}


void loop() {
  // put your main code here, to run repeatedly:
  /* for (int i=0; i<3;i++) {
    beep(100+i*200,200-i*50);
   // beep(50);
   // beep(50);
    delay(300);
  }
  for (int i=2; i>=0;i--) {
    beep(100+i*200,200-i*50);
   // beep(50);
   // beep(50);
    delay(300);
  }
  delay(500);*/
}
