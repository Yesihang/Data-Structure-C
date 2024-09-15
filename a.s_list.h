#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct node
{
	elemtype data;
	struct node* next;
}node;
typedef struct node* linklist;

int InitList(linklist* L)       //初始化头节点
{
	(*L) = (linklist)malloc(sizeof(node));
	if (!L)
	{
		printf("内存分配失败！\n");
		exit(0);
	}
	(*L)->next = NULL;
	return 0;
}

void CreateListTail(linklist* L)       //尾插入法创建单链表，n为元素个数
{
	int i, n;
	linklist p, r;
	(*L)=(linklist)malloc(sizeof(node));
	r = (*L);
	printf("请输入要插入元素个数:");
	scanf_s("%d", &n);
	printf("请输入要插入的元素值（用空格隔开）：\n");
	for (i = 0; i < n; i++)
	{
		p = (linklist)malloc(sizeof(node));
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int LengthList(linklist* L)     //计算链表长度
{
	int n = 0;
	linklist p = (*L)->next;
	while (p!=NULL)
	{
		p = p->next;
		n += 1;
	}
	return n;
}

int GetElem(linklist* L, int n, elemtype* e)      //查找第n个元素并将元素值返回给e
{
	int i = 1;
	linklist p = (*L)->next;
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

int InsertList(linklist* L, int n, elemtype e)      //在第n个位置插入元素e
{
	int i = 1;
	linklist p = (*L);
	linklist j;
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
	j = (linklist)malloc(sizeof(node));
	j->data = e;
	j->next = p->next;
	p->next = j;

	return 0;
}

int DeleteList(linklist* L, int n, elemtype* e)				//删除L中第i个元素，并用e返回其值
{
	int i = 1;
	linklist p = (*L);
	linklist j;
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

int ClearList(linklist* L)					//单链表的整表删除
{
	linklist p, j;
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

void ShowList(linklist* L)					//打印整个链表
{
	linklist p = (*L)->next;
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
