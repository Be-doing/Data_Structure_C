#pragma once
#include<stdio.h>
//定义一个结构体
typedef struct SeqList {
	int* arr;
	size_t size;
	size_t maxNum;
}Sql;

//初始化接口
void sql_init(Sql* sl, size_t mannum);
//销毁接口
void sql_destroy(Sql* sl);
//扩容接口
void check_maxNum(Sql* sl);
//显示接口
void print_arr(Sql* sl);

//增接口
	//头插
void sql_add_front(Sql* sl, int num);
	//尾插
void sql_add_end(Sql* sl, int num);

//删接口
	//头删
void sql_del_front(Sql* sl);
	//尾删
void sql_del_front(Sql* sl);

//查接口
void sql_find(Sql* sl, int num);

//改接口


