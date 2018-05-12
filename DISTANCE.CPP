// wap to add to distances given in feet ,inch and meter, centemetre
// 2.54 cm=1 inch
// 1 foot = 12 inch
// 3 feet = 1 yard
// 1760 yards = 1 mile
// 8 km = 5 mile
#include<conio.h>
#include<iostream.h>
class mc;
class fi
{
int feet;
int inch;
public:
void get_distance();
void display_distance();
friend void add_distance(fi,mc);
};
void fi:: get_distance()
{
cout<<"\n enter the distance details :";
cout<<"\n feet =";
cin>>feet;
cout<<" inch =";
cin>>inch;
}
void fi:: display_distance()
{
cout<<"\n the distance details is :";
cout<<"\n feet ="<<feet;
cout<<"\n inch ="<<inch;
}
class mc
{
int meter;
int cen;
public:
void get_distance();
void display_distance();
friend void add_distance(fi,mc);
};
void mc:: get_distance()
{
cout<<"\n enter the distance details :";
cout<<"\n meter =";
cin>>meter;
cout<<" centimeter =";
cin>>cen;
}
void mc:: display_distance()
{
cout<<"\n the distance details is:";
cout<<"\n meter ="<<meter;
cout<<"\n centimeter ="<<cen;
}
void add_distance(fi fob ,mc mob)
{
int choice,inches,centimter,meters,feets;
cout<<"\n in which form you want the result :";
cout<<"\n press 1 for distance in feet and inch";
cout<<"\n press 2 for distance in meter and centimeter \n";
cin>>choice;
if(choice==1)
{
  inches=(mob.meter*100+mob.cen)/2.54;  // cnv of meter & centimeter into inches
  fob.inch=fob.inch+inches; // total inches
  fob.feet=fob.feet+(fob.inch/12);
  fob.inch=(fob.inch)%12;
  fob.display_distance();
}
else
{
  centimter=(fob.feet*12+fob.inch)*2.54; // cnv of feet & inches into centimeter
  mob.cen=mob.cen+centimter; // total centimeter
  mob.meter=mob.meter+(mob.cen/100);
  mob.cen=mob.cen%100;
  mob.display_distance();
}
}
void main()
{

  clrscr();
  fi obj1;
  mc obj2;
  obj1.get_distance();
  obj2.get_distance();
  add_distance(obj1,obj2);
  getch();
}