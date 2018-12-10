#pragma once
typedef struct Queuenode //队列结点
{
	int data;
	struct Queuenode* next;
}Queuenode;

typedef struct Queue//队首和队尾
{
	Queuenode* front;
	Queuenode* end;
	int size;
}Queue;

//队列的初始化
void qu_init(Queue* qu);
//队列的销毁
void qu_destroy(Queue* qu);
//打印队列
void qu_print(Queue* qu);
//获取结点
Queuenode* qu_getnode(int data);
//队列的插入
void qu_add(Queue* qu, int data);
//队列的删除
void qu_del(Queue* qu);
//求队列队首
void qu_frontnode(Queue* qu);
//求队列队尾
void qu_endnode(Queue* qu);
//判断队尾为空
void qu_empt(Queue* qu);
//队列的长度
int qu_size(Queue* qu);
