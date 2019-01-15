/*
 * Exercise1.c
 *
 * Created: 11/22/2013 2:17:05 PM
 * Author: Mohamed Tarek
 */


#include <avr/io.h>
#include <util/delay.h> // to use delay function

int main(void)
{   //unsigned char arr[]={};
     unsigned char i=0;
	DDRD = DDRD | (1<<PD0) | (1<<PD1) |(1<<PD2) |(1<<PD3)  ;
	//DDRC |= 0x0F;
    DDRA = DDRA  & (~(1<<PA0)) & (~(1<<PA1));
    while(1)
    {
        if (PINA &(1<<PA0))
        {
            if(i<9)
                i++;
            else
                i=0;
           PORTD = (PORTD & 0xF0) |  (i&0x0F);
            while(PINA &(1<<PA0));

        }
        else if (PINA &(1<<PA1))
        {
            i--;
           PORTD = (PORTD & 0xF0) |  (i&0x0F);
            while(PINA &(1<<PA1));

        }
    }
}
