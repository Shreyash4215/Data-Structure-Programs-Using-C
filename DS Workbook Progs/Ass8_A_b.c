#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int vertex;
	struct node *next;
}NODE;
NODE *list[10];
void createList(int m[10][10],int n)
{
	int i,j;
	NODE *temp,*newnode;
	for(i=0;i<n;i++)
	{
		list[i]=NULL;
		for(j=0;j<n;j++)
		{			
			if(m[i][j]==1)
			{
				newnode=(NODE*)malloc(sizeof(NODE));
				newnode->next=NULL;
				newnode->vertex=j+1;
				if(list[i]==NULL)
				{
					list[i]=temp=newnode;
				}
				else
				{
					temp->next=newnode;	
					temp=newnode;				
				}
			}			
		}
	}
}

void displayList(int m[10][10],int n)
{
	int i;
	struct node *temp;
	printf("\n Adjacency List is =\n");
	for(i=0;i<n;i++)
	{
		printf("\nV%d->",i+1);
		temp=list[i];
		while(temp)
		{
			printf("V%d ->",temp->vertex);
			temp=temp->next;
		}
		printf("NULL");
	}
}

int main()
{
	int m[10][10],i,j,n;
	printf("Enter how many vertices =");
	scanf("%d",&n);
	printf("\nEnter vertices =");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m[i][j]=0;
			if(i!=j)
			{
				printf("\n Is there an edge between %d and %d (1 or 0)",i+1,j+1);
				scanf("%d",&m[i][j]);
			}
		}
	}
	printf("\n Adjacency Matrix is =");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%5d",m[i][j]);
		}
		printf("\n");
	}
	createList(m,n);
	displayList(m,n);	
	return 0;
}

