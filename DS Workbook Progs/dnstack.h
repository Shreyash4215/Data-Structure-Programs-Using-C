#include<stdio.h>

typedef struct stack
{	
	int data;
	struct stack *next;
}ST;
ST *top;
void create()
{
	top=NULL;
}
int isEmpty()
{
	return(top==NULL);
}
void Push(int ch)
{
	ST *newnode;
	newnode=(ST *)malloc(sizeof(ST));
	newnode->data=ch;
	newnode->next=NULL;
	if(top==NULL)
		top=newnode;
	else
	{
		top->next=newnode;
		top=newnode;
	}
}

int Pop()
{
	ST *temp=top;
	int ch=temp->data;
	
	return ch;
}
