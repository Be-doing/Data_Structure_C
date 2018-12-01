#include "SListNode.h"
#include<stdlib.h>
main()
{
	HEAD slnode;
	sl_init(&slnode);
	sl_add_front(&slnode, 3);
	sl_add_front(&slnode, 2);
	sl_add_front(&slnode, 1);
	sl_print(&slnode);

	//sl_destroy(&slnode);
	//sl_print(&slnode);

	sl_add_end(&slnode, 4);
	sl_add_end(&slnode, 5);
	sl_add_end(&slnode, 6);
	sl_print(&slnode);

	sl_del_front(&slnode);
	sl_del_front(&slnode);
	sl_print(&slnode);

	sl_del_end(&slnode);
	sl_del_end(&slnode);
	sl_print(&slnode);

	system("pause");
}