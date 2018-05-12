// program to create calculator of basic arithmetics operations
#include<iostream.h>
#include<conio.h>
#include<dos.h>

float addition(float,float);
float subtraction(float,float);
float multiplication(float,float);
float division(float,float);

void main()
{
	float operand1, operand2, result;
	char operator1, choice;
	clrscr();

	do
	{       clrscr();

		cout<<"Enter the 1st operand : ";
		cin>>operand1;

		cout<<"Enter the operator (+,-,*,/) : ";
		cin>>operator1;

		cout<<"Enter the 2nd operand : ";
		cin>>operand2;

		switch(operator1)
		{
			case '+':
				result=addition(operand1,operand2);
				break;

			case '-':
				result=subtraction(operand1,operand2);
				break;

			case '*':
				result=multiplication(operand1,operand2);
				break;

			case '/':
				if(operand2==0)
				cout<<"\n division is not possible !!!";
				else
				result=division(operand1,operand2);
				break;

			default:
				cout<<"Invalid operator, try again";
				break;

		}

		cout<<"\nProcessing";
		delay(500);
		cout<<".";
		delay(500);
		cout<<".";
		delay(500);
		cout<<".";
		delay(500);
		cout<<"\n";
		cout<<operand1<<" "<<operator1<<" "<<operand2<<" = "<<result;

		cout<<"\nDo you want to continue (y/n) : ";
		cin>>choice;

	 }while(choice !='n');

	getch();

}

float addition(float operand1, float operand2)
{
	float result;
	result=operand1+operand2;
	return result;
}

float subtraction(float operand1, float operand2)
4{
	float result;
	result=operand1-operand2;
	return result;
}

float multiplication(float operand1, float operand2)
{
	float result;
	result=operand1*operand2;
	return result;
}

float division(float operand1, float operand2)
{
	float result;
	result=operand1/operand2;
	return result;
}