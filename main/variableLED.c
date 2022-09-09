/*****************************************************************************
* variableLED.c - This program turns a LED at various brightness level with 2 switches.
* Circuit uses a Atmega328P chip. One switch turns on the LED at 12.5% duty cycle.
* Another switch turns on LED at 52 % duty cycle and both the buttons pressed
* together at 100% duty cycle

* Date          Author          Revision
* 04/14/2022    Anush Rathod    Initial write of code
* 04/18/2022	 Anush Rathod	  Using Lecture 18 slides to finalize the code
* 04/19/2022	 Anush Rathod	  Adding comments and debugging

* REFERENCES
* ECE 231 Spring 22, Lecture slides 17,18 Author - David McLaughlin
******************************************************************************/

#include <avr/io.h>
#include<util/delay.h>


int main(void){

   DDRD = 1<<DDD6; // initializing output for LED at D6
   PORTB = 1<<PB0| 1<<PB1; // initializing internal pullup resistor at B0 and B1

   TCCR0A = 0x81;
   TCCR0B = 0x03;

   while(1){

      if ((((PINB & (1<<PB0)) == 0)) && ((PINB & (1<<PB1)) != 0)){ // if SW1 is pressed and SW2 is not pressed

         OCR0A = 32; // duty cycle set at 12.5 %

      }

      if((((PINB & (1<<PB1)) == 0)) && ((PINB & (1<<PB0)) != 0)){ // if SW2 is pressed and SW1 is not pressed

         OCR0A = 134; // duty cycle set at 52%

      }

      if ((((PINB & (1<<PB1)) == 0)) && ((PINB & (1<<PB0)) == 0)){ // if both the switched are pressed

         OCR0A = 255; // duty cycle set at 100%

      }

      else{

         OCR0A = 0;

      }

   } 
}
