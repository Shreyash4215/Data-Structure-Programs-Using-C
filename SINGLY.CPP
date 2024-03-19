#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define NODEALLOC (struct node *)malloc(sizeof(struct node))

struct node
 {
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
	void search(NODEPTR start,int n);

  start=create_list();

  printf("\n Singly list is= : \n");
  display_list(start);

  printf("\n\n\t Enter the number to be Searched : ");
  scanf("%d",&n);

  search(start,n);
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
    }

    if(start==NULL)
      start=temp=newnode;
    else
     {
      temp->next=newnode;
      temp=newnode;
     }
  return(start);
 }

void display_list(NODEPTR first)
 {
  printf("\n START ->");
  while(first!=NULL)
   {
    printf("%d->",first->data);
    first=first->next;
   }
  printf(" NULL \n");
 }

void search(NODEPTR t1,int n)
 {
  int cnt=0,nno;
  NODEPTR temp;

  for(temp=t1;temp!=NULL;temp=temp->next)
    if(temp->data==n)
    {
      cnt++;
      printf("\n\t Number Found");

      printf("\n\t Enter the NEW Value : ");
      scanf("%d",&nno);

      temp->data=nno;
      display_list(t1);
    }

   if(cnt==0)
    printf("\n\t Element not Found ...");
 }



 
