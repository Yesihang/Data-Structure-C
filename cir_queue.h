#pragma once
#include<stdio.h>
#define MAX 40

typedef int elemtype;
typedef struct {
	elemtype date[MAX];
	int front;
	int rear;
}cirQueue;
typedef cirQueue* poin_queue;

int InitQueue(poin_queue Q)           //初始化
{
	Q->front = 0;
	Q->rear = 0;
	return 0;
}

int CreateQueue(poin_queue Q)          //多元素入队
{
	if ((Q->rear + 1) % MAX == Q->front)
	{
		printf("队列已满！");
		return 0;
	}
	int i;
	printf("请输入插入元素个数：");
	scanf_s("%d", &i);
	while (i > MAX - (Q->rear - Q->front + MAX) % MAX - 1)
	{
		printf("插入元素过多，请重新输入个数：");
		scanf_s("%d", &i);
	}
	puts("请输入要插入的元素(用空格隔开):");
	for (int n = 0; n < i; n++)
	{
		scanf_s("%d", &(Q->date[Q->rear]));
		Q->rear = (Q->rear + 1) % MAX;
	}
	return 0;
}

int EnQueue(poin_queue Q, elemtype e)          //入队
{
	if ((Q->rear + 1) % MAX == Q->front)
	{
		printf("队列已满！");
		return 0;
	}
	Q->date[Q->rear] = e;
	Q->rear =(Q->rear + 1)%MAX;
	return 0;
}

int DeQueue(poin_queue Q, elemtype* e)         //出队，并将值赋给e
{
	if (Q->front == Q->rear)
	{
		printf("这是一个空队列！");
		return 0;
	}
	*e= Q->date[Q->front];
	Q->front = (Q->front + 1) % MAX;
	return 0;
}

int LengthQueue(poin_queue Q)       //计算队列的长度，并返回其值
{
	return (Q->rear - Q->front + MAX) % MAX;
}

int ShowQueue(poin_queue Q)     //打印队列
{
	if (Q->front == Q->rear)
	{
		printf("这是一个空队列！");
		return 0;
	}
	int i=0;
	while (((Q->front + i)%MAX) != Q->rear)
	{
		printf("->%d", Q->date[Q->front+i]);
		++i;
	}
}

int ClearQueue(poin_queue Q)          //清空队列
{
	if (Q->front == Q->rear)
	{
		printf("这是一个空队列！");
		return 0;
	}
	Q->front = 0;
	Q->rear = 0;
	return 0;
}
