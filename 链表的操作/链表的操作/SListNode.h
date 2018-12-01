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
//获取数据
SL* gain_data(int data);
//链表的头插
void sl_add_front(HEAD* psl, int num);
//链表的尾插
void sl_add_end(HEAD* psl, int num);
//链表的头删
void sl_del_front(HEAD* psl);
//链表的尾删
void sl_del_end(HEAD* psl);
//链表的查询
SL* sl_find(HEAD* psl, int num);
//链表的随机插入
void sl_insert(HEAD* psl, SL* pos ,int num);
//链表的随机删除
void sl_esare(HEAD* psl, SL* pos, int num);
//链表的删除第一个数字
void sl_firstnum(HEAD* psl, int num);