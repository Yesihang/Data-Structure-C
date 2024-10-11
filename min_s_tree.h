include "mat_group.h"

//-----------------------------最小生成树（普里姆算法）---------------------------------------

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



//------------------------------最小生成树（克鲁斯卡尔算法）--------------------------

typedef struct {
	int begin;
	int end;
	int weight;
}edge;

int find(int parent[], int i) //查询连线顶点尾部下标
{
	while (parent[i] > 0)
		i = parent[i];
	return i;
}

void MiniSpanTree_Kruskal(AMgraph G) //
{
	int i, j, k;
	edge temp;
	edge edges[NUM * NUM];
	int parent[NUM];

	k = 0;
	for(i=0;i<G.numnode;i++) //将邻接矩阵转换为边集数组
		for(j=0;j<G.numnode;j++)
			if (G.arc[i][j] != INFINITY && G.arc[i][j] != 0)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G.arc[i][j];
				k++;
			}

	for (i = 0; i < G.numedge- 1; i++) //边集数组排序（min->max）
	{
		for (j = i + 1; j < G.numedge; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				temp = edges[i];
				edges[i] = edges[j];
				edges[j] = temp;
			}
		}
	}

	for (i = 0; i < G.numnode; i++)
		parent[i] = 0;
	for (i = 0; i < G.numedge; i++)
	{
		j = find(parent, edges[i].begin);
		k = find(parent, edges[i].end);
		if (j != k)
		{
			parent[j] = k;
			printf("(%d,%d) %d", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}
