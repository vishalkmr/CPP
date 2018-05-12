#include<iostream.h>
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();

int i,x;

// Output operations
i=1;
cout<<"\n i++<<i "<<i++<<"  "<<i;

i=1;
cout<<"\n i<<i++ "<<i<<" "<<i++;

i=1;
cout<<"\n ++i<<i "<<++i<<" "<<i;

i=1;
cout<<"\n i<<++i "<<i<<" "<<++i;


// Aritmetic operations
i=1;
x=(i++)+(i++)+(i++) ;// no effect
cout<<"\n\n x=(i++)+(i++)+(i++) "<<" x="<<x<<" i="<<i;

i=1;
x=(i)+(++i)+(i) ;// final value of i is substituted
cout<<"\n x=(i)+(++i)+(i) "<<" x="<<x<<" i="<<i;

i=1;
x=(i)+(++i)+(++i) ;// final value of i is substituted
cout<<"\n x=(i)+(++i)+(++i) "<<" x="<<x<<" i="<<i;

i=1;
x=(++i)+(++i)+(i++) ;// final value of i is substituted
cout<<"\n x=(++i)+(++i)+(i++) "<<" x="<<x<<" i="<<i;



// Arrays operations
cout<<"\n\n a: 0 1 2 3 4 5 6 7 8 9";
i=0;
int a[10]={0,1,2,3,4,5,6,7,8,9};
x=a[i++]+a[i++]+a[i++]+a[i++]+a[i++];
cout<<"\n x=a[i++]+a[i++]+a[i++]+a[i++]+a[i++] "<<"\n x="<<x<<" i="<<i;

i=0;
x=a[++i]+a[i]+a[i]+a[i]+a[i];
cout<<"\n x=a[++i]+a[i]+a[i]+a[i]+a[i] "<<"\n x="<<x<<" i="<<i;

i=0;
x=a[++i]+a[i]+a[++i]+a[i]+a[i];
cout<<"\n x=a[++i]+a[i]+a[++i]+a[i]+a[i] "<<"\n x="<<x<<" i="<<i;

i=0;
x=a[++i]+a[i++]+a[i++]+a[i++]+a[i++];
cout<<"\n x=a[++i]+a[i++]+a[i++]+a[i++]+a[i++] "<<"\n x="<<x<<" i="<<i;


getch();
}