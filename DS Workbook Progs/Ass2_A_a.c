#include<stdio.h>
void merge_sort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);
int main()
{
	int a[30], n, i;
	printf("\n Enter how many no.s =");
	scanf("%d",&n);
	printf("\n Enter %d element=",n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	merge_sort(a,0,n-1);
	printf("sorted array=");
	for(i=0;i<n;i++)
		printf("\t %d",a[i]);
 	return 0;
}

void merge_sort(int a[],int low,int high)
{
	int mid;
	if(low<high) 
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

void merge(int a[],int low,int mid,int high)
{
	int i,j,k,b[30];
	i=low;
	j=mid+1;
	k=0;
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
	for(k=0,i=low;i<=high;i++,k++)
		a[i]=b[k];
}





























