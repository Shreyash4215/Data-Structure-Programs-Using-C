#include<stdio.h>
#define max 30

void quicksort(int no[max],int first,int last)
{
	int i,j,pivot,temp;
	if(first<last)
	{	
		pivot=first;
		i=first;
		j=last;

		while(i<j)
		{
			while(no[i]<=no[pivot] && i<last)
				i++;
			while(no[j]>no[pivot])
				j--;
			if(i<j)
			{
				temp=no[i];
				no[i]=no[j];
				no[j]=temp;
			}			
		}
		temp=no[pivot];
		no[pivot]=no[j];
		no[j]=temp;
		quicksort(no,first,j-1);
		quicksort(no,j+1,last);
	}
}
int main()
{
	int i,count,no[max];
	printf("how many number =");
	scanf("%d",&count);
	printf("\nEnter %d elements=",count);
	for(i=0;i<count;i++)
		scanf("%d",&no[i]);
	quicksort(no,0,count-1);
	printf("\nSorted elements=\t");
	for(i=0;i<count;i++)
		printf("\t%d",no[i]);
 	return 0;
}
