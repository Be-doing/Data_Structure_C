#include "SListNode.h"
#include<stdlib.h>
SL slistnode;
HEAD head;

//����ĳ�ʼ��
void sl_init(HEAD* psl)
{
	psl->head->next = NULL;
}



//��ӡ����
void sl_print(HEAD* psl)
{
	while (psl->head->next!=NULL)
	{
		printf("%d\t",psl->head->data);
	}
	printf("\n");
}