#pragma once
#include<stdio.h>
#include<stdio.h>
#define MAX 40
typedef int elemtype;
typedef struct {
	elemtype data[MAX];
	int top;
}arrStack;

int InitStack(arrStack* S)          //初始化
{
	S->top = -1;
	return 0;
}

int Push(arrStack* S,elemtype e)           //进栈
{
	if (S->top = MAX - 1)
	{
		puts("栈已满！");
		return 0;
	}
	++(S->top);
	S->data[S->top] = e;
	return 0;
}

int Pop(arrStack* S, elemtype* e)          //出栈
{
	if(S->top=-1)
	{
		puts("这是空栈！");
		return 0;
	}
	*e = S->data[S->top];
	--(S->top);
	return 0;
}

int LengthStack(arrStack*S)       //计算栈的长度，并返回其值
{
	return (S->top+1);
}

int ShowStack(arrStack* S)       //打印栈
{
	if (S->top = MAX - 1)
	{
		printf("这是一个空栈！");
		return 0;
	}
	int i = 0;
	for (i; i <= S->top; i++)
		printf("->%d", S->data[i]);
	return 0;
}

int ClearStack(arrStack* S)       //清空栈
{
	if (S->top = MAX - 1)
	{
		printf("这是一个空栈！");
		return 0;
	}
	S->top = -1;
	return 0;
}
