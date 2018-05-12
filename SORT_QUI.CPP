#include<stdio.h>
#include<conio.h>
int partition(int array[],int lb,int ub)
{
int i,j,pivot,temp;
pivot=array[lb];
i=lb+1;
j=ub;



while(i<=j)
{
while(array[i]<=pivot && i<=j)
   i++;
while(array[j]>pivot && i<=j)
   j--;
if(i<j)
{
temp=array[i];
array[i]=array[j];
array[j]=temp;
}
}
temp=array[j];
array[j]=array[lb];
array[lb]=temp;


  printf("\n %d \n",i);
  for(int k=0;k<=7;k++)
 {
  printf("%d ",array[k]);
 }

return j;

}

void quicksort(int array[],int lb,int ub)
{
 if(lb<=ub)
 {
  int pivot=partition(array,lb,ub);

  quicksort(array,lb,pivot-1);
  quicksort(array,pivot+1,ub);
 }

}

void main()
{
clrscr();
int array[]={5,7,0,2,1,3,6,4};
quicksort(array,0,7);
for(int k=0;k<=7;k++)
 {
  printf("%d ",array[k]);
 }

getch();
}