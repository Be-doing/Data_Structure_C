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
//��ȡ����
SL* gain_data(int data);
//�����ͷ��
void sl_add_front(HEAD* psl, int num);
//�����β��
void sl_add_end(HEAD* psl, int num);
//�����ͷɾ
void sl_del_front(HEAD* psl);
//�����βɾ
void sl_del_end(HEAD* psl);
//����Ĳ�ѯ
SL* sl_find(HEAD* psl, int num);
//������������
void sl_insert(HEAD* psl, SL* pos ,int num);
//��������ɾ��
void sl_esare(HEAD* psl, SL* pos, int num);
//�����ɾ����һ������
void sl_firstnum(HEAD* psl, int num);