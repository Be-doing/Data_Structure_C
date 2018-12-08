#include "DListNode.h"
#include<stdio.h>
#include<stdlib.h>
//创建结点
DL* get_point(int data)
{
	DL* node = (DL*)malloc(sizeof(DL));
	node->data = data;
	node->next = node->prev = NULL;
	return node;
}
//初始化
void dl_init(DLS* dls)
{
	DL* head = get_point(0);
	head->next = head;
	head->prev = head;
	dls->head = head;
}
//销毁
	//清空
void dl_clear(DLS* dls)
{
	DL* temp;
	DL* fellow;
	for (temp=dls->head->next; temp != dls->head; temp = fellow)
	{
		fellow = temp->next;
		free(temp);
	}
	dls->head->next =dls->head;
	dls->head->prev= dls->head;
}
void dl_destroy(DLS* dls)
{
	dl_clear(dls);
	free(dls->head);
}
//查找
DL* dl_find(DLS* dls, int data)
{
	DL* temp = dls->head->next;
	for (temp; temp != dls->head; temp = temp->next)
	{
		if (temp->data == data)
		{
			return temp;
		}
	}
	return NULL;
}
//打印
void dl_print(DLS* dls)
{
	DL* temp = dls->head->next;
	for (temp; temp != dls->head; temp = temp->next)
	{
		printf("%d <==> ", temp->data);
	}
	printf("head\n");
}
//插入
	//随机结点之前插入
void dl_randadd(DL* pos, int data)
{
	DL* node = get_point(data);
	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}
//前插
void dl_frontadd(DLS* dls, int data)
{
	//DL_randadd(dls->head->next, data);
	DL* node = get_point(data);
	node->next = dls->head->next;
	node->prev = dls->head;
	dls->head->next->prev = node;
	dls->head->next = node;
}
//尾插
void dl_endtadd(DLS* dls, int data)
{
	//DL_randadd(dls->head, data);
	DL* node = get_point(data);
	node->next = dls->head;
	node->prev = dls->head->prev;
	dls->head->prev->next = node;
	dls->head->prev = node;
}

//随机删除
void dl_randdel(DL* pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
//头删
void dl_frontdel(DLS* dls)
{
	DL* temp = dls->head->next;
	dls->head->next->next->prev = dls->head;
	dls->head->next = dls->head->next->next;
	free(temp);
}
//尾删
void dl_enddel(DLS* dls)
{
	DL* temp = dls->head->prev;
	dls->head->prev->prev->next = dls->head;
	dls->head->prev = dls->head->prev->prev;
	free(temp);
}

