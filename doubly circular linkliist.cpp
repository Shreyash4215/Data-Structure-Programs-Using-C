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

	NODEPTR last;				// variable declaration
	NODEPTR create_list();
	void display_list(NODEPTR last);

  last=create_list();

   printf("\n Singly list is= : \n");
   display_list(last);

 }
NODEPTR create_list()
 {
  NODEPTR newnode,last=NULL,temp;
  int i=0,n;

  printf("\n How many nodes :");
  scanf("%d",&n);

  for(i=0;i<n;i++)
   {
    temp=NODEALLOC;
    
    printf("\n Enter the value of %d node :",i+1);
    scanf("%d",&temp->data);
    

    if(last==NULL)
    {
      last=temp;
      last->next=last;
      last->prev=last;
    }
    else
     { 
	  temp->next=last->next;
      last->next=temp;
	  temp->prev=last->prev;      	
      temp->prev=last;
      last=temp;
     }
 }
 	printf("\n last=%d",last->data);
 
  return(last);
 }

void display_list(NODEPTR first)
 {
 	NODEPTR temp, p1,p2;
 	
 	temp=first->next;
 	
	p1=first;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev; 
	}
	first=p1;
	temp=first->next;
	
	printf("\t %d",first->data);
	
	while(temp != first)
   {
    printf("\t %d",temp->data);
   	temp=temp->next;
    }
}
 
 
