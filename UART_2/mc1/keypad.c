#include "keypad.h"
int keypad_3x4 ()
{
    DDRA =0xf0;
    int i,j,flag=0;
  for(i=0;i<3;i++)
  {
      DDRA =1<<(i+4);
       PORTA =~(1<<(i+4));
       for(j=0;j<4;j++)
          if(!(PINA& (1<<j)))
          {

             return matrix[i][j];

          }

  }

}
