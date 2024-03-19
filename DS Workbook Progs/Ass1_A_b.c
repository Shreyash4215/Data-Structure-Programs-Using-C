#include<stdio.h>
void Insertion_sort(int a[],int n); //Declaration
main()
{
int a[30],i,n;
printf("\n Enter how many-");
scanf("%d",&n);
printf("\n Enter %d elements",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
Insertion_sort(a,n); ////Calling 
return 0;
}
void Insertion_sort(int a[],int n) //Defination
{
int i,j,key;
for(j=1;j<n;j++)
{
key=a[j];
for(i=j-1;i>=0;i--)
{
if(a[i]>key)
a[i+1]=a[i];
else
break;
}
a[i+1]=key;
}
printf("\n Sorted array is =");
for(i=0;i<n;i++)
printf("\n %d",a[i]);
}

