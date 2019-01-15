/*
 */
#define set_RS  PORTD= (PORTD |(1<<PD4))
#define clear_RS  PORTD=(PORTD &~(1<<PD4))
#define set_RW  PORTD=(PORTD |(1<<PD5))
#define clear_RW  PORTD=(PORTD &~(1<<PD5))
#define set_E  PORTD=(PORTD |(1<<PD6))
#define clear_E  PORTD=(PORTD &~(1<<PD6))
#include <avr/io.h>
#include <util/delay.h>
void LCD_data(unsigned char data)
{
  set_RS;
  clear_RW;
  _delay_ms(1);
  set_E;
  _delay_ms(1);
  PORTC =data&0xf0;
  _delay_ms(1);
  clear_E ;
    _delay_ms(1);
    set_E;
     _delay_ms(1);
   PORTC =(data<<4)&0xf0;
    _delay_ms(1);
  clear_E;
  _delay_ms(1);
}
void LCD_cmd(unsigned char cmd)
{
  clear_RS;
  clear_RW;
  _delay_ms(1);
  set_E;
  _delay_ms(1);
   PORTC =cmd&0xf0;
  _delay_ms(1);
  clear_E ;
    _delay_ms(1);
    set_E;
     _delay_ms(1);
   PORTC =(cmd<<4)&0xf0;
  _delay_ms(1);
  clear_E;
  _delay_ms(1);
}
void LCD_intialize ()
{
   LCD_cmd(0x02);  //2 lines
    LCD_cmd(0x28);  //2 lines
   LCD_cmd(0x01);   //clear
   LCD_cmd(0x0c);   //cursor off

}
void LCD_display_char (unsigned char a)
{
     LCD_data(a);
}
void LCD_display_string (unsigned char *a)
{
    int i=0; ;
    while(a[i]!='\0')
    {
       LCD_data(a[i]);
        i++;
    }
}
void LCD_display_string_byloc (unsigned char *a,int raw ,int col)
{
    switch(raw)
    {
    case 1 :
        {
            LCD_cmd(col | 0x80);
            LCD_display_string(a);
            break;
        }
     case 2 :
        {
            LCD_cmd((col+0x40) | 0x80);
            LCD_display_string(a);
            break;
        }
    }
}
int main(void)
{
   DDRC =0xff;
   DDRD =0xff;
  LCD_intialize ();
   LCD_display_string_byloc("ahmad",2,5);
    while(1)
    ;

    return 0;
}
