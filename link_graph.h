//邻接表---------------------------------------------------
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NUM 40
typedef int elemtype;
typedef struct edgenode  //临边结点
{
	int sign;
	struct edgenode* next;
}edgenode;
typedef struct vertexnode  //顶点节点
{
	elemtype date;
	edgenode* firstedge;
}vertexnode;
typedef struct ALgraph 
{
	vertexnode vertexlist[NUM];
	int numnode, numedge;
}ALgraph;

void CreateLGraph(ALgraph* G)           //创建邻接表（无权无向）
{
	int i,a,b;
	edgenode* p;
	printf("请输入顶点数和边数：\n");
	scanf_s("%d %d", &G->numnode, &G->numedge);
	printf("请依次输入顶点数据：\n");
	for (i = 0; i < G->numnode; i++)
	{
		scanf_s("%d", &G->vertexlist[i].date);
		G->vertexlist[i].firstedge = NULL;
	}
	printf("请输入(v,v')的依附顶点下标：\n");
	for (i = 0; i < G->numedge; i++)
	{
		scanf_s("%d %d", &a, &b);
		p = (edgenode*)malloc(sizeof(edgenode));
		p->sign = a;
		p->next = G->vertexlist[b].firstedge;//头插法
		G->vertexlist[b].firstedge = p;
		p = (edgenode*)malloc(sizeof(edgenode));
		p->sign = b;
		p->next = G->vertexlist[a].firstedge;
		G->vertexlist[a].firstedge = p;
	}
}

bool visited[NUM];//标志是否访问
void DFS(ALgraph* G, int i)      //邻接表深度优先遍历算法
{
	visited[i] = true;
	printf("->%d", G->vertexlist[i].date);
	edgenode* p = G->vertexlist[i].firstedge;
	while (p)
	{
		if (!visited[p->sign])
			DFS(G, p->sign);
		p = p->next;
	}
}

void DFSTraverse(ALgraph* G)           //邻接表深度遍历
{
	int i;
	for (i = 0; i < G->numnode; i++)
		visited[i] = false;
	for (i = 0; i < G->numnode; i++)//连通图只执行一次
		if (!visited[i])
			DFS(G, i);
}





//辅助队列--------------------------------------------------------------
typedef int elemtype;
typedef struct {
	elemtype date[NUM];
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
int EnQueue(poin_queue Q, elemtype e)          //入队
{
	if ((Q->rear + 1) % NUM == Q->front)
	{
		printf("队列已满！");
		return 0;
	}
	Q->date[Q->rear] = e;
	Q->rear = (Q->rear + 1) % NUM;
	return 0;
}
int DeQueue(poin_queue Q, elemtype* e)         //出队，并将值赋给e
{
	if (Q->front == Q->rear)
	{
		printf("这是一个空队列！");
		return 0;
	}
	*e = Q->date[Q->front];
	Q->front = (Q->front + 1) % NUM;
	return 0;
}
int QueueEmpty(poin_queue Q)         //检查是否为空
{
	if (Q->front == Q->rear)
		return 1;
	else
		return 0;
}
//辅助队列---------------------------------------------------

void BFSTraverse(ALgraph* G)             //邻接表广度遍历算法
{
	int i;
	edgenode* p;
	cirQueue Q;
	for (i = 0; i < G->numnode; i++)
		visited[i] = false;
	InitQueue(&Q);
	for (i = 0; i < G->numnode; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			printf("->%d", G->vertexlist[i].date);
			EnQueue(&Q, i);
			while (QueueEmpty(&Q) == 0)
			{
				DeQueue(&Q, &i);
				p = G->vertexlist->firstedge;
				while (p)
				{
					if (!visited[p->sign])
					{
						visited[p->sign] = true;
						printf("->%d", G->vertexlist[p->sign].date);
						EnQueue(&Q, p->sign);
					}
					p = p->next;
				}
			}
		}
	}
}
