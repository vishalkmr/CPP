#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int arr1[100],arr2[100],arr3[100],i=0,j=0,k=0,l=0,temp=0,n,carry=0;

n3;

for(i=0;i<100;i++)
arr3[i]=0;

cout<<"\n enter the 1st number :\n ";
for(i=0;i<n;i++)
cin>>arr1[i];


cout<<"\n enter the 2nd number :\n ";
for(i=0;i<n;i++)
cin>>arr2[i];
int carry1=0;
int p=0;

for(j=n-1;j>-1;j--)
{
 for(i=n-1;i>-1;i--)
  {

  temp=arr1[i]*arr2[j]+carry;
    carry=temp/10;
    temp=temp%10;
    carry1=(temp+arr3[k])/10;
    arr3[k++]=(temp+arr3[k])%10;
	arr3[k]=arr3[k]+carry1;
    //  cout<<"\n  " <<arr1[i]<<"   "<<arr2[j]<<"   "<<temp<<"   "<<arr3[k-1]<<"   "<<carry<<"   "<<carry1<<"  ";
  //  for(int x=6;x>-1;x--)
//    cout<<arr3[x];



 }// 1st loop

  if(carry>0)
  {
  arr3[k++]=carry;
  carry=0;
  }
 if(carry1>0)
 {
 arr3[k-1]=arr3[k-1]+carry1;
 carry1=0;
 }
l=k;
  k=++p;
//cout<<"\n \t";
  //  for(int x=6;x>-1;x--)
    //cout<<arr3[x];

}

cout<<"\n the multiplication of numbers is :\n     ";
for(i=l;i>-1;i--)
cout<<arr3[i];



getch();
}