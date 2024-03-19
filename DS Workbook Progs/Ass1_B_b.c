#include<stdio.h>
struct emp
{
	char name[20];
	int age;
};
void BubbleSort(struct emp e[],int n);   //Declaration
int main()
{
	FILE *fp=fopen("Emp.txt","r");
	struct emp e[30];
	int i=0;

	while((fscanf(fp,"%s%d",e[i].name,&e[i].age))!=EOF)
		{
			i++;
		}
BubbleSort(e,i);   //Calling 
return 0;
}
void BubbleSort(struct emp e[],int n)  //Defination
{
int pass,i;
struct emp e1;
for(pass=1;pass<n;pass++)
{
for(i=0;i<n-pass;i++)
{
if(strcmp(e[i].name,e[i+1].name)>0) 
{
e1=e[i];
e[i]=e[i+1];
e[i+1]=e1;
}
}
}
printf("\n Sorted array=");
for(i=0;i<n;i++)
{
printf("\n%s \t%d",e[i].name,e[i].age);
}
}


