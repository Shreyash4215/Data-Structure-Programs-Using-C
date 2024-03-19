// save this file ststack.c

#include<stdio.h>
#include "ststack.h"
int main()
{
int ch,n;
STACK s;
create(&s);
do
{
printf("\n Enter for 1.push, 2.pop, 3.stop=");
scanf("%d",&ch);
switch(ch)
{
case 1:if(isFull(&s)==1)
	printf("Overflow");
	else
	{
	printf("Enter no. to push=");
	scanf("%d",&n);
	push(&s,n);
	}
	break;
case 2:if(isEmpty(&s)==1)
	printf("Underflow");
	else
	{
	n=pop(&s);
	printf("Poped no.=%d",n);
	}
	break;
}
}while(ch!=3);
}

