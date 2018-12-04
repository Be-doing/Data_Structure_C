
#include"OJ链表.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

//数据入表
SL* gain_data(int num)
{
	SL* node = (SL*)malloc(sizeof(SL));
	assert(node);
	node->data = num;
	node->next = NULL;
	return node;
}
void sl_init(HEAD* sql)
{
	sql->head = NULL;
}
//打印链表
void sl_print(HEAD* psl)
{
	SL* cur = psl->head;
	while (cur != NULL)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//链表的头插
void sl_add_front(HEAD* psl, int num)
{
	SL* node = gain_data(num);
	assert(node);
	node->next=psl ->head;
	psl->head = node;
}
//链表的尾插
void sl_add_end(HEAD* psl, int num)
{
	if (psl == NULL)
	{
		sl_add_front(psl, num);
		return;
	}
	SL* last = psl->head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	SL* node = (SL*)malloc(sizeof(SL));
	node->data = num;
	node->next = NULL;
	assert(node);
	last->next = node;
}
// 删除链表中等于给定值 val 的所有节点。
SL* sl_delall(HEAD* psl, int num)
{
	if (psl == NULL) {
		return NULL;
	}
	SL* prev = psl->head;
	SL* cur = psl->head->next;
	while (cur != NULL) {
		if (cur->data != num) {
		prev = cur;
		}
		else {
			prev->next = cur->next;
			free(cur);
		}
		cur = prev->next;
	}
	SL* newHead = psl->head;
	if (psl->head->data == num) {
		newHead = psl->head->next;
		free(psl);
	}
	return newHead;
}
//反转一个单链表。
void sl_reverse(HEAD* psl)
{
	
}