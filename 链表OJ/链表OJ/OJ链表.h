#pragma once
typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SL;

typedef struct SLHEAD
{
	SL* head;
}HEAD;
void sl_init(HEAD* spl);
//链表的头插
void sl_add_front(HEAD* psl, int num);
//链表的尾插
void sl_add_end(HEAD* psl, int num);
//打印链表
void sl_print(HEAD* psl);
// 删除链表中等于给定值 val 的所有节点。
void sl_delall(HEAD* psl,int num);
//反转一个单链表。
void sl_reverse(HEAD* psl);
//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
SL* sl_midnode(HEAD* psl);//（数据）
//输入一个链表，输出该链表中倒数第k个结点。
int sl_botk(HEAD* psl, int k);
//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
SL* sl_link(HEAD* psl1, HEAD* psl2);
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 。
void sl_comp(HEAD* psl, int x);
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
SL* sl_delsameall(HEAD* psl);
//链表的回文结构。
int sl_judpal(HEAD* psl);
//输入两个链表，找出它们的第一个公共结点。
SL* sl_findcon(HEAD* psl1, HEAD* psl2);
//判断是否带环
int sl_cycle(HEAD* psl);
