#pragma once


#include<assert.h>

#define N 1024

typedef struct stack
{
	char arr[N];
	int top;
}Stack;
void st_init(Stack* st)
{
	st->top = 0;
}
void st_destroy(Stack* st)
{
	st->top = 0;
}
void st_add(Stack* st, char data)
{
	assert(st->top<N);
	st->arr[st->top] = data;
	++st->top;
}
void st_del(Stack* st)
{
	assert(st->top>0);
	--st->top;
}
char st_top(Stack* st)
{
	assert(st->top > 0);
	return st->arr[st->top-1];
}
int st_empt(Stack* st)
{
	return st->top == 0;
}
int st_size(Stack* st)
{
	return st->top;
}
