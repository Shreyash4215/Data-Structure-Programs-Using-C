#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *next;
}NODE;

void create(NODE *head)
{
	int i,n,data;
	NODE *newnode,*last,*temp;
	printf("\nEnter how many nodes =");
	scanf("%d",&n);
	last= head;
	for(i=0;i<n;i++)
	{
		newnode=(NODE *)malloc(sizeof(NODE));
		newnode->next=NULL;
		printf("\n Enter data = ");
		scanf("%d",&data);
		newnode->data=data;
		if(last==head)
		{			
			last->next=newnode;
			last=newnode;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				if(temp->next->data>data)
					break;
				temp=temp->next;
			}
			newnode->next=temp->next;
			//if(temp->next!=NULL)
				temp->next=newnode;
		}
	}
}
void insert(NODE *head,int n)
{
	NODE *temp,*newnode;
	newnode=(NODE *)malloc(sizeof(NODE));	
	newnode->data=n;
	for(temp=head;(temp->next->data<n)&&(temp->next!=NULL);)
		temp=temp->next;
	if(temp->next==NULL)
	{
		temp->next=newnode;
		newnode->next=NULL;
	}	
	else
	{
		newnode->next=temp->next;
		temp->next=newnode;
	}	
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
		else if(temp->data>n)
			return 0;
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
	printf("\b\b");
}

int main()
{
	NODE *head;
	int n,ch,pos;
	head=(NODE *)malloc(sizeof(NODE));
	head->next=NULL;
	create(head);
	do
	{
		printf("\n Enter : "); 
		printf("\n 1 : Insert ");
		printf("\n 2 : Search ");
		printf("\n 3 : Display ");
		printf("\n 4 : Exit ");
		printf("\n U R Choice =");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter data to insert = ");
				scanf("%d",&n);
				insert(head,n);
				break;
			case 2:
				printf("\n Enter data to search");
				scanf("%d",&n);
				pos=search(head,n);
				if(pos==0)
					printf("\n Data does not exist");
				else
					printf("\n Data found at %d position",pos); 
				break;
			case 3:
				display(head);
				break;	
		}				
	}while(ch!=4);
	return 0;
}
