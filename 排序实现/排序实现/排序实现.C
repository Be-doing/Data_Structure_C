
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
//冒泡排序
int* bubble_sort(int* arr, int size)
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
	return arr;
}
//直接插入排序
int* insert_sort(int* arr, int size)
{
	assert(arr);
	int i, j; 
	int temp; 
	for (i = 1; i < size; i++) 
	{ 
		temp = arr[i]; 
		for (j = i - 1; j >= 0; j--) 
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
	return arr;
}
//选择排序
int* choice_sort(int *arr, int size)
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr;
}
//快速排序
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x)//从右到左找到第一个小于x的数  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] <= x)//从左往右找到第一个大于x的数  
				i++;
			if (i < j)
				s[j--] = s[i];

		}

		s[i] = x;//i = j的时候，将x填入中间位置  
		quick_sort(s, l, i - 1);//递归调用 
		quick_sort(s, i + 1, r);
	}
}
void mergeAdd(int arr[], int left, int mid, int right, int *temp) {
		int i = left;
	int j = mid + 1;
	int k = left;//临时下标
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}
	//把temp中的内容拷给arr数组中
	//进行归并的时候，处理的区间是arr[left,right),对应的会把
	//这部分区间的数组填到tmp[left,right)区间上
	memcpy(arr + left, temp + left, sizeof(int)*(right - left + 1));
}
void mergeSort(int arr[], int left, int right, int *temp) {
	int mid = 0;
	if (left < right) {
		mid = left + (right - left) / 2;
		mergeSort(arr, left, mid, temp);
		mergeSort(arr, mid + 1, right, temp);
		mergeAdd(arr, left, mid, right, temp);
	}

}
main()
{
	int arr[] = { 1,2,5,7,6,3,4,8,4 };
	int len = sizeof(arr) / sizeof(int);
	int* temp = bubble_sort(arr, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d  ", temp[i]);
	}
	printf("\n");


	int arr2[] = { 1,2,5,7,6,3,4,8,4 };
	int len2 = sizeof(arr2) / sizeof(int);
	int* temp2 = insert_sort(arr2, len);

	for (int i = 0; i < len2; i++)
	{
		printf("%d  ", temp2[i]);
	}
	printf("\n");


	int arr3[] = { 1,2,5,7,6,3,4,8,4 };
	int len3 = sizeof(arr3) / sizeof(int);
	int* temp3 = choice_sort(arr3, len);

	for (int i = 0; i < len3; i++)
	{
		printf("%d  ", temp3[i]);
	}
	printf("\n");
	system("pause");
}