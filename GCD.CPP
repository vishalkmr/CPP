#include<stdio.h>
#include<conio.h>
int gcd(m,n)
{
 if(m==0 || n==0)
   return 0;
 if(m%n==0)
   return n;
 return gcd(n,m%n);
}


void main()
{
clrscr();
int m,n;
printf("M : ");
scanf("%d",&m);
printf("N : ");
scanf("%d",&n);

printf("%d",gcd(m,n));
getch();
}

