/*
 */

#include <avr/io.h>
int keypad_num [3][4]={
   { 1, 4, 7} ,   /*  initializers for row indexed by 0 */
   {2, 5, 8} ,   /*  initializers for row indexed by 1 */
   {3,6, 9} ,  /*  initializers for row indexed by 2 */
   {11,0,12}
};
int num =0;
void keypad_3x4 ()
{ int i,j,flag=0;
  for(i=0;i<3;i++)
  {
      DDRA =1<<(i+4);
       PORTA =~(1<<(i+4));
       for(j=0;j<4;j++)
          if(!(PINA& (1<<j)))
          {

             num= ((3*j)+i+1);

          }

  }

}

int main(void)
{

 DDRC = 0x0f;
PORTC =0;

    while(1)
    {
         keypad_3x4 ();
        if((num >= 0) && (num <= 9))
		{
			 PORTC = num;
		}
    }

    return 0;
}
