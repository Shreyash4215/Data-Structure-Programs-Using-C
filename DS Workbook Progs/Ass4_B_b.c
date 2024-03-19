#include<stdio.h>
#include"csstack.h"

int main()
{
	ST ps;
	int i,ch;
	char name[40],revname[40],c;
	create(&ps);
	printf("Enter name=");
	scanf("%s",&name);
	
	for(i=0;name[i]!='\0';i++)
	{
		if(isFull(&ps)!=1)
			Push(&ps,name[i]);				
	}

	printf("\n Reversed String is = ");
	i=0;
	while(isEmpty(&ps)!=1)
	{
		revname[i]= Pop(&ps);
		i++;
	}
	revname[i]='\0';
	printf("%s",revname);

	if(strcmp(name,revname)==0)
		printf("Given String is Palindrome");
	else
		printf("Given String is Not Palindrome");

	return 0;
}
