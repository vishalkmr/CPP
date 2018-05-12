#include<time.h>
#include<iomanip.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
class student
{
 int roll;
 int marks;
 char name[60];
 char grade;
 protected:
 void computegrade();
 public:
 void modify();
 void read();
 int getroll();
 void display()
 {
  cout<<"\n"<<name<<"\t      "<<roll<<"\t      "<<marks<<"\t      "<<grade;

  /* if(grade=='a')
   {
    textattr(2);
    cout<<"\n";
    cprintf("%s",name);
    cprintf("         %d",roll);
    cprintf("         %d",marks);
    cprintf("         %d",grade);
    }
   if(grade=='b')
   {
    textattr(3);
    cout<<"\n"<<name<<"\t      "<<roll<<"\t      "<<marks<<"\t      "<<grade;
    }
   if(grade=='c')
   {
    textattr(4);
    cout<<"\n"<<name<<"\t      "<<roll<<"\t      "<<marks<<"\t      "<<grade;
    }
    if(grade=='d')
   {
    textattr(5);
    cout<<"\n"<<name<<"\t      "<<roll<<"\t      "<<marks<<"\t      "<<grade;
    }
   if(grade=='e')
   {
    textattr(6);
    cout<<"\n"<<name<<"\t      "<<roll<<"\t      "<<marks<<"\t      "<<grade;
    }
     */
 }

};
void student:: computegrade()
 {
  if(marks>85)
  grade='a';
  else  if(marks>75)
  grade='b';
  else  if(marks>65)
  grade='c';
  else  if(marks>50)
  grade='d';
  else
  grade='e';
  }
 void student:: read()
 {
  cout<<"\n enter the student name : ";
  gets(name);
  cout<<"\n enter the student roll number :";
  cin>>roll;
  cout<<"\n enter the student marks :";
  cin>>marks;
  computegrade();
  }
 void student ::modify()
 {
  cout<<"\n--enter the new details of student--";
  cout<<"\n enter the student name : ";
  gets(name);
  cout<<"\n enter the student roll number :";
  cin>>roll;
  cout<<"\n enter the student marks :";
  cin>>marks;
  computegrade();
  }
 int student ::getroll()
 {
    return roll;
  }
void main()
{
  clrscr();
  char ch;
  char fname[50]={"student.dat"};
  int choice,roll,pos;
  student std;
  ifstream fi;
  ofstream fo;
  while(1)
  {
    clrscr();
    cout<<"\n-----FILE MENU-----";
    cout<<"\n  1. write data on file";
    cout<<"\n  2. read data from file";
    cout<<"\n  3. modify the data of a given student";
    cout<<"\n  0. exit\n";
    cin>>choice;
    switch(choice)
    {
      case 1:
	   fo.open(fname,ios::app|ios::binary);
	   if(!fo)
	   {
	    cout<<"\n cant open the file";
	     break;
	   }
	   while(1)
	   {
	    std.read();
	    fo.write((char*)&std,sizeof(student));
	    cout<<" \n want to enter more data press(y/n)";
	    cin>>ch;
	    if(ch=='n')
	      break;
	    }
	   fo.close();
	   break;
       case 2:
	  fi.open(fname,ios::binary|ios::in);
	  if(!fi)
	   {
	    cout<<"\n cant open the file";
	     break;
	   }
	   textattr(4);
	   cprintf("\nname          roll            marks          grade");
	   textattr(7);
	   while(fi.read((char*)&std,sizeof(student)))
	    {
	     std.display();
	    }
	    getch();
	    fi.close();
	    break;
       case 3:
	   fi.open(fname,ios::binary|ios::in);
	    cout<<"\n enter the roll number of student ";
	    cin>>roll;
	    while(fi.read((char*)&std,sizeof(student)))
	     {
		if(roll==std.getroll())
		{
		cout<<"yes";
		std.modify();
		pos=fi.tellg()-sizeof(student);
		fo.open(fname,ios::ate|ios::binary);
		fo.seekp(pos,ios::beg);
		fo.write((char*)&std,sizeof(student));
		}
	     }
	     getch();
	     fi.close();
	     fo.close();
	     break;
       case 0:
		 exit(0);
    }//end of switch
  }//end of while
getch();
 }




