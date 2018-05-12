/*
print the patern shown below :
here n=6
     *
    ***
   *****
  *******
 *********
***********
 *********
  *******
   *****
    ***
     *
 */
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
void main()
{
 clrscr();
 int i,j,k,n,space,star,ran;
 cout<<"enter the  value of n: \n";
 cin>>n;

 // initialisation of space and star for upper half
 space=n-1;
 star=1;
 for(i=1;i<=n;i++)
 {
  for(k=1;k<=space;k++)
   cout<<" ";
  for(j=1;j<=star;j++)
  {
	sound(10*random(100));
	delay(75);
	nosound();
	ran=random(16);
	if(ran==0)
	ran=ran+1;
	textattr(ran+BLINK);
	cprintf("*");
  }
  // updation of star and space
    star=star+2;
    space--;
    printf("\n");
 }
 // initialisation of space and star for lower half
   space=1;
   star=2*(n-1)-1;
 for(i=1;i<=n;i++)
  {
    for(k=1;k<=space;k++)
      cout<<" ";
    for(j=1;j<=star;j++)
     {
	sound(10*random(100));
	delay(75);
	nosound();
	ran=random(16);
	if(ran==0)
	ran=ran+1;
	textattr(ran+BLINK);
	cprintf("*");
      }
  // updation of star and space
    star=star-2;
    space++;
    printf("\n");
  }
  getch();
}