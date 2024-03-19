#include<stdio.h>
#include"singlylist.h"

int main()
{
	NODE *head;
	int n,ch,pos;
	head=(NODE *)malloc(sizeof(NODE));
	head->next=NULL;
	create(head);
	do
	{
		printf("\n Enter : "); 
		printf("\n 1 : Insert ");
		printf("\n 2 : Search ");
		printf("\n 3 : Delete ");
		printf("\n 4 : Display ");
		printf("\n 5 : Exit ");
		printf("\n U R Choice =");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter data & Position where insert data");
				scanf("%d%d",&n,&pos);
				insert(head,n,pos);
				break;
			case 2:
				printf("\n Enter data to search");
				scanf("%d",&n);
				pos=search(head,n);
				if(pos==0)
					printf("\n Data does not exist");
				else
					printf("\n Data found at %d position",pos); 
				break;
			case 3:
				printf("\n Enter data to delete");
				scanf("%d",&n);
				Delete(head,n);
				break;
			case 4:
				display(head);
				break;	
		}				
	}while(ch!=5);
	return 0;
}
