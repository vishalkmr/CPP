// program to showing the function overloading
#include<iostream.h>
#include <conio.h>
#include<stdio.h>
#include<math.h>
float area(float); // circle
float area(float,float);   // rectangular
float area(float,float,float);  // triangle
int main(void)
{
   clrscr();
   float result;
   result= area(5);
   cout<<"\narea of circle : "<<result;
    result= area(5,4);
   cout<<"\narea of rectangle : "<<result;
    result= area(5,4,3);
   cout<<"\narea of triangle =  : "<<result;
   getch();
   return 0;
}
float area(float r)
{
  float result;
  result=3.14*r*r;
  return  result;
}
float area(float l,float b)
{
  float result;
  result=l*b;
  return  result;

}
float area(float a,float c,float b)
{
  float result,s;
  s=(a+b+c)/2;
  result=sqrt(s*(s-a)*(s-b)*(s-c));
  return  result;
}