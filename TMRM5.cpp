/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
 
#include "Arduino.h"
#include "TMRM5.h"
#include "avr/io.h"

extern unsigned char ucDesbordamientos;

TMRM5::TMRM5(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}
 
void TMRM5::SetupTMR5()
{
noInterrupts();
//config & init timer 5
TCCR5A=0;
TCCR5B=0;
TCNT5H=0;
TCNT5L=0;
//external clock on terminal 47 of arduino Mega 2560
//clock on rising edge.
TCCR5B |= (1 << CS50)|(1 << CS51)|(1 << CS52);
TIMSK5 = 0;
TIMSK5 |= (1 << TOIE5);
TIFR5=0;
TIFR5 |= (0 << TOV5);
interrupts();
}

//function to read the counter (timer 5)
unsigned long TMRM5::ReadTMR5 ()
{
unsigned long ulAcarreo;  
unsigned long ulConteoT5;  
ulConteoT5=(unsigned long)TCNT5;
ulAcarreo=(unsigned long)ucDesbordamientos;
ucDesbordamientos=0;
ulAcarreo=ulAcarreo*65536;
ulConteoT5=ulConteoT5 + ulAcarreo;
TCNT5=0;
return ulConteoT5;
}
