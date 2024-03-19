#include<stdlib.h>
#include<stdio.h>

#define NA (struct node *)malloc(sizeof(struct node))

struct node
{
	int data;
	struct node *left,*right;
};

typedef struct node *TP;

main()
{
	TP root;

	TP create_bst();
    void search_tree(TP);
	
	printf("\n ENTER DATA IN TREE : \n");
	root=create_bst();
	search_tree(root);
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

void search_tree(TP root)
{
	TP temp;
	
	int n,i,flag=0;
			
	temp=root;

	printf("\n Which NODE you want to search In Tree ?: ");
	scanf("%d",&n);
	
			while(temp!=NULL)
			{
				if(temp->data == n)
				{
					flag=1;
					break;
				}
				if(n < temp->data)	
				{
					if(temp->left->data == n)
					{
					   flag=1;
					break;
					}
					else
						temp=temp->left;
						if(temp->left==NULL)
						{
							break;
						}
				}				
				else
				{
					if(n > temp->data)
					{
						if(temp->right->data ==n )
						{
							flag=1;
							break;
						}
						else
							temp=temp->right;
							if(temp->right==NULL)
						{
							break;
						}
					}
				}
			}
			if(flag==1)
			{
				printf("\n %d NODE is found in Tree",n);
			}
			else
			{
			 	printf("\n %d NODE is NOT found in Tree",n);
			}	
}
		
	



