
/*
E->E+T/T
T->T*F/F
F->i/(E)

Final grammer after removing left recursion (E` = A and T`=B)

 E->TA
 A->NULL/+TA
 T->FB
 B->NULL/*FB
 F->i/(E)


*/
#include<iostream.h>
#include <conio.h>
#include<stdio.h>
#include <string.h>

char look_ahead;
void E();
void F();
void A();
void T();
void B();
int flag=0;
void main()
{
	clrscr();
	cout<<"\nEnter the string ending with $ :";
	look_ahead=getchar();
	E();
	if(look_ahead=='$'&&flag==0)
		cout<<"\n Entered string is valid";
	else
		cout<<"\n Entered string is not valid";
	getch();
}
//  E->TA
void E()
{
    cout<<"\n E->TA ";
	T();
	A();
}

// A->NULL / +TA
void A()
{
	if(look_ahead=='+')
	{
		cout<<"\n A->+TA \t+";
		look_ahead=getchar();
		T();
		A();
	 }
	else
	{
	    cout<<"\n A->NULL ";
		return;
	 }
}

//  T->FB
void T()
{
	cout<<"\n T->FB ";
	F();
	B();
}

// B->NULL / +FB
void B()
{
	if(look_ahead=='*')
	{
		cout<<"\n B->*FB \t*";
		look_ahead=getchar();
		F();
		B();
	}
	else
	{    cout<<"\n B->NULL ";
		return;
	 }
}



// F->i / (E)
void F()
{    
	if(look_ahead=='i')
	{
	   cout<<"\n F->i   \ti ";
	   look_ahead=getchar();
	 }
    else if(look_ahead=='(')
	 {
	   cout<<"\n F->(E)   \t( ";
	   look_ahead=getchar();
	   E();
	   if(look_ahead==')')
	    {
	         look_ahead=getchar();
	         cout<<"\n F->(E)   \t) ";
	      }
	   else
	     flag=1;
	 }
    else
	    flag=1;
}
