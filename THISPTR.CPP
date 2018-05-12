// program to showing the working of this pointer
#include<iostream.h>
#include <conio.h>
#include<stdio.h>
class sample
{
 float x;
 float y;
 public:
 void read();
 void display();
 void fun(sample&);
};
void sample::read()
{
 cout<<"\n enter the x:";
 cin>>x;
 cout<<" enter the y:";
 cin>>y;
}
void sample::display()
{
 cout<<"\n x:"<<x;
 cout<<"\n y:"<<y;
}
void sample::fun(sample &obj)
{
cout<<"\n adress of the implicite object"<<this;
// this pointer contains the address of object whose member function is called
cout<<"\n adress of the explicite object"<<&obj;
}
int main(void)
{
   clrscr();
   sample a,b;
   cout<<"\n the address of object a:"<<&a;
   cout<<"\n the address of object b:"<<&b;
   a.read();
   a.display();
   b.read();
   b.display();
   a.fun(b);
   getch();
   return 0;
}

