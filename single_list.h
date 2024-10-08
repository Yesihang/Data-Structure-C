#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct _s_node
{
	elemtype data;
	struct _s_node* next;
}s_node;
typedef s_node* s_linklist;

int InitList(s_linklist* L)                            //初始化头节点
{
	(*L) = (s_linklist)malloc(sizeof(s_node));
	if (!L)
	{
		printf("内存分配失败！\n");
		exit(0);
	}
	(*L)->next = NULL;
	return 0;
}

void CreateListHead(s_linklist* L)                     //头插入法插入元素，n为元素个数（注意要先创建头节点）
{
	int i, n;
	s_linklist p, r;
	r = NULL;
	printf("请输入要插入元素个数:");
	scanf_s("%d", &n);
	printf("请输入要插入的元素值（用空格隔开）：\n");
	for (i = 0; i < n; i++)
	{
		p = (s_linklist)malloc(sizeof(s_node));
		scanf_s("%d", &p->data);
		p->next = r;
		r = p;
	}
	(*L)->next = r;
}

void CreateListTail(s_linklist* L)                      //尾插入法插入元素，n为元素个数
{
	int i, n;
	s_linklist p, r;
	r = (*L);
	printf("请输入要插入元素个数:");
	scanf_s("%d", &n);
	printf("请输入要插入的元素值（用空格隔开）：\n");
	for (i = 0; i < n; i++)
	{
		p = (s_linklist)malloc(sizeof(s_node));
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int InsertList(s_linklist* L, int n, elemtype e)            //在第n个位置插入元素e
{
	int i = 1;
	s_linklist p = (*L);
	s_linklist j;
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
	j = (s_linklist)malloc(sizeof(s_node));
	j->data = e;
	j->next = p->next;
	p->next = j;
        return 0;
}

int LengthList(s_linklist* L)                                 //计算链表长度
{
	int n = 0;
	s_linklist p = (*L)->next;
	while (p!=NULL)
	{
		p = p->next;
		n += 1;
	}
	return n;
}

int GetElem(s_linklist* L, int n, elemtype* e)                 //查找第n个元素并将元素值赋给e
{
	int i = 1;
	s_linklist p = (*L)->next;
	while (p && i < n)
	{
		p = p->next;
		++i;
	}
	if (!p || i > n)
	{
		printf("查找失败！\n");
		return 0;
	}
	(*e) = p->data;
	return 0;
}

int LocateElem(s_linklist* L, elemtype e)      //查找元素n，并返回该元素的位置（未查到则返回0）
{
	int i = 1;
	s_linklist p = (*L)->next;
	while (p->next!= NULL && p->data != e)
	{
		p = p->next;
		++i;
	}
	if (p->data != e)
	{
		printf("无法找到该元素！");
		return 0;
	}
	printf("查找到该元素在第%d位",i);
	return i;
}

int DeleteList(s_linklist* L, int n, elemtype* e)       	//删除L中第i个元素，并用e返回其值
{
	int i = 1;
	s_linklist p = (*L);
	s_linklist j;
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
	j = p->next;
	p->next = j->next;
	*e = j->data;
	free(j);
	return 0;
}

int ClearList(s_linklist* L)					//删除整个链表
{
	s_linklist p, j;
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

void ShowList(s_linklist* L)					//打印整个链表
{
	s_linklist p = (*L)->next;
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
