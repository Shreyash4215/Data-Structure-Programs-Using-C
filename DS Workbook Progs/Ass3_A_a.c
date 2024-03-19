#include<stdio.h>
main()
{
	int a[30],n,i,key,pos;
	printf("\n Enter how many nos-");
	scanf("%d",&n);
	printf("\n Enter %d nos.- ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	printf("\n Enter key to search-");
	scanf("%d",&key);
	pos=LinearS(a,n,key);
	if(pos==-1)
		printf("\n Not found");
	else
	printf("\n Key found at %d position",pos);
}

int LinearS(int a[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			return i;
	}
	return -1;
}

