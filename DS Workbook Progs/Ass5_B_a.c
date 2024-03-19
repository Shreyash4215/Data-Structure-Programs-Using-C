#include<stdio.h>
#include"cstqueue.h"
int main()
{
	int n,ch;
	Q pq;
	init(&pq);
	do
	{
		printf("\n Enter 1: Add 2: Remove 3: Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if(isFull(&pq)==1)
				{
					printf("\n Queue is Full");
				}
				else
				{
					printf("\nEnter no to add=");
					scanf("%d",&n);
					add(&pq,n);
				}
				break; 
			case 2:
				if(isEmpty(&pq)==1)
					printf("\n Queue is empty");
				else
				{
					n=Remove(&pq);
					printf("\n Removed no = %d",n);	
				}
		}
	}while(ch!=3);
}
