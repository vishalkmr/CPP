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

   float x1,y1,x2,y2,x,y,dx,dy,xinc,yinc,step,m;
   cout<<"\n enter the coordinates of 1st point :-\n";
   cout<<"x1 : ";cin>>x1;
   cout<<"y1 : ";cin>>y1;
   cout<<"\n enter the coordinates of 2nd point :-\n";
   cout<<"x2 : ";cin>>x2;
   cout<<"y2 : ";cin>>y2;
   cout<<(y2-y1)/(x2-x1);
  clrscr();
     int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   x=x1;
   y=y1;
   dx=x2-x1;
   dy=y2-y1;
   if(abs(dx)>abs(dy))
     step=abs(dx);
   else
     step=abs(dy);
   xinc=dx/step;
   yinc=dy/step;
   m=dy/dx;
 while(x!=x2 && y!=y2)
   {

   x=x+xinc;
   y=y+yinc;
   delay(10);
   putpixel(x,y,7);
    delay(100);
    }
   getch();
   closegraph();
   return 0;
}

