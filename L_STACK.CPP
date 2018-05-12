// Program to implement linear Linked-Stack
#include<process.h>
#include <stdio.h>
#include<string.h>
#include <conio.h>
#include<alloc.h>
// structure for elements of Linked-Stack
struct node
{
 char value[10];
 struct node *next;// self-refrential structure node
};
// initialization  of global variables
  int size=sizeof(struct node);
  struct node *top=NULL;   // top points to top most element of Linked-Stack
// function declaration
  void push();
  void pop();
  void search();
  void display();
void  main()
{
 int choice;
 char ch;
 do
 {
  clrscr();
  printf("\n ************** LINKED-STACK MENU *****************");
  printf("\n\t 1. Push an elements on Linked-Stack");
  printf("\n\t 2. Pop of elements form Linked-Stack");
  printf("\n\t 3. Search an elements form Linked-Stack");
  printf("\n\t 4. Exit");
  printf("\n\tWhich operation you want to perform : ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
	   push();
	   display();
	   break;
    
    case 2:
	   pop();
	   display();
	   break;
   
    case 3:
	   search();
	   break;

    case 4:
	   exit(0);

    default :
	   printf("\n You have entered a wrong choice !");
	   break;

  }
   getch();
 }while(1);
   getch();
}
// function to PUSH items at the top of Linked-Stack
void push()
{
    struct node *insert_ptr;
    insert_ptr= (struct node *)malloc(size); // dynamic memory alocation
    // reading the information about node
    printf("\n Enter the element value you want to push : ");
    scanf("%s",&(insert_ptr->value));
    insert_ptr->next=NULL;
    if(insert_ptr== NULL) // memory overflow
      printf("\n Memmory is Full !");
    else if(top==NULL) // when linked-satck is initially  empty
     {
       top= insert_ptr;
     }
    else
     {
      insert_ptr->next=top;
      top=insert_ptr;
     }

}
// function to pop items from the top  of linked-stack
void pop()
{
    struct node *delete_ptr;
    if(top== NULL) // memory underflow
     {
       printf("\n linked-stack is empty. Deletion is not posible !");
       return;
      }
    delete_ptr=top; // pointing to element to be deleted
    if(top->next==NULL) // when Linked-Stack contains only one element
     {
      // after poping Linked-Stack becomes empty
      top=NULL;
      }
    else // otherwise
     {
      top=top->next; // updating top
      }
    printf("\n The poped element value is : %s \n",delete_ptr->value);
    free(delete_ptr); // memeory deallocation
}
// function to search a desired element form linked-stack
void search()
{
  char item[10];
  struct node* ptr;
  int count=1;
  printf("\n Enter the element you want to search :");
  fflush(stdin);
  scanf("%s",&item);
  ptr = top;
  while(ptr!=NULL)
   {
    if(!strcmp(item,ptr->value))
    {
     printf("\n Element found at %d position from Top of Linked-Stack ",count);
     return;
    }
    ptr=ptr->next;
    count++;
   }
   printf("\n Element doesn't find in Linked-Stack !" );


}

// function to display Linked-Stack contents using linked-list traversal
void display()
{
 if(top== NULL)
   printf("\n The LINKED-STACK is empty !");
 else
   {
    struct node *ptr;
    ptr= top;
    printf("\n Linked-Stack Content :\n");
    while(ptr)
     {
      if(ptr==top)
       {
	  printf("   TOP-> | %s | ",ptr->value);
	   printf("\n\t ------");

	}
      else
       {
	printf("\n\t | %s | ",ptr->value);
	printf("\n\t ------ ");
       }
       ptr=ptr->next;
      }
    }
}