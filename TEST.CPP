
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<iostream.h>
#include<stdlib.h>
#define size(a) sizeof(a)/sizeof(*a)
void print(int []);
void main()
{
clrscr();
signed int a=-300;
void *s=&a;
s=(char *)s+1;
printf("%d",*(char *)s);

getch();

}
void print(int a[])
{

cout<<"\n in function";
cout<<sizeof(a)/sizeof(*a);


}
