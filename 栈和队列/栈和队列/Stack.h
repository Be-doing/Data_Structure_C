#pragma once


//动态增长的栈
typedef struct Stack
{
	int *stack;
	int top;
	int capacity;
}Stack;

//栈的 初始化
void st_init(Stack* st, int capacity);
//栈的销毁
void st_destroy(Stack* st);
//栈的扩容
void st_capacity(Stack* st);
//打印栈
void st_print(Stack* st);
//栈的插入
void st_add(Stack* st, int data);
//栈的删除
void st_del(Stack* st);
//输出栈顶元素
int st_topdata(Stack* st);
//求栈的有效长度
int st_size(Stack* st);
//判断是否为空
int st_empty(Stack* st);
