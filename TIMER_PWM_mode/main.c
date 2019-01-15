/*
 */

#include <avr/io.h>
  void PWM_init ()
    {
        TCNT0 =0;
        OCR0 =128;
        TCCR0 =TCCR0| (1<<WGM00) | (1<<COM01)|(1<<CS01) |(1<<WGM01);
         DDRB |=1<<PB3;

    }
int main(void)
{

  PWM_init ();
    while(1)
    {

    }

    return 0;
}
