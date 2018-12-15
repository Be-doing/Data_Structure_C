#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
//括号匹配 “{}”“()”“[]”；没有匹配返回 0 ，匹配返回非0
//左右括号数量相等
int bracket(char* bra)
{
	char* p = bra;
	Stack stack;
	st_init(&stack);
	while (*p)
	{
		switch (*p)
		{
		case '(':
		case '{':
		case '[':
			st_add(&stack, *p);
			break;
		case ')':
		case '}':
		case ']':
			if (st_empt(&stack))
			{
				return 0;
			}
			char left = st_top(&stack);
			if (!((left=='('&&*p == ')')||(left == '{'&&*p == '}')||(left == '['&&*p == ']')))
			{
				return 0;
			}
			st_del(&stack);
		default:
			break;
		}
		++p;
	}
	return 1;
}


void Stack_test()
{
	char* test = "{{({}[])}}";
	printf("%d\n", bracket(test));
	system("pause");
}



#include"Queue.h"
//用队列实现栈
	//创建栈
typedef struct MyStack
{
	int capacity;
	Queue queue;
}MyStack;
	//初始化/创建
MyStack* myst_init(int capacity)
{
	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
	assert(stack);
	stack->capacity = capacity;
	qu_init(&(stack->queue));
	return stack;	
}
	//添加
void myst_push(MyStack* st, int data)
{
	assert((st->queue.size)<(st->capacity));
	qu_push(&(st->queue),data);
}
	//删除
void myst_pop(MyStack* st)
{
	assert(st->queue.size>0);
	qu_pop(&(st->queue.front));
}
main()
{
	Stack_test();
}