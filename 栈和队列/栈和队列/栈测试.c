#include"Stack.h"
#include<stdlib.h>
#include<stdio.h>
main()
{
	Stack sttest;
	st_init(&sttest,2);
	st_add(&sttest,1);
	st_add(&sttest, 2);
	st_add(&sttest, 3);
	st_print(&sttest);

	st_del(&sttest);
	st_print(&sttest);

	printf("topdata == %d\n", st_topdata(&sttest));

	printf("stack_length == %d \n",st_size(&sttest));

	printf("%d\n",st_empty(&sttest));
	system("pause");
}