// programme to implement the various operation on arrays
#include<conio.h>
#include<stdio.h>
//#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
void traversal(int[],int);
void insertion(int[],int*,int,int);
void deletion(int[],int*,int);
int linearsearch(int[],int,int,int*);
int binarysearch1(int[],int,int,int*);
int binarysearch2(int[],int,int,int*);
void exchangesort(int[],int);
void selectionsort(int[],int);
void insertionsort(int[],int);
void bubblesort(int[],int);
void quicksort(int[],int,int );
int partition(int[],int,int);
void mergesort(int[],int,int);
void merge(int[],int,int,int);
void main()
{
  clrscr();
  int array[100],size,item,result,i,choice,c,pos;
  char ch;
  printf("\n enter the size of array :\n ");
  scanf("%d",&size);
  printf("\n enter the elements of array :" );
  for( i=0;i<size;i++)
  {
     printf("\n enter the %dth element of array : ",i+1);
     scanf("%d",&array[i]);
   }

   do
   {
    clrscr();
    printf ("\n ---- array opertion menu ---- ");
    printf("\n\t 1. traversal ");
    printf("\n\t 2. search");
    printf("\n\t 3. inseration ");
    printf("\n\t 4. deletion ");
    printf("\n\t 5. sorting ");
    printf("\n\t 6. exit \n ");
    scanf("%d",&choice);
    switch(choice)
    {
    // 1 travesal
    case 1:
	       traversal(array,size);
	       break;

    // 2 search
    case 2:
	     printf("\n which type of searching algorithm you want to use ");
	     printf("\n 1. linear search ");
	     printf("\n 2. binary search \n ");
	     scanf("%d",&c);
	     switch(c)
	     {
	       // 2.1 linear search
	       case 1 :
		       printf("\n enter the element you want to search \n");
		       scanf("%d",&item);
		       result=linearsearch(array,size,item,&pos);
		       if(result==1)
		       printf("\n the element is found at %dth position of array",pos);
		       else
		       printf("\n the element is not found in array ");
		       break;
	       // 2.2 binary search
	       case 2 :
		       printf("\n for using the  binary search the array must be in ascendin or descending order");
		       printf("\n 1.  array is in ascending order");
		       printf("\n 2.  array is in descending order");
		       printf("\n 3.  array is neither in ascending or descending order and exit");
		       scanf("%d",&c);
		       switch(c)
		       {
			 // 2.2.1 binarysearch for ascending array
			 case 1:
			   printf("\n enter the element you want to search \n");
			   scanf("%d",&item);
			   result=binarysearch1(array,size,item,&pos);
			   if(result==1)
			   printf("\n the element is found at %dth position of array",pos);
			   else
			   printf("\n the element is not found in array ");
			   break;

			 // 2.2.2 binarysearch for descending array
			 case 2:
			   printf("\n enter the element you want to search \n");
			   scanf("%d",&item);
			   result=binarysearch2(array,size,item,&pos);
			   if(result==1)
			   printf("\n the element is found at %dth position of array",pos);
			   else
			   printf("\n the element is not found in array ");
			   break;

			 case 3:
			   break;

			 default:
			   printf("\n you entered the wrong entery ");
			}
		       break;
	       default :
		       printf("\n you entered the wrong entery ");
	      }
	       break;

    // 3 insertion
    case 3 :
	printf("\n enter the elment and postion to which you want to insert the new element \n");
	scanf("%d%d",&item,&pos);
	insertion(array,&size,item,pos);
	traversal(array,size);
	break;

    // 4 deletion
    case 4 :
	printf("\n enter the element which you want to delete from the array ");
	scanf("%d",&item);
	deletion(array,&size,item);
	traversal(array,size);
	break;

    // 5 sorting
    case 5 :
	printf("\n which type of sorting algorithm you want to choose ");
	printf("\n\t 1. exchange sort");
	printf("\n\t 2. selection sort");
	printf("\n\t 3. insertion sort");
	printf("\n\t 4. bubble sort");
	printf("\n\t 5. quick sort");
	printf("\n\t 6. mege sort\n ");
	scanf("%d",&c);
	switch(c)
	 {
	   // 5.1 exchange sort
	   case 1:
		  exchangesort(array,size);
		  traversal(array,size);
		  break;

	   // 5.2 selection sort
	   case 2:
		  selectionsort(array,size);
		  traversal(array,size);
		  break;

	   // 5.3 insertion sort
	   case 3:
		  insertionsort(array,size);
		  traversal(array,size);
		  break;
	   // 5.4 bubble sort
	   case 4:
		  bubblesort(array,size);
		  traversal(array,size);
		  break;

	   // 5.5 qiuck sort
	   case 5:
		  quicksort(array,0,size-1);
		  traversal(array,size);
		  break;

	   // 5.6 merge sort
	   case 6:
		  mergesort(array,0,size-1);
		  traversal(array,size);
		  break;
	   default :
		 printf("\n you enter the wrong entery ");
	 }
	 break;

    case 6 :
	     exit(0);
	     break;
    default :
	printf("\n you entered the wrong entery ");
     }
   printf("\n want to perform more operation press y/n \n");
   fflush(stdin);
   scanf("%c",&ch);
  }while (ch=='y');

     getch();
 }

//traversal ()is used to travel the elements of array
void traversal(int array[],int size)
{
 int i;
 printf("\n  the array contains : ");
 for (i=0;i<size;i++)
 printf("\n  array[%d] = %d",i,array[i]);
}

//linearsearch() is used to find an item using linear search
int linearsearch(int array[],int size,int item,int *pos)
{
 int i,flag;
 flag=0;
 for (i=0;i<size;i++)
 {
    if(array[i]==item)
    {
       flag=1;
       *pos=i;
       break;
    }
  }
 if(flag==1)
 return 1;
 else
 return 0;
 }

