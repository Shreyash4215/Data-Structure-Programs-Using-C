/*
	PROGRAM:BINARY SEARCH TREE
*/

#include<stdlib.h>
#include<stdio.h>

#define NA (struct node *)malloc(sizeof(struct node))

struct node
{
	int data;
	struct node *left,*right;
};

typedef struct node *TP;

struct q
{
	TP item;
	struct q *next;
}*front,*rear;

main()
{
	TP root;

	TP create_bst();
	void levelwise_tree(TP);

	printf("\n ENTER DATA IN TREE : \n");
	root=create_bst();
	levelwise_tree(root);
}

TP create_bst()
{
	TP newnode,root=NULL,temp;
	char ch;
	int n,i;

	printf("\n HOW MANY ELEMENTS ? ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		newnode=NA;
		printf("\n ENTER THE ELEMENT TO BE INSERTED : ");
		scanf("%d",&newnode->data);
		newnode->left=newnode->right=NULL;
		
		if(root==NULL)
			root=newnode;
		else
		{
			temp=root;
			while(temp!=NULL)
			{
				if(root->data==newnode->data)
				{
				 printf("\n dont add similar item");
				 n=n+1;
				 break;
				}
				
				if(newnode->data < temp->data)		// add node in left side
				{
					if(temp->left==NULL)
					{
						temp->left=newnode;
						break;
					}
					else
						temp=temp->left;
				}
				
				else
				{
					if(newnode->data > temp->data)	// add node in right side
					{
						if(temp->right==NULL)
						{
							temp->right=newnode;
							break;
						}
						else
							temp=temp->right;
					}
				}
			}
		}
	}
    return(root);
}

void levelwise_tree(TP root)
{
	TP delq();
	void addq(TP);
	void initq();
	int emptyq();
	int l=0;

	TP temp=root,dummy=NULL;
	initq();
	addq(temp);
	addq(dummy);
	printf("\n LEVEL : %d \t",l);

	do
	{
		temp=delq();

		if(temp!=dummy)
			printf(" %d ",temp->data);

		if(temp==dummy)
		{
			if(!emptyq())
			{
				l++;
				printf("\n LEVEL : %d \t",l);
				addq(dummy);
			}
		}
		else
		{
			if(temp->left)
				addq(temp->left);
				
			if(temp->right)
				addq(temp->right);
		}
	}while(!emptyq());
	printf("\n THE HEIGHT OF TREE IS : %d ",l+1);
}

void initq()
{
	front=rear=NULL;
}

int emptyq()
{
	return(front==rear);
}

void addq(TP root)
{
	struct q *nn;
	nn=(struct q *)malloc(sizeof(struct q));
	nn->item=root;
	nn->next=NULL;

	if(front==NULL)
		rear=front=nn;
	else
	{
		rear->next=nn;
		rear=nn;
	}
}

TP delq()
{
	TP t;
	struct q *temp=front;
	t=front->item;
	front=front->next;
	free(temp);
	return(t);
}

