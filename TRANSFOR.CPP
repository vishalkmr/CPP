#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
static int i=1,ch=1,choice=1;
static int a[3][3]={0,0,1,0,0,1,0,0,1 };
static int t[3][3]={1,0,0,0,1,0,0,0,1 };
static int c[3][3]={0,0,1,0,0,1,0,0,1 };
void draw(int [3][3]);
void insert(int x1,int y1,int x2,int y2,int x3,int y3,int m,int n);
void retrive(int [3][3]);
void display(int[3][3]);
void operation();
void connect(int[3][3],int[3][3]);
void main()
{

 clrscr();
 double x1,x2,x3,y1,y2,y3,m,n;
 cout<<"\n enter the coordinates of triangle :";
 cout<<"\n 1st coordinates : \n";
 cin>>x1;

 cin>>y1;
 cout<<" 2nd coordinates : \n";
 cin>>x2;
 cin>>y2;
 cout<<" 3rd coordinates : \n";
 cin>>x3;
 cin>>y3;
 cout<<"\n what operation you want to perform : ";
 cout<<"\n1. translation ";
 cout<<"\n2. scaling ";
 cout<<"\n3. reflaction ";
 cout<<"\n4. rotation ";
 cin>>choice;
 switch(choice)
 {
 case 1:
   cout<<" enter the translated coordinates : \n";
   cin>>m;
   cin>>n;
   break;
 case 2:
   cout<<" enter the scaling coordinates : \n";
   cin>>m;
   cin>>n;
  break;
 case 3:
   cout<<" choose the axis of rotation : \n";
   cout<<"\n1. x-axis ";
   cout<<"\n2. y-axis ";
   cout<<"\n3. y=x axis ";
   cout<<"\n4. y=-x axis ";
   cout<<"\n5. about origin ";
   cin>>ch;
   break;
 case 4:
   cout<<" enter the angle from which the triangle to be rotated : \n";
   cin>>m;
     break;
  default :
  cout<<"wrong entry !!!";
 }
 insert(x1,y1,x2,y2,x3,y3,m,n);
 display(a);
 display(t);
  delay(1000);
 clrscr();
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
  draw(a);
  delay(500);
   operation();
   getch();
  closegraph();
  cleardevice();


}
void insert(int x1,int y1,int x2,int y2,int x3,int y3,int m,int n)
{
a[0][0]=x1;
a[0][1]=y1;
a[1][0]=x2;
a[1][1]=y2;
a[2][0]=x3;
a[2][1]=y3;
if(choice==1) //translation
{
t[2][0]=m;
t[2][1]=n;
}
else if(choice==2) //scaling
{
t[0][0]=m;
t[1][1]=n;
}
else if(choice==3)// reflaction
{
//cout<<"working";
  if(ch==1)
    {
       t[0][0]=1;
	t[0][1]=0;
	t[1][0]=0;
	t[1][1]=-1;
     }
  if(ch==2)
    {
       t[0][0]=-1;
	t[0][1]=0;
	t[1][0]=0;
	t[1][1]=1;
     }

  if(ch==3)
    {
       t[0][0]=0;
	t[0][1]=1;
	t[1][0]=1;
	t[1][1]=0;
     }
      if(ch==4)
    {
       t[0][0]=0;
	t[0][1]=-1;
	t[1][0]=-1;
	t[1][1]=0;
     }
       if(ch==5)
    {
       t[0][0]=-1;
	t[0][1]=0;
	t[1][0]=0;
	t[1][1]=-1;
     }

}
else if(choice==4)// rotation
{
    m=m * 0.01746;
    cout<<m;
       t[0][0]=cos(m);
	t[0][1]=sin(m);
	t[0][2]=0;
	t[1][0]=-sin(m);
	t[1][1]=cos(m);
	t[1][2]=0;
	t[2][0]=0;
	t[2][1]=0;
	t[2][2]=1;
	}

}
void display(int mat[3][3])
{
cout<<"\n";
for(int i=0 ;i<3;i++)
{
for(int j=0 ;j<3;j++)
{
 cout<<mat[i][j]<<"   ";
}
cout<<"\n";
}
}
void operation()
{
int i,j,k;
for(i=0;i<3;i++)
{ for( j=0;j<3;j++)
  {
    c[i][j]=0;
    for(k=0;k<3;k++)
     {
	c[i][j]=a[i][k]*t[k][j]+c[i][j];
     }
   sound(10*(i+20));
	delay(75);
	nosound();
	cleardevice();
	 draw(a);
	 retrive(c);
       connect(a,c);
	delay(500);
  }

}
}
void draw(int a[3][3])
{
setcolor(9);
line(a[0][0],a[0][1],a[1][0],a[1][1]);
line(a[1][0],a[1][1],a[2][0],a[2][1]);
line(a[2][0],a[2][1],a[0][0],a[0][1]);
}
void retrive(int c[3][3])
{
setcolor(i++);
line(c[0][0],c[0][1],c[1][0],c[1][1]);
line(c[1][0],c[1][1],c[2][0],c[2][1]);
line(c[2][0],c[2][1],c[0][0],c[0][1]);
}
void connect(int a[3][3],int c[3][3])
{
setcolor(2);
line(a[0][0],a[0][1],c[0][0],c[0][1]);
line(a[1][0],a[1][1],c[1][0],c[1][1]);
line(a[2][0],a[2][1],c[2][0],c[2][1]);
}