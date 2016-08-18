//#include <IRremote.h>
#include <CUltrasone.h>
#include <CMotor.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(13, 12, 3, 4, 5, 6);
uint8_t deReceivePin = 11;
uint8_t deSendPin = 2;
CUltrasone deUSsensor(deSendPin, deReceivePin, 4000.);
CMotor deMotor(8, 10, 9);
float deDistance = 0;

//unsigned int IRpin = ;
//IRrecv deIR(IRpin);
//decode_results deResults;
long deUStime = 0;
long deTimeBetweenUS=150;
//long deIRtime = 0;

void setup() {
  // put your setup code here, to run once:
  //setupUSsensor();
  deUSsensor.setup();
  deMotor.setup();
  deMotor.setMotorDirection(CMotor::links);
  deMotor.setMotorSpeed(150);
  lcd.begin(16,2);
  lcd.print("Afstand tot mij:");
  //deIR.enableIRIn();
  deUStime = millis();
  //deIRtime = millis();
  Serial.begin(9600);
}

void setupUSsensor() {
  pinMode(deReceivePin, INPUT);
  pinMode(deSendPin, OUTPUT);
}

float getDistance() {
  //send pulse
  digitalWrite(deSendPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(deSendPin, LOW);  
  
  // receive pulse
  unsigned int tmpEchoTime; // alleen positieve getallen nodig => unsigned
  tmpEchoTime = pulseIn(deReceivePin, HIGH);
  return (tmpEchoTime/2.0)*0.3435;
}

float median(int n, float x[]) {
    float temp;
    int i, j;
    // the following two loops sort the array x in ascending order
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(x[j] < x[i]) {
                // swap elements
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    if(n%2==0) {
        // if there is an even number of elements, return mean of the two elements in the middle
        return((x[n/2] + x[n/2 - 1]) / 2.0);
    } else {
        // else return the element in the middle
        return x[n/2];
    }
}

float getMedianDistance(const int iNo){
  float tmpDistances[iNo];
  for (int i=0; i<iNo; i++) {
    tmpDistances[i]=getDistance();
  }
  return median(iNo, tmpDistances);
}

void displayDistance(float tmpDistance){
  Serial.println(tmpDistance);
  lcd.clear();
  lcd.print("Afstand tot mij:");
  lcd.setCursor(0, 1);
  lcd.print("  ");
  lcd.print(round(tmpDistance));
  lcd.print(" mm");
}

void loop() {
  // put your main code here, to run repeatedly:

  long tmpUSlapse = millis()-deUStime;
  if (tmpUSlapse/deTimeBetweenUS == tmpUSlapse/(float)(deTimeBetweenUS)) {
    float tmpDistance=deUSsensor.getMedianDistance(5);
    if (tmpDistance<60) {
      deMotor.setMotorSpeed(0);
    } else if (tmpDistance>100) {
      deMotor.setMotorSpeed(150);
    }
    displayDistance(tmpDistance);
  }
  
  //long tmpDelay = millis()-deTime;
  //long tmpIRdelay = millis() - deIRtime;
  //if (tmpDelay/1000. == tmpDelay/1000) {
  /*  if (deUSsensor.getDistance(deDistance))
    {
      Serial.println(deDistance);
      lcd.clear();
      lcd.print("Afstand tot mij:");
      lcd.setCursor(0, 1);
      lcd.print("  ");
      lcd.print(round(deDistance));
      lcd.print(" mm");
    } else {
      lcd.setCursor(0, 1);
      lcd.print("problem");
      lcd.print(tmpDelay/1000);
    }*/
  //} 
  /*else {
    if (tmpIRdelay/500.==tmpIRdelay/500 && deIR.decode(&deResults)) {
      handleIR();//deResults is defined globally
      deIR.resume();
    }
  }*/
}

/*void handleIR() // takes action based on IR code received

// describing Car MP3 IR codes 

{

  switch(deResults.value)

  {

  case 0xFFA25D:  
    Serial.println(" CH-            "); 
    break;

  case 0xFF629D:  
    Serial.println(" CH             "); 
    break;

  case 0xFFE21D:  
    Serial.println(" CH+            "); 
    break;

  case 0xFF22DD:  
    Serial.println(" PREV           "); 
    break;

  case 0xFF02FD:  
    Serial.println(" NEXT           "); 
    break;

  case 0xFFC23D:  
    Serial.println(" PLAY/PAUSE     "); 
    break;

  case 0xFFE01F:  
    Serial.println(" VOL-           "); 
    break;

  case 0xFFA857:  
    Serial.println(" VOL+           "); 
    break;

  case 0xFF906F:  
    Serial.println(" EQ             "); 
    break;

  case 0xFF6897:  
    Serial.println(" 0              "); 
    break;

  case 0xFF9867:  
    Serial.println(" 100+           "); 
    break;

  case 0xFFB04F:  
    Serial.println(" 200+           "); 
    break;

  case 0xFF30CF:  
    Serial.println(" 1              "); 
    break;

  case 0xFF18E7:  
    Serial.println(" 2              "); 
    break;

  case 0xFF7A85:  
    Serial.println(" 3              "); 
    break;

  case 0xFF10EF:  
    Serial.println(" 4              "); 
    break;

  case 0xFF38C7:  
    Serial.println(" 5              "); 
    break;

  case 0xFF5AA5:  
    Serial.println(" 6              "); 
    break;

  case 0xFF42BD:  
    Serial.println(" 7              "); 
    break;

  case 0xFF4AB5:  
    Serial.println(" 8              "); 
    break;

  case 0xFF52AD:  
    Serial.println(" 9              "); 
    break;

  default: 
    Serial.println(" other button   ");

  }
}*/
