#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define NODEALLOC (struct node *)malloc(sizeof(struct node))

struct node
 {
  struct node *prev;	
  int data;
  struct node *next;
 };

typedef struct node *NODEPTR;

main()
 {
  int n;

	NODEPTR start;				// variable declaration
	NODEPTR create_list();
	void display_list(NODEPTR start);

  start=create_list();

  printf("\n Singly list is= : \n");
  display_list(start);

 }
NODEPTR create_list()
 {
  NODEPTR newnode,start=NULL,temp;
  int i=0,n;

  printf("\n How many nodes :");
  scanf("%d",&n);

  for(i=0;i<n;i++)
   {
    newnode=NODEALLOC;
    newnode->next=NULL;

    printf("\n Enter the value of %d node :",i+1);
    scanf("%d",&newnode->data);
    

    if(start==NULL)
    {
      start=temp=newnode;
      newnode->prev=NULL;
    }
    
    else
     {       	
      temp->next=newnode;
      newnode->prev=temp;
      temp=newnode;
     }
 }
  return(start);
 }

void display_list(NODEPTR first)
 {
 	NODEPTR temp;
 	int flag=1;
 	
  printf("\n START ->");
  while(first!=NULL)
   {
    printf("%d->",first->data);
    temp=first;
    first=first->next;
    if(first==NULL)
    {
    	flag=1;
	}
   }
  printf(" NULL \n");
  
  if(flag==1)
  {
  	printf(" \n the reversed list is : ");
  	
	  first=temp;
	    	
  	 while(first!=NULL)
   {
    printf("%d->",first->data);
    first=first->prev;
    }
  }
  
 }

 
