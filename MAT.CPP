#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int mat1[3][3]={1,2,3,4,5,6,7,8,9};
int mat2[3][3]={1,2,3,4,5,6,7,8,9};
int mat3[3][3],temp[3][3];
int i,j,k;
for(i=0;i<3;i++)
{ for( j=0;j<3;j++)
  {
    mat3[i][j]=0;
    for(k=0;k<3;k++)
    {
	mat3[i][j]=mat1[i][k]*mat2[k][j]+mat3[i][j];
     }
    }
}
for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
  {
     cout<<mat3[i][j];
     cout<<" ";
   }
   cout<<"\n";
   }
 getch();
}