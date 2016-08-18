#ifndef CMotor_H
#define CMotor_H

#include <Arduino.h>

class CMotor {
  public:
  CMotor(const unsigned int iControlPin1A, const unsigned int iControlPin2A, const unsigned int iENablePin);
  void setup();
  void setMotorDirection(bool iMotorDirection);
  void setMotorSpeed(int iMotorSpeed);

static const bool links; 
static const bool rechts;
 
private:
  unsigned int controlPin1A;
  unsigned int controlPin2A;
  unsigned int ENablePin;
};



#endif

