#include "DListNode.h"
#include<stdio.h>
#include<stdlib.h>
main()
{
	DLS dl_main;
	//��ʼ��
	dl_init(&dl_main);

	//ͷ��
	dl_frontadd(&dl_main, 3);
	dl_frontadd(&dl_main, 2);
	dl_frontadd(&dl_main, 1);
	dl_print(&dl_main);

	//β��
	dl_endtadd(&dl_main, 10);
	dl_endtadd(&dl_main, 20);
	dl_endtadd(&dl_main, 30);
	dl_print(&dl_main);

	//�����
	DL* pos = dl_find(&dl_main, 20);
	dl_randadd(pos , 100);
	dl_print(&dl_main);

	//ͷɾ
	dl_frontdel(&dl_main);
	dl_print(&dl_main);

	//βɾ
	dl_enddel(&dl_main);
	dl_print(&dl_main);

	//���ɾ��
	dl_randdel(pos);
	dl_print(&dl_main);
	system("pause");
}
