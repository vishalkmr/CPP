#include<iostream.h>
#include<conio.h>
int exp(int ,int );
void main()
{
  int n,x;
  clrscr();
  cout<<"Enter x: ";
  cin>>x;
  cout<<"Enter n: ";
  cin>>n;
  cout<<exp(x,n);
  getch();


}
int exp(int x,int n)
{
  int r;
  if(x==1)
  return 1;
  else if(n==1)
   return x;
  else
    {
      if(n%2==0)
       { r= exp(x,n/2);
	 return r*r;
	 }
      else
       { r= exp(x,(n-1)/2);
	 return r*r*x;
	}
    }
}