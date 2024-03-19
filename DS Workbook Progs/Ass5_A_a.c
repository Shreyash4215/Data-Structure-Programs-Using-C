#include<stdio.h>
#include"stqueue.h"
int main()
{
Q *pq;
int n,ch;
creat(&pq);
do
{
printf("\n Enter 1-Add, 2-Remove, 3-Exit");
scanf("%d",&ch);
switch(ch)
{
case 1:if(isFull(&pq)==1)
		printf("\n Q is Full");
		else
		{
		printf("\n Enter no. to Add in a Q");
		scanf("%d",&n);
		Add(&pq,n);
		}
		break;
case 2:if(isEmpty(&pq)==1)
		printf("\n Underflow");
		else
		{
		n=Remove(&pq);
		printf("\nno.=%d",n);
		}
		break;
}
}while(ch!=3);
}
