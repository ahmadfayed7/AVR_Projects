#include <avr/io.h>

int main(void)
{
  DDRA  &= ~(1<<PA0) & ~(1<<PA1) &~(1<<PA2);
  DDRC  |= (1<<PC0) | (1<<PC1);

    while(1)
    {
         if(PINA |(1<<PA0))
         {
             PORTC |= (1<<PC0);
             PORTC &= ~(1<<PC1);
         }
         if(PINA |(1<<PA1))
         {
            PORTC |= (1<<PC1);
             PORTC &= ~(1<<PC0);
         }
         if(PINA |(1<<PA2))
         {
              PORTC &= ~(1<<PC0);
             PORTC &= ~(1<<PC1);
         }

    }

    return 0;
}
