/* Program of double linked list*/
# include <stdio.h>
# include <malloc.h>
# include <process.h>

struct node
{
	struct node *prev;
	int info;
	struct node *next;
}*start;

void create_list(int num)
{
	struct node *q,*tmp;
	tmp= (struct node*)malloc(sizeof(struct node));
	tmp->info=num;
	tmp->next=NULL;
	if(start==NULL)
	{
		tmp->prev=NULL;
		start=tmp;
//		start->prev=tmp;
	}
	else
	{
		q=start;

		// travelling upto end
		while(q->next!=NULL)
		{
			q=q->next;
		}
		
		// adding new node's two connections
		q->next=tmp;
		tmp->prev=q;
	}
}/*End of create_list()*/

void del()
{
	struct node *tmp,*i,*q,*s;
	int a,p;
	
	i=start;
	while(i!=NULL)
	{
		s=i->next;
		p=i->info;
							
	while(s!=NULL)
	{
		if(s->info==p)
		{
			a=p;
			        		
	if(start->info==a)
	{
		tmp=start;
		start=start->next;
		start->prev = NULL;
		free(tmp);
		break;
		}
	q=start;
	
	while(q->next->next!=NULL)
	{
		if(q->next->info==a)   
		{
			tmp=q->next;
			q->next=tmp->next;
			tmp->next->prev=q;
			free(tmp);
			break;
		}
		q=q->next;
	}
	break;
	}
		s=s->next;
	}	
		i=i->next;
	}
}
	
void display()
{
	struct node *q;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	q=start;
	printf("List is :\n");
	while(q!=NULL)
	{
		printf("%d ", q->info);
		q=q->next;
	}
	printf("\n");
}
	
main()
{
	int choice,n,m,po,i;
	start=NULL;

	while(1)
	{
		printf("\n *** Menu ***\n");
		printf("1.Create List\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			printf("How many nodes you want : ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf("Enter the element : ");
				scanf("%d",&m);
				create_list(m);
			}
			break;
		 case 2:
			
			del();
			break;
		 case 3:
			display();
			break;

		 case 4:
			exit(0);
		 default:
			printf("Wrong choice\n");
	}/*End of switch*/
   }/*End of while*/
}/*End of main()*/


