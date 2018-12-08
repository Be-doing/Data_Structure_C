#pragma once

typedef struct DListNode
{
	int data;
	struct DListNode* next;
	struct DListNode* prev;
}DL;

typedef struct DList
{
	DL* head;
}DLS;

//初始化
void dl_init(DLS* dls);
//销毁
void dl_destroy(DLS* dls);
//查找
DL* dl_find(DLS* dls, int data);
//打印
void dl_print(DLS* dls);
//插入
	//随即插入
void dl_randadd(DL* pos, int data);
	//前插
void dl_frontadd(DLS* dls, int data);
	//尾插
void dl_endtadd(DLS* dls, int data);
//删除
	//随机删除
void dl_randdel(DL* pos);
	//头删
void dl_frontdel(DLS* dls);
	//尾删
void dl_enddel(DLS* dls);

