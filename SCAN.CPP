#include<dos.h>
#include<iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void scan(int , int ,int,int,int,int);
void scan(int left=0,int right=500,int up=0,int down=500, int cl=2,int gp=0 )
{
int y,x,c,d;

for(x=left;x<right;x++)
{
  c=0;
  for(y=up;y<down;y++)
  {

   if(getpixel(x,y)!=0 && x!=left && x!= right)
    {
    while(getpixel(x,y)!=0)
	y++;
	c++;
     }
     if(c==1 && getpixel(x,y)==0)
     {
     putpixel(x,y,cl);

     y=y+gp;
      }
   }
}
}
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midyy;
   int radius = 100;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

 circle(250,250,100);
 rectangle(100,150,200,200);
 rectangle(350,350,400,400);
  scan(100,200,100,2000,2,4);
  scan(150,350,150,350,4);
 scan(350,400,350,400,2,2);

   getch();
   closegraph();
   return 0;
}

