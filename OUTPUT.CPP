#include<iostream.h>
#include<conio.h>
#include<stdio.h>
int find(int,int);
void call_by_reference(int* x,int* y,int* z );
int f(int);
int f1(int);
int f2(int,int);
void f3(int,int);

void main()
{
clrscr();
int x,y,a,b;
float d;
// problem  1
cout<<"\n problem 1 \n";
 a=5;
 b=12;
cout<<" "<<find(a,find(a,b)); // print smallest of a and b

// problem 2
cout<<"\n\n problem 2 \n ";
cout<<(a!=b); // true 1
cout<<(a==b);  // false 0
cout<<(a=b);   //  (a=b) return b thus b value is printed

// problem 3
cout<<"\n\n problem 3 ";
if(a=8)
 cout<<"\n if statement";  // assinment operation return 8 which is true thus if statment is printed

else
 cout<<"\n else statment";

// problem 4
cout<<"\n\n problem 4 ";
// execution starts form right to left in arirhmetic operation
x=4;
cout<<"\n "<<x++<<x++<<x++;
x=4;
cout<<"\n "<<x++ + x++ + x++;
x=4;
cout<<"\n "<<++x<<++x<<++x;
x=4;
cout<<"\n "<<++x + ++x + ++x;

// problem 5
cout<<"\n\n problem 5 \n";
x=10;
y=3;
call_by_reference(&y,&x,&x);
cout<<" x = "<<x;
cout<<" y = "<<y;

// problem 6
cout<<"\n\n problem 6 \n";
cout<<" "<<f(1);


// problem 7
cout<<"\n\n problem 7 \n";
d=5.1234;
cout<<" %d ";printf("%d");    // any garbage value is printed
cout<<"\n %f = "; printf("%f",d);
cout<<"\n %.0f = "; printf("%.0f",d);
cout<<"\n %.1f = "; printf("%.1f",d);
cout<<"\n %.2f = "; printf("%.2f",d);
cout<<"\n %1f = "; printf("%1f",d);

// problem 8
cout<<"\n\n problem 8 \n";
cout<<" "<<f1(5);

// problem 9
cout<<"\n\n problem 9 \n";
f2(18,6);

// problem 10
cout<<"\n\n problem 10 \n";
int sum=0;
f3(2048,sum);
cout<<" "<<sum<<" ";

// problem 11
cout<<"\n\n problem 11 \n";
void *vp;
char ch='g';
char *cp="goofy";
int j=20;
vp=&ch;
printf(" %c",*(char*)vp);   // prints g
vp=&j;
printf("%d",*(int*)vp);   // prints 20
vp=cp;
printf("%s",(char*)vp+3);  // prints fy

// problem 12
cout<<"\n\n problem 12 \n";
int i=258;
int* iptr=&i;
printf(" %d %d",*((char*)iptr),*((char*)iptr+1));

// problem 13
cout<<"\n\n problem 13 \n";
 x=0;
for(i=0;i<10;i++)
 if(i%2 && x++)
 x+=2;
cout<<" x = "<<x;

// problem 14
cout<<"\n\n problem 14 \n";
switch(4)
{
printf("before case"); // statements before case doesnot executes
case 1: cout<<" 1 ";
case 2: cout<<" 2 ";
case 4: cout<<" 4 ";
case 5: cout<<" 5 ";
case 6: cout<<" 6 ";
default:cout<<" default ";

}
// problem 15
cout<<"\n\n problem 15 \n";
//printff() return number of character in printf(" ")  %d,%f,\n.. are counted as one
//scanf() return 1 or 0 depeanding on validity of input type
x=5;
printf("outside : %d ",printf("inside : %d ",x));
cout<<"\n";
cout<<" "<<printf("vishal")<<" "<<printf("kumar");
cout<<"\n";
//cout<<"  "<<(scanf("%d",&x));


// problem 16
cout<<"\n\n problem 16 \n";
char ch1[]="\0";
if(printf("%s",ch1))
cout<<" true";
else
cout<<" false";



getch();
}
int find(int x, int y)
{
 if(x<y)
 return 0;
 else
  return (x-y);
}
void call_by_reference(int *x,int *y,int *z )
{
  *y=*y+4;        // y=10+4=14
  *z=*x+*y+*z;    // z=3+14+14=31
  // here value of z in expresion is changed as y change bcz they are binded to same element

}
int f(int n)
// 1st call  f(1) intially n=1 i=1 , updation n=2 i=2
// 2nd call  f(2) intially n=2 i=2 , updation n=4 i=3
// 3rd call  f(4) intially n=4 i=3 , updation n=7 i=4
// 4th call  f(7) intially n=7 i=4 , here if condition is true return n=7
{
static int i =1;
if(n>=5) return n;
n=n+i;
i++;
return f(n);
}

int f1(int n)
{
static int r =0;
if(n<=0) return 1;
if(n>3)
{
r=n;
return f1(n-2)+2;
}
return f1(n-1)+r;
}
int f2(int m, int n)
{
 while(m!=n)
 {
   if(m>n)
   m=m-n;
   else
   n=n-m;
  }
 printf(" %d ",n);
}
void f3(int n, int sum)
{
 int k=0, j=0;
 if(n==0)
 return ;
 k=n%10;
 j=n/10;
 sum=sum+k;
 f3(j,sum);
 cout<<" "<<k<<" ";


}



