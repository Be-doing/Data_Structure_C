#pragma once
#include<stdlib.h>
#include<stdio.h>
typedef int HPDataType;
//˳���ʵ�ֶ�
typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}Heap;

//����
void hp_create(HPDataType* arr, int size);
//�ѵĳ�ʼ��
void hp_init(Heap* hp, HPDataType* arr, int capacity);
//�ѵ�����
void hp_destroy(Heap* hp);
//�ѵĲ���
void hp_add(Heap* hp, HPDataType data);
//�ѵ�ɾ��
void hp_del(Heap* hp);
//�Ѷ�Ԫ��
int hp_top(Heap* hp);
//�ѵĽ����
int hp_size(Heap* hp);
//�ж϶��Ƿ�Ϊ��
int hp_empty(Heap* hp);