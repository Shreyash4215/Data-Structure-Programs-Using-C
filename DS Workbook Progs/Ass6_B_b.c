#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *next;
}NODE;

void create(NODE *head)
{
	int i,n;
	NODE *newnode,*last;
	printf("\nEnter how many nodes =");
	scanf("%d",&n);
	last= head;
	for(i=0;i<n;i++)
	{
		newnode=(NODE *)malloc(sizeof(NODE));
		newnode->next=head;
		printf("\n Enter data = ");
		scanf("%d",&newnode->data);
		last->next=newnode;
		last=newnode;
	}	
}
void append(NODE *head,int n)
{
	NODE *temp,*newnode;
	newnode=(NODE *)malloc(sizeof(NODE));	
	newnode->data=n;
	for(temp=head;(temp->next!=head);temp=temp->next);
	newnode->next=head;
	temp->next=newnode;		
}

void display(NODE *head)
{
	NODE *temp;
	printf("\n List =>");
	for(temp=head->next;temp!=head;temp=temp->next)
	{
		printf(" %d=>",temp->data);
	}	
	printf("\r\r");
}

int main()
{
	NODE *head;
	int n,ch,pos;
	head=(NODE *)malloc(sizeof(NODE));
	head->next=head;
	create(head);
	do
	{
		printf("\n Enter : "); 
		printf("\n 1 : Append ");
		printf("\n 2 : Display ");
		printf("\n 3 : Exit ");
		printf("\n U R Choice =");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter data to append = ");
				scanf("%d",&n);
				append(head,n);
				break;
			case 2:
				display(head);
				break;	
		}				
	}while(ch!=3);
	return 0;
}
