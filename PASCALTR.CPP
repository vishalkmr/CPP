#include<conio.h>
#include<dos.h>
#include<iostream.h>
int factorial(int n);
int combination(int n ,int r);
void main()
{
 clrscr();
 int n;
 cout<< "\t------ PASCAL TRIANGLE ------";
 cout<<"\n\t        Enter N : ";
 cin>>n;
 cout<<"\n";
 int space =20;
 for(int i=1;i<=n;i++)
 {

  for(int k=1;k<=space;k++)
    cout<<" ";
  if(i==1) cout<<" 1 ";
  else
  {
      for(int j=0;j<=i;j++)
      {
	 delay(150);
	 cout<<combination(i,j)<<" ";
       }
  }
  cout<<"\n";
  space--;
 }



 getch();
}
int factorial(int n)
{
 int fact=1;
 for(int i=1;i<=n;i++)
	fact=fact*i;
 return fact;
}
int combination(int n ,int r)
{
  int c;
  c=factorial(n)/(factorial(n-r)*factorial(r));
  return c;
}