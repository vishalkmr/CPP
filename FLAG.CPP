#include<dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main()
{
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

    setcolor(4);
   rectangle(255,100,340,115);
    setcolor(2);
    rectangle(255,130,340,145);
     setcolor(7);
    rectangle(255,115,340,130);
     setcolor(8);
     rectangle(250,100,255,350);
     setcolor(14);

    rectangle(235,350,270,360);
    rectangle(225,360,280,370);
   rectangle(215,370,290,380);
	setcolor(9);

       line(304,120,297,122);
    line(300,117,297,122);
      line(290,127,297,122);
    line(297,130,297,122);
    line(293,118,297,122);
    line(301,126,297,122);
   circle(297,122,8);


   getch();
   closegraph();
   return 0;
}

