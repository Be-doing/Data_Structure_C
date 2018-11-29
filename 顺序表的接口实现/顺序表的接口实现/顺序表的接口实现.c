#include "SeqList.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//Sql sql;

void sql_init(Sql* sl, size_t maxnum) 
{
	assert(sl != NULL);
	sl->arr = (int*)malloc(sizeof(int)*maxnum);
	sl->maxNum = maxnum;
	sl->size = 0;
}

void sql_destroy(Sql* sl)
{
	assert(sl != NULL);
	sl->arr = NULL;
	sl->maxNum = sl->size = 0;
}

void print_arr(Sql* sl)
{
	assert(sl != NULL);
	for (size_t i = 0; i < sl->size; i++)
	{
		printf("%d ",sl->arr[i]);
	}
	printf("\n");
}

//���ݽӿ�
void check_maxNum(Sql* sl) 
{
	assert(sl != NULL);
	if (sl->size==sl->maxNum)
	{
		printf("�������ݡ���\n");
		sl->maxNum *= 2;
		int* newarr = (int*)malloc(sizeof(int)*sl->maxNum);
		for (size_t i = 0; i < sl->size; i++)
		{
			newarr[i] = sl->arr[i];
		}
		free(sl->arr);
		sl->arr = newarr;
		printf("���ݳɹ�");
	}
}
//��ӿ�
int sql_find(Sql* sl, int num)
{
	assert(sl != NULL);
	for (size_t i = 0; i < sl->size; ++i)
	{
		if (num==sl->arr[i])
		{
			return i;
		}
	}
	return 0;
}
void sql_updata(Sql* sl, size_t pos, int num)
{
	assert(sl != NULL);
	sl->arr[pos] = num;
}
//���ӿ�
	//ͷ��
void sql_add_front(Sql* sl, int num)
{
	assert(sl != NULL);
	for (size_t add = sl->size; add > 0; add--)
	{
		sl->arr[add] = sl->arr[add - 1];
	}
	sl->arr[0] = num;
	++sl->size;
}
	//β��
void sql_add_end(Sql* sl, int num)
{
	assert(sl != NULL);
	sl->arr[sl->size] = num;
	++sl->size;
}
	//�������
void sql_add_rand(Sql* sl, size_t pos, int num)
{
	assert(sl != NULL);
	for (size_t i = sl->size; i > pos; i--)
	{
		sl->arr[i] = sl->arr[i-1];
	}
	sl->arr[pos] = num;
	++sl->size;
}
//ɾ�ӿ�
	//ͷɾ
void sql_del_front(Sql* sl)
{
	assert(sl != NULL);
	for (size_t del = 0; del < sl->size-1; del++)
	{
		sl->arr[del] = sl->arr[del + 1];
	}
		--sl->size;
}

	//βɾ
void sql_del_end(Sql* sl)
{
	assert(sl != NULL);
	sl->arr[sl->size - 1] = sl->arr[sl->size];
	--sl->size;
}
	//���ɾ��
void sql_del_randpos(Sql* sl, size_t pos)
{
	assert(sl != NULL);
	for (size_t i = pos; i < sl->size; i++)
	{
		sl->arr[pos] = sl->arr[pos + 1];
	}
	--sl->size;
}
void sql_del_randnum(Sql* sl, int num)
{
	assert(sl != NULL);
	int pos = sql_find(sl, num);
	sql_del_randpos(sl, pos);
}

//��չ
	//ð������
void sql_bubblesort(Sql* sl)
{
	assert(sl != NULL);
	for (size_t i = 0; i < sl->size; i++)
	{
		int con = 1;
		for (size_t j = 0; j < sl->size - i - 1; j++)
		{
			if (sl->arr[j] > sl->arr[j+1])
			{
				int temp = sl->arr[j];
				sl->arr[j] = sl->arr[j + 1];
				sl->arr[j + 1] = temp;
				con = 0;
 			}
		}
		if (con == 1)
		{
			return;
		}
	}
}
	//�۰����
int sql_half_find(Sql* sl, int num)
{
	assert(sl != NULL);
	int left = 0;
	int right = sl->size;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (sl->arr[mid]==num)
		{
			return mid;
		}
		else if (sl->arr[mid] < num)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return -1;
}
//ɾ����ͬ����
void sql_del_allsame(Sql* sl, int num)
{
	assert(sl != NULL);
	int notsame = 0;
	for (size_t i = 0; i < sl->size; i++)
	{
		if (sl->arr[i]!=num)
		{
			++notsame;
		}
	}
	sl->size = notsame;
}


