#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
void main()
{
clrscr();
for(int i=0;i<255;i++)
{
printf("\n  %c   %d ",i,i);
delay(100);
}
getch();
}


