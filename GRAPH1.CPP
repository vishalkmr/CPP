// Program to implement weighted undirected graphs using adjacent matrix
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
// global variables
static char adj[10][10];
static int choice,vertices,i,j;
void create_graph();
void insert_vertex();
void insert_edge();
void delete_vertex();
void delete_edge();
void display();
void main()
{
 clrscr();
 create_graph();
 display();
 getch();
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
// function to create the graph structure
void create_graph()
{
 char val;
 printf("\n Enter the number of vertex : ");
 scanf("%d",&vertices);
 for(i=1;i<=vertices;i++)  // inserting vertices name
 {
     printf("\n Enter the %d vertex : ",i);
     fflush(stdin);
     scanf("%c",&val);
     adj[i][0]=val;
     adj[0][i]=val;

 }
 // setting cooresponding edge to 0
 for(i=1;i<=vertices;i++)
  {
    for(j=1;j<=vertices;j++)
     {
       adj[i][j]='0';
       adj[j][i]='0';
     }

  }
}
// function to display the content of undirected graph
void  display()
{
  if(vertices<1)// empty  graph
     {
       printf("\n Undirected Graph is Empty !");
       return;
     }
   printf("\n Undirected Graph Contains :\n\t");
   for(i=0;i<=vertices;i++)
  {
    for(j=0;j<=vertices;j++)
     {
       printf(" %c ",adj[i][j]);
     }
    printf("\n\t");
  }

}
// function to insert an vertex to undirected graph
void insert_vertex()
{
 char vertex;
 printf("\n Enter the Vertex you want to insert : ");
 fflush(stdin);
 scanf("%c",&vertex);
 vertices++; // increasing no. of verteices
 // inserting vertex name
  adj[0][vertices]=vertex;
  adj[vertices][0]=vertex;
 // setting cooresponding edge to 0
  for(i=1;i<=vertices;i++)
   {
      adj[i][vertices]='0';
      adj[vertices][i]='0';
    }
}
// function to insert an edge to undirected graph
void insert_edge()
{
 char initial , final, weight;
 printf("\n Enter the First Vertex of edge : ");
 fflush(stdin);
 scanf("%c",&initial);
 printf("\n Enter the Second Vertex of edge : ");
 fflush(stdin);
 scanf("%c",&final);
 printf("\n Enter the Weigth of edge : ");
 fflush(stdin);
 scanf("%c",&weight);

 // setting cooresponding edge to 1
   for(i=0;i<=vertices;i++)
   {
      if(adj[i][0]==initial)
      {
	for(j=0;j<=vertices;j++)
	{
	  if(adj[0][j]==final)
	   {
	     adj[i][j]=weight;
	     adj[j][i]=weight;
	   }
	 }
       }
    }
}
// function to delete an vertex to undirected graph
void delete_vertex()
{
 char vertex;
 int pos;
 printf("\n Enter the Vertex you want to delete : ");
 fflush(stdin);
 scanf("%c",&vertex);
 // finding cooresponding position of vertex
  for(i=1;i<=vertices;i++)
   {
      if(adj[0][i]==vertex)
       {
	 pos=i;
	 break;
       }
    }
 // shifting the vertex to override/overlap the deleted vertex and cooresponding positons
  for(i=pos;i<vertices;i++)    // right to left fold
   {
     for(j=0;j<=vertices;j++)
       {
	 adj[j][i]=adj[j][i+1];
	}
    }
  for(i=pos;i<vertices;i++)    // bootom to top fold
   {

	 for(j=0;j<=vertices;j++)
       {
	 adj[i][j]=adj[i+1][j];
	}
  }
 vertices--; // decreasing no. of verteices
}
// function to delete an edge to undirected graph
void delete_edge()
{
 char initial,final;
 printf("\n Enter the First Vertex of edge : ");
 fflush(stdin);
 scanf("%c",&initial);
 printf("\n Enter the Second Vertex of edge : ");
 fflush(stdin);
 scanf("%c",&final);
 // setting cooresponding edge to 1
   for(i=0;i<=vertices;i++)
   {
      if(adj[i][0]==initial)
      {
	for(j=0;j<=vertices;j++)
	{
	  if(adj[0][j]==final)
	   {
	     adj[i][j]='0';
	     adj[j][i]='0';
	   }
	 }
       }
    }
}