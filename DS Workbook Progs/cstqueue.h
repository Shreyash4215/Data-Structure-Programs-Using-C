#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct queue
{
	int data[MAXSIZE];
	int front,rear;
}Q;
void init(Q *pq)
{
	pq->front=pq->rear=MAXSIZE-1;
}
int isEmpty(Q *pq)
{
	if(pq->rear==pq->front)
		return 1;
	else
		return 0;
}
int isFull(Q *pq)
{
	if((pq->rear+1)%MAXSIZE==pq->front)
		return 1;
	else
		return 0;
}
void add(Q *pq,int n)
{
	pq->rear=(pq->rear+1) %MAXSIZE;
	pq->data[pq->rear]=n;
}
int Remove(Q *pq)
{
	pq->front=(pq->front+1) %MAXSIZE;
	return (pq->data[pq->front]);
}
