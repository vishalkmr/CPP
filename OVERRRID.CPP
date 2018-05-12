// program to implement the concept of function overriding
#include<conio.h>
#include<iostream.h>
// base class definition
class person
{
public:
void skills()
{
cout<<"\n knowledge about society ";
}
};
// derived class definition
class doctor:public person
{
public:
void skills()
{
cout<<"\n knowledge about medicine ,surgery ";
}
};
void main()
{
    clrscr();
    person p,*ptr;
    doctor d;
    p.skills(); //invocation of skill() of class person
    d.skills(); //invocation of skill() of class derived due to overriding
    ptr=&p;
    ptr->skills();
    ptr=&d; // upcasting
    ptr->skills();
    //invocation of skill() of class person due to early binding
    getch();
 }