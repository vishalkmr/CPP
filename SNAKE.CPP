#include<graphics.h>
#include<iostream.h>
#include<dos.h>
#include<process.h>
#include<stdio.h>
#include<conio.h>
class snake
{
 int count;// control length of snake
 char direction;
 int x,y;
 public:
 void frame();
 void pointer();
 void module();
 void input();
 void setxy();

} ;
void snake:: module()
{
 count=0;
 x=10;
 y=10;
 direction='d';
 while(1)
 {
 frame();
 gotoxy(x,y);
 pointer();
 input();
 setxy();
 count++;
 if(count==10)
 break;
 clrscr();
  }
}
void snake::frame()
{
cout<<"\t\t point=  \t\tlife= ";
cout<<"\n  **************************************************************";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  *                                                            *";
cout<<"\n  **************************************************************";
}
void snake::pointer()
{
 int i=0;
 cout<<"*";
 while(i<count)
 {
  cout<<"*";
   i++;
 }
 cout<<"";

}
void snake::input()
{
  while(1)
  {
  cin>>direction;
  if(direction=='w'||direction=='a'||direction=='s'||direction=='d')
   break;
  }
}
void snake::setxy()
{
 if(direction=='w')
     y--;
 if(direction=='s')
     y++;
 if(direction=='a')
     x--;
 if(direction=='d')
     x++;

}
void main()
{
 clrscr();
 int top,left,right,bottom;
 snake obj;
 obj.module();

 getch();


}
