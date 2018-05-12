// Program to implement addition and deletion of elements of a liner queue using one dimension array
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
int  addrear(int[],int*,int*,int,int);
int  delfront(int[],int*,int*);
void display(int [],int ,int);
void main()
{
clrscr();
int queue[100],i,front,rear,choice,item,result;
int size;
printf("\n Enter the size of queue : ");
scanf("%d",&size);
front=-1;
rear=-1;
do
{
  clrscr();
  printf("\n ***** LINEAR QUEUE MENU  ****** ");
  printf("\n\t 1. Addtion ");
  printf("\n\t 2. Deletion ");
  printf("\n\t 3. Exit  \n  Your choice : ");
  scanf("%d",&choice);
  switch(choice)
 {
    case 1:
      printf("\n Enter the value you want to add : ");
      scanf("%d",&item);
      result=addrear(queue,&front,&rear,item,size);
      if(!result)

       printf("\n Queue is full. Addition is not possible !");
       display(queue,front,rear);
      break;
    case 2 :
      result=delfront(queue,&front,&rear);
      if(result == -999)
       printf("\n Queue empty . Deletion is not possible !");
      else
       {
	 printf("\n The deleted item is : %d ",result);
	 printf("\n");
	 display(queue,front,rear);
       }
      break;
     case 3:
	 exit(0);
  }
   getch();
}while(1);
getch();
}
// addrear() is used to add element at the rear end of the queue ,it returns 0 for queue underflow and 1 for succesful addtion
int  addrear(int queue[],int* front,int*rear,int item,int size)
{
  if(*rear==size-1) // queue overflows
    return 0;
    else
  {
   /* when queue is initially  empty  means after addition
     the added item is front as well as rear */
   if(*rear==-1)
   {
      *rear=0;
      *front=0;
      queue[*rear]=item;

    }
   //otherwise
   else
    {
       *rear=*rear+1;
	queue[*rear]=item;
    }
   return 1;
  }
}
// delfront() is used to delete element at the front end of the queue , it return -999 for queue overflow otherwise returns vlaue of deleted item
int  delfront(int queue[],int* front,int*rear)
{
  int item;
  if(*front==-1)// queue underflow
    return -999;
  else
  {
     item= queue[*front];
    /* when queue contain only one element
       means after deletion the queue is empty */
    if(*rear==*front)
    {
      *rear=-1;
      *front=-1;
     }
     //otherwise
     else
     {
       *front=*front+1;
      }
     return item;
   }
}
// display() is used to print the element of the queue
void display(int queue[],int front,int rear)
{
     if(front==-1)
       printf("\n Queue becomes empty !");
     else
      {
       printf("\n Queue Content :\n\t");
       printf("Front=>");
       for(int i=front;i<=rear;i++)
	printf(" | %d",queue[i]);
       printf(" | <=Rear") ;

      }
}
