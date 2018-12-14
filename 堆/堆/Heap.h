#pragma once
#include<stdlib.h>
#include<stdio.h>
typedef int HPDataType;
//顺序表实现堆
typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}Heap;

//建堆
void hp_create(HPDataType* arr, int size);
//堆的初始化
void hp_init(Heap* hp, HPDataType* arr, int capacity);
//堆的销毁
void hp_destroy(Heap* hp);
//堆的插入
void hp_add(Heap* hp, HPDataType data);
//堆的删除
void hp_del(Heap* hp);
//堆顶元素
int hp_top(Heap* hp);
//堆的结点数
int hp_size(Heap* hp);
//判断堆是否为空
int hp_empty(Heap* hp);