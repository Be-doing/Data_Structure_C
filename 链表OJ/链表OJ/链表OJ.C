
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
		if (fast != NULL)
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
	if ((fast == NULL)||(k == 0))
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
		return psl1;
	}
	if (psl2 == NULL)
	{
		return psl2;
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
	return 0;
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
		psl = psl->head->next;
		newp = newp->next;
	}
	return 0;
}