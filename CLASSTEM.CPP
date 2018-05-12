// program to implement the concept of template class
#include<iostream.h>
#include <conio.h>
#include<stdio.h>
#include<math.h>
// declaring a class for  generic data type using template
template<class type >
class sample
{
  type a;
  public:
  sample(type x)
  {
   a=x;
  }
  void display();
};
template<class type >
void sample<type>::display																																																																					()
{
cout<<"\n the data member is : ";
cout<<a;
}
int main(void)
{
   clrscr();
   // for class having integer data member
   sample<int>obj1(34);
   obj1.display();
    // for class having stringr data member
   sample<char>obj2('v');
    obj2.display();
    // for class having integer data member
   sample<float>obj3(4.6);
     obj3.display();
   getch();
   return 0;
}
