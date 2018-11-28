#include "SeqList.h"
#include<stdlib.h>
 void main()
 {
	Sql sql_main;
	sql_init(&sql_main,10);
	sql_add_front(&sql_main, 1);
	sql_add_front(&sql_main, 2);
	sql_add_front(&sql_main, 3);
	print_arr(&sql_main);

	sql_add_rand(&sql_main, 1, 3);
	sql_add_rand(&sql_main, 2, 4);
	sql_add_rand(&sql_main, 2, 4);
	print_arr(&sql_main);

	sql_del_front(&sql_main);
	print_arr(&sql_main);

	sql_del_randnum(&sql_main,1);
	print_arr(&sql_main);

	system("pause");
 }