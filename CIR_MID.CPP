#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
int xc,yc;
	void symmetry(int x, int y)
{
 putpixel(x+xc,y+yc,1);
 sound(100);
 delay(1);
 nosound();
 putpixel(-x+xc,y+yc,2);
 sound(800);
 delay(8);
 nosound();
 putpixel(x+xc,-y+yc,3);
 sound(20);
 delay(2);
 nosound();
 putpixel(-x+xc,-y+yc,4);
 sound(700);
 delay(9);
 nosound();
 putpixel(y+xc,x+yc,5);
 sound(300);
 delay(4);
 nosound();
 putpixel(-y+xc,x+yc,6);
 sound(400);
 delay(7);
 nosound();
 putpixel(-y+xc,-x+yc,7);
 sound(500);
 delay(5);
 nosound();
 putpixel(y+xc,-x+yc,8);
 sound(600);
 delay(10);
 nosound();

}
void main()
{
int x,y,d,r;
cout<<"enter the radius of circle : ";
cin>>r;
cout<<"enter the center point \n";
cout<<"x : ";
cin>>xc;
cout<<"y : ";
cin>>yc;
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
d=1-r;
x=0;
y=r;
symmetry(x,y);
while(x<y)
{
	if(d>0)
	{
		d=d+2*(x-y)+5;
			x++;
			y--;
	}
	else
	{

		d=d+2*x+3;
		x++;
	}
	symmetry(x,y);

}
getch();
closegraph();
}
