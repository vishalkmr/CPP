// program to overload the extraction and insertion operation
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class complex
{
	float real,img;
	public:
	friend ostream & operator<<(ostream & s,complex &obj);
	friend istream & operator>>(istream & s,complex &obj);
};
ostream & operator<<(ostream & s,complex &obj)
{
s<<"the complex number :"<<obj.real<<"+"<<obj.img<<"i";
return s;
}
istream& operator>>(istream & s,complex &obj)
{
cout<<"\n enter the complex number :";
cout<<"\n enter the real part :";
s>>obj.real;
cout<<" enter the imganiary part :";
s>>obj.img;
return s;
}
void main()
{
 clrscr();
 complex obj;
 cin>>obj; // invocation of overloaded exatration operator
 cout<<obj;// invocation of overloaded insertion operator
 getch();
}