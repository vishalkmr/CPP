#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<iostream.h>
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
   }
int midx = getmaxx() / 2;
int midy = getmaxy() / 2;
// midx=319 maxx=639
//midy=239  maxy=479
for(int i=1;i<100;i++)
{

 setcolor(9+i);
 circle(midx, midy,150-i*5);
 setcolor(2+i);
 circle(midx, midy,50-i );

    setcolor(i);
   rectangle(319-i*4,239,319,239);
   rectangle(319,239-i*4,319,239);
   rectangle(319,239,319+i*4,239);
   rectangle(319,239,319,239+i*4);


 setcolor(5+i);
 circle(0, 0,100-i);
 circle(0,479,100-i);
 circle(639, 0,100-i);
 circle(639,479,100-i);
 setcolor(3+i);
 rectangle(209+i,129+i,430-i,350-i);
 setcolor(1+i);
 rectangle(0,0,639,479);
 delay(100);
	sound(10*random(100));
	delay(15);
	nosound();


}
getch();
cleardevice();       /* clear screen */
  return 0;
}
