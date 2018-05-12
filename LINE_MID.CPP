#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<math.h>
#include<iostream.h>
#include<dos.h>
int main(void)
{
   float x1,y1,x2,y2,x,y,dx,dy,incNE,incE,d;
   cout<<"\n enter the coordinates of 1st point :-\n";
   cout<<"x1 : ";cin>>x1;
   cout<<"y1 : ";cin>>y1;
   cout<<"\n enter the coordinates of 2nd point :-\n";
   cout<<"x2 : ";cin>>x2;
   cout<<"y2 : ";cin>>y2;
   clrscr();
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   x=x1;
   y=y1;
   dx=x2-x1;
   dy=y2-y1;
   d=2*dy-dx;  // d(start)
   incNE=2*(dy-dx);
   incE=2*dy;
   while(x<=x2)
   {
    putpixel(x,y,7);
     if(d<0)
    {
     d=d+incE;
    x++;
    }
    else
    {
    d=d+incNE;
    y++;
    x++;
    }

   }
   getch();
   closegraph();
   return 0;
}

