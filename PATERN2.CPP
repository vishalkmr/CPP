/**
program to generate
	  1
	 232
	34543
       4567654
      567898765
  when n=5
**/
#include<conio.h>
#include<dos.h>
#include<iostream.h>
void main()
{
 clrscr();
 int n;
 cout<<"\n\t        Enter N : ";
 cin>>n;
 cout<<"\n";
 int space =20;
//  loop variable n
 for(int i=1;i<=n;i++)
 {
  // loop for spaces
  for(int k=1;k<=space;k++)
    cout<<" ";
  //  loop left half portion
  for(int j=i;j<=2*i-1;j++)
      {
	 delay(150);
	 cout<<j;
       }
  //  loop right half portion
  for( j=2*i-2;j>=i;j--)
      {
	 delay(150);
	 cout<<j;
       }

  cout<<"\n";
  space--;
 }
 getch();
}
