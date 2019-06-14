#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
//括号匹配 “{}”“()”“[]”；没有匹配返回 0 ，匹配返回非0
//左右括号数量相等
//int bracket(char* bra)
//{
//	char* p = bra;
//	Stack stack;
//	st_init(&stack);
//	while (*p)
//	{
//		switch (*p)
//		{
//		case '(':
//		case '{':
//		case '[':
//			st_add(&stack, *p);
//			break;
//		case ')':
//		case '}':
//		case ']':
//			if (st_empt(&stack))
//			{
//				return 0;
//			}
//			char left = st_top(&stack);
//			if (!((left=='('&&*p == ')')||(left == '{'&&*p == '}')||(left == '['&&*p == ']')))
//			{
//				return 0;
//			}
//			st_del(&stack);
//		default:
//			break;
//		}
//		++p;
//	}
//	return 1;
//}
//
//
//void Stack_test()
//{
//	char* test = "{{({}[])}}";
//	printf("%d\n", bracket(test));
//	system("pause");
//}
//
//
//
//#include"Queue.h"
////用队列实现栈
//	//创建栈
//typedef struct MyStack
//{
//	int capacity;
//	Queue queue;
//}MyStack;
//	//初始化/创建
//MyStack* myst_init(int capacity)
//{
//	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));//因为没有给内存，则需要在堆上申请内存
//	assert(stack);
//	stack->capacity = capacity;
//	qu_init(&(stack->queue));
//	return stack;	
//}
//	//添加
//void myst_push(MyStack* st, int data)
//{
//	assert((st->queue.size)<(st->capacity));
//	
//	qu_push(&(st->queue),data);
//}
//	//删除
//void myst_pop(MyStack* st)
//{
//	assert(st->queue.size>0);
//	int size = st->queue.size;
//	for (int i = 0; i < size - 1; i++)
//	{
//		int temp = qu_head(&(st->queue));
//		qu_pop(&(st->queue));
//		qu_push(&(st->queue), temp);
//	}
//	qu_pop(&(st->queue));
//	--st->queue.size;
//}
//	//取栈顶元素
//int myst_top(MyStack* st)
//{
//	assert(st->queue.size > 0);
//	int size = st->queue.size;
//	for (int i = 0; i < size - 1; i++)
//	{
//		int temp = qu_head(&(st->queue));
//		qu_pop(&(st->queue));
//		qu_push(&(st->queue), temp);
//	}
//	int temp2 = qu_head(&(st->queue));
//	qu_pop(&(st->queue));
//	qu_push(&(st->queue), temp2);
//	return temp2;
//}
//	//判断为空
//int myst_empt(MyStack* st)
//{
//	return qu_empty(&(st->queue));
//}
//
////栈实现队列
//typedef struct MyQueue
//{
//	int maxSize;
//	Stack stackA;
//	Stack stackB;
//}MyQueue;
//
//	//初始化
//MyQueue* mtqu_init(int maxSize)
//{
//	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
//	assert(queue);
//	queue->maxSize = maxSize;
//	st_init(&(queue->stackA));
//	st_init(&(queue->stackB));
//
//	return queue;
//}
//	//添加
//void myqu_push(MyQueue* qu, int data)
//{
//	//st_push(&(qu->stackA), data);
//}
//	//删除
//void myqu_pop(MyQueue* qu)
//{
//	//(qu->stackB) == NULL
//	if (st_empt(&(qu->stackB)))
//	{
//		int size = st_size(&(qu->stackA));
//		for (int  i = 0; i < size; ++i)
//		{
//			int temp = st_top(&(qu->stackA));
//			st_del(&(qu->stackA));
////			st_push(&(qu->stackB), temp);
//		}
//	}
//	st_del(&(qu->stackB));
//}
//	//返回队首
//void myqu_front(MyQueue* qu)
//{
//	if (st_empt(&(qu->stackB)))
//	{
//		int size = st_size(&(qu->stackA));
//		for (int i = 0; i < size; ++i)
//		{
//			int temp = st_top(&(qu->stackA));
//			st_del(&(qu->stackA));
//			st_push(&(qu->stackB), temp);
//		}
//	}
////	return st_top(&(qu->stackB));
//}
//	//判断为空
//int myqu_empty(MyQueue* qu)
//{
//	return st_empt(&(qu->stackA)) && st_empt(&(qu->stackB));
//}
//
////实现一个最小栈
//typedef struct MinStack
//{
//	Stack stack1;
//	Stack stack2;
//}MinStack;
//	//初始化
//MinStack* mst_init()
//{
//	MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
//	assert(stack);
//	st_init(&(stack->stack1));
//	st_init(&(stack->stack2));
//	return stack;
//}
//	//进栈
//void mst_push(MinStack* mst, int data)
//{
//	st_push(&(mst->stack1),data);
//	if (st_empt(&(mst->stack2)))
//	{
//		st_push(&(mst->stack2), data);
//	}
//	else
//	{
//		int min = st_top(&(mst->stack2));
//		if (data < min)
//		{
//			min = data;
//			st_push(&(mst->stack2), min);
//		}
//	}
//}
//	//出栈
//void mst_pop(MinStack* mst)
//{
//	if (st_top(&(mst->stack1)) == st_top(&(mst->stack2)))
//	{
//		st_del(&(mst->stack2));
//	}
//	st_del(&(mst->stack1));
//}
//	//获取最小
//int mst_min(MinStack* mst)
//{
//	return st_top(&(mst->stack2));
//}
//	//栈顶
//int mst_top(MinStack* mst)
//{
//	return st_top(&(mst->stack1));
//}
//	//判断为空
//int mst_empty(MinStack* mst)
//{
//	return st_empt(&(mst->stack1));
//}





//循环队列
	//创建队列
typedef int CQData;
typedef struct CirculateQueue
{
	CQData arr[20];
	int size;
	int capacity;
	int front;
	int rear;
}CQ;

CQ* cq_init(int capacity)
{
	CQ* circulateQueue = (CQ*)malloc(sizeof(CQ));
	//circulateQueue->arr = (int*) malloc(sizeof(int)*capacity);
	circulateQueue->capacity = capacity;
	circulateQueue->front = circulateQueue->rear = circulateQueue->size = 0;
	return circulateQueue;
}
int cq_push(CQ* cq, int data)
{
	if (cq->capacity == cq->size)
	{
		return -1;
	}
	cq->arr[cq->rear] = data;
	cq->rear = (cq->rear + 1) % cq->capacity;
	return data;
}
int cq_pop(CQ* cq)
{
	if (cq->size == 0)
	{
		return -1;
	}
	--cq->size;
	cq->front = (cq->front + 1) % cq->capacity;
	return 1;
}
CQData cq_front(CQ* cq)
{
	if (cq->size == 0)
	{
		return -1;
	}
	return cq->arr[cq->front];
}
CQData cq_rear(CQ* cq)
{
	if (cq->size == 0)
	{
		return -1;
	}
	return cq->arr[(cq->rear + cq->capacity -1) % cq->capacity];
}
int cq_empty(CQ* cq)
{
	return cq->size == 0;
}
int cq_full(CQ* cq)
{
	return cq->size == cq->capacity;
}
void cq_free(CQ* cq)
{
	free(cq->arr);
	free(cq);
}
main()
{
	CQ* c;
	c = cq_init(20);
	cq_push(c, 20);
	cq_push(c, 20);
	cq_push(c, 20);
	cq_push(c, 20);
}