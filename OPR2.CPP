// programme to implement the concept of operator overloading
// here we overlaod a binary operator + and
// overloaded operator is act not a member function of the class
// we use the concept of friend function which is used to access private dataof class
#include<iostream.h>
#include<conio.h>
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
friend complex operator+(complex,complex);
// this function is not a member function so we pass both the complex which we want to add
};
void complex:: display()
{
cout<<"\n the complex no. is \n ";
cout<<real<<"+ "<<img<<"i";
}
complex operator+(complex c1,complex c2)
{
  complex c;
  c.real=c1.real+c2.real;
  c.img=c1.img+c2.img;
  return c;
}
void main()
{
clrscr();
complex c1(2,3),c2(3,4),c3,c4,c5;
c3=c1+c2;
// equivalent to c3=operator+(c1,c2)
c3.display();
c4=c1+2;
// equivalent to c4=operator+(c1,2)
c4.display();
c5=2+c2;
// equivalent to c5=operator+(2,c2)
c5.display();
getch();
}