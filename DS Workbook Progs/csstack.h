#include<stdio.h>
#define MAX 40

typedef struct stack
{	
	char data[MAX];
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
void Push(ST *ps,char ch)
{
	ps->top++;
	ps->data[ps->top]=ch;
}
char Pop(ST *ps)
{
	char ch= ps->data[ps->top];
	ps->top--;
	return ch;
}


