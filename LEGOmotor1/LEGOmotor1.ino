
const unsigned int controlPin1A = 2;
const unsigned int controlPin2A = 5;
const unsigned int ENablePin = 9;
unsigned int motorSpeed = 0;
unsigned int motorDirection = 1;


void setup() {
  // put your setup code here, to run once:

pinMode(controlPin1A, OUTPUT);
pinMode(controlPin2A, OUTPUT);
pinMode(ENablePin, OUTPUT);
//digitalWrite(ENablePin, LOW);
analogWrite(ENablePin, 0);
motorSpeed = 100;
}

void loop() {
  // put your main code here, to run repeatedly:



analogWrite(ENablePin, motorSpeed);

digitalWrite(controlPin1A, HIGH);
digitalWrite(controlPin2A, LOW);


delay(5000);

analogWrite(ENablePin, motorSpeed);

digitalWrite(controlPin1A, LOW);
digitalWrite(controlPin2A, HIGH);

delay(5000);



/*
for (int i = 0; i <256; i++)
  {
analogWrite(ENablePin, i);
digitalWrite(controlPin1A, HIGH);
digitalWrite(controlPin2A, LOW);
delay(100);
  }
*/











}
