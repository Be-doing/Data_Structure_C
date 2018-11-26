#pragma once
#include<stdio.h>
//����һ���ṹ��
typedef struct SeqList {
	int* arr;
	size_t size;
	size_t maxNum;
}Sql;

//��ʼ���ӿ�
void sql_init(Sql* sl, size_t mannum);
//���ٽӿ�
void sql_destroy(Sql* sl);
//���ݽӿ�
void check_maxNum(Sql* sl);
//��ʾ�ӿ�
void print_arr(Sql* sl);

//���ӿ�
	//ͷ��
void sql_add_front(Sql* sl, int num);
	//β��
void sql_add_end(Sql* sl, int num);

//ɾ�ӿ�
	//ͷɾ
void sql_del_front(Sql* sl);
	//βɾ
void sql_del_front(Sql* sl);

//��ӿ�
void sql_find(Sql* sl, int num);

//�Ľӿ�


