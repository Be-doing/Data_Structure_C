#include "SListNode.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
SL slistnode;
HEAD head;

//����ĳ�ʼ��
void sl_init(HEAD* psl)
{
	psl->head = NULL;
}
//���������
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
//��ӡ����
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
//�����ǰ��
void sl_add_front(HEAD* psl, int num)
{
	SL* node = gain_data(num);
	assert(node);
	node->next = psl->head;
	psl->head = node;
}
//�����β��
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
//�����ͷɾ
void sl_del_front(HEAD* psl)
{
	assert(psl != NULL);
	assert(psl->head != NULL);
	SL* oldhead = psl->head;
	psl->head = psl->head->next;
	free(oldhead);
}
//�����βɾ
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
//����Ĳ�ѯ
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
//������������
void sl_insert(SL* pos, int num)
{
	SL* node = gain_data(num);
	node->next = pos->next;
	pos->next = node;
}
//��������ɾ��
void sl_esare( SL* pos)
{

	SL* cur = pos->next;
	pos->next = pos->next->next;
	free(cur);
}
//�����ɾ����һ����������
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