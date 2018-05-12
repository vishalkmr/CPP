#include<stdio.h>
#include<conio.h>
void merge(int array[], int lb, int mid,int ub)
{
int i ,j,k;
int extra_array[100];
i=lb;
j=mid+1;
k=lb;
while(i<=mid && j<=ub)
{
if(array[i]<array[j])
  {
   extra_array[k]=array[i];
   i++;
   k++;
  }
else
  {
  extra_array[k]=array[j];
  k++;
  j++;
  }

}
while(i<=mid)
{
   extra_array[k]=array[i];
   i++;
   k++;

}
while(j<=ub)
{
   extra_array[k]=array[j];
   j++;
   k++;

}

for(int l=0;l<=ub;l++)
{
array[l]=extra_array[l];
}

}


void mergesort(int array[],int lb,int ub)
{
 if(lb<ub)
  {
    int mid=(ub+lb)/2;
    mergesort(array,lb,mid);
    mergesort(array,mid+1,ub);
    merge(array,lb,mid,ub);
  }
}

void main()
{
clrscr();
int array[]={-5,1,0,2,4,3,7,6};
mergesort(array,0,7);
for(int i=0;i<=7;i++)
{
printf("%d ",array[i]);

}


getch();
}