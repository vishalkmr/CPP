#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
int identifier(char [],int);
int string_ending_with_abb(char string[],int length);
void main()
{
	clrscr();
	char string[100];
	int choice,length;
	char ch;
	while(1)
	{
		clrscr();
		printf("\n Enter the string : ");
		fflush(stdin);
		gets(string);
		length=strlen(string);
		printf("\n--- Menu for string %s--\n 1.Identifier\n 2. Contant\n 3. (a|b)*abb\n 4.Exit \n ",string);
		scanf("%d",&choice);
		switch(choice)
		 {
			 case 1:
				   if(identifier(string,length))
				   {
						printf("\n Valid Identifier");
					}
				   else
				   {
						printf("\n Invalid Identifier");
					}
					break;
			case 2: break;
			case 3:     if(string_ending_with_abb(string,length))
				       {
					printf("\n Stirng can be gernerated by regular expressiona (a|b)*abb");
				       }
				     else
				     {
					printf("\n Stirng cannot be gernerated by regular expressiona (a|b)*abb");

				     }
				    break;

			case 4: exit(0);
			default:
					printf("\n You enterd wrong choice !");
		 }
	      getch();
	    }
	getch();
}

int identifier(char string[],int length)
{
     if((string[0]>=95&&string[0]<=122)||(string[0]>=65&&string[0]<=99)||string[0]=='_')
	{
		 for(int i=0;i<length;i++)
		{
			if((string[i]>=95&&string[i]<=122)||(string[i]>=65&&string[i]<=99)||string[i]=='_'||( string[i]>=48&&string[i]<=57))
				continue;
			else
				return 0;
		}
		return 1;
	}
     else
	{
	 return 0;
	}

}
int string_ending_with_abb(char string[],int length)
{
 int F=0,S1=0,S2=0,I=1,D=0;
 for(int i=0;i<length;i++)
 {
  if(I==1&&string[i]=='b')
    {  I=1;}
  else if(I==1&&string[i]=='a')
     { S1=1; I=0; }
  else if(S1==1&&string[i]=='a')
     { I=1;  S1=0;}
  else  if(S1==1&&string[i]=='b')
     { S2=1; S1=0; }
  else if(S2==1&&string[i]=='a')
     { S1=1; S2=0; }
  else if(S2==1&&string[i]=='b')
     { F=1; S2=0; }
  else if(F==1&&string[i]=='b')
     { I=1; F=0; }
  else if(F==1&&string[i]=='a')
     { S1=1; F=0; }
  else
    { D=1;F=0;S1=0;S2=0;I=1; }
 }
cout<<"\nF"<<F<<" I"<<I<<" S1"<<S1<<" S2"<<S2<<" D"<<D;
if(F==1)
 return 1;
else
 return 0;

}