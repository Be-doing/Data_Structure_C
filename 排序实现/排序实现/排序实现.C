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
	//时间复杂度 O(n^2)
void  Insert_Sort(int arr[], int size)
{
	assert(arr);
	int i;//带插入元素的下标
	int j; //需要进行比较的元素的下标。在i前面的元素都是已经排序好的元素。
	int temp; //进行存储。在插入的过程中，需要进行移动。
	for (i = 1; i < size; ++i)//1、从第二个元素插入，保证有可以比较的元素。
	{ 
		temp = arr[i]; //需要插入的元素，进行保存。
		for (j = i - 1; j >= 0; --j)//在已经有序的数列中，进行比较。
		{ 
			if (temp > arr[j]) //进行降序排序。如果待插入的元素大于它前一个元素arr[j]，
										//那么 j 位置的元素就需要向后移动一个位置。
			{ 
				arr[j + 1] = arr[j]; 
			}
			else //如果带插入元素不大于前一个元素，就停止
			{ 
				break;
			}
		} 
		arr[j + 1] = temp;//即为被插入元素的位置
	}
}
//希尔排序——缩小增量法
	//利用间隔排序
void Insert_Sort_Withgap(int arr[], int size, int gap)
{
	assert(arr);
	int i;
	int j;
	int temp;
	for (i = gap; i < size; ++i)//从下标为gap的元素作为带插入元素
	{
		temp = arr[i];//存储gap下标的元素
		for (j = i - gap; j >= 0; j -= gap)//从第 0 个元素进行比较
		{
			if (temp > arr[j])//降序
			{
				arr[j + gap] = arr[j];//gap位置的元素换成 j 所在下标的元素
			}
			else
			{
				break;
			}
		}
		arr[j + gap] = temp;//j 所在下标位置存储  temp
	}
}
	//希尔
void Shell_Sort(int arr[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;//改变gap 的值
		Insert_Sort_Withgap(arr, size, gap);
		if (gap == 1)
		{
			break;	//gap的值为一时停止
		}
	}
}
//选择排序
	//每一次选择一个最大的或者最小的放在序列的起始位置
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
void Choice_Sort2(int arr[], int size)
{
	for (int i = 1; i < size; ++i)//从下标为1 开始，找size - 1次
	{
		int max = 0;//假设最大的数的下标是第 0 个
		for (int j = 1; j <= size - i; ++j)//从下标为 1 的元素开始比较。直到最后一个数
		{
			if (arr[j] > arr[max])
			{
				max = j;//如果找到比下标为max的元素还大的元素则把max的值进行改变
			}
		}
		int temp = arr[size - i];
		arr[size - i] = arr[max];
		arr[max] = temp;
	}
}
//堆排序
	//升序建大堆，降序建小堆
//向下调整
void Adjust_down(int arr[], int size, int root)
{
	while (1)
	{
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int min = left;//最小的为最左孩子
		if (left >= size)//没有孩子结点
		{
			return;
		}
		if (right < size && arr[right] < arr[left])//有右孩子
		{
			min = right;
		}
		if (arr[root] <= arr[min])//根节点已经是最小
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
	int notlevel = (size - 2) / 2;//从最后一个非叶子结点开始调整
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
		Adjust_down(arr, size-temp,0);//从根节点开始调整
	}
}
//快速排序
	//基准值在右，左边优先，相反，右边优先：防止一比到底
int partition_1(int arr[], int left, int right)
{
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && arr[begin] <= arr[right])//必须有等，比如：1，1，1，1，1。造成死循环
		{
			++begin;
		}
		while (begin < end && arr[end] >= arr[right])
		{
			--end;
		}
		int temp = arr[begin];
		arr[begin] = arr[end];
		arr[end] = temp;
	}
	int temp = arr[begin];
	arr[begin] = arr[right];
	arr[right] = temp;

	return begin;
}
int partition_2(int arr[], int left, int right)//挖坑法
{
	int begin = left;
	int end = right;
	int pivot = arr[right];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= pivot)//必须有等，比如：1，1，1，1，1。造成死循环
		{
			++begin;
		}
		arr[end] = arr[begin];
		while (begin < end && arr[end] >= pivot)
		{
			--end;
		}
		arr[begin] = arr[end];
	}
	arr[begin] = pivot;
	return begin;
}
int partition_3(int arr[], int left, int right)
{
	int div = left;
	for (int cur = left ; cur < right; ++cur)
	{
		if (arr[cur] < arr[right])//1	3	9	2	4	6    
		{
			int temp = arr[cur];
			arr[cur] = arr[div];
			arr[div] = temp;
			++div;
		}
	}
	int temp = arr[right];
	arr[right] = arr[div];
	arr[div] = temp;
	return div;
}
void QuickSort(int arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	    int povit = partition_3(arr, left, right);
		QuickSort(arr, left, povit - 1);//递归调用 
		QuickSort(arr, povit + 1, right);
}
void Quick_Sort(int arr[], int size)
{
	QuickSort(arr, 0 , size -1);
}
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
