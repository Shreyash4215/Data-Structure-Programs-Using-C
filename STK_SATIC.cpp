#include<stdio.h>
#include<process.h>
#define max 5

struct stack
{
 int top;
 int data[max];
};

struct stack s;

int i,c;

int empty();
int full();

void push();
void pop();
void display();

main()
{
 s.top=-1;
 while(1)
 {
  printf("\n\n1.push \n2.pop \n3.display \n4.exit");
  printf("\nEnter your choice : ");
  scanf("%d",&c);
  switch(c)
  {
   case 1:push();
   break;
   case 2:pop();
   break;
   case 3:display();
   break;
   case 4:exit(0);
   break;
  }
 }
}

int full()
{
 if(s.top==max-1)
	 return(1);
 else
 	return(0);
}

int empty()
{
 if(s.top==-1)
 	return(1);
 else
 	return(0);
}

void push()
{
 int m;
 m=full();
 if(m==1)
 	printf("\nstack is full");
 else
 {
  s.top=s.top+1;
  printf("\nEnter the no. to push in stack : ");
  scanf("%d",&s.data[s.top]);
 }
}

void pop()
{
 int m;
 m=empty();
 if(m==1)
 	printf("\nstack is empty");
 else
 {
  printf("\n poped element = %d",s.data[s.top]);
  s.top=s.top-1;
 }
}

void display()
{
 int m,i;
 m=empty();
 if(m==1)
 	printf("\nStack is empty");
 else
 	for(i=s.top;i>=0;i--)
 		printf("\n%d",s.data[i]);
}

