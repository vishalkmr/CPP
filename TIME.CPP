#include<conio.h>
#include<iostream.h>
#include<graphics.h>
class time
{
 int hh,mm,ss;
 public:
 void get();
 time operator + (time t2);
 void display()
 {
  cout<<"time\n"<<hh<<":"<<mm<<":"<<ss;
 }
};
 time time ::operator + (time t2)
{
  time t;

  t.ss=(ss+t2.ss)%60;
  t.mm=((ss+t2.ss)/60+mm+t2.mm)%60;
  t.hh=(hh+t2.hh+(mm+t2.mm)/60)%24;
  return t;
}
void time :: get()
{
cout<<"enter the time\n ";
cin>>hh>>mm>>ss;
}
void main()
{
    clrscr();
    time t1,t2,t3;
    t3=t1+t2;
    t1.get();
    t1.display();
    t2.get();
    t2.display();
    t3=t1+t2;
    t3.display();

    getch();
 }