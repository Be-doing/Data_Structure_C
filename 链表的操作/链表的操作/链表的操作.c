#include "SListNode.h"
#include<stdlib.h>
SL slistnode;
HEAD head;

//链表的初始化
void sl_init(HEAD* psl)
{
	psl->head->next = NULL;
}



//打印链表
void sl_print(HEAD* psl)
{
	while (psl->head->next!=NULL)
	{
		printf("%d\t",psl->head->data);
	}
	printf("\n");
}