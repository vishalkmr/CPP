#include<iostream.h>
#include<conio.h>
int is_prime(int);
void main()
{
 int t,n,m;
 clrscr();
 cin>>t;
 cout<<t;
 for(int i=0;i<t;i++)
 {
   cin>>m;
   cin>>n;
   for(int j=m;j<=n;j++)
   {
    if(is_prime(j))
    cout<<j<<"\n";
   }


 }
  getch();
}
int is_prime(int x )
{
  for(int k=2;k<=x/2;k++)
    {
     if((x%k)==0)
     return 0;
     }
    if(x!=1)
    return 1;
}