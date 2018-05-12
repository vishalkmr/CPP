#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
class tic_tac
{
  char arr[9];//to store the mark  of player`s
  int flag;// to denote winning condtion
  int pos; // to set the desired mark at particular postion
  int mode;// to denote the modes of playing , single or two player mode
  protected:
  int player; //to denote various players
  void introduction();
  void mode1();
  void mode2();
  void com_input();
  void player1_input();
  void player2_input();
  void show_frame();
  void check();
  void winner();
  public:
  void module();

};
// function to give introduction about game and to get initial data from user
void tic_tac::introduction()
{
  clrscr();
  cout<<"\n\t********************* Welcome ********************** ";
  cout<<"\n\t******** You are Playing Tic-Tac-Toe Game ********** ";
  cout<<"\n\t**************************************************** ";
  cout<<"\n\t  In this Game Player have to Enter the Position \n\t    This Postion set The Player`s Mark \n\t   To Given Location on Tic -Tac_Toe Board ";
  cout<<"\n   --- The Postions on the Tic-Tac-Toe Board Is Shown Below ---\n\n\t\t";
  for(int j=0;j<9;j++)
  {
   cout<<" "<<j;
    if (j==5)
      cout<<"\n\t\t--------------\n\t\t";
    else if(j==2)
      cout<<"\n\t\t--------------\n\t\t";
    else if(j!=8)
      cout<<" : ";
  }
  cout<<"\n\t   There are Two Modes To Play This Game";
  cout<<"\n\t   1. One Player Mode OR To Play With Compuetr ";
  cout<<"\n\t   2. Two Player Mode OR To Play With Another Player ";
  while(1)
  {
  cout<<"\n\t   Enter Your Choice(1/2) : ";
  cin>>mode;
  if(mode==1||mode==2)
  break;
  }
  char ch;
 if(mode==1)
 cout<<"\n If you want to take  1st tern press (y/n)";
 if(mode==2)
 cout<<"\n If player 1 wants to take 1st tern press (y/n)";
 cin>>ch;
 if(ch=='y'||ch=='Y')
 player=1;
 else
 player=2;

}
// function to set the initial vlue of different data and it set the mark to desied location
void tic_tac::module()
{
 introduction();
  // set the intial array with spaces
 for(int j=0;j<9;j++)
   arr[j]=' ';
 flag=0;
 int i=0;
 //loop which continue upto all the position are filled or it will break if wiining condtion is encountered
 show_frame();
 while(i<9)
 {
  if(player==1)
   {
    player1_input();
    show_frame();
    player=2;
   }
  else if(player==2 && mode==1)
   {
    com_input();
    show_frame();
    player=1;
   }
  else if(player==2 && mode==2)
   {
    player2_input();
    show_frame();
    player=1;
   }
   check();
   winner();
   if(flag ==1)
   break;
   i++;
 }
if(i==9)
cout<<"\n No Player win !!! It is a Tie";
}

// this function checks the winning condtion
void tic_tac::check()
{
   if(arr[0]==arr[1]&&arr[1]==arr[2]&&arr[1]!=' ')
   flag=1;
   else if(arr[3]==arr[4]&&arr[4]==arr[5]&&arr[4]!=' ')
   flag=1;
   else  if(arr[6]==arr[7]&&arr[7]==arr[8]&&arr[7]!=' ')
   flag=1;
   else if(arr[0]==arr[3]&&arr[3]==arr[6]&&arr[3]!=' ')
   flag=1;
   else if(arr[1]==arr[4]&&arr[4]==arr[7]&&arr[4]!=' ')
   flag=1;
   else if(arr[2]==arr[5]&&arr[5]==arr[8]&&arr[5]!=' ')
   flag=1;
   else if(arr[0]==arr[4]&&arr[4]==arr[8]&&arr[4]!=' ')
   flag=1;
   else if(arr[2]==arr[4]&&arr[4]==arr[6]&&arr[4]!=' ')
   flag=1;
}
// thiis function decides who is the winner
void tic_tac::winner()
{
  if(flag==1)
  {
   if(player==1 && mode==1) // computer have player=2 which is changed after input so we compare player==1
     cout<<"\n computer wins !!! ";
   if(player==1 && mode==2)
     cout<<"\n Player 2 wins !!! ";
   if(player==2 && mode==1)
    cout<<"\n You wins !!! ";
   if(player==2 && mode==2)
     cout<<"\n Player 1  wins !!! ";
  }

}
// taking input from user or player 1
void tic_tac::player1_input()
{
while(1)
{
if(mode==1)
cout<<"\n You enter the postion : ";
else
cout<<"\n Player 1 enter the position  : ";
cin>>pos;
if(arr[pos]==' ')
  break;
}
arr[pos]='X';
}
// taking input  player 2
void tic_tac::player2_input()
{
while(1)
{
cout<<"\n Player 2 enter the position  : ";
cin>>pos;
if(arr[pos]==' ')
  break;
}
arr[pos]='O';
}
// set which postion computer will choose
void tic_tac::com_input()
{
   int defend,attack;
   defend=0;
   attack=0;
  //this code checks weather in next tern oponetnt is going to win ,if yes then it defends
  for(int i=0;i<8;i++)
  {
    if(arr[i]==' ')
    {
      arr[i]='X';
      check();
      arr[i]=' ';
      if(flag==1)
      {
	pos=i;
	defend=1;
	flag=0;
	break;
      }
     }
  }
  //this code checks weather in next tern computer is going to win ,if yes then it take that step
    for( i=0;i<8;i++)
  {
    if(arr[i]==' ')
    {
      arr[i]='O';
      check();
      arr[i]=' ';
      if(flag==1)
      {
	pos=i;
	attack=1;
	flag=0;
	break;
      }
    }
  }
  if(attack==1) // computer wins after this step
    {
    arr[pos]='O';
       cout<<"\n computer attacks *--> and choose position ... ";
	delay(100);
	cout<<pos;
	 delay(1000);

    }
  else if(defend==1)// computer defend or stop the player to wins after this step
    {
    arr[pos]='O';
	cout<<"\n computer defended *--) and choose position ... ";
	delay(100);
	cout<<pos;
	 delay(1000);

    }
  else
    while(1)
   {

    pos=random(8);
    if(arr[pos]==' ')
     {
	arr[pos]='O';
	cout<<"\n computer choose position ... ";
	delay(100);
	cout<<pos;
	 delay(1000);
	 break;
      }
   }

}

void tic_tac:: show_frame()
{
 clrscr();
 cout<<"\n*******>>>> TIC TAC TOE GAME <<<<********";
 if(mode==1)
 cout<<"\n*     You : X        Computer : O       *";
 else
 cout<<"\n*   Player 1 : X      Player 2 : O      *";
 cout<<"\n*****************************************";
 cout<<"\n*                                       *\n*\t ";
 for(int j=0;j<9;j++)
  {
   cout<<" "<<arr[j];
    if (j==5)
      cout<<"\t\t\t*\n*\t-------------\t\t\t*\n*\t ";
    else if(j==2)
      cout<<"\t\t\t*\n*\t-------------\t\t\t*\n*\t ";
    else if(j!=8)
      cout<<" : ";
  }
  cout<<"\t\t\t*\n*                                       *\n";
  cout<<"*****************************************\n\t";

}
void main()
{
clrscr();
randomize();
char ch;
tic_tac object;
do
{
object.module();
cout<<"\n Wants To Play Again......\n  press(y/n) \n ";
cin>>ch;
}while(ch=='y'||ch=='Y');
getch();
}
