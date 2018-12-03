
#include"OJ链表.h"
#include<stdlib.h>
#include<stdio.h>
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
//链表的尾插
void sl_add_end(HEAD* psl, int num)
{

	if (psl->head == NULL)
	{
		sl_add_front(psl, num);
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

void sl_delall(HEAD* psl, int num)
{
	if (psl == NULL) {
		return NULL;
	}

	HEAD* prev = psl;
	HEAD* cur = psl->head->next;

	while (cur != NULL) {
		if (cur->head->data != num) {
		prev = cur;
		}
		else {
			prev->head->next = cur->head->next;
			free(cur);
		}
		cur = prev->head->next;
	}

	HEAD* newHead = psl->head;
	if (psl->head->data == num) {
		newHead = psl->head->next;
		free(psl->head);
	}

	return newHead;
}