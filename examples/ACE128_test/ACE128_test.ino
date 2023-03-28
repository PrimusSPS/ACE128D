#include <ACE128D.h>
ACE128D encoder(2,3,4,5,6,7,8,9);
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  Serial.print(" Binary: ");
  Serial.print(encoder.GetBinaryCode());
  Serial.print(" Position: ");
  Serial.print(encoder.GetAbsolutePos());
  Serial.print(" Position without ML: ");
  Serial.print(encoder.GetAbsolutePos(false));
  Serial.print(" Angular Position: ");
  Serial.println(encoder.GetAbsoluteAngle());
}
