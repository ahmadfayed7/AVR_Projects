
#include "LCD.h"
void intialize_ADC ()
{

  ADMUX = 0;;
  ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0) ;

}
unsigned int ADC_read()
{
ADMUX &= 0xE0;
ADMUX = 0xE0|2;
ADCSRA |=(1<<ADSC);
while(!(ADCSRA&(1<<ADIF)));
ADCSRA |=1<<ADIF;
return ADC;
}

int main(void)
{
   DDRC =0xff;
   DDRD =0xff;
     DDRA &=~(1<<PA2);
   unsigned int temp;
  LCD_intialize ();
  intialize_ADC ();
    while(1)
    {
        LCD_loc(1,1);
       temp =ADC_read();
       temp = temp/256;

       LCD_int_to_string(temp);
    }

    return 0;
}
