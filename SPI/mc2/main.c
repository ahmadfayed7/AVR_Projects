/*
 */

#include <avr/io.h>
#include <util/delay.h>
void slave_init()
{
    DDRB &= ~(1<<PB4)&~(1<<PB5)&~(1<<PB7);
    DDRB |=(1<<PB6);
    SPCR |=(1<<SPE);
}
unsigned char slave_recieve()
{
    while(!(SPSR&(1<<SPIF)));
    return SPDR;
}
unsigned char slave_send_rx(unsigned char data)
{
    SPDR =data;
    while(!(SPSR&(1<<SPIF)));
    return SPDR;
}
int main(void)
{
   unsigned char data;
    DDRC=0xff;
     DDRA =0;
  slave_init();
    while(1)
    {


        if(PINA&(1<<PA0))

        {
            data =slave_send_rx(1);
        if(data==1)
            PORTC=0xff;
        else
            PORTC=0;
         _delay_ms(500);
        }
        else
         {
               data =slave_send_rx(0);
        if(data==1)
            PORTC=0xff;
        else
            PORTC=0;
         _delay_ms(500);
         }

    }

    return 0;
}
