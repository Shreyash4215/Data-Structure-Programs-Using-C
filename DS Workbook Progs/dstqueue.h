#include<stdio.h>
#define SIZE 100
typedef struct Queue
{
	int data[SIZE];
	int rear,front;
}Q;
void create(Q *pq)
{
	pq->front=-1;
	pq->rear=-1;
}
int isEmpty(Q *pq)
{
	return (pq->front==pq->rear);
}
void enQueueRear(Q *pq,int value)
{   
     char ch;
     if(pq->front == SIZE/2)
      {
            printf("\nQueue is full!!! Insertion is not possible!!! ");
            return;
      }
      do
      {
            printf("\nEnter the value to be inserted:");
            scanf("%d",&value);
            pq->data[pq->front] = value;
            pq->front++;
            printf("Do you want to continue insertion Y/N");
            ch=getchar();
      }while(ch=='y');
}
void enQueueFront(Q *pq,int value)
{   
     char ch;
     if(pq->front==SIZE/2)
      {
            printf("\nQueue is full!!! Insertion is not possible!!!");
            return;
      }
      do
      {
            printf("\nEnter the value to be inserted:");
            scanf("%d",&value);
            pq->rear--;
            pq->data[pq->rear] = value;
            printf("Do you want to continue insertion Y/N");
            ch=getchar();
      }
      while(ch == 'y');
}
int deQueueRear(Q *pq)
{
     int deleted;
     if(pq->front == pq->rear)
     {
            printf("\nQueue is Empty!!! Deletion is not possible!!!");
            return 0;
     }
     pq->front--;
     deleted = pq->data[(pq->front)+1];
     return deleted;
}
int deQueueFront(Q *pq)
{
     int deleted;
     if(pq->front == pq->rear)
     {
            printf("\nQueue is Empty!!! Deletion is not possible!!!");
            return 0;
     }
     pq->rear++;
     deleted = pq->data[(pq->rear)-1];
     return deleted;
}
void display(Q *pq)
{
     int i;
     if(pq->front == pq->rear)
        printf("\nQueue is Empty!!! Deletion is not possible!!!");
     else
     {
        printf("\nThe Queue elements are:");
        for(i=pq->rear;i<pq->front;i++)
        {
           printf("%d\t ",pq->data[i]);
        }
     }
}
