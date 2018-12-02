#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void founc1(int N)
{
	int L = 0;
	int M = 10;
	while (L < N)
	{
		++L;
	}
	while (M--)
	{
		++L;
	}
}
void founc2(int N , int M)
{
	int i = 0;
	
	while (i < N)
	{
		++i;
	}
	while (M--)
	{
		++i;
	}
}
void founc3(int* arr, int row)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row - i - 1; ++j)
		{
			if (arr[j] > arr[j +1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}
	}
}
int founc4(int* arr, int num) 
{
	int left = 0;
	int right = sizeof(arr)/sizeof(int);
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid]==num)
		{
			return mid;
		}
		else if (mid < num)
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
int founc5(int num)
{
	if (num < 3)
	{
		return num;
	}
	return founc5(num - 1) + founc5(num - 2);
}
void main() {
	int num = 5;
	printf("%d\n",founc5(num));
	system("pause");
}