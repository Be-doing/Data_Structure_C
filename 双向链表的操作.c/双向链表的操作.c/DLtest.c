#include "DListNode.h"
#include<stdio.h>
#include<stdlib.h>
main()
{
	DLS dl_main;
	//³õÊ¼»¯
	dl_init(&dl_main);

	//Í·²å
	dl_frontadd(&dl_main, 3);
	dl_frontadd(&dl_main, 2);
	dl_frontadd(&dl_main, 1);
	dl_print(&dl_main);

	//Î²²å
	dl_endtadd(&dl_main, 10);
	dl_endtadd(&dl_main, 20);
	dl_endtadd(&dl_main, 30);
	dl_print(&dl_main);

	//Ëæ»ú²å
	DL* pos = dl_find(&dl_main, 20);
	dl_randadd(pos , 100);
	dl_print(&dl_main);

	//Í·É¾
	dl_frontdel(&dl_main);
	dl_print(&dl_main);

	//Î²É¾
	dl_enddel(&dl_main);
	dl_print(&dl_main);

	//Ëæ»úÉ¾³ý
	dl_randdel(pos);
	dl_print(&dl_main);
	system("pause");
}
