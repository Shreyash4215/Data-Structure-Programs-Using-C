#include<stdio.h>
#include<malloc.h>

typedef struct Queue
{
	int data;
	struct Queue *next;
}Q;
Q *rear;
void create()
{
	rear=NULL;
}
int isEmpty()
{
	return rear==NULL;
}
void Add(int n)
{
	Q *newnode;
	newnode=(Q *)malloc(sizeof(Q));
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
int Peek()
{	
	Q *front=rear->next;
	return front->data;
}
