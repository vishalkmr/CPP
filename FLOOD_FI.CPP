#include<dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void flood_fill(int ,int,int,int );
void flood_fill(int x,int y,int o,int n )
{
if( getpixel(x,y)==o)
{

  putpixel(x,y,n);
  delay(1);
      flood_fill(x+1,y,o,n);
      flood_fill(x-1,y,o,n);
      flood_fill(x,y+1,o,n);
      flood_fill(x,y-1,o,n);
 }
}
int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   setcolor(7);
   rectangle(100,100,150,150);
   flood_fill(101,101,0,2);
   getch();
   closegraph();
   return 0;
}

