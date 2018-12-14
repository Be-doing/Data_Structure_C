#include"Heap.h"
//œ‘ æ
void hp_print(Heap* hp)
{
	int temp = 0;
	while (temp < hp->size)
	{
		printf("%d ", hp->arr[temp]);
		++temp;
	}
	printf("\n");
	
}
main()
{
	Heap heap;

	HPDataType arr[] = { 1, 2, 5, 9, 14, 16, 7, 8 };
	int size = sizeof(arr) / sizeof(HPDataType);
	hp_create(arr,size);
	hp_init(&heap,arr,size);
	hp_print(&heap);
	
	hp_add(&heap,37);
	hp_print(&heap);

	hp_del(&heap);
	hp_print(&heap);

	printf("%d\n",hp_top(&heap));

	printf("%d\n", hp_size(&heap));

	printf("%d\n",hp_empty(&heap));
	system("pause");
}