//  2d array address
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
 clrscr();
 int a[3][3]={1,2,3,4,5,6,7,8,9};
 cout<<"a[0][0] "<<&(a[0][0])<<"  a[0][1] "<<&a[0][1]<<"  a[0][2] "<<&a[0][2];
 cout<<"\na[1][0] "<<&(a[1][0])<<"  a[1][1] "<<&a[1][1]<<"  a[1][2] "<<&a[2][2];
 cout<<"\na[2][0] "<<&(a[2][0])<<"  a[2][1] "<<&a[2][1]<<"  a[2][2] "<<&a[2][2];

 cout<<"\na  "<<a;
 cout<<"\n&a  "<<&a;
 cout<<"\n*a  "<<*a;
 cout<<"\n**a  "<<**a;
 cout<<"\na+1  "<<a+1;
 cout<<"\n*(a+1)  "<<*(a+1);
 cout<<"\n*a+3 "<<*a+3;
 cout<<"\n**(a+1)  "<<**(a+1);
 cout<<"\n**a+1 "<<**a+1;

 cout<<"\n&a+1  "<<&a+1;






 getch();





}