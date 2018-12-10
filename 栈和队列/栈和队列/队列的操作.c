#include"Queuenode.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

//���еĳ�ʼ��
void qu_init(Queue* qu)
{
	assert(qu);
	qu->front = qu->end  = NULL;
	qu->size = 0;
}
//���е�����
void qu_destroy(Queue* qu)
{
	assert(qu);
	Queuenode* temp;
	for (Queuenode* cur = qu->front; cur != NULL; cur = temp)
	{
		temp = cur->next;
		free(cur);
	}
	qu->front = qu->end = NULL;
	qu->size = 0;
}
//��ӡ����
void qu_print(Queue* qu)
{
	assert(qu);
	Queuenode* temp = qu->front;
	if (temp == NULL) 
	{
		printf("�޶���\n");
		return;
	}
	printf("front = ");
	while (temp != NULL)
	{
		printf("%d => ",temp->data);
		temp = temp->next;
	}
	printf("end\n");
}
//��ȡ���
Queuenode* qu_getnode(int data)
{
	Queuenode* node;
	node = (Queuenode*)malloc(sizeof(Queuenode));
	node->data = data;
	node->next = NULL;

	return node;
}
//���еĲ���
void qu_add(Queue* qu, int data)
{
	Queuenode* node = qu_getnode(data);
	if (qu->end == NULL)
	{
		qu->front = qu->end = node;
	}
	else
	{
	qu->end->next = node;
	qu->end = node;
	}
	++qu->size;
}
//���е�ɾ��
void qu_del(Queue* qu)
{
	assert(qu);
	Queuenode* delnode = qu->front;
	qu->front = qu->front->next;
	free(delnode);
	if (qu->front == NULL)
	{
		qu->end = NULL;
	}
	--qu->size;
}
//����ж���
void qu_frontnode(Queue* qu)
{
	printf("front == %d\n",qu->front->data);
}
//����ж�β
void qu_endnode(Queue* qu)
{
	printf("end == %d\n",qu->end->data);
}
//�ж϶�βΪ��
void qu_empt(Queue* qu)
{
	if (qu->size == 0)
	{
		printf("����Ϊ��\n");
	}
	else
	{
		printf("������ %d ��Ԫ��\n",qu->size);
	}
}
//���еĳ���
int qu_size(Queue* qu)
{
	return qu->size;
}