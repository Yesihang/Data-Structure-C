//------------------------------邻接矩阵的实现----------------------------------------------
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>//提供bool


#define NUM 20
#define INFINITY 65535

typedef int elemtype;
typedef int weight; //权
typedef struct {
	elemtype vertex[NUM];
	int arc[NUM][NUM];
	int numnode, numedge; //顶点数，边数
}AMgraph;

void CreateMGraph(AMgraph* G)             //创建邻接矩阵（无权无向）
{
	int i,n, m;
	elemtype date;
	printf("请输入顶点数和边数：\n");
	scanf_s("%d %d", &G->numnode, &G->numedge);
	printf("请依次输入顶点数据：\n");
	for (i= 0; i < G->numnode; i++)
		scanf_s("%d", &G->vertex[i]);
	
	for ( i = 0;i< NUM; i++)
		for (n = 0; n < NUM;n++)
			G->arc[i][n] = 0;
	printf("请输入(v,v')的依附顶点下标：\n");
	for (i= 0; i < G->numedge;i++)
	{
		printf("->");
		scanf_s("%d  %d", &n, &m);
		G->arc[n][m] = 1;
		G->arc[m][n] = 1;
	}
}

void CreateMGraph_W(AMgraph* G)             //创建邻接矩阵（有权无向）
{
	int i,n, m, w;
	elemtype date;
	printf("请输入顶点数和边数：\n");
	scanf_s("%d %d", &G->numnode, &G->numedge);
	printf("请依次输入顶点数据：\n");
	for (i = 0; i < G->numnode; i++)
		scanf_s("%d", &G->vertex[i]);
	
	for (i = 0; i < G->numnode; i++)
		for ( n = 0; n< G->numnode; n++)
		{
			G->arc[i][n] = INFINITY;
			if (i== n)
				G->arc[i][n] = 0;
		}
	printf("请输入(v,v')的依附顶点下标和权值：\n");
	for (i = 0; i < G->numedge; i++)
	{
		printf("->");
		scanf_s("%d %d %d", &n, &m, &w);
		G->arc[n][m] = w;
		G->arc[m][n] = G->arc[n][m];
	}
}


//-------------------------------深度遍历算法-------------------------------------------
//无权值

bool visited[NUM];

void DFS(AMgraph* G,int i)           //深度优先递归算法
{
	visited[i] = 1;
	printf("->%d", G->vertex[i]);

	for (int j = 0; j < G->numnode; j++)
		if (G->arc[i][j] == 1 && !visited[j])
			DFS(G, j);
}

void DFSTraverse(AMgraph* G)           //邻接矩阵的深度遍历
{
	int i;
	for (i = 0; i < G->numnode; i++)
		visited[i] = 0;
	for (i = 0; i < G->numnode; i++)
		if (!visited[i])
			DFS(G, i);
}


//--------------------------------广度遍历算法----------------------------------------------
//无权值

//辅助队列
typedef int elemtype;         
typedef struct {
	elemtype date[NUM];
	int front;
	int rear;
}cirQueue;
typedef cirQueue* poin_queue;
int InitQueue(poin_queue Q)   //初始化
{
	Q->front = 0;
	Q->rear = 0;
	return 0;
}
int EnQueue(poin_queue Q, elemtype e)   //入队
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
int DeQueue(poin_queue Q, elemtype* e)   //出队，并将值赋给e
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
int QueueEmpty(poin_queue Q)  //检查是否为空
{
	if (Q->front == Q->rear)
	    return 1;
	else
		return 0;
}

void BFSTraverse(AMgraph* G)            //邻接矩阵广度遍历算法
{
	cirQueue Q;
	int i, j;
	for (i = 0; i < G->numnode; i++)
		visited[i] = 0;
	InitQueue(&Q);
	for (i = 0; i < G->numnode; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			printf("->%d", G->vertex[i]);
			EnQueue(&Q, i);
			while (QueueEmpty(&Q) == 0)
			{
				DeQueue(&Q, &i);
				for (j = 0; j < G->numnode; j++)
					if (G->arc[i][j] == 1 && visited[j] == 0)
					{
						visited[j] = 1;
						printf("->%d", G->vertex[j]);
						EnQueue(&Q, j);
					}
			}
		}
	}

}


//-----------------------------最小生成树（普里姆算法）---------------------------------------
//有权值

void MiniSpanTree_Prim(AMgraph G)
{
	int min, a, b, c;
	int lowcost[NUM];
	int adjvex[NUM];
	lowcost[0] = 0;
	adjvex[0] = 0;

	for (a = 1; a < G.numnode; a++)
	{
		lowcost[a] = G.arc[0][a];
		adjvex[a] = 0;
	}
	for (a = 1; a < G.numnode; a++)
	{
		min = INFINITY;
		b = 1, c = 0;
		while( b< G.numnode)
		{
			if (lowcost[b] != 0 && lowcost[b] < min)
			{
				min = lowcost[b];
				c = b;
			}
			b++;
		}
		printf("(%d,%d)", adjvex[c], c);
		lowcost[c] = 0;
		for (b = 1; b < G.numnode; b++)
		{
			if (lowcost[b]!=0&&G.arc[c][b] < lowcost[b])
			{
				lowcost[b] = G.arc[c][b];
				adjvex[b] = c;
			}
		}
	}
}
