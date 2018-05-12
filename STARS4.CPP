/*
print the patern shown below :
here n=6
*         *
**       **
***     ***
****   ****
***** *****
***********
 */
#include<conio.h>
#include<stdio.h>
void main()
{
 clrscr();
 int i,j,k,n,space,star;
 printf("enter the  value of n: \n");
 scanf("%d",&n);
 // initialisation of space and star
 space=2*n-3;
 star=1;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=star;j++)
  printf("*");
  for(k=1;k<=space;k++)
  printf(" ");
  if(i==n)
  {
    for(j=1;j<=star-1;j++)
    printf("*");
  }
  else
  {
    for(j=1;j<=star;j++)
    printf("*");
  }
  // updation of star and space
  star=star+1;
  space=space-2;
  printf("\n");
  }
  getch();
}