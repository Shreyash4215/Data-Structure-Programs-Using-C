#include<stdio.h>
struct emp
{
	char name[20];
	int age;
};
void merge_sort(struct emp e[],int low,int high); 
void merge(struct emp e[],int low,int mid,int high);
int main()
{
	struct emp e[30];
	int i=0,n;
	FILE *fp=fopen("Emp.txt","r");
	FILE *fp2=fopen("Empage.txt","w+");

	while((fscanf(fp,"%s%d",e[i].name,&e[i].age))!=EOF)
		{
			i++;
		}
	merge_sort(e,0,i-1);
	n=i;
	printf("\n Sorted data is=");
	for(i=0;i<n;i++)
	{
		fprintf(fp2,"%s \t%d\n",e[i].name,e[i].age);
	}
	fclose(fp);
	fclose(fp2);
	return 0;
}

void merge(struct emp e[],int low,int mid,int high)
{
	int i,j,k;
	struct emp e1[30];
	i=low;
	j=mid+1;
	k=0;
	while(i<=mid && j<=high)
	{
		if(e[i].age<e[j].age)
		{	e1[k]=e[i];
			i++;
			k++;
		}
		else
		{	e1[k]=e[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		e1[k]=e[i];
		i++;
		k++;
	}
	while(j<=high)
	{	
		e1[k]=e[j];
		k++;
		j++;
	}
	for(k=0,j=low;j<=high;j++,k++)
	{
		e[j]=e1[k];
	}
}
void merge_sort(struct emp e[],int low,int high)
{
int mid;
if(low<high)
{
		mid=(low+high)/2;
		merge_sort(e,low,mid);
		merge_sort(e,mid+1,high);
		merge(e,low,mid,high);
}
}

