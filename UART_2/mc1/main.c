/*
 */


#include "keypad.h"

    void UART_init()
{

  UCSRA |=(1<<U2X);
  UCSRB = (1<<RXEN) | (1<<TXEN);
  UCSRC |=(1<<URSEL) | (1<<UCSZ0) |(1<<UCSZ1);
  UBRRL= 12;
  UBRRH= 12;
}
void send_byte(unsigned char data)
{
 UDR = data;
 while(!(UCSRA&(1<<TXC))) ;

UCSRA |=1<<TXC;

}
int main(void)
{

  unsigned char data;
   UART_init();
    while(1)
    {
     data = keypad_3x4() +'0';
    send_byte(data);
    _delay_ms(500);

    }

    return 0;
}
