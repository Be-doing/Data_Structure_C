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
	//�������
void sql_add_rand(Sql* sql,size_t pos, int num);

//ɾ�ӿ�
	//ͷɾ
void sql_del_front(Sql* sl);
	//βɾ
void sql_del_front(Sql* sl);
	//���ɾ��
void sql_del_randpos(Sql* sl ,size_t pos);
void sql_del_randnum(Sql* sl, int num);

//��ӿ�
int sql_find(Sql* sl, int num);

//�Ľӿ�
void sql_updata(Sql* sl,size_t pos,int num);

//��չ
	//ð������
void sql_bubblesort(Sql* sl);

	//�۰����
void sql_half_find(Sql* sl, int num);

	//ɾ����ͬ����
void sql_del_allsame(Sql* sl, int num);
