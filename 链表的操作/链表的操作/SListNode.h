#pragma once


typedef struct SListNode //创建单向链表
{						
	int data;//结点数据
	struct SListNode* next;//指向下一节点的指针
}SL;

typedef struct SList
{
	SL* head;
}HEAD;

//链表的初始化
void sl_init(HEAD* psl);
//链表的销毁
void sl_destroy(HEAD* psl);

//打印链表
void sl_print(HEAD* psl);

//链表的头插
void sl_add_front(HEAD* psl,int num);