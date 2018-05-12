#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<iostream.h>
#include<stdlib.h>
void main()
{
clrscr();
int n;
int a[100];
cout<<"Enter size :";
cin>>n;
cout<<"Enter elements : \n";
for(int k=0;k<n;k++)
cin>>a[k];

int b[100]={0};
int flag=1;
int i=n-1;
int j=0;
int carry=1;
int temp;
for(i=n-1;i>=0;i--)
{
      b[j]=(a[i]+carry)%10;
	carry=(a[i]+carry)/10;
	j++;
      if(carry>0 && i==0)
       { b[j]=carry;
	j++;
       }
  }

cout<<"\n Original Number";
for(i=0;i<n;i++)
printf("%d",a[i]);

cout<<"\n Result  :";
for(int l=j-1;l>=0;l--)
{
printf("%d",b[l]);
}

getch();

}
