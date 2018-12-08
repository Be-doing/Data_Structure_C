#include "DListNode.h"
#include<stdio.h>
#include<stdlib.h>
//�������
DL* get_point(int data)
{
	DL* node = (DL*)malloc(sizeof(DL));
	node->data = data;
	node->next = node->prev = NULL;
	return node;
}
//��ʼ��
void dl_init(DLS* dls)
{
	DL* head = get_point(0);
	head->next = head;
	head->prev = head;
	dls->head = head;
}
//����
	//���
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
//����
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
//��ӡ
void dl_print(DLS* dls)
{
	DL* temp = dls->head->next;
	for (temp; temp != dls->head; temp = temp->next)
	{
		printf("%d <==> ", temp->data);
	}
	printf("head\n");
}
//����
	//������֮ǰ����
void dl_randadd(DL* pos, int data)
{
	DL* node = get_point(data);
	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}
//ǰ��
void dl_frontadd(DLS* dls, int data)
{
	//DL_randadd(dls->head->next, data);
	DL* node = get_point(data);
	node->next = dls->head->next;
	node->prev = dls->head;
	dls->head->next->prev = node;
	dls->head->next = node;
}
//β��
void dl_endtadd(DLS* dls, int data)
{
	//DL_randadd(dls->head, data);
	DL* node = get_point(data);
	node->next = dls->head;
	node->prev = dls->head->prev;
	dls->head->prev->next = node;
	dls->head->prev = node;
}

//���ɾ��
void dl_randdel(DL* pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
//ͷɾ
void dl_frontdel(DLS* dls)
{
	DL* temp = dls->head->next;
	dls->head->next->next->prev = dls->head;
	dls->head->next = dls->head->next->next;
	free(temp);
}
//βɾ
void dl_enddel(DLS* dls)
{
	DL* temp = dls->head->prev;
	dls->head->prev->prev->next = dls->head;
	dls->head->prev = dls->head->prev->prev;
	free(temp);
}

