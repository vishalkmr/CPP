// Program to implement linked-queue ( linear queue using linear linked list)
#include<process.h>
#include <stdio.h>
#include<string.h>
#include <conio.h>
#include<alloc.h>
// structure for elements of Linked-Queue
struct node
{
 char value[10];
 struct node *next;// self-refrential structure node
};
// initialization  of global variables
  int size=sizeof(struct node);
  struct node *front=NULL;   // front points to front element of Linked-Queue
  struct node *rear=NULL;    // rear points to last element of Linked-Queue
// function declaration
  void insert_end();
  void delete_beginning();
  void search();
  void display();
void  main()
{
 int choice;
 char ch;
 do
 {
  clrscr();
  printf("\n ************** LINKED-QUEUE MENU *****************");
  printf("\n\t 1. Addition of element on Linked-Queue");
  printf("\n\t 2. Deletion of elements form Linked-Queue");
  printf("\n\t 3. Search an elements form Linked-Queue");
  printf("\n\t 4. Exit");
  printf("\n\tWhich operation you want to perform : ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
	   insert_end();
	   display();
	   break;

    case 2:
	   delete_beginning();
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
// function to insert items at the rear end of Linked-Queue
void insert_end()
{
    struct node *insert_ptr;
    insert_ptr= (struct node *)malloc(size); // dynamic memory alocation
    // reading the information about node
    printf("\n Enter the element value you want to insert at rear end : ");
    scanf("%s",&(insert_ptr->value));
    insert_ptr->next=NULL;
    if(insert_ptr== NULL) // memory overflow
      printf("\n Memmory is Full !");
    else if(front==NULL) // when linked-queue is initially  empty
     {
       front= insert_ptr;
       rear=insert_ptr;
     }
    else
     {
      rear->next=insert_ptr;
      rear=insert_ptr;
     }

}
// function to delete items from the front end of Linked-Queue
void delete_beginning()
{
    struct node *delete_ptr;
    if(front== NULL) // memory underflow
     {
       printf("\n Linked-Queue is empty. Deletion is not posible !");
       return;
      }
    delete_ptr=front; // pointing to element to be deleted
    if(front==rear) // when Linked-Queue contains only one element
     {
      // after deletion Linked-Queue becomes empty
      front=NULL;
      rear=NULL;
      }
    else // otherwise
     {
      front=front->next; // updating front
      }
    printf("\n The deleted element value is : %s \n",delete_ptr->value);
    free(delete_ptr); // memeory deallocation
}
// function to search a desired element form linked-Queue
void search()
{
  char item[10];
  struct node* ptr;
  int count=1;
  printf("\n Enter the element you want to search :");
  fflush(stdin);
  scanf("%s",&item);
  ptr = front;
  while(ptr!=NULL)
   {
    if(!strcmp(item,ptr->value))
    {
     printf("\n Element found at %d position in Linked-Queue ",count);
     return;
    }
    ptr=ptr->next;
    count++;
   }
   printf("\n Element doesn't find in Linked-Queue !" );


}
// function to display Linked-Queue contents using Linked-List traversal
void display()
{
 if(front== NULL)
   printf("\n The Linked-Queue is empty !");
 else
  {
   struct node *ptr;
   ptr= front;
   printf("\n Linked-Queue Content :\n    ");
   printf("Front=>");
   while(ptr)
   {
     printf(" | %s ",ptr->value);
     ptr=ptr->next;
   }
     printf("| <=REAR");

  }
}