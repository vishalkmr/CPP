// program to implement the concept of inheritance
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
class person  // base class
{
char name[100];
int age;
char dob[10];
protected:
void readperson();
void displayperson();
};
class student: public person // derived class
{
int roll;
int marks;
public:
void readstudent();
void displaystudent();
};
void person:: readperson()
{
cout<<"\n enter the name : ";
cin>>name;
cout<<"\n enter the age : ";
cin>>age;
cout<<"\n enter the date of birth : ";
cin>>dob;
}
void person:: displayperson()
{
cout<<"\n name :"<<name;
cout<<"\n age :"<<age;
cout<<"\n birth :"<<dob;
}
void student:: readstudent()
{
readperson(); // calling the inherited memeber
cout<<"\n enter the rollno : ";
cin>>roll;
cout<<"\n enter the marks : ";
cin>>marks;
}
void student:: displaystudent()
{
displayperson(); // calling the inherited memeber
cout<<"\n rollno : "<<roll;
cout<<"\n enter the marks :"<<marks;
}
void main()
{
    clrscr();
    student obj;
    obj.readstudent();
    obj.displaystudent();
    getch();
 }