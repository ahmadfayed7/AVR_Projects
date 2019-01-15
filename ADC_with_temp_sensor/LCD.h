#include <util/delay.h>
#include <avr/io.h>
#define set_RS  PORTD= (PORTD |(1<<PD4))
#define clear_RS  PORTD=(PORTD &~(1<<PD4))
#define set_RW  PORTD=(PORTD |(1<<PD5))
#define clear_RW  PORTD=(PORTD &~(1<<PD5))
#define set_E  PORTD=(PORTD |(1<<PD6))
#define clear_E  PORTD=(PORTD &~(1<<PD6))
void LCD_data(unsigned char data);
void LCD_cmd(unsigned char cmd);
void LCD_intialize ();
void LCD_display_char (unsigned char a);
void LCD_display_string (unsigned char *a);
void LCD_loc(int raw ,int col);
void LCD_display_string_byloc (unsigned char *a,int raw ,int col);
void intrger_to_string (char *s ,int size,int i);
void LCD_int_to_string (int data);
