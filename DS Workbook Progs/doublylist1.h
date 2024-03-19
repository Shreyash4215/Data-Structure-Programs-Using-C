#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *next,*prev;
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
		newnode->next=NULL;
		newnode->prev=NULL;
		printf("\n Enter data = ");
		scanf("%d",&newnode->data);
		last->next=newnode;
		newnode->prev=last;
		last=newnode;
	}
}
void insert(NODE *head,int n,int pos)
{
	NODE *temp,*newnode;
	int i;
	for(i=1,temp=head;(i<pos)&&(temp!=NULL);i++)
		temp=temp->next;
	if(temp==NULL)
	{
		printf("\n Invalid Position");
		return;
	}	
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->next=temp->next;
	temp->next->prev=newnode;
	newnode->prev=temp;
	newnode->data=n;
	temp->next=newnode;
}
void Delete(NODE *head,int n)
{
	NODE *temp,*temp1;
	
	for(temp=head;temp->next!=NULL;temp=temp->next)
	{
		if(temp->next->data==n)
		{
			temp1=temp->next;
			temp->next=temp1->next;
			temp1->next->prev=temp;
			free(temp1);
			return ;
		}
	}	
	printf("\n Enter data not exist in list");
}
int search(NODE *head,int n)
{
	NODE *temp;
	int pos;
	for(pos=1,temp=head->next;temp!=NULL;temp=temp->next,pos++)
	{
		if(temp->data==n)
		{
			return pos;
		}
	}	
	return 0;
}
void display(NODE *head)
{
	NODE *temp;
	printf("\n List =>");
	for(temp=head->next;temp!=NULL;temp=temp->next)
	{
		printf(" %d=>",temp->data);
	}	
	printf("\r\r  ");
}
