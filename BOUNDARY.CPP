// boundary fill algo
#include<dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void boundary_fill(int ,int,int,int );
void boundary_fill(int x,int y,int b,int f )
{
if( getpixel(x,y)!=b && getpixel(x,y)!=f)
{
  putpixel(x,y,f);
  delay(2);
      boundary_fill(x+1,y,b,f);
      boundary_fill(x-1,y,b,f);
      boundary_fill(x,y+1,b,f);
      boundary_fill(x,y-1,b,f);
 }
}
int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   setcolor(7);
   circle(100,100,30);
   boundary_fill(100,100,7,2);
   rectangle(200,200,250,250);
   boundary_fill(205,205,7,6);
   getch();
   closegraph();
   return 0;
}

