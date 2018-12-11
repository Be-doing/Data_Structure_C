#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
//括号匹配 “{}”“()”“[]”；没有匹配返回 0 ，匹配返回非0
//左右括号数量相等
int bracket(char* bra)
{
	char* p = bra;
	Stack stack;
	st_init(&stack);
	while (*p)
	{
		switch (*p)
		{
		case '(':
		case '{':
		case '[':
			st_add(&stack, *p);
			break;
		case ')':
		case '}':
		case ']':
			if (st_empt(&stack))
			{
				return 0;
			}
			char left = st_top(&stack);
			if (!((left=='('&&*p == ')')||(left == '{'&&*p == '}')||(left == '['&&*p == ']')))
			{
				return 0;
			}
			st_del(&stack);
		default:
			break;
		}
		++p;
	}
	return 1;
}


void Stack_test()
{
	char* test = "{{({}[])}}";
	printf("%d\n", bracket(test));
	system("pause");
}

main()
{
	Stack_test();
}