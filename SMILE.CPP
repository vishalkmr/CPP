#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
void main()
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 for(int i=1;i<100;i++)
 {
 setcolor(i);
 circle(290,220,15);
 circle(200,220,15);
 circle(250,250,100);
 arc(250,280,180,0,40);
 line(240,220,238,280);
 line(245,220,248,280);
 delay(50);
 }
 getch();









}
