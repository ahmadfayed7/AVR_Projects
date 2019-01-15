#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
ISR (INT2_vect )
{
 static unsigned char num =0;
 if (num==9)
    num=0;
 else
    num++;
 PORTC =(PORTC&0xF0) |(num &0x0F);
}
void interrupt_init()
{
    SREG &=~(1<<7);
    DDRB &=~ (1<<PB2);
    GICR |= (1<<INT2);
   MCUCSR |=(1<<ISC2);
     SREG |=(1<<7);
}
int main(void)
{

   interrupt_init();
   DDRC =0x0F;
   PORTC =0;
    while(1)
    {
    }

    return 0;
}
