/*
  ACE128D.cpp - Library for reading data from Bourns ACE-128 Absolute Encoder
  Created by Shaurya Pratap Singh, March 6, 2023.
  Released into the public domain.
*/

#include "ACE128D.h"
#include "ACE128D_87654321.h"
#define TOTAL_POS 128

// Constructor to initialize the object with digital pins of microcontroller connected with ACE-128
// Make sure to refer to the ACE-128 Dataset for Pin layout and connections
ACE128D::ACE128D(uint8_t dpin8, uint8_t dpin7, uint8_t dpin6, uint8_t dpin5, uint8_t dpin4, uint8_t dpin3, uint8_t dpin2, uint8_t dpin1)
{
  // Position Values based on ACE128 Dataset
	pin8 = dpin8;
	pin7 = dpin7;
	pin6 = dpin6;
	pin5 = dpin5;
	pin4 = dpin4;
	pin3 = dpin3;
	pin2 = dpin2;
	pin1 = dpin1;

	pinMode(pin8, INPUT_PULLUP);
	pinMode(pin7, INPUT_PULLUP);
	pinMode(pin6, INPUT_PULLUP);
	pinMode(pin5, INPUT_PULLUP);
	pinMode(pin4, INPUT_PULLUP);
	pinMode(pin3, INPUT_PULLUP);
	pinMode(pin2, INPUT_PULLUP);
	pinMode(pin1, INPUT_PULLUP);
}

// A standard binary to decimal coverter
int ACE128D::Binary2Dec(char *s) 
{
	int result = 0;
	while(*s) 
	{
		result <<= 1;
		if(*s++ == '1') result |= 1;
	}
	return result;
}

// Returns Binary/Gray Code read from digital pins 
String ACE128D::GetBinaryCode()
{
  char bin_chars[]  = { 
                        digitalRead(pin8) + '0',
                        digitalRead(pin7) + '0',
                        digitalRead(pin6) + '0',
                        digitalRead(pin5) + '0',
                        digitalRead(pin4) + '0',
                        digitalRead(pin3) + '0',
                        digitalRead(pin2) + '0',
                        digitalRead(pin1) + '0', '\0' 
                      };

  return String(bin_chars);
}

// Returns the Absolute positon based on the Dataset of ACE-128
// Muliturn == True (default): Includes all positons of ACE-128 (ACE-128 Supports two turns)
// Muliturn == False : Includes all positons in single turn then cycles the position
uint8_t ACE128D::GetAbsolutePos(bool multiturn)
{
  char bin_chars[9];
  strcpy(bin_chars, GetBinaryCode().c_str());
	uint8_t dec_index = Binary2Dec(bin_chars);

  if (multiturn == false && ACE128[dec_index] > ((TOTAL_POS/2)-1))
  {
    return ACE128[dec_index] - (TOTAL_POS/2);
  }
  
	return ACE128[dec_index];
}

// Returns Absolute postion with Multiturn Enabled 
uint8_t ACE128D::GetAbsolutePos()
{
  return GetAbsolutePos(true);
}

//Returns Absolute Angle (Multiturn Off only)
float ACE128D::GetAbsoluteAngle()
{
  return GetAbsolutePos(false)*5.625;   
}


