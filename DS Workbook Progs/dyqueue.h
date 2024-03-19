#include<stdio.h>
#include<stdlib.h>
typedef struct Queue
{
int data;
struct Queue *next;
}Q;
Q *rear;

void create()
{
rear=NULL;
}

int isEmpty()
{
if(rear==NULL)
return 1;
else
return 0;
}

void Add(int n)
{
Q *newnode;
newnode=(Q*)malloc(sizeof(Q));
newnode->data=n;
if(rear==NULL)
{
rear=newnode;
rear->next=rear;
}
else
newnode->next=rear->next;
rear->next=newnode;
rear=newnode;
}

int Remove()
{
int n;
Q *temp;
temp=rear->next;
n=temp->data;
if(rear->next==rear)
free(rear);
else
{
rear->next=temp->next;
free(temp);
}
return n;
}

