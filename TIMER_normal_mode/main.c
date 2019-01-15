/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>
ISR(TIMER0_OVF_vect)
{
   static int times =0;
   times++;
   if(times==2)
   {
       times=0;
       PORTC ^=1<<PC0;
   }
}
void timer0_init()
{   SREG |=(1<<7);
    TCNT0 =0;
    TCCR0 = TCCR0 | (1<<CS00) | (1<<CS02) & ~(1<<CS01);  // FCPU/1024;
    TCCR0 |= (1<<FOC0);
    TCCR0 =TCCR0 & ~(1<<WGM01) &~ (1<<WGM00);  //normal mode
    TIMSK |=1<<TOIE0;

}
int main(void)
{
    DDRC |= 1<<PC0;
    PORTC &= ~(1<<PC0);
    timer0_init();

    while(1)
    {

    }

    return 0;
}
