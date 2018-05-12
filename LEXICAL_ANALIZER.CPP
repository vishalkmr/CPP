/*****************************************************************************

      Program to generate token present in a file

*****************************************************************************/

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
struct token
{
   char name[100];
   char *type;
   int line_no;

};
struct token T[100];
int t=0;


char file_name[50]="PROGRAM.TXT";
char ch;
char str[100];

FILE *wp,*rp;

void append();
void read();
int check_keyword();
void token_generator(char[],int,int);
void program_parser();
int string_compare(char [], char[],int);
int valid_identifier(char [],int );
int valid_operator(char string[],int length);
int valid_keyword(char string[],int length);
void main()
{
  int choice,roll,pos;
  while(1)
  {
			fflush(stdin);
			clrscr();
			cout<<"\n-----FILE MENU-----";
			cout<<"\n  1. Write data on file";
			cout<<"\n  2. Read data from file";
			cout<<"\n  3. Generating tokens ";

			cout<<"\n  0. exit\n";
			cin>>choice;
			switch(choice)
			{
				  case 1:
				  append();
				  break;
				   case 2:

				   read();
					break;
				  case 3:
				       program_parser();
				     // for(int i=0;i<35;i++)
				     // cout<<"     "<<T[i].name;
				  /*
					//writing tokens into file
					FILE *fp;
					fp=fopen("TOKEN_TABLE.TXT","w");

					while(1)
					   {
						 fputs("\n--------------------->   Token Table  <--------------------",fp);
						 fputs("\n    Token Name  -----  Token Type  -----  Line NO",fp);
						  }
						 if(i>=t)break;
					       }
					 fclose(fp);
				    */		getch();

					break;
				   case 0:
					 exit(0);
			}//end of switch
  }//end of while

 getch();
 }
// Append the data at the end of file
void append()
{
	   wp=fopen(file_name,"a");
	   cout<<"\n Enter the data  : \n";
	   while(strlen(gets(str))>0)
	   {
		 fputs(str,wp);
		 fputs("\n",wp);
	      }
	      fclose(wp);
}
// Read the content of file
void read()
{   clrscr();
    int n=1,c=1,i;
    cout<<"\n Enter the file name : ";
    cin>>file_name;
    rp=fopen(file_name,"r");
	   if(rp)
	  {
	     while(1)
	     {
		// reading a character from the file
		ch=fgetc(rp);
		// checking end of file
		if (ch==EOF)
		 break;
	       // counting new line
		if (ch=='\n')
	      {

		cout<<"\t\t<"<<n<<">";
		 n=n+1;

	       }
	      delay(10);
	// printing the character
	      cout<<ch;
	     }// end of while loop
	  //   cout<<"line no "<<n;
	      fclose(rp);
	     }
	     getch();//to hold output
}


