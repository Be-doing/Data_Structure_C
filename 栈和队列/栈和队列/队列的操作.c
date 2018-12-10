#include"Queuenode.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

//队列的初始化
void qu_init(Queue* qu)
{
	assert(qu);
	qu->front = qu->end  = NULL;
	qu->size = 0;
}
//队列的销毁
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
//打印队列
void qu_print(Queue* qu)
{
	assert(qu);
	Queuenode* temp = qu->front;
	if (temp == NULL) 
	{
		printf("无队列\n");
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
//获取结点
Queuenode* qu_getnode(int data)
{
	Queuenode* node;
	node = (Queuenode*)malloc(sizeof(Queuenode));
	node->data = data;
	node->next = NULL;

	return node;
}
//队列的插入
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
//队列的删除
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
//求队列队首
void qu_frontnode(Queue* qu)
{
	printf("front == %d\n",qu->front->data);
}
//求队列队尾
void qu_endnode(Queue* qu)
{
	printf("end == %d\n",qu->end->data);
}
//判断队尾为空
void qu_empt(Queue* qu)
{
	if (qu->size == 0)
	{
		printf("队列为空\n");
	}
	else
	{
		printf("队列有 %d 个元素\n",qu->size);
	}
}
//队列的长度
int qu_size(Queue* qu)
{
	return qu->size;
}