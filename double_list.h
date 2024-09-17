#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
typedef struct _d_node {
	elemtype data;
	struct _d_node* prior;
	struct _d_node* next;
}d_node;
typedef d_node* d_linklist;

int InitList(d_linklist* L)       //初始化头节点
{
	(*L) = (d_linklist)malloc(sizeof(d_node));
	if (!L)
	{
		printf("内存分配失败！\n");
		exit(0);
	}
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return 0;
}

int CreateListTail(d_linklist* L)       //尾插入法插入元素，n为元素个数
{
	int n;
	d_linklist p,r;
	r = (*L);
	printf("请输入要插入元素个数:");
	scanf_s("%d", &n);
	printf("请输入要插入的元素值（用空格隔开）：\n");
	for (int i = 0; i < n; i++)
	{
		p = (d_linklist)malloc(sizeof(d_node));
		scanf_s("%d", &p->data);
		r->next = p;
		p->prior =r;
		p->next = NULL;
		r = p;
	}
	return 0;
}

int GetElem(d_linklist* L, int n, elemtype *e)       //查找第n个元素并将元素值返回给e
{
	int i=1;
	d_linklist p = (*L)->next;
	while (p && i < n)
	{
		p = p->next;
		++i;
	}
	if (!p||i>n)
	{
		printf("查找失败！");
		return 0;
	}
	*e = p->data;
	return 0;
}

int InsertList(d_linklist* L, int n, elemtype e)      //在第n个位置插入元素e
{
	int i = 1;
	d_linklist p = (*L)->next;
	d_linklist j;
	while (p && i < n)
	{
		p = p->next;
		++i;
	}
	if (!p || i > n)
	{
		printf("插入元素失败！\n");
		return 0;
	}
	j = (d_linklist)malloc(sizeof(d_node));
	j->data = e;
	j->next = p;
	j->prior = p->prior;
	(p->prior)->next = j;
	p->prior = j;
	return 0;
}

int DeleteList(d_linklist* L, int n, elemtype* e)				//删除L中第i个元素，并用e返回其值
{
	int i = 1;
	d_linklist p = (*L)->next;
	while (p && i < n)
	{
		p = p->next;
		++i;
	}
	if (!p || i > n)
	{
		printf("删除元素失败！\n");
		return 0;
	}
	*e = p->data;
	(p->prior)->next = p->next;
	(p->next)->prior = p->prior;
	free(p);
	return 0;
}

int ClearList(d_linklist* L)					//双链表的整表删除
{
	d_linklist p, j;
	p = (*L)->next;
	while (p)
	{
		j = p->next;
		free(p);
		p = j;
	}
	(*L)->next = NULL;
	return 0;
}

void ShowList(d_linklist* L)					//打印整个链表
{
	d_linklist p = (*L)->next;
	if (p == NULL)
		printf("这是一个空链表!\n");
	else
		printf("单链表：");
	while (p)
	{
		printf("->%d", p->data);
		p = p->next;
	}
	printf("\n");
}
