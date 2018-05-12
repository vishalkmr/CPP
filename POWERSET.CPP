// program to calculate power set of a given set
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<process.h>
int no_elemnets(int );// to calculate no. of element in power set
int no_elemnets(int n )
{
 int pow;
 if(n==0)
  return 1;
 pow=2;
 for(int i=1;i<n;i++)// to find 2*2*2....n times
 {
   pow=pow*2;
 }
  return pow;
}
void binary_cnv(int,int[],int);// convert the given no. into binary form
void binary_cnv(int n,int b[],int size)
{
  int i,beg,end,temp;
  for(i=0;i<size;i++) // initialising the array with 0 values
  {
    b[i]=0;
  }
  i=0;
  while(n)  // storing remainder each time in array b[]
  {
   b[i]=n%2;
   n=n/2;
   i++;
  }
  for(beg=0,end=size-1;beg<end;beg++,end--) //storing in reverse order to get binary no.
  {
    temp=b[beg];
    b[beg]=b[end];
    b[end]=temp;
  }

}

void main()
{
    clrscr();
    int size,n,b[100],j,i,flag;
    char s[100];
    cout<<"\n enter the size of set :" ;
    cin>>size;
  if(size==0) // when size is 0
    {
    cout<<"{$}";
    }
  else
   {
    n=no_elemnets(size);
    cout<<"\n enter the elements of set : \n" ;
     for(j=0;j<size;j++)
     {
     cin>>s[j];
     }
    cout<<"\n the set is: \n{" ;
     for(j=0;j<size;j++)
     {
     cout<<s[j];
     if(j!=size-1)
     cout<<",";
     }
     cout<<"}";
     cout<<"\n the size of power set is :"<<n;
     cout<<"\n the elements in the power set is :\n ";
	cout<<"{";
      for(j=0;j<n;j++)
      {
	binary_cnv(j,b,size);
	 if(j==0)  // when binary value is 0000
	  {
	   cout<<"$,";
	   continue;
	  }
	  cout<<"{";
	for(i=0;i<size;i++)
	 {
	 if(b[i]==1)
	 {
	   cout<<s[i];
	    flag=0;
	   for(int k=i+1;k<size;k++)//loop to find the weather the , is placed after the element or not
	   {
	     if(b[k]==1)
	     flag=1;
	   }
	    if(flag==1)
	     {
	       cout<<",";
	      }
	 }
	 }
	   cout<<"}";
       if(j!=n-1) // condtion to avoid , after the last element
       {
	 cout<<",";
       }
      }
	 cout<<"}";
   }
     getch();
 }