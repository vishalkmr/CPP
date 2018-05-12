// program to convert the infix expression to postfix expression
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int braces(char[]);
int size =50;
int precedence(char);
void push(char[],int*,char);
char pop(char[],int*);
void main()
{
 clrscr();
 int p,top,c,pce,pse;
 top=-1;
 char  stack[100],infix[100],postfix[100],poped,item;
 printf("\n enter the infix expression : \n\t ");
 gets(infix);
 c=braces(infix);
 if(c==1)
 {
 printf("\n entered expression is valid  ");
 }
 else
 {
 printf(" \n entered expression is invalid ");
 }
 p=0;
 int s=strlen(infix);
 for(int i=0;i<=s;i++)
 {
 /* when an operand is encounter then
    we take it to postfix expression or target side */
 if(infix[i]!='('&&infix[i]!=')'&&infix[i]!='^'&&infix[i]!='/'&&infix[i]!='*'&&infix[i]!='-'&&infix[i]!='+')
  {
     postfix[p]=infix[i];
     p++;
   }
 /* when left parenthesis is encounter then
     push it onto stack */
 else if(infix[i]=='(')
  {    item=infix[i];
     push(stack,&top,item);
   }
 /* when right prenthesis is encounter then
    repeatedly pop the element having grater precedence then incoming operator until left parenthesis is encountered
    pop the left prenthesis but it doesnot added to target side */
 else if( infix[i]==')')
  {
    while((poped=pop(stack,&top))!='(')
     {  postfix[p]=poped;
	p++;
     }
   }
 /* when an operator is encounter then
    we have to compare the precedence of incoming opretor/element with precedence of stack element
   1. if precedence of stack element is greater then or equal to precedence of incoming element then
     we repeatedly pop the element until precedence of incoming element is greater then precedence of stack element
   2. otherewise
     we push the element onto stack */
 else
  {   item=infix[i];
      pce= precedence(item);
      pse= precedence(stack[top]);
      if(pce>pse)
      push(stack,&top,item);
      else
      { while(pce<=pse)
	  {  poped=pop(stack,&top);
	      postfix[p]=poped;
	      p++;
	      pse= precedence(stack[top]);
	    }
	    push(stack,&top,item);
       }
    }
}
/* after scaning the infix expression some elements are left in the stack
   so we pop these elements until null is poped from the stack */
while((poped=pop(stack,&top))!='?')
{     postfix[p]=poped;
	      p++;
  }

printf("\n  the postfix expression\n\t ");
for(i=0;i<p;i++)
printf("%c",postfix[i]);
getch();
}
// push() is to push the given element into stack
void push(char stack[],int* top ,char item)
{
  int i;
  if(*top==size-1)
     printf("\n stack is full ");
   else
    {
     *top=*top+1;
      stack[*top]=item;
     }
}
/* pop() is to pop the element from stack and return back the poped element
   this return ? to indicate that null is poped or stack is empty*/
char pop(char stack[],int *top )
{
  int i;
  char item;
   if(*top==-1)
     return '?';
   else
   {
      item= stack[*top];
      *top=*top-1;
	return item;
     }

}
// braces() checks the validity of the expression on the basis parenthesis in the expression
int braces(char infix [])
{  char s[100];
   int  len,t;
   t=-1;
   len=strlen(infix);
    char poped;
    for(int i=0;i<=len;i++)
    {   if(infix[i]=='(')
	 push(s,&t,infix[i]);
	else if(infix[i]==')')
	     poped =pop(s,&t);
    }
       if(t==-1&&poped!='?')
	   return 1;
	  else
	  return 0 ;
     }

/*
this is another way to check validity without using stack
int braces(char infix [])
{
   int l,r,i,s;
   l=0;
   r=0;
   s=strlen(infix);
   printf(" %d",s);
   for(i=0;i<=s;i++)
   {
    if(infix[i]=='(')
      l++;
    else if (infix[i]==')')
      r++;
    }
  if(l==r)
    return 1;
   else
   return 0;
 } */
//prcedence() is used to calculate the precedence of given opertor
int precedence(char item)
{
   switch(item)
   {
     case '^': return 5;
     case '*': return 4;
     case '-': return 3;
     case '+': return 3;
     case '/': return 4;
     default:   return 0;
    }
}