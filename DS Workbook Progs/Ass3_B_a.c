#include<stdio.h>
struct cities 
{
	char name[30];
	int code;
};
void BubbleSort(struct cities a[100],int n)
{
	struct cities temp;
	int i,pass;
	for(pass=1;pass<n;pass++)
	{
		for(i=0;i<n-pass-1;i++)
		{
		if(strcmp(a[i].name,a[i+1].name)>0)
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
}
int BinarySearch(struct cities a[100],int n,char key[30])
{
	int top,bottom,mid;
	top=0;
	bottom=n-1;
	while(top<=bottom)
	{
		mid=(top+bottom)/2;
		if(strcmp(a[mid].name,key)==0)
			return a[mid].code;
		else
		{	
			if(strcmp(a[mid].name,key)<0)
				bottom=mid-1;
			else
				top=mid+1;
		}	
	}
	return 0;
}
int main()
{
	int i=0,j;
	char city[30];
	struct cities c[100];
	FILE *fp= fopen("cities1.txt","r");
   while(fscanf(fp,"%s%d",c[i].name,&c[i].code)!=EOF)
	{i++;}
	BubbleSort(c,i);
	printf("Enter City to Search =");
	scanf("%s",city);
	j=BinarySearch(c,i,city);	
	if(j==0)
		printf("\n city NOT found "); 	
	else
		printf("\n city found with STD Code =%d",j); 	
}

