/*
 */


#include "LCD.h"
void UART_init()
{

  UCSRA |=(1<<U2X);
  UCSRB = (1<<RXEN) | (1<<TXEN);
  UCSRC |=(1<<URSEL) | (1<<UCSZ0) |(1<<UCSZ1);
  UBRRL= 12;
  UBRRH= 12;
}

char recieve_byte()
{
UCSRA |= (1<<RXC);
UCSRA &= ~(1<<TXC);
while(!(UCSRA&(1<<RXC)));
  return UDR;
}
int main(void)
{

    unsigned char data;
    DDRD =(1<<PD4)|(1<<PD5)|(1<<PD6);
     DDRC =0xff;
     LCD_intialize();
    UART_init();
    while(1)
    {
         data =recieve_byte();
         LCD_loc(1,1);
        LCD_display_char(data);
        //LCD_display_char('a');
    }

    return 0;
}
