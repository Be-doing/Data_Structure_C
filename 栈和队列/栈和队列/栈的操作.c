#include "Stack.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
//栈的 初始化
void st_init(Stack* st, int capacity)
{
	st->capacity = capacity;
	st->top = 0;
	st->stack = (int*)malloc(sizeof(int) * st->capacity);

}
//栈的销毁
void st_destroy(Stack* st)
{
	st->stack = NULL;
	st->capacity = st->top = 0;
}
//栈的扩容
void st_capacity(Stack* st)
{
	assert(st);
	if (st->top = st->capacity)
	{
		printf("栈顶已经达到容量，正在扩容……\n");
		st->capacity = st->capacity * 2;
		int* newst = (int *)malloc(sizeof(int) * st->capacity);
		for (int i = 0; i < st->top; ++i)
		{
			newst[i] = st->stack[i];
		}
		free(st->stack);
		st->stack = newst;
		printf("扩容完毕\n");
	}
	
}
//打印栈
void st_print(Stack* st)
{
	for (int i = 0; i < st->top; i++)
	{
		printf("%d -> ",st->stack[i]);
	}
	printf("top\n");
}

//栈的插入
void st_add(Stack* st,int data)
{
	if (st->top == st->capacity)
	{
		st_capacity(st);
	}
	st->stack[st->top] = data;
	++st->top;
}
//栈的删除
void st_del(Stack* st)
{
	assert(st);
	if (st->top == 0)
	{
		return;
	}
	--st->top;
}
//输出栈顶元素
int st_topdata(Stack* st)
{
	return st->stack[st->top-1];
}
//求栈的有效长度
int st_size(Stack* st)
{
	return st->top ;
}
//判断是否为空
int st_empty(Stack* st)
{
	if (st->top == 0)
	{
		return 0;
	}
	return 1;
}
