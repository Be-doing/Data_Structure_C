#include "SeqList.h"

 void main()
 {
	Sql sql_main;
	sql_init(&sql_main,10);
	sql_add_front(&sql_main, 1);
	sql_add_front(&sql_main, 1);
	sql_add_front(&sql_main, 1);
	print_arr(&sql_main);
 }