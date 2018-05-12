#include<iostream.h>
#include<dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
float max(float , float );
float min(float , float );
int main()
{
   clrscr();
   float x1,y1,x2,y2,dx,dy,p[4],q[4],xmax,xmin,ymax,ymin,u1,u2,flag;
   u1=0;
   u2=1;
   flag=0;
   cout<<"\n enter the clipping window coordinates :-\n";
   cout<<"xmin : ";cin>>xmin;
   cout<<"ymin : ";cin>>ymin;
   cout<<"xmax : ";cin>>xmax;
   cout<<"ymax : ";cin>>ymax;
   cout<<"\n enter the coordinates of 1st point :-\n";
   cout<<"x1 : ";cin>>x1;
   cout<<"y1 : ";cin>>y1;
   cout<<"\n enter the coordinates of 2nd point :-\n";
   cout<<"x2 : ";cin>>x2;
   cout<<"y2 : ";cin>>y2;
   dx=x2-x1;
   dy=y2-y1;
   p[0]=-dx;  q[0]=x1-xmin;
   p[1]=dx;   q[1]=xmax-x1;
   p[2]=-dy;  q[2]=y1-ymin;
   p[3]=dy;   q[3]=ymax-y1;
for(int i=0;i<4;i++)
{
 if(p[i]==0)
   {
    if(q[i]<0)
   {
    flag=1;
    break;
   }
   }
  if(p[i]<0)
   {  u1=max(0,q[i]/p[i]);

    }
  if (p[i]>0)
     { u2=min(1,q[i]/p[i]);
      }
 }
   if(u1>u2 ||flag==1)
   {
   cout<<"\n line is completelty outside the clipping window";
   getch();

   return 0;
   }

  int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   setcolor(7);
   line(x1,y1,x2,y2); //initial line
      setcolor(4);
   line(xmin,ymin,xmax,ymin);
   line(xmin,ymin,xmin,ymax);
   line(xmax,ymin,xmax,ymax);
   line(xmax,ymax,xmin,ymax);

   x1=x1+dx*u1;
   y1=y1+dy*u1;
   x2=x1+dx*u2;
   y2=y1+dy*u2;
      delay(1000);
    cleardevice();
   setcolor(2);
   line(x1,y1,x2,y2);
      setcolor(4);
   line(xmin,ymin,xmax,ymin);
   line(xmin,ymin,xmin,ymax);
   line(xmax,ymin,xmax,ymax);
   line(xmax,ymax,xmin,ymax);

   getch();
   closegraph();
      return 0;
}
float max(float n1 , float n2 )
{
  if(n1>n2)
  return n1;
  else
  return n2;


}
float min(float n1 ,float  n2 )
{
  if(n1<n2)
  return n1;
  else
  return n2;


}
