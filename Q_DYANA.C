#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct que
{
	int data;
	struct que *next;
};

struct que *front,*rear,*newNode,*temp;

void add();
void display();
void delet();

main()
{
	front=NULL;
	rear=NULL;

	while(1)
	{
		int ch;
		printf("\n\n  Please Select operation to Perform:");
		printf("\n  1.Add");
		printf("\n  2.Display");
		printf("\n  3.Delete");
		printf("\n  4.Exit");
		printf("\n\n  Please Enter your Choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: add();
					break;
			case 2: display();
					break;
			case 3: delet();
					break;
			case 4: exit(0);
					break;
			default: printf("\n  Please Enter a Valid Choice!!!");
					break;
		}
	}
}

void add()
{
	newNode=(struct que*)malloc(sizeof(struct que));
	printf("\n  Please enter the number to be added: ");
	scanf("%d",&newNode->data);
	newNode->next=NULL;

	if(front==NULL)
	{
		front=newNode;
		rear=newNode;
	}
	else
	{
		rear->next=newNode;
		rear=rear->next;
	}
}

void delet()
{
	temp=front;

	if(temp==NULL)
	{
		printf("\n  Queue is Empty!!! No Element to Remove!!");
	}
	else
	{
		printf("\n  %d has been Deleted !!! ",front->data);
		front=front->next;
		temp->next=NULL;
		free(temp);
	}
}

void display()
{
	temp=front;
	if(temp==NULL)
	{
		printf("\n Queue is Empty!!!");
	}
	else
	{
		printf("\n\n Elements in queue are :\n\t");
		while(temp!=NULL)
		{
			printf("\n\t %d ",temp->data);
			temp=temp->next;
		}
	}
}

