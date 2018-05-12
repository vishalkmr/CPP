/*
// program to print fibonacci series with linear complexity
#include<iostream.h>
#include<conio.h>
void main()
{
   int i,n,a,b,temp;
   clrscr();
   cout<<"\n enter the value of n";
   cin>>n;
   b=1;
   a=0;
   for(i=0;i<n;i++)
   {
      cout<<b<<" ";
      temp=b;
      b=b+a;
      a=temp;
  }
  getch();
}
*/
// program to print fibonacci series with logerathmic complexity
#include<iostream.h>
#include<conio.h>
 int mat[2][2]={1,1,1,0};

int fib(int n);
void main()
{
   int i,n,a,b,temp;
   clrscr();
   cout<<"\n enter the value of n";
   cin>>n;
   b=1;
   a=0;
  getch();
}
int fib(int n )
{



}