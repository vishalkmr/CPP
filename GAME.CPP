#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<timer.h>
int function(int num1,int num2,int op);
void evaluation();
int score;
void main()
{
  clrscr();
  int num1,result,num2,op,ans,score;
  int time=0;
//   textattr(7);
  randomize();
  while (1)
 {
      clrscr();
   cout<<"time :"<<time<<"\tscore :"<<score<<"\n";
   num1=random(20);
   num2=random(20);
   op=rand()%4;
   result=function(num1,num2,op);
   cout<<"\a"<<num1;

   switch(op)
   {
    case 0:
     cout<<"\a +";
     break;
    case 1:
     cout<<"\a/";
     break;
    case 2:
     cout<<"\a*";
     break;
    case 3:
     cout<<"\a-";
     break;
    }
   cout<<"\a "<<num2;
   cout<<" = ";
   cin>>ans;
   if(ans==result)
   {
     score++;
/*     textattr(5+BLINK);
     textbackground(9);
     cout<<"RIGHT !!!";
     delay(100);
     textbackground(0);
     textattr(9);
  */
    }
 //  else
 //   textbackground(0);
   //    cout<<"RIGHT !!!";
    time++;
    if(time>=10)
    {
    break;
    }
 }
  getch();
}
int function(int num1,int num2,int op)
{
  int result=0;
   switch(op)
   {
    case 0:
     result=num1+num2;
     break;
    case 1:
     result=num1/num2;
    break;
    case 2:
     result=num1*num2;
    break;
    case 3:
     result=num1-num2;
    break;
    }
  return result;
}

 /*void evaluation()
{
  printf("\n your score is %d", score);
  if(score>temp-2)
  printf("\n you are a genius");
  else if(score==0)
  printf("\n you need to work hard ");
  else
  printf("\n you are a average player ");

}*/