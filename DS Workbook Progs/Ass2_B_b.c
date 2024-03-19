#include<stdio.h>

struct emp 
{
    char name[30];
};

void merge_sort(struct emp e[],int low,int high);
void merge(struct emp e[],int low, int mid,int high);

int main()
{
   FILE *fp,*fs;
   struct emp e[20];
   int n,i,a[20];
   
     fp=fopen("employee.txt","r");
     fs=fopen("empsort.txt","w");
     i=0;
   
  while(fscanf(fp,"%s",e[i].name)!=EOF)
     {
        i++;
     }  
	printf("%d",i);
     merge_sort(e,0,i-1);
     n=i;
     printf("\n sorted array\n ");
     for(i=0;i<n;i++)
     {
          fprintf(fs,"%s\n",e[i].name);
         //printf("\t %s",e[i].name);
     }
     fclose(fp);
     fclose(fs);
      fs=fopen("empsort.txt","r");
      printf("\n Sorted data in the file is\n");
	i=0;
       while(!feof(fs))
      {
        fscanf(fs,"%s",e[i].name);
        printf("\t %s",e[i].name);
        i++;
      }  
      fclose(fs);
     return 0;
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

void merge(struct emp e[],int low, int mid,int high)
{
  	int i,j,k;
   	struct emp b[20];
   	i=low; j=mid+1; k=0;
   	while(i<=mid && j<=high)
    	{
       	if(strcmp(e[i].name,e[j].name)<0)
         	b[k++]=e[i++];
       	else
         	b[k++]=e[j++];
     	}
   	while(i<=mid)
        	b[k++]=e[i++];
   	while(j<=high)
      		b[k++]=e[j++];
   	
	for(k=0,i=low;i<=high;i++,k++)
     		e[i]=b[k];
}     
                   
