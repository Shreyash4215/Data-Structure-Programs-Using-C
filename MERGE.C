#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODEPTR;

main()
{
	NODEPTR createlist(NODEPTR);
	void display(NODEPTR);
	NODEPTR merge(NODEPTR,NODEPTR,NODEPTR);

	NODEPTR list1=NULL,list2=NULL,list3=NULL;
	list1=createlist(list1);
	list2=createlist(list2);
	list3=merge(list1,list2,list3);

	printf("\nThe First list is : \n");
	display(list1);
	
	printf("\nThe Second list is : \n");
	display(list2);
	
	printf("\nMeged list is : \n");
	display(list3);
}

NODEPTR createlist(NODEPTR list)
{
	int i,n;
	NODEPTR temp,nn;

	printf("\n\nHow many elements in the list : ");
	scanf("%d",&n);
	
	printf("Enter the %d elements in increasing order : ",n);
	temp=list;
	
	for(i=1;i<=n;i++)
	{
		nn=(NODEPTR)malloc(sizeof(struct node));
		nn->next=NULL;
		scanf("%d",&nn->data);
		if(list==NULL)
		{
			list=temp=nn;
		}
		else
		{
			temp->next=nn;
			temp=nn;
		}
	}
	return list;
}

void display(NODEPTR list)
{
	NODEPTR temp=list;
	for(temp=list;temp!=NULL;temp=temp->next)
	printf("%3d",temp->data);
}

NODEPTR merge(NODEPTR list1,NODEPTR list2,NODEPTR list3)
{
	NODEPTR t1=list1,t2=list2,t3=list3,nn;
	while(t1&&t2)
	{
		nn=(NODEPTR)malloc(sizeof(struct node));
		nn->next=NULL;
		
		if(t1->data < t2->data)
		{
			nn->data=t1->data;
			t1=t1->next;
		}
		else
		{
			nn->data=t2->data;
			t2=t2->next;
		}
		
		if(list3==NULL)
			t3=list3=nn;
		else
		{
			t3->next=nn;
			t3=t3->next;
		}
	}
	
	if(t1)
		t3->next=t1;

	if(t2)
		t3->next=t2;

	return list3;
}

