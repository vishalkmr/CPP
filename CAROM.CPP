#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
class carom
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

void carom::frame()
{
cout<<"\t*******************************************\n";
cout<<"\t**                                       **\n";
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
cout<<"\t**          			          **\n";
cout<<"\t*******************************************\n";

}

void main()
{
 clrscr();
 line(1,2,3,4);
  getch();
}