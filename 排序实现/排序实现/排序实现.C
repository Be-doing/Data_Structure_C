#include"Sort.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
//冒泡排序
void Bubble_Sort(int arr[], int size)
{
	assert(arr);
	for(int row = 0; row < size - 1; ++row)
	{
		int flag = 1;
		for(int col = 0; col < size - row - 1; ++col)
		{
			if (arr[col] < arr[col + 1])
			{
				int temp = arr[col + 1];
				arr[col + 1] = arr[col];
				arr[col] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
//直接插入排序
void  Insert_Sort(int arr[], int size)
{
	assert(arr);
	int i, j; 
	int temp; 
	for (i = 1; i < size; ++i)
	{ 
		temp = arr[i]; 
		for (j = i - 1; j >= 0; --j)
		{ 
			if (temp > arr[j]) 
			{ 
				arr[j + 1] = arr[j]; 
			}
			else 
			{ 
				break;
			}
		} 
		arr[j + 1] = temp;
	}
}
//希尔排序
	//利用间隔排序
void Insert_Sort_Withgap(int arr[], int size, int gap)
{
	assert(arr);
	int i, j;
	int temp;
	for (i = gap; i < size; ++i)
	{
		temp = arr[i];
		for (j = i - gap; j >= 0; j -= gap)
		{
			if (temp > arr[j])
			{
				arr[j + gap] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + gap] = temp;
	}
}
	//希尔
void Shell_Sort(int arr[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;
		Insert_Sort_Withgap(arr, size, gap);
		if (gap == 1)
		{
			break;
		}
	}
}
//选择排序
void Choice_Sort(int arr[], int size)
{
	for (int i = 1; i < size ; ++i)
	{
		for (int j =  0; j <  i; ++j)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
			}
		}
	}
}
//堆排序
//向下调整
void Adjust_down(int arr[], int size, int root)
{
	while (1)
	{
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int min = left;
		if (left >= size)
		{
			return;
		}
		if (right < size && arr[right] < arr[left])
		{
			min = right;
		}
		if (arr[root] <= arr[min])
		{
			return;
		}
		int temp = arr[root];
		arr[root] = arr[min];
		arr[min] = temp;

		root = min;
	}
}
	//建堆
void CreateBigHeap(int arr[], int size)
{
	//对左子树建堆，再对右子树建堆
	int notlevel = (size - 2) / 2;
	while (notlevel >= 0)
	{
		Adjust_down(arr, size, notlevel);
		--notlevel;
	}
}

void HeapSort(int arr[], int size)
{
	//建堆
	CreateBigHeap(arr, size);

	for (int temp = 1; temp < size; ++temp)
	{
		int t = arr[0];
		arr[0] = arr[size - temp];
		arr[size - temp] = t;	
		Adjust_down(arr, size-temp,0);
	}
}
////快速排序
//void quick_sort(int s[], int l, int r)
//{
//	if (l < r)
//	{
//		int i = l, j = r, x = s[l];
//		while (i < j)
//		{
//			while (i < j && s[j] >= x)//从右到左找到第一个小于x的数  
//				j--;
//			if (i < j)
//				s[i++] = s[j];
//
//			while (i < j && s[i] <= x)//从左往右找到第一个大于x的数  
//				i++;
//			if (i < j)
//				s[j--] = s[i];
//
//		}
//
//		s[i] = x;//i = j的时候，将x填入中间位置  
//		quick_sort(s, l, i - 1);//递归调用 
//		quick_sort(s, i + 1, r);
//	}
//}
//void mergeAdd(int arr[], int left, int mid, int right, int *temp) {
//		int i = left;
//	int j = mid + 1;
//	int k = left;//临时下标
//	while (i <= mid && j <= right) {
//		if (arr[i] < arr[j]) {
//			temp[k++] = arr[i++];
//		}
//		else {
//			temp[k++] = arr[j++];
//		}
//	}
//	while (i <= mid) {
//		temp[k++] = arr[i++];
//	}
//	while (j <= right) {
//		temp[k++] = arr[j++];
//	}
//	//把temp中的内容拷给arr数组中
//	//进行归并的时候，处理的区间是arr[left,right),对应的会把
//	//这部分区间的数组填到tmp[left,right)区间上
//	memcpy(arr + left, temp + left, sizeof(int)*(right - left + 1));
//}
//void mergeSort(int arr[], int left, int right, int *temp) {
//	int mid = 0;
//	if (left < right) {
//		mid = left + (right - left) / 2;
//		mergeSort(arr, left, mid, temp);
//		mergeSort(arr, mid + 1, right, temp);
//		mergeAdd(arr, left, mid, right, temp);
//	}
//
//}
