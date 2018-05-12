// Program to implement directed graph using linked list
#include<process.h>
#include <stdio.h>
#include<string.h>
#include <conio.h>
#include<alloc.h>
struct succesor  // for succesor of a vertex node
{
 char value[10];
 int weight;
 struct succesor *connected;// self-refrential structure node
};
struct vertex   // for each vertex
{
 char value[10];
 struct succesor *connected;
 struct vertex *next; // self-refrential structure node
};

// initialization  of global variables
  int size1=sizeof(struct vertex);
  int size2=sizeof(struct succesor);
  struct vertex *head=NULL;   // head points to starting vertex of graph
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
 clrscr();
do
{
 clrscr();
 printf("\n********** UNDIRECTED GRAPH MENU ********* ");
 printf("\n\t 1. Insertion of Vertex ");
 printf("\n\t 2. Insertion of Edge  ");
 printf("\n\t 3. Deletion of Vertex ");
 printf("\n\t 4. Deletion of Edge ");
 printf("\n\t 5. Exit \n  Your choice : ");
 scanf("%d",&choice);
  switch(choice)
  {

   case 1 :
	 insert_vertex();
	 display();
	 break;

   case 2 :
	 insert_edge();
	 display();
	 break;

   case 3 :
	 delete_vertex();
	 display();
	 break;

   case 4 :
	 delete_edge();
	 display();
	 break;

    case 5 :
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
// function to insert a given vertex in directed graph
void insert_vertex()
{
   struct vertex *v_ptr;
   v_ptr= (struct vertex *)malloc(size1); // dynamic memory alocation
	 // reading the information about vertex
    printf("\n Enter the vertex name : ");
    scanf("%s",&(insert_ptr->value));
    insert_ptr->next=NULL;
    insert_ptr->connected=NULL;
    if(insert_ptr== NULL) // memory overflow
      printf("\n Memmory is Full !");
    else if(head==NULL) // when graph is initially  empty
     {
       head= v_ptr;
      }

    else
     {
      insert_ptr->next=head;
	head=insert_ptr;
     }
}

// function to insert an edge in directed graph
void insert_edge()
{
   int weight;
   cahr initial[10],final[10];
   struct vertex *ptr;
   struct succesor *insert_ptr;
   ptr= (struct vertex *)malloc(size1); // dynamic memory alocation
   insert_ptr= (struct vertex *)malloc(size2); // dynamic memory alocation
   // reading the information about vertex
    printf("\n Enter the Initial vertex name : ");
    scanf("%s",&initial);
    printf("\n Enter the Final vertex name : ");
    scanf("%s",&final);
    printf("\n Enter the Weight of edge : ");
    scanf("%d",&weight);
    insert_ptr->next=NULL;
    insert_ptr->connected=NULL;
    if(insert_ptr== NULL) /	/ memory overflow
      printf("\n Memmory is Full !");
    else if(head==NULL) // when graph is initially  empty
     {
       head= insert_ptr;
      }

    else
     {
      insert_ptr->next=head;
	head=insert_ptr;
     }





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
