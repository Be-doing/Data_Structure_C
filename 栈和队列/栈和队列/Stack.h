#pragma once


//��̬������ջ
typedef struct Stack
{
	int *stack;
	int top;
	int capacity;
}Stack;

//ջ�� ��ʼ��
void st_init(Stack* st, int capacity);
//ջ������
void st_destroy(Stack* st);
//ջ������
void st_capacity(Stack* st);
//��ӡջ
void st_print(Stack* st);
//ջ�Ĳ���
void st_add(Stack* st, int data);
//ջ��ɾ��
void st_del(Stack* st);
//���ջ��Ԫ��
int st_topdata(Stack* st);
//��ջ����Ч����
int st_size(Stack* st);
//�ж��Ƿ�Ϊ��
int st_empty(Stack* st);
