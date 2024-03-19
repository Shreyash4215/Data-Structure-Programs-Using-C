#include<stdio.h>
void bubblesort(int a[],int n);
int binarysearch(int a[],int n,int key);
int main()
{
 int a[30],n,i,pos,key;
 printf("\n Enter the no of elements");
 scanf("%d",&n);
 printf("\n Enter %d numbers",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  bubblesort(a,n);
   printf("\n Enter key to sarch");
   scanf("%d",&key);
   pos=binarysearch(a,n,key);
   if(pos==-1)
   	printf("\n Key not found");
   else
	   printf("\n key found at %d position",pos);
}

void bubblesort(int a[],int n)
 {
   int pass,i,temp;
   for(pass=1;pass<n;pass++)
   {
    for(i=0;i<n-pass;i++)
    {
     if(a[i]>a[i+1])
      {
       temp=a[i];
       a[i]=a[i+1];
       a[i+1]=temp;
      }
    }
   }
 }
int binarysearch(int a[],int n,int key)
 {
  int top,bottom,mid;
  top=0;
  bottom=n-1;
  while(top<=bottom)
  {
   mid=(top+bottom)/2;
   if(a[mid]==key)
   return mid;
   else
   {
    if(key<a[mid])
    bottom=mid-1;
    else
    top=mid+1;
   }
  }
   return -1;
 }
