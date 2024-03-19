#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int data;
	struct queue *next;
}Q;
Q * rear;
void init()
{
	rear=NULL;
}
int isEmpty()
{
	if(rear==NULL)
		return 1;
	else
		return 0;
}
void add(int n)
{
	Q *newnode;
	newnode=(Q*)malloc(sizeof(Q));
	newnode->data=n;	
	if(rear==NULL)
	{
		rear=newnode;
		rear->next=rear;
	}
	else
	{
		newnode->next=rear->next;
		rear->next=newnode;
		rear=newnode;
	}
}
int Remove()
{
	Q *front=rear->next;
	int n=front->data;
	if(rear->next==rear)
	{
		free(front);
		rear=NULL;
	}	
	else
	{
		rear->next=front->next;
		free(front);
	}
	return n;
}
