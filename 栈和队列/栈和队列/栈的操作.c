#include "Stack.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
//ջ�� ��ʼ��
void st_init(Stack* st, int capacity)
{
	st->capacity = capacity;
	st->top = 0;
	st->stack = (int*)malloc(sizeof(int) * st->capacity);

}
//ջ������
void st_destroy(Stack* st)
{
	st->stack = NULL;
	st->capacity = st->top = 0;
}
//ջ������
void st_capacity(Stack* st)
{
	assert(st);
	if (st->top = st->capacity)
	{
		printf("ջ���Ѿ��ﵽ�������������ݡ���\n");
		st->capacity = st->capacity * 2;
		int* newst = (int *)malloc(sizeof(int) * st->capacity);
		for (int i = 0; i < st->top; ++i)
		{
			newst[i] = st->stack[i];
		}
		free(st->stack);
		st->stack = newst;
		printf("�������\n");
	}
	
}
//��ӡջ
void st_print(Stack* st)
{
	for (int i = 0; i < st->top; i++)
	{
		printf("%d -> ",st->stack[i]);
	}
	printf("top\n");
}

//ջ�Ĳ���
void st_add(Stack* st,int data)
{
	if (st->top == st->capacity)
	{
		st_capacity(st);
	}
	st->stack[st->top] = data;
	++st->top;
}
//ջ��ɾ��
void st_del(Stack* st)
{
	assert(st);
	if (st->top == 0)
	{
		return;
	}
	--st->top;
}
//���ջ��Ԫ��
int st_topdata(Stack* st)
{
	return st->stack[st->top-1];
}
//��ջ����Ч����
int st_size(Stack* st)
{
	return st->top ;
}
//�ж��Ƿ�Ϊ��
int st_empty(Stack* st)
{
	if (st->top == 0)
	{
		return 0;
	}
	return 1;
}
