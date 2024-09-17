#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;

typedef struct Q_node{
	elemtype data;
	struct Q_node* next;
}q_node;

typedef q_node* poin_queue;

typedef struct {
	poin_queue front;
	poin_queue rear;
}linkQueue;

int InitQueue(linkQueue* Q)             //初始化
{
	Q->front = (poin_queue)malloc(sizeof(q_node));
	if (!Q)
	{
		printf("内存分配失败！\n");
		exit(0);
	}
	(Q->front)->next = NULL;
	Q->rear = Q->front;
	return 0;
}


int EnQueue(linkQueue* Q, elemtype e)              //入队
{
	poin_queue s;
	s = (poin_queue)malloc(sizeof(q_node));
	s->next = NULL;
	s->data = e;
	(Q->rear)->next = s;
	Q->rear = s;
	return 0;
}

int DeQueue(linkQueue* Q, elemtype *e)            //出队，并将值赋给e
{
	if (Q->front == Q->rear)
	{
		printf("这是一个空队列！");
		return 0;
	}
	poin_queue s;
	s= Q->front->next;
	*e = s->data;
	Q->front->next = s->next;
	free(s);
	if (Q->front->next == NULL)
		Q->rear = Q->front;
	return 0;
}

int ShowQueue(linkQueue *Q)           	//打印整个链表
{
	poin_queue s;
	s = Q->front->next;
	if (s==NULL)
	{
		printf("这是一个空队列！\n");
		return 0;
	}
	printf("队列：");
	while (s != NULL)
	{
		printf("->%d", s->data);
		s = s->next;
	}
	printf("\n");
	return 0;
}

int LengthQueue(linkQueue* Q)            //计算队列的长度，并返回其值
{
	int i=0;
	poin_queue s = Q->front->next;
	while (s != NULL)
	{
		s = s->next;
		++i;
	}
	return i;
}


int ClearQueue(linkQueue* Q)          //清空队列
{
	if (Q->front == Q->rear)
	{
		printf("这是一个空队列！");
		return 0;
	}
	poin_queue s, j;
	s = Q->front->next;
	while (s != NULL)
	{
		j = s->next;
		free(s);
		s = j;
	}
	Q->front->next = s;
	Q->rear = Q->front;
	return 0;
}
