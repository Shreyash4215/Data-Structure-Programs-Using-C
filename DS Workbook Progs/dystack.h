
// save this file dystack.h
#include<stdio.h>
typedef struct
{
int data;
struct stack *next;
}STACK;
STACK *top;

void create()
{
top=NULL;
}

int isEmpty()
{
if(top==NULL)
return 1;
else
return 0;
}

void push(int n)
{
STACK *newnode;
newnode=(STACK*)malloc(sizeof(STACK));
newnode->data=n;
newnode->next=top;
top=newnode;
}

int pop()
{
int n;
STACK *temp;
temp=top;
n=top->data;
top=top->next;
free(temp);
return n;
}