//binarysearch1() is used to find an item in array of acending order using binary search
int binarysearch1(int array[],int size,int item,int *pos)
{
 int i,flag,beg,last,mid;
 beg=0;
 last=size-1;
 mid=(beg+last)/2;
 flag=0;
 while(beg<=last)
 {
  if (array[mid]==item)
    {
    flag=1;
    break;
    }
  else
  if(array[mid]<item)
    {
     beg=mid+1;
     }
  else
     last=mid-1;
  // updation of mid
  mid=(beg+last)/2;
  }
 *pos=mid;
 if(flag==1)
 return 1;
 else
 return 0;
}

//binarysearch2() is used to find an item in array of descending order using binary search
int binarysearch2(int array[],int size,int item,int *pos)
{
 int i,flag,beg,last,mid;
 beg=0;
 last=size-1;
 mid=(beg+last)/2;
 flag=0;
 while(beg<=last)
 {
  if (array[mid]==item)
    {
    flag=1;
    break;
    }
  else
  if(array[mid]<item)
    {
     last=mid-1;
     }
  else
     beg=mid+1;
  // updation of mid
  mid=(beg+last)/2;
  }
 *pos=mid;
 if(flag==1)
 return 1;
 else
 return 0;
}

//insertion() is used to insert an item at disired location
void insertion(int array[],int *size,int item,int pos)
{
 int i;
 for(i=*size;i>pos;i--)
 {
   array[i]=array[i-1];
 }
 array[pos]=item;
 *size=*size+1;
}

// deletion() is used to delete an element froom array
void deletion(int array[],int*size,int item)
{
 int i,pos,result;
 //  first we have to find the loaction of element to be deleted
    result=linearsearch(array,*size,item,&pos);
    if(result!=1)
    {
     printf("\n the element is not found and deletion cannot performed ");
     return;
    }
 // now we have to delete the element using cocept of overwriting
 for(i=pos;i<*size-1;i++)
 {
   array[i]=array[i+1];
 }
 *size=*size-1;
}

/* quicksort() is used to
  1. find pivote
  2. update lower bound
  3. call the partition */
void quicksort(int list[],int lb,int ub)
{
  int split;
  if(lb<ub)
  {
  split=partition(list,lb,ub);
  quicksort(list,lb,split-1);
  quicksort(list,split+1,ub);
  }
}
/* partition is  used to divide the array in two list such that
   left list elements is less than pivote
   right list elements is grater than pivote */
int partition(int list[],int lb,int ub)
{
  int i,j,temp,pivote;
  pivote=list[lb];
  i=lb+1;
  j=ub;
  while(i<=j)
  {
    while(pivote>=list[i] && i<=j)
      i++;
    while(pivote<list[j] && i<=j)
      j--;
    if(i<j)
    {
     temp=list[i];
     list[i]=list[j];
     list[j]=temp;
     }
  }
  temp=list[lb];
  list[lb]=list[j];
  list[j]=temp;
  return j;
}

// exchangesort
void  exchangesort(int array[],int size)
{
 int i,j,temp;
 for(i=0;i<size;i++)
 {
  for(j=i+1;j<size;j++)
  {
    if(array[i]>array[j])
    {
      temp=array[i];
      array[i]=array[j];
      array[j]=temp;
    }
  }
 }
}

// selection sort
void selectionsort(int array[], int size)
{
 int temp,small,i,j,pos;
 for(i=0;i<size;i++)
 {
  small=array[i];
  pos=i;
  for(j=i+1;j<size;j++)
  {
   if(small>array[j])
   {
     small=array[j];
     pos=j;
   }
  }
  temp=array[i];
  array[i]=array[pos];
  array[pos]=temp;
 }
}

// insertion sort
void insertionsort(int array[],int size)
{
  int i,temp,j;
  for(i=1;i<size;i++)
  {
   temp=array[i];
   j=i-1;
   while(array[j]>temp&&j>=0)
   {
     array[j+1]=array[j];
     j--;
   }
  array[j+1]=temp;
  }
}

// bubble sort
void bubblesort(int array[],int size)
{
  int i,j,temp;
  for(i=0;i<size;i++)
  {
   for(j=0;j<size-i-1;j++)
   {
    if(array[j]>array[j+1])
    {
      temp=array[j];
      array[j]=array[j+1];
      array[j+1]=temp;
    }
   }
  }
}

/* merge sort()  it is used to
   1. divide the list into sublist until singelton is left
   2. join these sublist recursively */
void mergesort(int list[],int lb,int ub)
{
  int mid;
  if(lb<ub)
  {
    mid=(lb+ub)/2;
    mergesort(list,lb,mid);
    mergesort(list,mid+1,ub);
    merge(list,lb,mid,ub);
   }
}
// merge() is used to join the sublists created by mergesort()
void merge(int list[],int lb,int mid ,int ub)
{
  int i,j,mergelist[100],k;
  i=lb;
  k=lb;
  j=mid+1;
  while(i<=mid&&j<=ub)
  {
   if(list[i]>=list[j])
    {
     mergelist[k]=list[j];
     j++;
     k++;
    }
   else
    {
     mergelist[k]=list[i];
     i++;
     k++;
    }
  }
  while(i<=mid)
   {
    mergelist[k]=list[i];
    i++;
    k++;
   }
  while(j<=ub)
   {
    mergelist[k]=list[j];
    j++;
    k++;
   }
  for(int n=lb; n<=ub; n++)
   {
    list[n]=mergelist[n];
   }
}

