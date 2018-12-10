#include"Queuenode.h"
#include<stdlib.h>
#include<stdio.h>
main()
{
	Queue qu_test;

	qu_init(&qu_test);

	qu_add(&qu_test, 1);
	qu_add(&qu_test, 2);
	qu_add(&qu_test, 3);
	qu_print(&qu_test);

	qu_del(&qu_test);
	qu_print(&qu_test);

	qu_empt(&qu_test);
	qu_endnode(&qu_test);
	qu_frontnode(&qu_test);

	printf("≥§∂» « %d\n", qu_size(&qu_test));

	qu_destroy(&qu_test);
	qu_print(&qu_test);
	system("pause");
}