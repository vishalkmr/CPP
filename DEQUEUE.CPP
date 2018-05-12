//Program to implement dequeue using one dimension circular array
#include<conio.h>
#include<process.h>
#include<stdio.h>
int  addrear(int[],int*,int*,int,int);
int  delfront(int[],int*,int*, int);
int  addfront(int[],int
*,int*,int,int);
int  delrear(int[],int*,int*, int);

void display(int [],int ,int, int);

void main()
{
clrscr();
int queue[100],i,size,front,rear,choice,item,result;
front=-1;
rear=-1;
printf("\n Enter the size of deueue : ");
scanf("%d",&size);
do
{
  clrscr();
  printf("\n ******* DEQUEUE MENU *******");
  printf("\n\t 1. Addtion from rear");
  printf("\n\t 2. Deletion from front");
  printf("\n\t 3. Addtion from front");
  printf("\n\t 4. Deletion from rear");
  printf("\n\t 5. Exit ");
  printf("\n  Your choice : ");
  scanf("%d",&choice);
  switch(choice)
 {
   case 1: // Addtion from rear
      printf("\n Enter the value you want to add at rear end : ");
      scanf("%d",&item);
      result=addrear(queue,&front,&rear,item,size);
      if(!result)
       printf("\n Queue is full. Addition is not possible !");
       display(queue,front,rear,size);
      break;
    case 2 : // Deletion from front
      result=delfront(queue,&front,&rear,size);
      if(result == -999)
       printf("\n Queue empty . Deletion is not possible !");
      else
       {
	 printf("\n The deleted item is : %d ",result);
	 printf("\n");
	 display(queue,front,rear,size);
       }
      break;
     case 3: // Addtion from front
      printf("\n Enter the value you want to add at front end : ");
      scanf("%d",&item);
      result=addfront(queue,&front,&rear,item,size);
      if(!result)
       printf("\n Queue is full. Addition is not possible !");
       display(queue,front,rear,size);
      break;
     case 4 : // Deletion from rear
      result=delrear(queue,&front,&rear,size);
      if(result == -999)
       printf("\n Queue empty . Deletion is not possible !");
      else
       {
	 printf("\n The deleted item is : %d ",result);
	 printf("\n");
	 display(queue,front,rear,size);
       }
      break;


    case 5:
	 exit(0);
  }
   getch();
  }while(1);
getch();
}
// addrear() is used to add element at the rear end of the queue ,it returns 0 for queue underflow and 1 for succesful addtion
int  addrear(int queue[],int* front,int*rear,int item,int size)
{
  if(*rear==size-1 && *front==0 ||*front==(*rear+1)%size) // queue overflows
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
       *rear=(*rear+1)%size;  // circularly updation of *rear
	queue[*rear]=item;   // adding item at *front
    }
   return 1;
  }
}
// delfront() is used to delete element at the front end of the queue , it return -999 for queue overflow otherwise returns vlaue of deleted item
int  delfront(int queue[],int* front,int*rear, int size)
{
  int item;
  if(*front==-1)// queue underflow
    return -999;
  else
  {
     item= queue[*front]; // deleted front item
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
       *front=(*front+1)%size; // circularly updation of *front
      }
     return item;
   }
}
// addfront() is used to add element at the front end of the queue ,it returns 0 for queue underflow and 1 for succesful addtion
int  addfront(int queue[],int* front,int*rear,int item,int size)
{
  if(*rear==size-1 && *front==0 ||*front==(*rear+1)%size) // queue overflows
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
	if(*front==0)
	  *front=size-1;
	else
	 *front=(*front-1)%size;
	queue[*front]=item;   // adding item  at *front
    }
   return 1;
  }
}
// delrear() is used to delete element at the front end of the queue , it return -999 for queue overflow otherwise returns vlaue of deleted item
int  delrear(int queue[],int* front,int*rear, int size)
{
  int item;
  if(*front==-1)// queue underflow
    return -999;
  else
  {
     item= queue[*rear];  //deleted rear item
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
     if(*rear==0)
     *rear=size-1;
     else
       *rear=(*rear-1)%size; // circularly updation of *rear
      }
     return item;
   }
}

// display() is used to print the element of the queue
void display(int queue[],int front,int rear, int size)
{
     int i;
     if(front==-1)
       printf("\n Queue becomes empty !");
     else
      {
       printf("\n Queue Content :\n\t");
       if(rear>=front) // normal condition when rear>=front
       {
	printf("Front=>");
	for(i=front;i<=rear;i++)
	 printf(" | %d",queue[i]);
	 printf(" | <=Rear") ;
	}
       else
       {
	// when queue rear crosses 0 position then queue is divided in two parts
	printf("Front=>");
	for(i=front;i<size;i++) // part1 : queue from front to size-1 position
	 printf(" | %d",queue[i]);
	for( i=0;i<=rear;i++) // part2 : queue from 0 position to rear position
	 printf(" | %d",queue[i]);
	 printf(" | <=Rear") ;
	}
      }
}
