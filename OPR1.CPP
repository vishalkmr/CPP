// programme to implement the concept of operator overloading
// here we overlaod a binary operator + and
// overloaded operator is act as member function of the class
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class complex
{
private:
float real;
float img;
public:
complex()
{
real=0;
img=0;
}
complex(float a)
{
real=a;
img=0;
}
complex(float a,float b)
{
real=a;
img=b;
}
void display();
complex operator+(complex);
//only one complex is to be passed and through another this function is called
};
void complex:: display()
{
cout<<"\n the complex no. is \n ";
cout<<real<<"+ "<<img<<"i";
cin>>img;

}
complex  complex:: operator+(complex c2)
{
  complex c;
  c.real=real+c2.real;
  c.img=img+c2.img;
  return c;
}
void main()
{
clrscr();
complex c1(2,3),c2(3,4),c3,c4;
c3=c1+c2;
// equivalent to c3=c1.operator+(c2)
c3.display();
c4=c1+2;
//equivqlent to c4=c1.operator+(2)
c4.display();
/* if we write c4=2+c1; it will result an error
 because it is equivalent to c4=2.operator+(c1)
 means we are calling a member of class with integer 2
 which is an error becuase member function can only be called through object of that class
*/
 getch();
}