// program to implement the concept of virtual function to achive run time polymorphism
#include<conio.h>
#include<iostream.h>
// base class containing virtual function
class person
{
public:
virtual void skills()
{
cout<<"\n knowledge about society ";
}
};
// derived class
class doctor:public person
{
public:
void skills()
{
cout<<"\n knowledge about medicine ,surgery ";
}
};
// derived class
class engeineer:public person
{
public:
void skills()
{
cout<<"\n knowledge about computers,programming ";
}
};
void main()
{
    clrscr();
    person p,*ptr;
    doctor d;
    engeineer e;
    ptr=&p;
    ptr->skills(); // invokes skill() of person class due to early binding
    ptr=&d;  // upcasting
    ptr->skills(); // invokes skill() of doctor class due to late binding
    ptr=&e;  // upcasting
    ptr->skills(); //invokes skill() of engieneer class due to late binding
    getch();
 }