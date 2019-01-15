/*
 */

#include <avr/io.h>

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
char recieve_byte()
{
UCSRA |= (1<<RXC);
UCSRA &= ~(1<<TXC);
while(!(UCSRA&(1<<RXC)));
  return UDR;
}
void UART_send_String(unsigned char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        send_byte(str[i]);
        i++;
    }
}
void UART_receiveString(unsigned char *Str)
{
	unsigned char i = 0;
	Str[i] = recieve_byte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = recieve_byte();
	}
	Str[i] = '\0';
}

int main(void)
{

    // Insert code
    UART_init();
    unsigned char data;
    while(1)
    {
        data= recieve_byte();
        send_byte(data);

    }

    return 0;
}
