//Program to implement push and pop operation on stack using one dimension array
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void push(int[],int*,int,int);
void pop(int[],int*);
void display(int[],int*);
void main()
{
 clrscr();
 int stack[100],choice,size,item,top;
 top=-1;
 printf("\n Enter the size of stack : ");
 scanf("%d",&size);
do
{
 clrscr();
 printf("\n********** Menu ********* ");
 printf("\n\t 1. Push ");
 printf("\n\t 2. Pop  ");
 printf("\n\t 3. Exit \n  Your choice : ");
 scanf("%d",&choice);
  switch(choice)
  {
   //push
   case 1 :
       if(top==size-1)
	printf("\n Stack is full .Push operation is not possible !");
       else
       {
	printf("\n Enter the value you want to push on the stack : ");
	scanf("%d",&item);
	push(stack,&top,item,size);
	printf("\n The stack after push operation becomes :");
	display(stack,&top);
       }
	break;

   // pop
   case 2 :
       if(top==-1) // stack is empty
	printf("\n Stack is empty. Pop operation is not possible !");
       else
       {
	pop(stack,&top);
	if(top==-1) // stack is empty after poping
	 printf(" \n The stack is empty after pop operation ! ");
	else
	 {
	 printf("\n The stack after pop operation becomes :");
	 display(stack,&top);
	 }
	}
	 break;

    // exit
    case 3 :
	  exit(0);
	  break;

    // default case
    default:
       printf(" \n You enter the wrong choice !");
  }
  getch();
} while(1);
 getch();
}

//function to perform push operation on stack
void push(int stack[],int* top ,int item,int size)
{
  int i;
  if(*top==size-1)// stack overflow
     return;
  else
    {
     *top=*top+1;
      stack[*top]=item;
     }

}

//function to perform pop operation on stack
void pop(int stack[],int *top)
{
  int i,item;
  if(*top==-1)// stack underflow
     return;
  else
   {
      item= stack[*top];
      *top=*top-1;
      printf("\n The poped element is : %d ",item);
    }

}

// function to display the element of the stack
void  display(int stack[],int *top)
{
 int i;
 if(*top==-1) // stack empty
   return;
 else
 {
   for (i=*top;i>=0;i--)
  {
   if(i==*top)
   {
    printf("\n\n   TOP->") ;
    printf(" | %d",stack[i]);
   }
   else
   printf("\n\t | %d",stack[i]);
   printf(" |\n\t ------ ") ;
   }
 }
}