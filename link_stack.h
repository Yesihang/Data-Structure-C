#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct S_node {
	elemtype date;
	struct S_node* next;
}s_node;
typedef s_node* poin_stack;
typedef struct {
	poin_stack top;
	int count;
}linkstack;

void InitStack(linkstack* S)             //初始化
{
	S->top = (poin_stack)malloc(sizeof(s_node));
	S->top->next = NULL;
	S->count = 0;
}

int Push(linkstack* S,elemtype e)              //进栈
{
	poin_stack q;
	q= (poin_stack)malloc(sizeof(s_node));
	q->date = e;
	q->next = S->top;
	S->top = q;
	S->count++;
	return 0;
}

int Pop(linkstack* S, elemtype* e)            //出栈
{
	if (S->top->next = NULL)
	{
		puts("这是空栈！");
		return 0;
	}
	poin_stack q;
	*e = S->top->date;
	q = S->top;
	S->top = q->next;
	free(q);
	S->count--;
	return 0;
}

int ClearStack(linkstack* S)         //清除栈
{
	if (S->top->next = NULL)
	{
		puts("这是空栈！");
		return 0;
	}
	poin_stack q;
	while (S->top->next != NULL)
	{
		q = S->top;
		S->top = q->next;
		free(q);
		S->count--;
	}
	return 0;
}
