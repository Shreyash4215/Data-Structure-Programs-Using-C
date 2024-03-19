#include<stdio.h>

int main()
{
	int m[10][10],i,j,n,in=0,out=0;
	printf("Enter how many vertices =");
	scanf("%d",&n);

	printf("\nEnter vertices =");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m[i][j]=0;
			if(i!=j)
			{
				printf("\n Is there an edge between %d and %d (1 or 0)",i+1,j+1);
				scanf("%d",&m[i][j]);
			}
		}
	}

	for(i=0;i<n;i++)
	{
		in=0; out=0;
		for(j=0;j<n;j++)
		{
			in+= m[j][i];
			out+=m[i][j];			
		}
		printf("\n V%d In = %d Out=%d Total=%d",i+1,in,out,(in+out));
	}
	return 0;
}
