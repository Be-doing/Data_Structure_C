
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
	SL* node = (SL*)malloc(sizeof(SL));
	node->data = num;
	node->next = NULL;
	assert(node);
	last->next = node;
}
// 删除链表中等于给定值 val 的所有节点。
void sl_delall(HEAD* psl, int num)
{
	if (psl == NULL) {
		return;
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
	psl->head = newHead;

}
//反转一个单链表。
void sl_reverse(HEAD* psl)
{
	SL* p0 = NULL;
	SL* p1 = psl->head;
	SL* p2 = psl->head->next;
	while (p1 != NULL)
	{
		p1  ->next= p0;
		p0 = p1;
		p1 = p2;
		if (p2 != NULL)
		{
			p2 = p2->next;
		}
	}
	psl->head = p0;
}
//返回链表的中间结点的数据
SL* sl_midnode(HEAD* psl)
{
	SL* fast = psl->head;
	SL* slow = psl->head;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
//输入一个链表，输出该链表中倒数第k个结点。
int sl_botk(HEAD* psl, int k)
{
	SL* fast = psl->head;
	SL* slow = psl->head;
	while ((fast!=NULL)&&(k--))
	{
		fast = fast->next;
	}
	if (fast == NULL)
	{
		return -1;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow->data;
}
//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
SL* sl_link(HEAD* psl1, HEAD* psl2)
{
	if (psl1 == NULL)
	{
		return psl1->head;
	}	
	if (psl2 == NULL)
	{
		return psl2->head;
	}
	SL* newsl = NULL;
	SL* newend = NULL;
	SL* p1 = psl1->head;
	SL* p2 = psl2->head;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data <= p2->data)
		{
			if (newend == NULL)
			{
				newsl = newend = p1;
			}
			newend->next = p1;
			newend = newend->next;
			p1 = p1->next;
		}
		else
		{
			if (newend == NULL)
			{
				newsl = newend = p2;
			}
			newend->next = p2;
			newend = newend->next;
			p2 = p2->next;
		}
	}
	if (p1 == NULL)
	{
		newend->next = p2;
	}
	else
	{
		newend->next = p1;
	}
	return newsl;
}
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 。
void sl_comp(HEAD* psl, int x)
{
	SL* minp = NULL;
	SL* minpend = NULL;
	SL* maxp = NULL;
	SL* maxpend = NULL;

	SL* temp = psl->head;
	while (temp != NULL)
	{
		if (temp->data < x)
		{
			if (minp == NULL)
			{
				minp = minpend = temp;
			}
			else
			{
				minpend->next = temp;
				minpend = minpend->next;
			}

		}
		else
		{
			if (maxpend == NULL)
			{
				maxp = maxpend = temp;
			}
			else
			{
				maxpend->next = temp;
				maxpend = maxpend->next;
			}
		}
		temp = temp->next;
	}
	minpend->next = maxp;
}
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
SL* sl_delsameall(HEAD* psl)
{
	if (psl->head == NULL) {
		return NULL;
	}

	SL* p0 = NULL;
	SL* p1 = psl->head;
	SL *p2 = psl->head;

	while (p2 != NULL) {
		if (p1->data != p2->data) {
			p0 = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL && p2->data == p1->data) {
				p2 = p2->next;
			}
			// 1. p2 走到链表结尾
			// 2. p2 遇到不相等的值了
			if (p2 == NULL) {
				if (p0 != NULL) {
					p0->next = p2;	// NULL
				}
				else {
					return NULL;
				}
				break;
			}
			if (p0 != NULL) {
				p0->next = p2;
			}
			else {
				psl->head->next = p2;
			}
			p1 = p2;
			p2 = p2->next;
		}
	}

	return psl->head;
}

//链表的回文结构。
int sl_judpal(HEAD* psl)
{
	if (psl == NULL)
	{
		return 0;
	}
	//HEAD* node = psl;
	HEAD temp;
	temp.head = sl_midnode(psl);
	sl_reverse(&temp);
	SL* newp = temp.head; //保存翻转后的链表的头节点
	while (psl != NULL)
	{
		if (psl->head->next == newp->next)
		{
			return 1;
		}
		psl->head = psl->head->next;
		newp = newp->next;
	}
	return 0;
}

//输入两个链表，找出它们的第一个公共结点。
//写一个求链表长度的函数
int get_length(HEAD* psl)
{
	SL* temp;
	temp = psl->head;
	int len = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		++len;
	}
	return len;
}
SL* sl_findcon(HEAD* psl1,HEAD* psl2)
{
	int len1 = get_length(psl1);
	int len2 = get_length(psl2);
	SL* longer;
	SL* shorter;
	int diff;
	diff = len1 - len2;
	if (diff < 0)
	{
		diff = 0 - diff;
		longer = psl2->head;
		shorter = psl1->head;
	}
	else
	{
		longer = psl1->head;
		shorter = psl2->head;
	}
	for (int i = 0; i < diff; ++i)
	{
		longer = longer->next;
	}
	while (longer != shorter)
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	return longer;
}

//判断是否带环
int sl_cycle(HEAD* psl)
{
	SL* fast = psl->head;
	SL* slow = psl->head;
	do
	{
		if (fast == NULL)	//没有结点
		{
			break;
		}
		fast = fast->next;
		if (fast == NULL)	//一个结点
		{
			break;
		}
		fast = fast->next;
		slow = slow->next;
	} while (fast != NULL);
	if (fast == NULL)	//始终没有遇见
	{
		return -1;
	}		//遇见
	return 1;
}

//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深度拷贝。
typedef struct RandomListNode 
{
	int data;
	struct RandomListNode *next;
	struct RandomListNode *random;
}RLN;
RLN *	creatNode(int data)
{
	RLN* newnode = (RLN*)malloc(sizeof(RLN));
	newnode->data = data;
	newnode->next = newnode->random = NULL;
}
RLN* copyRondom(RLN* head)
{
	RLN* oldnode = head;
	while (oldnode != NULL)
	{
		RLN* newnode = creatNode(oldnode->data);
		newnode->data = oldnode->data;
		newnode->next = oldnode->next;
		oldnode->next = newnode;
	}
	oldnode = head;
	while (oldnode != NULL)
	{
		RLN* newnode = oldnode->next;
		if (oldnode->random != NULL)
		{
			newnode->random = oldnode->random;
		}
		oldnode = oldnode->next->next;
	}
	oldnode = head;
	RLN* newhead = head->next;
	while (oldnode = NULL)
	{
		RLN* newnode = oldnode->next;
		oldnode->next = newnode->next;
		if (oldnode->next != NULL)
		{
			newnode->next = oldnode->next->next;
		}
		else {
			newnode->next = NULL;
		}
		oldnode = oldnode->next;
	}
}

