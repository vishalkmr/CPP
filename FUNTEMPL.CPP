// program to implement the concept of template function
#include<iostream.h>
#include <conio.h>
#include<stdio.h>
#include<math.h>
// declaring a new  generic data type using template
template<class type >
void swap(type &a,type &b)
{
 type temp;
  temp=a;
  a=b;
  b=temp;
}
int main(void)
{
   clrscr();
   //swaping two integers
   int x=3,y=4;
   cout<<"\n\n value befor swaping :";
   cout<<"\n a : "<<x<<" b : "<<y;
   swap(x,y);
   cout<<"\n value after swaping :";
   cout<<"\n a : "<<x<<" b : "<<y;
  //swaping two character
   char p='v',q='g';
   cout<<"\n\n character before swaping :";
   cout<<"\n a : "<<p<<" b : "<<q;
   swap(p,q);
   cout<<"\n character after swaping :";
   cout<<"\n a : "<<p<<" b : "<<q;
   // swaping two strings
   char r[]="vishal",s[]="vivek";
   cout<<"\n\n strings  before swaping :";
   cout<<"\n a : "<<r<<" b : "<<s;
   swap(r,s);
   cout<<"\n strings after swaping :";
   cout<<"\n a : "<<r<<" b : "<<s;
   getch();
   return 0;
}
