
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
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