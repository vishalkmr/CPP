#include<stdio.h>
#include<iostream.h>
#include<conio.h>
void fun(int[]) ;
void main()
{
clrscr();
int a[4][3]={1,2,3,4,5,6,7,8,9,10,11,12};
cout<<"\n"<<a[2][1];



/*for(int i=0;i<7;i++)
{

cout<<"\n"<<a+i;
cout<<"\n"<<*(a+i);
} */
getch();


}

void fun(int b[])
{
cout<<"\n"<<*b+3;
cout<<"\n"<<b+3;
b[3]+=1;
cout<<"\n"<<*(b+3);

cout<<"\n"<<b+3;


}

