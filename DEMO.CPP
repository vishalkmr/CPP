#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
class motion
{
int x,y;// FOR COORDINATES
int oprx,opry; //for storing the value of preivious increment and decriment
int cases;
int clr; // for differnt colours when word hit the lines
char word[100];  // word which moves in screen
int len;// lenth of word
public:
void frame(); // to form the frame
void pointer();
void check(); // check the values of x and y ,then set various cases
void setxy(); // depending upon certain cases it increment/deciment the x,y
};
void motion::pointer()
{
  // x=10...50   y=2..20
  oprx=0;
  opry=0;
  cases=0;
  clr=random(12)+1;
  textattr(4);
 cprintf(" Enter the word : ");
 // cprintf("\n enter the word ");
  gets(word);
  len=strlen(word);// calculating the length of word
  x=9+random(40); // randomize the value of x initialy
  y=2+random(16); // randomize the value of y initialy
  for(int i=0;i<50;i++)
 {
  clrscr();
   frame(); // making frames
   setxy(); // setting the values of x,y
  gotoxy(x,y); //move the pointer to desired values of x,y
  sound(10*random(100)); //for sound effect
  delay(100);
  nosound();
  if(cases!=1)//the case when the word stricks the boundaries and the colour of word changed
  {
    clr=random(12)+1;
    textattr(clr);
  }
  else
  textattr(clr);
  cprintf("%s",word);
  delay(30);
  textattr(7);

   }
}
void motion::check()
{
  if(y>2 && y<20 && x>10 && x<(51-len))
   cases=1;// inside
   else if(x==(51-len) && y==20)
   cases=2;
   else if(x==(51-len)&& y==2)
   cases=3;
   else if(x==10 && y==20)
   cases=4;
   else if(x==10 && y==2)
   cases=5;
   else if(y==2)
   cases=6; //outside y
    else if(y==20)
   cases=7; //outside y
   else if(x==10)
   cases=8; //outside x
   else if(x==(51-len))
   cases=9; //outside x
}

void motion::setxy()
{
  check();
  switch(cases)
  {
  case 1: // lies inside the block
	  if(oprx==0)
	  x--;
	  if(oprx==1)
	  x++;
	  if(opry==0)
	  y--;
	  if(opry==1)
	  y++;
	  break;
  case 2: // for corner of bottom right side
	  x--;
	  y--;
	  oprx=0;
	  opry=0;
	  break;
  case 3:// for corner of upper right side
	  x--;
	  y++;
	  oprx=0;
	  opry=1;
	  break;
  case 4: // for corner of bottom left side
	  x++;
	  y--;
	  oprx=1;
	  opry=0;
	  break;
 case 5:  // for corner of upper left side
	  x++;
	  y++;
	  oprx=1;
	  opry=1;
	  break;
  case 6:// for top line y=1
	  y++;
	  opry=1;
	  if(oprx==0)
	  x--;
	  if(oprx==1)
	  x++;
	  break;
   case 7://for bottom line y=21
	  y--;
	  opry=0;
	  if(oprx==0)
	  x--;
	  if(oprx==1)
	  x++;
	  break;
  case 8: //for left side line x=9
	  x++;
	  oprx=1;
	  if(opry==0)
	  y--;
	  if(opry==1)
	  y++;
	  break;
   case 9: //for right side line x=51
	  x--;
	  oprx=0;
	  if(opry==0)
	  y--;
	  if(opry==1)
	  y++;
	  break;

   }
}

void motion::frame()
{
cout<<"\t*******************************************\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*                                         *\n";
cout<<"\t*******************************************\n";

}

void main()
{
 clrscr();
 randomize();
 motion obj;
 obj.pointer();
 getch();
}



