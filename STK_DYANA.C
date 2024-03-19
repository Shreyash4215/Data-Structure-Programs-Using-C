#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct stack
{
	int data;
	struct stack *next;
};

struct stack *top,*newNode,*temp;

int i,c;
void push();
void pop();
void display();

main()
{
	top=NULL;
	
	while(1)
	{
		printf("\n\n\t 1.push \n\t 2.pop \n\t 3.display \n\t 4.exit");
		printf("\n\t Enter your choice : ");
		scanf("%d",&c);
		
		switch(c)
		{
			case 1:
					push();
					break;
			case 2:
					pop();
					break;
			case 3:
					display();
					break;
			case 4:
					exit(0);
		}
	}
}

void push()
{
	newNode=(struct stack *)malloc(sizeof(struct stack));
	printf("\n Enter the no. to push : ");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	
	if(top==NULL)
		top=newNode;
	else
		newNode->next=top;
		
	top=newNode;
}

void pop()
{
	temp=top;

	if(top==NULL)
		printf("\n Stack is empty");
	else
	{
		printf("\n poped element = %d",temp->data);
		top=top->next;
		temp->next=NULL;
		free(temp);
	}
}

void display()
{
	temp=top;

	if(top==NULL)
		printf("\n Stack is empty");
	else
		printf("\nThe elements in stack are : ");

	while(temp!=NULL)
	{
		printf("\n\t%d",temp->data);
		temp=temp->next;
	}
}

