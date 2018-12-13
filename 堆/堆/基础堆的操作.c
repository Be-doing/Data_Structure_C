#include"Heap.h"
#include<stdlib.h>
Heap heap;

//���µ����㷨
//�ж��Ƿ��������ӣ����򷵻�
//�У����ж��Ƿ����Һ��ӣ����ж����Ӻ��Һ���˭��
//�ж��Ƿ���Ҫ����
//��������
void hp_down(HPDataType* arr, int size, int root)
{
	int left = (root - 1)/2;
	int right = (root - 2)/2;
	int min;
	if (left >= size)
	{
		return;
	}
	if (right < size && arr[right] < arr[left])
	{
		min = right;
	}
	else
	{
		min = left;
	}
	if (arr[root] > arr[min])
	{
		HPDataType temp = arr[root];
		arr[root] = arr[min];
		arr[min] = temp;
	}
	//root = min;
	hp_down(arr,size,min);
}

//����
void hp_create(HPDataType* arr, int size)
{
	//�����һ����Ҷ�ӽ�㿪ʼ������֪���Ѷ�
	int temp = (size-1)/2;
	while (temp >= 0)
	{
		hp_down(arr,size,temp);
		--temp;
	}
}
//�ѵ�����
void check_capacity(Heap* hp)
{
	if (hp->size == hp->capacity)
	{
		hp->capacity = hp->capacity * 2;
		HPDataType* newarr = (HPDataType*)malloc(sizeof(HPDataType) * hp->capacity);
		for (int i = 0; i < hp->size; ++i)
		{
			newarr[i] = hp->arr[i];
		}
		free(hp->arr);
		hp->arr = newarr;
	};
}
//�ѵĳ�ʼ��
void hp_init(Heap* hp, HPDataType* arr, int capacity)
{
	hp->capacity = capacity;
	hp->size = 0;
	hp->arr = (HPDataType*)malloc(sizeof(HPDataType) * hp->capacity);
	int len = sizeof(arr) / sizeof(HPDataType);
	for (int temp = 0; temp < len; ++temp)
	{
		hp->arr[temp] = arr[temp];
		++hp->size;
		check_capacity(hp);
	}
	hp_create(hp->arr, hp->size);
}
//�ѵ�����
void hp_destroy(Heap* hp)
{
	hp->capacity = hp->size = 0;
	free(hp->arr);
}
