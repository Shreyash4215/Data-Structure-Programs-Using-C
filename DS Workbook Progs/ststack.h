#include<stdio.h>
#define MAX 40

typedef struct stack
{	
	int data[MAX];
	int top;
}ST;

void create(ST *ps)
{
	ps->top=-1;
}
int isEmpty(ST *ps)
{
	return(ps->top==-1);
}
int isFull(ST *ps)
{
	return(ps->top==MAX-1);
}
void Push(ST *ps,int ch)
{
	ps->top++;
	ps->data[ps->top]=ch;
}
int Pop(ST *ps)
{
	int ch= ps->data[ps->top];
	ps->top--;
	return ch;
}
