
const unsigned int controlPin1A = 8;
const unsigned int controlPin2A = 10;
const unsigned int ENablePin = 9;


const bool links = false; 
const bool rechts = true;

void setup() 
{
  // put your setup code here, to run once:

  pinMode(controlPin1A, OUTPUT);
  pinMode(controlPin2A, OUTPUT);
  pinMode(ENablePin, OUTPUT);
  digitalWrite(ENablePin, LOW);//digitalWrite on turns the ENable pin simply off
  //analogWrite(ENablePin, 0);//analogWrite on a digital pin sends out a pulse
  setMotorSpeed(0);
}

void setMotorSpeed(int iMotorSpeed) 
{
  if (iMotorSpeed > 255) iMotorSpeed = 255;
  if (iMotorSpeed < 0) iMotorSpeed = 0;
  analogWrite(ENablePin, iMotorSpeed);
}

void setMotorDirection(bool iMotorDirection)
{
  if (iMotorDirection == rechts) 
  {
    digitalWrite(controlPin1A, HIGH);
    digitalWrite(controlPin2A, LOW);
  } else 
  {
    digitalWrite(controlPin1A, LOW);
    digitalWrite(controlPin2A, HIGH);
  }
}

void loop() 
{
  // put your main code here, to run repeatedly.
  setMotorSpeed(100);
  setMotorDirection(rechts);
  delay(5000);

  setMotorSpeed(255);
  setMotorDirection(links);
  delay(5000);


  /*

  digitalWrite(controlPin2A, LOW);
  digitalWrite(controlPin1A, HIGH);
  for (int i = 0; i <256; i++)
    {
    
      analogWrite(ENablePin, i);

      delay(100);
    }

  */

}




