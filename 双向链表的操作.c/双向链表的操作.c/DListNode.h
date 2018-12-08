#pragma once

typedef struct DListNode
{
	int data;
	struct DListNode* next;
	struct DListNode* prev;
}DL;

typedef struct DList
{
	DL* head;
}DLS;

//��ʼ��
void dl_init(DLS* dls);
//����
void dl_destroy(DLS* dls);
//����
DL* dl_find(DLS* dls, int data);
//��ӡ
void dl_print(DLS* dls);
//����
	//�漴����
void dl_randadd(DL* pos, int data);
	//ǰ��
void dl_frontadd(DLS* dls, int data);
	//β��
void dl_endtadd(DLS* dls, int data);
//ɾ��
	//���ɾ��
void dl_randdel(DL* pos);
	//ͷɾ
void dl_frontdel(DLS* dls);
	//βɾ
void dl_enddel(DLS* dls);

