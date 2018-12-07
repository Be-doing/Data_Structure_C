#include"OJÁ´±í.h"
#include<stdlib.h>
#include<stdio.h>
main()
{
	HEAD sl_main;
	sl_init(&sl_main);
	//sl_add_end(&sl_main,2);
	//sl_add_end(&sl_main,3);
	//sl_add_end(&sl_main, 3);
	//sl_add_end(&sl_main, 3);
	//sl_add_end(&sl_main, 3);
	//sl_print(&sl_main);
	//sl_reverse(&sl_main);
	//sl_print(&sl_main);
	//printf("%d\n",sl_midnode(&sl_main));
	//printf("%d\n",sl_botk(&sl_main,0));
	sl_add_end(&sl_main, 1);
	sl_add_end(&sl_main, 2);
	sl_add_end(&sl_main, 4);
	sl_add_end(&sl_main, 5);
	sl_add_end(&sl_main, 5);
	sl_add_end(&sl_main, 6);

	sl_print(&sl_main);
	HEAD temp;
	temp.head = sl_delsameall(&sl_main);
	sl_print(&sl_main);
	//sl_comp(&sl_main,2);
	//sl_print(&sl_main);
	//HEAD sl_main2;
	//sl_init(&sl_main2);
	//sl_add_end(&sl_main2, 3);
	//sl_add_end(&sl_main2, 5);
	//sl_add_end(&sl_main2, 6);
	//sl_print(&sl_main2);

	//HEAD temp;
	//temp.head=sl_link(&sl_main,&sl_main2);

	//sl_print(&temp);

	system("pause");
}

