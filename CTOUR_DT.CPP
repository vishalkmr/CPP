// program to show various types of constructor and distructor
#include<conio.h>
#include<iostream.h>
class C
{
  int i;
  float j;
  public:
   C() // default constructor
   {
    i=0;
    j=0;
   }
   C(int x) //parameterized constructor with one parameter
   {
    i=x;
    j=0;
   }
   C(int x,float y) //parameterized constructor with two parameter
   {
    i=x;
    j=y;
   }
   void display()
   {
     cout<<"\n\n i="<<i;
     cout<<"\n j="<<j;
    }
   C( C &obj) // copy constructor
   {
    i=obj.i;
    j=obj.j;
   }
  ~C()  // distructor
   {
   cout<<"\n destruction of object";
   }
};// end of class
void main()
{
    clrscr();
    int x;
    float y;
    C a(10); // object construction using parameterized constructor with one parameter
    a.display();
    C b(1,7.7);// object construction using parameterized constructor with two parameter
     b.display();
    C c(b); //object construction using copy constructor
    c.display();
    cout<<"\n\n enter the desired value of i and j for object \n";
    cin>>x>>y;
    C d(x,y); // object creation using dynamic value provideedby user
    d.display();
    getch();
 }