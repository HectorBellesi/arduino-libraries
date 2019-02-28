/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef TMRM5_h
#define TMRM5_h
 
#include "Arduino.h"
#include "avr/io.h"

class TMRM5
{
  public:
    TMRM5(int pin);
    void SetupTMR5();
    unsigned long ReadTMR5();
  private:
    int _pin;
};
 
#endif