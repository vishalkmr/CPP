// Program to implement linear linked list
#include<process.h>
#include <stdio.h>
#include<string.h>
#include <conio.h>
#include<alloc.h>
// structure for elements of linked-list
struct node
{
 char value[10];
 struct node *next;// self-refrential structure node
};
// initialization  of global variables
  int size=sizeof(struct node);
  struct node *start=NULL;   // start points to starting element of linked-list
  struct node *back=NULL;    // back points to last element of linked-list
// function declaration
  void insert_beginning();
  void insert_end();
  void delete_beginning();
  void delete_end();
  void search();
  void reversal();
  void display();
void  main()
{
 int choice;
 char ch;
 do
 {
  clrscr();
  printf("\n ************** LINKED LIST MENU *****************");
  printf("\n\t 1. Insertion of elements at Beginnig");
  printf("\n\t 2. Insertion of elements at End");
  printf("\n\t 3. Deletion of elements form Beginnig");
  printf("\n\t 4. Deletion of elements form End");
  printf("\n\t 5. Search an elements form Linked-List");
  printf("\n\t 6. Reversing the elements of Linked-List");
  printf("\n\t 7. Exit");
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
	   reversal();
	   display();
	   break;
    case 7:
	   exit(0);

    default :
	   printf("\n You have entered a wrong choice !");
	   break;

  }
   getch();
 }while(1);
   getch();
}
// function to insert items at the beginning of linked-list
void insert_beginning()
{
    struct node *insert_ptr;
    insert_ptr= (struct node *)malloc(size); // dynamic memory alocation
    // reading the information about node
    printf("\n Enter the element value you want to insert at beginnig : ");
    scanf("%s",&(insert_ptr->value));
    insert_ptr->next=NULL;
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
      start=insert_ptr;
     }

}
// function to insert items at the end of linked-list
void insert_end()
{
    struct node *insert_ptr;
    insert_ptr= (struct node *)malloc(size); // dynamic memory alocation
    // reading the information about node
    printf("\n Enter the element value you want to insert at end : ");
    scanf("%s",&(insert_ptr->value));
    insert_ptr->next=NULL;
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
      back=insert_ptr;
     }

}
// function to delete items from the beginning of linked-list
void delete_beginning()
{
    struct node *delete_ptr;
    if(start== NULL) // memory underflow
     {
       printf("\n Linked-list is empty. Deletion is not posible !");
       return;
      }
    delete_ptr=start; // pointing to element to be deleted
    if(start==back) // when linked-list contains only one element
     {
      // after deletion linked-list becomes empty
      start=NULL;
      back=NULL;
      }
    else // otherwise
     {
      start=start->next; // updating start
      }
    printf("\n The deleted element value is : %s \n",delete_ptr->value);
    free(delete_ptr); // memeory deallocation
}
// function to delete items from the end of linked-list
void delete_end()
{
    struct node *delete_ptr,*second_last,*last;
    if(start== NULL) // memory underflow
     {
       printf("\n Linked-list is empty. Deletion is not posible !");
       return;
      }
    delete_ptr=back; // pointing to element to be deleted
    if(start==back) // when linked-list contains only one element
     {
      // after deletion linked-list becomes empty
      start=NULL;
      back=NULL;
     }
    else // otherwise
     {
      last=start;
      second_last=start;
       while(last!=back) // loop to find second_last elements of linked-list
	{
	 second_last=last;
	 last=last->next;
	}
      // updating back
      back=second_last;
      back->next=NULL;
     }
    printf("\n The deleted element value is : %s \n",delete_ptr->value);
    free(delete_ptr); // memeory deallocation
}
// function to search a desired element form liked-list
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
     printf("\n Element found at %d position in Liked-List ",count);
     return;
    }
    ptr=ptr->next;
    count++;
   }
   printf("\n Element doesn't find in Liked-List !" );
}
// function to reverse the orderof items  of the linked-list
void reversal()
{
    struct node *prev,*curr,*ahead;
    if(start== NULL) // memory underflow
     {
       printf("\n Linked-list is empty !");
       return;
      }
    if(start!=back)//means more then 1 elements in the Liked-List
    {
      prev=start;
      curr=start;
      ahead=curr->next;
      start->next=NULL; // 1st element become last element
       while(ahead!=NULL)
	{
	 curr=ahead;
	 ahead=ahead->next;
	 curr->next=prev;
	 prev=curr;
	}
     start=curr;// now start points to last element
     }
}


// function to display linked-list contents using traversal
void display()
{
 if(start== NULL)
   printf("\n The linked list is empty !");
 else
  {
   struct node *ptr;
   ptr= start;
   printf("\n Linked-List Content :\n    ");
   while(ptr)
   {
     printf(" | %s | ->",ptr->value);
     ptr=ptr->next;
   }
   printf(" NULL");

  }
}