#include<stdio.h>
#include"dyqueue.h"
int main()
{
Q *pq;
int n,ch;
create (&pq);
do
{
printf("\n Enter 1-Add, 2-Remove, 3-Exit");
scanf("%d",&ch);
switch(ch)
{
case 1:
		printf("\n Enter no. to Add in a Q=");
		scanf("%d",&n);
		Add(n);
		break;
case 2:if(isEmpty( )==1)
		printf("\n Underflow");
		else
		{
		n=Remove( );
		printf("\nno.=%d",n);
		}
		break;
}
}while(ch!=3);
}
