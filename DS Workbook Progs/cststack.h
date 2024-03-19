#include<stdio.h>
#define MAX 100
typedef struct stack
{
	char data[MAX];
	int top;
}ST;
void init(ST *ps)
{
	ps->top=-1;
}
int isEmpty(ST *ps)
{
	if(ps->top==-1)
		return 1;
	else
		return 0;
}
int isFull(ST *ps)
{
	if(ps->top==MAX-1)
		return 1;
	else
		return 0;
}
void push(ST *ps,char ch)
{
	ps->top++;
	ps->data[ps->top]=ch;
}
char pop(ST *ps)
{
	char c= ps->data[ps->top];
	ps->top--;
	return c;
}
