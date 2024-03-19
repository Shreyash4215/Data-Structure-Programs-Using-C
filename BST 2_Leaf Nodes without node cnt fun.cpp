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
	int cn(TP);
	int cnl(TP);
	TP create_bst();
   	 
	root=create_bst();

	printf("\n LEAF NODES IN THE TREE  : %d ",cnl(root));
}
TP create_bst()
{
	TP newnode,root=NULL,temp;
	char ch;
	int n,i,c=0;

	printf("\n HOW MANY ELEMENTS ? ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		newnode=NA;
		printf("\n ENTER THE ELEMENT TO BE INSERTED : ");
		scanf("%d",&newnode->data);		
		newnode->left=newnode->right=NULL;
        
        c++;
        
		if(root==NULL)
			root=newnode;
		else
		{
			temp=root;
			while(temp!=NULL)
			{
				if(newnode->data < temp->data)
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
					if(newnode->data > temp->data)
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
	printf("\n TOTAL NODES IN THE TREE : %d ",c);				
	return(root);
}
int cnl(TP root)
{
	static int c=0;
	TP temp=root;

	if(temp==NULL) 
		return (c);
	
	if (temp->left==NULL && temp->right==NULL)
		return (++c);
	
	cnl(temp->left);
	cnl(temp->right);

	return(c);
}

