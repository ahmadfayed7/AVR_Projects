/*
 */

#include <avr/io.h>
#include <util/delay.h>
void master_init()
{
    DDRB  |= (1<<PB4)|(1<<PB5)|(1<<PB7);
    DDRB  &=~(1<<PB6);
    SPCR |=(1<<MSTR)|(1<<SPE);
}
void master_send(unsigned char data)
{
    SPDR = data;
    while(!(SPSR&(1<<SPIF)));
}
unsigned char master_send_rx(unsigned char data)
{
    SPDR = data;
    while(!(SPSR&(1<<SPIF)));
    return SPDR ;
}
int main(void)
{
   master_init();
    DDRA =0;
   DDRC=0xff;
   unsigned char data;

    while(1)
    {
        if(PINA&(1<<PA0))

        {
            data =master_send_rx(1);
        if(data==1)
            PORTC=0xff;
        else
            PORTC=0;
         _delay_ms(500);
        }
        else
         {
               data =master_send_rx(0);
        if(data==1)
            PORTC=0xff;
        else
            PORTC=0;
         _delay_ms(500);
         }

    }

    return 0;
}
