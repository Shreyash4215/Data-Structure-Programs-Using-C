#include<stdio.h>
#define MAXSIZE 30
typedef struct
{
int data[MAXSIZE];
int front,rear;
}Q;
void creat(Q *pq)
{
pq->front=-1;
pq->rear=-1;
}

void Add(Q *pq,int n)
{
pq->rear++;
pq->data[pq->rear]=n;
}

int Remove(Q *pq)
{
int n;
pq->front++;
n=pq->data[pq->front];
return n;
}

int isEmpty(Q *pq)
{
if(pq->front==pq->rear)
return 1;
else
return 0;
}

int isFull(Q *pq)
{
if(pq->rear==MAXSIZE-1)
return 1;
else
return 0;
}