void program_parser()
{
	clrscr();
	char word[10000];
	int w=0;
	int n=1,c=0,i;
	int q0=1,q1=0,q2=0,q3=0,q4=0,q5=0,q6=0,q7=0,q8=0,q9=0;
	rp=fopen(file_name,"r");
		if(rp)
		{

		while(1)
		{
							// reading a character from the file
							ch=fgetc(rp);
							// checking end of file
							if (ch==EOF)
							break;
							// counting new line
							if (ch=='\n')
							{
								      cout<<"\n line no : "<<n<<" tokens :"<<c<<" ";
								int l=0;
								char temp[20];
								//token_generator(word,w,n);
								for(int i=0;i<w;i++)
								  {   if(word[i]!='|')
								       temp[l++]=word[i];
								      else
								      {
									for(int p=0;p<l;p++)
									 T[t].name[p]=temp[p];
									   T[t].line_no=int(10);
								       t++;
								       l=0;
								      }


								      cout<<word[i];
								   }

								   if(n==10)
								 break;

									c=0; 	n=n+1;
									w=0;
								}
							//##########   DFA  #######################
							/************************
							to remove comments

							q5 --> / arived
							q6  --> // arived
							q7 --> /* arrived
							q8 --> * arived
							******************************/
							if(ch=='/'&& q5==0 && q7!=1 && q8!=1&&q2!=1&&q6!=1)
								{
								q5=1;
								}

							// means / OR * not present AFTER /
							else if(q5==1&&ch!='/'&&ch!='*')
									{
									q6=0;
									q0=1;q1=0;q2=0;q4=0;q5=0;  q7=0;q8=0;
									++c;
									// that means  / is division operator
									word[w++]='|';
									word[w++]='/';
									word[w++]='|';
									word[w++]=ch;


									}

							// means single comment  present   / AFTER /
							else if(q5==1&&ch=='/')
									{
									q6=1;
									q0=0;q1=0;q2=0;q4=0;q5=0;

									}


							// means /* is present   * AFTER /
							else if(q5==1&&ch=='*')
										{
										q7=1;
										q0=0;q1=0;q2=0;q4=0;q5=0;q6=0;

										}


							// means * is present for */
							else if(q7==1&&ch=='*')
									{
									q8=1;
									q0=0;q1=0;q2=0;q4=0;q5=0;q6=0;q7=0;

									}
							// means / NOT PRESENT AFTER  *
							else if(q8==1&&ch!='/')
									{
									q8=1;
									q0=0;q1=0;q2=0;q4=0;q5=0;q6=0;q7=0;

									}
							// means / is present  AFTER *
							else if(q8==1&&ch=='/')
									{
									q8=0;
									q0=1;q1=0;q2=0;q4=0;q5=0;q6=0;q7=0;

									}


							//escaping the processing of elements present after //
							else if(q6==1&&ch=='\n')
									{
									q6=0;
									q0=1;q1=0;q2=0;q4=0;q5=0;

									}

							// for operators
							else if (q0==1&&(ch==')'||ch=='('||ch==';'||ch=='&'||ch==','||ch=='+'||ch=='#'||ch=='<'||ch=='>'||ch==';')||ch=='}'||ch=='{'||ch=='.'||ch=='&'||ch=='*'||ch=='-'||ch==','||ch==':'||ch=='/'||ch=='='||ch=='['||ch==']'||ch=='{'||ch=='}'||ch=='|'||ch=='&')


									{      //new word   & not the 1st one
									if(word[w-1]=='|'||w==0)
									{    ++c;
									word[w++]=ch;
									word[w++]='|';

									}
									else  if(w!=0) //word not completed yet new operator is coming
									{   ++c;
									word[w++]='|';
									++c;
									word[w++]=ch;
									word[w++]='|';
									}
									}



							/****************************
							for string
							q2 --> used to recognize string

							****************************/
							else	if (q0==1&&ch=='"')
									{   q2=1; q0=0; word[w++]=ch;   }
							else if (q2==1&&ch!='"')
									{   q2=1;  word[w++]=ch;  }

							else if (q2==1&&ch=='"')
									{
									++c;
									word[w++]=ch;
									word[w++]='|';

									q0=1;
									q2=0;
									}

							/***************************

							valid identifier start with a-z | A-Z | _

							q1 state is used to recognize identifiers

							*************************** */
							else if(q0==1&&((ch>=97&&ch<=122)||(ch>=65&&ch<=90)||ch=='_'))
									{  q1=1;q0=0; word[w++]=ch;	}
							else if (q1==1&&(ch>=97&&ch<=122)||(ch>=65&&ch<=90)||ch=='_'||(ch>=48&&ch<=57))
									{   q1=1;  word[w++]=ch; }
							/*********************
							for functions

							**********************/
							else if(q1==1&&(ch=='('))
									{
									++c;
									word[w++]='|';
									// for ) operaotor
									word[w++]=ch;
									c++;
									word[w++]='|';
									q0=1;
									q1=0;

									}
							/*
							to find the ending of the word
							*/
							else if(q1==1&&(ch=='<'||ch=='>'||ch==';'||ch==' '||ch=='('||ch==')'||ch=='+'||ch=='"'||ch=='['||ch=='.'||ch=='{'||ch==']'||ch=='}'))
										{


										++c;
										word[w++]='|';

										//to count seprating operator
										if(ch!='|'&&ch!=' ')
										{
										word[w++]=ch;
										word[w++]='|';
										++c;
										}
										q0=1;q1=0;
								   }

							// printing the character
							cout<<ch;
							}// end of while loop


	fclose(rp);

	}

}
/*void token_generator(char word[],int length,int line_no)
{
 char *keyword[20]={"int","void","if","else","return","char","float","for","switch","break"};
 int i=0,j=0,k=0,flag=0,s=0;
 char temp[20];
   for( i=0;i<length;i++)
   {
//    cout<<word[i];
	  if(word[i]!=' ') //copy word into temp
	  {
	    temp[j]=word[i];  j++;
	  }


	  else if(word[i]==' ') // end of word
	  {    // stroring into Token Structure
	       for(int l=0;l<j;l++)
	       T[t].name[l]=temp[l];
	       T[t].line_no=line_no;
	       // for operator
	       if(j==1&&(temp[0]=='+'||temp[0]=='-'||temp[0]=='/'||temp[0]=='*'||temp[0]=='('||temp[0]==')'||temp[0]=='<'||temp[0]=='>'||temp[0]=='{'||temp[0]=='}'||temp[0]=='['||temp[0]==']'||temp[0]=='.'||temp[0]==';'||temp[0]=='|'||temp[0]=='#'))
	       {
//	          cout<<"Operator ";
		    T[t].type="Operator";
		   flag=1;
		   }

	    //for keywords
	    for(k=0;k<10;k++)
	    {
	       if ( string_compare(keyword[k],temp,j) )
		   {
//		    cout<<"Keyword ";
		   T[t].type="Keyword";
		   flag=1;

		   }
	     }

	    if(valid_identifier(temp,j)&&!flag)
	       {
  //		  cout<<"Identifier ";
		  T[t].type="Identifier";
		}
		   j=0;
		flag=0;
		t++;
	  }




   }

} */
int string_compare(char keyword[],char word[],int len)
{
  int f=0,i,j;
  for(i=0;i<len;i++)
  {
   if(keyword[i]!=word[i])
   return 0;
  }
  return 1;
}
int valid_keyword(char string[],int length)
{
 char *keyword[20]={"int","void","if","else","return","char","float","for","switch","break"};
 int i=0,j=0,k=0,flag=0,s=0;
	    for(k=0;k<10;k++)
	    {
	       if ( string_compare(keyword[k],string,length) )
		   return 1;

	     }
	     return 0;

}
int valid_operator(char string[],int length)
{
	       if(length==1&&(string[0]=='+'||string[0]=='-'||string[0]=='/'||string[0]=='*'||string[0]=='('||string[0]==')'||string[0]=='<'||string[0]=='>'||string[0]=='{'||string[0]=='}'||string[0]=='['||string[0]==']'||string[0]=='.'||string[0]==';'||string[0]=='|'||string[0]=='#'))
		     return 1;
		 else
	     return 0;

}

int valid_identifier(char string[],int length)
{
     if((string[0]>=95&&string[0]<=122)||(string[0]>=65&&string[0]<=99)||string[0]=='_')
	{
		 for(int i=1;i<length;i++)
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
