// programme to evaluate the value of postfix expression
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int size =50;
void push(int[],int*,int);
int pop(int[],int*);
void main()
{
  clrscr();
  int top=-1;
  int s,i;
  char opr,oprend,postfix[100];
  int stack[100],result,p1,p2,poped;
  printf("\n enter the postfix expression : ");
  gets(postfix);
  s=strlen(postfix);
  printf("%d",s);
  for(i=0;i<=s;i++)
  printf("%c",postfix[i]);
  for(i=0;i<=s;i++)
  {
   if(postfix[i]=='^')
   {
       opr=postfix[i];
       p1=pop(stack,&top);
       p2=pop(stack,&top);
       result=p1^p2;
       push(stack,&top,result);
    }
   else
   if(postfix[i]=='*')
   {
       opr=postfix[i];
       p1=pop(stack,&top);
       p2=pop(stack,&top);
       result=p1*p2;
       push(stack,&top,result);
     }
   else
   if(postfix[i]=='/')
   {
       opr=postfix[i];
       p1=pop(stack,&top);
       p2=pop(stack,&top);
       result=p1/p2;
       push(stack,&top,result);
    }
   else
   if(postfix[i]=='+')
   {
       opr=postfix[i];
       p1=pop(stack,&top);
       p2=pop(stack,&top);
       result=p1*p2;
       push(stack,&top,result);
    }
   else
   if(postfix[i]=='-')
   {
       opr=postfix[i];
       p1=pop(stack,&top);
       p2=pop(stack,&top);
       result=p1-p2;
       push(stack,&top,result);
    }
   else
    {
	 oprend=postfix[i];
	 push(stack,&top,oprend);
    }
  }
  poped=pop(stack,&top);
  printf("\n  the result expression ");
  printf("%d",poped);
  getch();
}
void push(int stack[],int* top ,int item)
{

  if(*top==size-1)
     printf("\n stack is full ");
   else
    {
     *top=*top+1;
      stack[*top]=item;
     }
}
int pop(int stack[],int *top )
{
   int item;
   if(*top==-1)
     return -9999;
   else
   {
      item= stack[*top];
      *top=*top-1;
	return item;
     }

}
