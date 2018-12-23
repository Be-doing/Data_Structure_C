
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
//√∞≈›≈≈–Ú
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
//÷±Ω”≤Â»Î≈≈–Ú
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
			if (temp < arr[j]) 
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
main()
{
	int arr[] = { 1,2,5,7,6,3,4,8,4 };
	int len = sizeof(arr) / sizeof(int);
	int* temp = bubble_sort(arr, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d  ", temp[i]);
	}
	system("pause");
}