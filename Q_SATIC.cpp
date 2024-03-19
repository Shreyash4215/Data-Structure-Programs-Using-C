#include<stdio.h>
#include<process.h>
# define max 5

struct queue
{
 int data[max];
 int top;
};

struct queue q;

void pop();
void display();
void push();
int full();
int empty();

main()
{
 int c;
 q.top=0;
 q.top=-1;

 while(1)
 {
  printf("\n1.push \n2.display \n3.pop \n4.exit");
  printf("\n\nEnter your choice : ");
  scanf("%d",&c);

  switch(c)
  {
   case 1:push();
   break;
   case 2:display();
   break;
   case 3:pop();
   break;
   case 4:exit(0);
   break;
   default:printf("\nYour choice is invalid");
  }
 }
}

int full()
{
 if(q.top==max-1)
	 return(1);
 else
 	return(0);
}

int empty()
{
 if((q.top==0 && q.top==-1)||(q.top==q.top+1))
 	return(1);
 else
 	return(0);
}

void push()
{
 int m;
 m=full();

 if(m==1)
	 printf("\n Queue is full");
 else
 {
  q.top=q.top+1;
  printf("\n Enter the no. to be pop : ");
  scanf("%d",&q.data[q.top]);
 }
}

void pop()
{
 int m;
 m=empty();

 if(m==1)
	 printf("\n Queue is empty");
 else
 {
  printf("\n poped element = %d ",q.data[q.top]);
  printf("\nElement is successfully poped");
  q.top=q.top+1;
 }
}

void display()
{
 int m,i;
 m=empty();

 if(m==1)
	 printf("\n Queue is empty");
 else
 {
  printf("\nThe elements in Queue are : ");
  for(i=q.top;i<=q.top;i++)
 	 printf("\n%d",q.data[i]);
 }
}

