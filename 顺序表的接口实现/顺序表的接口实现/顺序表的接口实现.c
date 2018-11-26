#include "SeqList.h"

#include<stdio.h>

Sql seqlist;

void sql_init(Sql* sl, size_t maxnum) 
{
	sl->arr = 0;
	sl->maxNum = maxnum;
	sl->size = 0;
}

void sql_destroy(Sql* sl)
{
	sl->arr = NULL;
	sl->maxNum = sl->size = 0;
}

void print_arr(Sql* sl)
{
	for (size_t i = 0; i < sl->size-1; i++)
	{
		printf("%d ",sl->arr[i]);
	}
	printf("\n");
}

//增接口
	//头插
void sql_add_front(Sql* sl, int num)
{
	for (size_t add = sl->size; add > 0; add--)
	{
		sl->arr[add] = sl->arr[add - 1];
	}
	sl->arr[0] = num;
	++sl->size;
}
	//尾插
void sql_add_end(Sql* sl, int num)
{
	sl->arr[sl->size] = num;
	++sl->size;
}
