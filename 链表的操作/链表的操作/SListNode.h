#pragma once


typedef struct SListNode //������������
{						
	int data;//�������
	struct SListNode* next;//ָ����һ�ڵ��ָ��
}SL;

typedef struct SList
{
	SL* head;
}HEAD;

//����ĳ�ʼ��
void sl_init(HEAD* psl);
//���������
void sl_destroy(HEAD* psl);

//��ӡ����
void sl_print(HEAD* psl);

//�����ͷ��
void sl_add_front(HEAD* psl,int num);