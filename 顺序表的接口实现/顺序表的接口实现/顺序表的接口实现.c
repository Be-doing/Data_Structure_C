#include "SeqList.h"

#include<stdio.h>
#include<stdlib.h>

//Sql sql;

void sql_init(Sql* sl, size_t maxnum) 
{
	sl->arr = (int*)malloc(sizeof(int)*maxnum);
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
	for (size_t i = 0; i < sl->size; i++)
	{
		printf("%d ",sl->arr[i]);
	}
	printf("\n");
}

//扩容接口
void check_maxNum(Sql* sl) 
{
	if (sl->size==sl->maxNum)
	{
		printf("正在扩容……\n");
		sl->maxNum *= 2;
	}
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

//删接口
	//头删
void sql_del_front(Sql* sl)
{
	for (size_t del = 0; del < sl->size-1; del++)
	{
		sl->arr[del] = sl->arr[del + 1];
	}
		--sl->size;
}
	//尾删
void sql_del_front(Sql* sl)
{
	sl->arr[sl->size - 1] = sl->arr[sl->size];
	--sl->size;
}

