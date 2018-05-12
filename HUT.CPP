#include<dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main()
{
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
  for(int i=1;i<20;i++)
  {
   setcolor(i);
    rectangle(150+i,150+i,250+i,250+i);
   rectangle(250+i,150+i,400+i,250+i);
   rectangle(180+i,200+i,220+i,250+i);
   line(200+i,80+i,150+i,150+i);
    line(200+i,80+i,250+i,150+i);
     line(200+i,80+i,360+i,80+i);
     line(360+i,80+i,400+i,150+i);
    circle(199+i,128+i,15);
     delay(50);
     }
   getch();
   closegraph();
   return 0;
}

