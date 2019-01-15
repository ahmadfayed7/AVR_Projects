#include "LCD.h"
void LCD_data(unsigned char data)
{
  set_RS;
  clear_RW;
  _delay_ms(1);
  set_E;
  _delay_ms(1);
  PORTC =data;
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
   PORTC =cmd;
  _delay_ms(1);
  clear_E;
  _delay_ms(1);
}
void LCD_intialize ()
{
    LCD_cmd(0x38);  //2 lines
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
void LCD_loc(int raw ,int col)
{
 switch(raw)
    {
    case 1 :
        {
            LCD_cmd(col | 0x80);

            break;
        }
     case 2 :
        {
            LCD_cmd((col+0x40) | 0x80);
            break;
        }
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
void intrger_to_string (char *s ,int size,int i)
{
    int rem;
     int len =0;
     int n = i;
     int k=0;
     while(i!=0)
     {
         len++;
         n=n/10;
     }
for(k=0;k<len;k++)
{
  rem = i%10;
  i=i/10;
  s[len - (k+1)]=rem + '0';
}
s[len]='\0';
}
void LCD_int_to_string (int data)
{

     char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */

   LCD_display_string(buff);
}
