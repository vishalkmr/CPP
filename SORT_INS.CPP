#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int array[]={0,7,1,5,3,6,2,4};
int j,temp;
for(int i=1;i<=7;i++)
{
j=i-1;
temp=array[i];
while((array[j]>temp)&&j>=0)
{
array[j+1]=array[j];
j=j-1;
}

array[j+1]=temp;
}

for(int k=0;k<=7;k++)
 {
  printf("%d ",array[k]);
 }

getch();
}