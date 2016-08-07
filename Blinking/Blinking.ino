/*
  Blinking
  Blinks three leds one at a time, or three leds simultaneously when 
  button connected to pin 2

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

const unsigned int pins[3]= {10,11,12};
const unsigned int togglePin = 2;
unsigned int nu=HIGH;

int teller;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  for (int i=0; i<3; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
  pinMode(togglePin, INPUT);
  teller = 1000;
  Serial.begin(9600);
  Serial.println("Hello world");
}

// knipper methode: all three leds at once, or one at a time
void knipper(int iAan, int iUit, bool iAll){
  if (iAll){
    for (int i=0; i<3; i++) {
      digitalWrite(pins[i],HIGH);
    }
    delay(iAan);
    for (int i=0; i<3; i++) {
      digitalWrite(pins[i],LOW);
    }
    delay(iUit);
  } else {
    digitalWrite(pins[0],HIGH);
    delay(iAan);
    for (int i=1; i<3; i++) {
      digitalWrite(pins[i-1],LOW);
      digitalWrite(pins[i], HIGH);
      delay(iAan);
    }
    digitalWrite(pins[2],LOW);
    delay(iUit);
  }
}


// the loop function runs over and over again forever
void loop() {
    nu=digitalRead(togglePin);
    knipper(teller, teller/4, nu);
  //teller = teller -50;
}
