/*
print the patern shown below :
here n=6
     *
    ***
   *****
  *******
 *********
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
 space=n-1;
 star=1;
 for(i=1;i<=n;i++)
 {
  for(k=1;k<=space;k++)
  printf(" ");
  for(j=1;j<=star;j++)
  printf("*");
  // updation of star and space
  star=star+2;
  space--;
  printf("\n");
  }
  getch();
}