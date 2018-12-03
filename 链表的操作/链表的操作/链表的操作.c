#include "SListNode.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
SL slistnode;
HEAD head;

//链表的初始化
void sl_init(HEAD* psl)
{
	psl->head = NULL;
}
//链表的销毁
void sl_destroy(HEAD* psl)
{
	SL* sl;
	SL* cur = psl->head;
	while (cur!=NULL)
	{
		sl = cur->next;
		free(cur);
		cur = sl;
	}
	psl->head = NULL;
}
//打印链表
void sl_print(HEAD* psl)
{
	SL* cur = psl->head;
	while (cur!=NULL)
	{
		printf("%d-->",cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
	
}
SL* gain_data(int data)
{
	SL* node = (SL*)malloc(sizeof(SL));
	assert(node);
	node->data = data;
	node->next = NULL;
	return node;
}
//链表的前插
void sl_add_front(HEAD* psl, int num)
{
	SL* node = gain_data(num);
	assert(node);
	node->next = psl->head;
	psl->head = node;
}
//链表的尾插
void sl_add_end(HEAD* psl, int num)
{

	if (psl->head == NULL)
	{
		sl_add_front(psl,num);
		return;
	}
	SL* last = psl->head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	SL* node = gain_data(num);
	assert(node);
	last->next = node;
}
//链表的头删
void sl_del_front(HEAD* psl)
{
	assert(psl != NULL);
	assert(psl->head != NULL);
	SL* oldhead = psl->head;
	psl->head = psl->head->next;
	free(oldhead);
}
//链表的尾删
void sl_del_end(HEAD* psl)
{
	assert(psl != NULL);
	assert(psl->head != NULL);
	if (psl->head->next == NULL)
	{
		sl_del_front(psl);
		return;
	}
	SL* cur = psl->head;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	SL* oldend = cur->next;
	cur->next = cur->next->next;
	free(oldend);
}
//链表的查询
SL* sl_find(HEAD* psl, int num)
{
	assert(psl);
	SL* cur = psl->head;
	while (cur!=NULL)
	{
		if (cur->data == num)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//链表的随机插入
void sl_insert(SL* pos, int num)
{
	SL* node = gain_data(num);
	node->next = pos->next;
	pos->next = node;
}
//链表的随机删除
void sl_esare( SL* pos)
{

	SL* cur = pos->next;
	pos->next = pos->next->next;
	free(cur);
}
//链表的删除第一个遇见数字
void sl_firstnum(HEAD* psl, int num)
{
	SL *prev = NULL;
	SL *cur = psl->head;

	while (cur != NULL && cur->data != num) {
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL) {
		return;
	}
	if (prev == NULL) {
		sl_del_front(psl);// 1
		return;
	}
	prev->next = cur->next;
	free(cur);
}