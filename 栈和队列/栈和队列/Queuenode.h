#pragma once
typedef struct Queuenode //���н��
{
	int data;
	struct Queuenode* next;
}Queuenode;

typedef struct Queue//���׺Ͷ�β
{
	Queuenode* front;
	Queuenode* end;
	int size;
}Queue;

//���еĳ�ʼ��
void qu_init(Queue* qu);
//���е�����
void qu_destroy(Queue* qu);
//��ӡ����
void qu_print(Queue* qu);
//��ȡ���
Queuenode* qu_getnode(int data);
//���еĲ���
void qu_add(Queue* qu, int data);
//���е�ɾ��
void qu_del(Queue* qu);
//����ж���
void qu_frontnode(Queue* qu);
//����ж�β
void qu_endnode(Queue* qu);
//�ж϶�βΪ��
void qu_empt(Queue* qu);
//���еĳ���
int qu_size(Queue* qu);
