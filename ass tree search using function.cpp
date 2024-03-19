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
	int flag=0;
	
	TP create_bst();
    int search_tree(TP);
	
	printf("\n ENTER DATA IN TREE : \n");
	root=create_bst();
	search_tree(root);
	
	flag=search_tree(root);
	if(flag==1)
			{
				printf("\n %d NODE is found in Tree",root);
			}
			else
			{
			 	printf("\n %d NODE is NOT found in Tree",root);
			}		
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

int search_tree(TP root)
{
	static int l=0,srch;
	TP temp=root;
				
				if(l==0)
				{
					printf("\n ENTER the node you want to search in node : \n");
					scanf("%d",&srch);	
				}
				
				l++;
				
			if(temp == NULL)
			{
				return(0);
			}
			else
			{
			if(temp->data==srch)
			{			
			   return(1);
				}
			}
				
	search_tree(temp->left);
	search_tree(temp->right);
}
		
	



