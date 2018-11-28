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
	//随机加入
void sql_add_rand(Sql* sql,size_t pos, int num);

//删接口
	//头删
void sql_del_front(Sql* sl);
	//尾删
void sql_del_front(Sql* sl);
	//随机删除
void sql_del_randpos(Sql* sl ,size_t pos);
void sql_del_randnum(Sql* sl, int num);

//查接口
int sql_find(Sql* sl, int num);

//改接口
void sql_updata(Sql* sl,size_t pos,int num);

//拓展
	//冒泡排序
void sql_bubblesort(Sql* sl);

	//折半查找
void sql_half_find(Sql* sl, int num);

	//删除相同的数
void sql_del_allsame(Sql* sl, int num);
