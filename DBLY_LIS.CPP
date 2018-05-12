// Program to implement doubly linked list
#include<process.h>
#include <stdio.h>
#include<string.h>
#include <conio.h>
#include<alloc.h>
// structure for element of Doubly-Linked-List
struct node
{
 char value[10];
 struct node *next;// self-refrential structure node
 struct node *prevoius; // self-refrential structure node
};
// initialization  of global variables
  int size=sizeof(struct node);
  struct node *start=NULL;   // start points to starting element of Doubly-Linked-List
  struct node *back=NULL;    // back points to last element of Doubly-Linked-List
// function declaration
  void insert_beginning();
  void insert_end();
  void delete_beginning();
  void delete_end();
  void search();
  void display();
void  main()
{
 int choice;
 char ch;
 do
 {
  clrscr();
  printf("\n ************** DOUBLY LINKED LIST MENU *****************");
  printf("\n\t 1. Insertion of elements at Beginnig");
  printf("\n\t 2. Insertion of elements at End");
  printf("\n\t 3. Deletion of elements form Beginnig");
  printf("\n\t 4. Deletion of elements form End");
  printf("\n\t 5. Search an elements form Doubly-Linked-List");
  printf("\n\t 6. Exit");
  printf("\n\tWhich operation you want to perform : ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
	   insert_beginning();
	   display();
	   break;
    case 2:
	   insert_end();
	   display();
	   break;

    case 3:
	   delete_beginning();
	   display();
	   break;
    case 4:
	   delete_end();
	   display();
	   break;

    case 5:
	   search();
	   break;

    case 6:
	   exit(0);

    default :
	   printf("\n You have entered a wrong choice !");
	   break;

  }
   getch();
 }while(1);
   getch();
}
// function to insert items at the beginning of Doubly-Linked-List
void insert_beginning()
{
    struct node *insert_ptr;
    insert_ptr= (struct node *)malloc(size); // dynamic memory alocation
    // reading the information about node
    printf("\n Enter the element value you want to insert at beginnig : ");
    scanf("%s",&(insert_ptr->value));
    insert_ptr->next=NULL;
    insert_ptr->prevoius=NULL;
    if(insert_ptr== NULL) // memory overflow
      printf("\n Memmory is Full !");
    else if(start==NULL) // when linked list is initially  empty
     {
       start= insert_ptr;
       back=insert_ptr;
     }
    else
     {
      insert_ptr->next=start;
	  start->prevoius=insert_ptr;
	  start=insert_ptr;
     }

}
// function to insert items at the end of Doubly-Linked-List
void insert_end()
{
    struct node *insert_ptr;
    insert_ptr= (struct node *)malloc(size); // dynamic memory alocation
    // reading the information about node
    printf("\n Enter the element value you want to insert at end : ");
    scanf("%s",&(insert_ptr->value));
    insert_ptr->next=NULL;
    insert_ptr->prevoius=NULL;
	if(insert_ptr== NULL) // memory overflow
      printf("\n Memmory is Full !");
    else if(start==NULL) // when linked list is initially  empty
     {
       start= insert_ptr;
       back=insert_ptr;
     }
    else
     {
      back->next=insert_ptr;
      insert_ptr->prevoius=back;
	  back=insert_ptr;
     }

}
// function to delete items from the beginning of Doubly-Linked-List
void delete_beginning()
{
    struct node *delete_ptr;
    if(start== NULL) // memory underflow
     {
       printf("\n Doubly-Linked-List is empty. Deletion is not posible !");
       return;
      }
    delete_ptr=start; // pointing to element to be deleted
    if(start==back) // when Doubly-Linked-List contains only one element
     {
      // after deletion Doubly-Linked-List becomes empty
      start=NULL;
      back=NULL;
      }
    else // otherwise
     {
      start=start->next; // updating start
      start->prevoius=NULL;
	  }
    printf("\n The deleted element value is : %s \n",delete_ptr->value);
    free(delete_ptr); // memeory deallocation
}
// function to delete items from the end of Doubly-Linked-List
void delete_end()
{
    struct node *delete_ptr;
    if(start== NULL) // memory underflow
     {
       printf("\n Doubly-Linked-List is empty. Deletion is not posible !");
       return;
      }
    delete_ptr=back; // pointing to element to be deleted
    if(start==back) // when Doubly-Linked-List contains only one element
     {
      // after deletion Doubly-Linked-List becomes empty
      start=NULL;
      back=NULL;
     }
    else // otherwise
     {
      // updating back
      back=back->prevoius;
      back->next=NULL;
     }
    printf("\n The deleted element value is : %s \n",delete_ptr->value);
    free(delete_ptr); // memeory deallocation
}
// function to search a desired element form doubly-linked-list
void search()
{
  char item[10];
  struct node* ptr;
  int count=1;
  printf("\n Enter the element you want to search :");
  fflush(stdin);
  scanf("%s",&item);
  ptr = start;
  while(ptr!=NULL)
   {
    if(!strcmp(item,ptr->value))
    {
     printf("\n Element found at %d position in Doubly-Linked-List ",count);
     return;
    }
    ptr=ptr->next;
    count++;
   }
   printf("\n Element doesn't find in Doubly-Linked-List !" );


}

// function to display Doubly-Linked-List contents using traversal
void display()
{
 if(start== NULL)
   printf("\n The Doubly-Linked-List is empty !");
 else
  {
   struct node *ptr;
   ptr= start;
   printf("\n Doubly-Linked-List Content :\n ");
   printf(" NULL <=>");
   while(ptr)
   {
     printf("| %s |<=>",ptr->value);
     ptr=ptr->next;
   }
   printf(" NULL");

  }
}