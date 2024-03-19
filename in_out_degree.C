
#include<stdio.h>
#include<conio.h>
main()
{
 int m[10][10],r,c,sumin,sumout,n,v;

 printf("\nHow many vertices : ");
 scanf("%d",&n);

 for(r=0;r<n;r++)
	 for(c=0;c<n;c++)
	  {
	   m[r][c]=0;
	    if(r!=c)
	    {
	     printf("Is there an edge between vertex %d and %d (1/0) : ",r+1,c+1);
	     scanf("%d",&m[r][c]);
	    }
	  }

 printf("\n\nVertex Indgree Outdegree Total degree\n");

 for(v=0;v<n;v++)
 {
  sumin=0;
  for(r=0;r<n;r++)
	  sumin=sumin+m[r][v];

  sumout=0;
  for(c=0;c<n;c++)
	  sumout=sumout+m[v][c];

  printf("%2d\t%d\t%d\t\t%d\n",v+1,sumin,sumout,sumin+sumout);
 }
 getch();
}
