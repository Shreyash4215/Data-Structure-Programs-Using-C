/*
PROGRAM:  BINARY SEARCH TREE STRUCTURE.DISPLAY INORDER,
   	     PREORDE & POSTORDER OF TREE.
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

main()
 {
  TP root;
  TP create_bst();
  void pre(TP);
  void in(TP);
  void post(TP);
  printf("\n ENTER DATA IN TREE : \n");
  root=create_bst();
  printf("\n PREORDER : \n");
  pre(root);
  printf("\n INORDER : \n");
  in(root);
  printf("\n POSTORDER : \n");
  post(root);
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
	if(newnode->data<temp->data)
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
	   if(newnode->data>temp->data)
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

void pre(TP root)
 {
  TP temp=root;
  if(temp!=NULL)
   {
    printf(" %d ",temp->data);
    pre(temp->left);
    pre(temp->right);
   }
 }

void in(TP root)
 {
  TP temp=root;
  if(temp!=NULL)
   {
    in(temp->left);
    printf(" %d ",temp->data);
    in(temp->right);
   }
 }

void post(TP root)
 {
  TP temp=root;
  if(temp!=NULL)
   {
    post(temp->left);
    post(temp->right);
    printf(" %d ",temp->data);
   }
 }

/*************************************************************************
	    OUTPUT:-
     ENTER DATA IN TREE :
     HOW MANY ELEMENTS ? 10
     ENTER THE ELEMENT TO BE INSERTED : 568
     ENTER THE ELEMENT TO BE INSERTED : 985
     ENTER THE ELEMENT TO BE INSERTED : 648
     ENTER THE ELEMENT TO BE INSERTED : 235
     ENTER THE ELEMENT TO BE INSERTED : 698
     ENTER THE ELEMENT TO BE INSERTED : 458
     ENTER THE ELEMENT TO BE INSERTED : 658
     ENTER THE ELEMENT TO BE INSERTED : 987
     ENTER THE ELEMENT TO BE INSERTED : 556
     ENTER THE ELEMENT TO BE INSERTED : 4678
     PREORDER :

	      568  235  458  556  985  648  698  658  987  4678

     INORDER :

	      235  458  556  568  648  658  698  985  987  4678

     PSTORDER :

	      556  458  235  658  698  648  4678  987  985  568
**************************************************************************/
