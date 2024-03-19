/* Program of sorting using merge sort through recursion*/
#include<stdio.h>
#define MAX 20

int array[MAX];
merge( int low, int mid, int high )
{
		printf("\n low=%d,mid=%d,high=%d",low,mid,high);
		
	int temp[MAX];
	int i = low;
	int j = mid +1 ;
	int k = low ;

	while( (i <= mid) && (j <=high) )
	{
		if(array[i] <= array[j])
			temp[k++] = array[i++] ;
		else
			temp[k++] = array[j++] ;
	}/*End of while*/
	while( i <= mid )
		temp[k++]=array[i++];
	while( j <= high )
		temp[k++]=array[j++];

	for(i= low; i <= high ; i++)
		array[i]=temp[i];
}/*End of merge()*/


merge_sort( int low, int high )
{
	int mid;
	if( low != high )
	{
		printf("\n\n come=1");
		mid = (low+high)/2;
		printf("\n\n come=2");
		merge_sort( low , mid );
		printf("\n\n come=3");
		merge_sort( mid+1, high );
		printf("\n\n come=4");
		merge( low, mid, high );
		
		
	}
}/*End of merge_sort*/


main()
{
	int i,n;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&array[i]);
	}

	printf("Unsorted list is :\n");
	for( i = 0 ; i<n ; i++)
		printf("%d ", array[i]);

	merge_sort( 0, n-1);

	printf("\nSorted list is :\n");
	for( i = 0 ; i<n ; i++)
		printf("%d ", array[i]);
	printf("\n");
}/*End of main()*/





