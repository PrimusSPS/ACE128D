/*
  ACE128D.h - Library for reading data from Bourns ACE-128 Absolute Encoder
  Created by Shaurya Pratap Singh, March 6, 2023.
  Released into the public domain.
*/

#ifndef ACE128D_h
#define ACE128D_h

#include<Arduino.h>

class ACE128D
{
private:
  uint8_t pin8;
  uint8_t pin7;
  uint8_t pin6;
  uint8_t pin5;
  uint8_t pin4;
  uint8_t pin3;
  uint8_t pin2;
  uint8_t pin1;  

public:
	ACE128D(uint8_t dpin8, uint8_t dpin7, uint8_t dpin6, uint8_t dpin5, uint8_t dpin4, uint8_t dpin3, uint8_t dpin2, uint8_t dpin1);
  
  String GetBinaryCode();
  int Binary2Dec(char*);
  uint8_t GetAbsolutePos();
  uint8_t GetAbsolutePos(bool multiturn);   // Get absolute position without multiturn
  float GetAbsoluteAngle();  
	// ~ACE128D();
};

#endif
