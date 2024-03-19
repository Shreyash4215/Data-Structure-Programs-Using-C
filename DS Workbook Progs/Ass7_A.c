#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct node
{
	int data;
	struct node *left,*right;
}NODE;
/**********************************************/
typedef struct 
{
	NODE *data[MAXSIZE];
	int top;
}STACK;
/**********************************************/
void initstack(STACK *ps)
{
	ps->top=-1;
}
void push(STACK *ps,NODE *temp)
{
	ps->data[++ps->top]=temp;
}
NODE *pop(STACK *ps)
{
	return(ps->data[ps->top--]);
}
int isEmpty(STACK *ps)
{
	return(ps->top==-1);
}
int isFull(STACK *ps)
{
	return(ps->top==MAXSIZE-1);
}
/**********************************************/

NODE *createBST(NODE *root)
{
	NODE *newnode,*temp;
	int i,n,num;
	printf("\n How many nodes =");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		printf("\n Enter the element=");
		scanf("%d",&num);
		newnode->data=num;
		newnode->left=newnode->right=NULL;
		if(root==NULL)
		{
			root=newnode;
		}
		else
		{
			temp=root;
			while(1)
			{
				if(num<temp->data)
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
	return root;
}
NODE *insertBST(NODE *root,int n)
{
	NODE *newnode,*temp;

	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->data=n;
	newnode->left=newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		temp=root;
		while(1)
		{
			if(num<temp->data)
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
	return root;
}
int countnodes(NODE *root)
{
	static int cnt=0;
	NODE *temp=root;
	if(temp!=NULL)
	{
		count++;
		countnodes(temp->left);
		countnodes(temp->right);
	}
	return cnt;
}
int countleaf(NODE *root)
{
	static int cnt=0;
	NODE *temp=root;
	if(temp!=NULL)
	{
		if((temp->left==NULL)&&(temp->right==NULL))
			count++;
		countleaf(temp->left);
		countleaf(temp->right);
	}
	return cnt;
}
void preorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{
		printf(" %d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}	
}
void inorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{		
		inorder(temp->left);
		printf(" %d ",temp->data);
		inorder(temp->right);
	}	
}
void postorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{		
		postorder(temp->left);
		postorder(temp->right);
		printf(" %d ",temp->data);
	}	
}
void nonrecinorder(NODE *root)
{
	NODE *temp=root;
	STACK s;
	initstack(&s);
	while(1)
	{
		while(temp!=NULL)
		{
			push(&s,temp);
			temp=temp->left;
		}
		if(isEmpty(&s))
			return;
		temp=pop(&s);
		printf("%d ",temp->data);
		temp=temp->right;
	}
}

NODE* search(NODE *root,int key)
{
	NODE *temp=root;
	while(temp!=NULL)
	{
		if(key==temp->data)
			return temp;
		if(key<temp->data)
			temp=temp->left;
		else
			temp=temp->right;
	}
	return NULL;
}
int main()
{
	int n,choice;
	NODE *root=NULL;
	do
	{
		printf("\n Enter ");
		printf("\n 1 : For Create ");
		printf("\n 2 : For Recursive Traversal");		
		printf("\n 3 : For Non-Recursive Inorder Traversal");			
		printf("\n 4 : For Counting Nodes");			
		printf("\n 5 : For Counting Non-leaf Nodes");			
		printf("\n 6 : For Insert a Node");			
		printf("\n Enter your choice =");		
		scanf("%d",&choice);	
		switch(choice)
		{
			case 1:
				root=createBST(root);
				break;
			case 2:
				printf("\n Preorder =");
				preorder(root);
				printf("\n Inorder =");
				inorder(root);
				printf("\n Postorder =");		
				postorder(root);
				break;
			case 3:
				printf("\n Non-recursive In-order =");				
				nonrecinorder(root);
				break;
		}	
	}while(choice!=3);
}
