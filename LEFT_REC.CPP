
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<iostream.h>
#include<string.h>

void main()
{
  clrscr();
  int n,i=0,j=0;
  char A;
  char a[10],b[10];
  char pr1[11],pr2[12];
  cout<<"\n Enter the 1st Productions :";
  gets(pr1);
  cout<<"\n Enter the 2nd  Productions :";
  scanf("%s",pr2);
  A=pr1[0];
  j=4;
  for(i=0;i<strlen(pr1);i++)
   a[i]=pr1[j++];
   j=3;
   for(i=0;i<strlen(pr2);i++)
   b[i]=pr2[j++];
  cout<<"\n After removing left recursion  \n" ;
  cout<<A<<"->"<<b<<A<<"'";
  cout<<"\n"<<A<<"'->"<<a<<A<<"'/Null";

  getch();



}
