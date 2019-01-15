/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>
ISR(TIMER0_COMP_vect)
 {
    PORTC ^=1<<PC0;

 }
  void Timer_init ()
  {
     TCNT0 = 0; //timer initial value
	OCR0  = 128; //compare value
	TIMSK |= (1<<OCIE0); //enable compare interrupt
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);

  }
int main(void)
{
    DDRC |= 1<<PC0;
    PORTC &= ~(1<<PC0);
    SREG |=1<<7;
   Timer_init();


    while(1)
    {

    }

    return 0;
}
