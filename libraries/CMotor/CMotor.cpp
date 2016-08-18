#include <Arduino.h>
#include <CMotor.h>



const bool CMotor::links = false; 
const bool CMotor::rechts = true;


CMotor::CMotor(const unsigned int iControlPin1A, const unsigned int iControlPin2A, const unsigned int iENablePin)
{
  controlPin1A = iControlPin1A;
  controlPin2A = iControlPin2A;
  ENablePin = iENablePin;
}

void CMotor::setup()
{
  pinMode(controlPin1A, OUTPUT);
  pinMode(controlPin2A, OUTPUT);
  pinMode(ENablePin, OUTPUT);
  digitalWrite(ENablePin, LOW);
}

void CMotor::setMotorSpeed(int iMotorSpeed) 
{
  if (iMotorSpeed > 255) iMotorSpeed = 255;
  if (iMotorSpeed < 0) iMotorSpeed = 0;
  analogWrite(ENablePin, iMotorSpeed);
}

void CMotor::setMotorDirection(bool iMotorDirection)
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

