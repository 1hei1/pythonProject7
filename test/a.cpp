//图的基本运算算法
#include <stdio.h>
#include <malloc.h>
#include </home/heige/source/test/t.h>

//------------------------------------------------------------
//----邻接矩阵的基本运算算法----------------------------------
//------------------------------------------------------------
void CreateMat(MatGraph& g, int A[MAXV][MAXV], int n, int e) //创建图的邻接矩阵
{
int i, j;
g.n = n; g.e = e;
for (i = 0; i < g.n; i++)
for (j = 0; j < g.n; j++)
g.edges[i][j] = A[i][j];
}
void DispMat(MatGraph g)//输出邻接矩阵g
{
int i, j;
for (i = 0; i < g.n; i++)
{
for (j = 0; j < g.n; j++)
if (g.edges[i][j] != INF)
printf("%4d", g.edges[i][j]);
else
printf("%4s", "∞");
printf("\n");
}
}
//------------------------------------------------------------

//------------------------------------------------------------
//----邻接表的基本运算算法------------------------------------
//------------------------------------------------------------
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) //创建图的邻接表
{
int i, j;
ArcNode* p;
G = (AdjGraph*)malloc(sizeof(AdjGraph));
for (i = 0; i < n; i++)//给邻接表中所有头节点的指针域置初值
G->adjlist[i].firstarc = NULL;
for (i = 0; i < n; i++)//检查邻接矩阵中每个元素
for (j = n - 1; j >= 0; j--)
if (A[i][j] != 0 && A[i][j] != INF)//存在一条边
{
p = (ArcNode*)malloc(sizeof(ArcNode));//创建一个节点p
p->adjvex = j;
p->weight = A[i][j];
p->nextarc = G->adjlist[i].firstarc;//采用头插法插入节点p
G->adjlist[i].firstarc = p;
}
G->n = n; G->e = n;
}
void DispAdj(AdjGraph* G)//输出邻接表G
{
ArcNode* p;
for (int i = 0; i < G->n; i++)
{
p = G->adjlist[i].firstarc;
printf("%3d: ", i);
while (p != NULL)
{
printf("%3d[%d]→", p->adjvex, p->weight);
p = p->nextarc;
}
printf("∧\n");
}
}
void DestroyAdj(AdjGraph*& G)//销毁图的邻接表
{
ArcNode* pre, * p;
for (int i = 0; i < G->n; i++)//扫描所有的单链表
{
pre = G->adjlist[i].firstarc;//p指向第i个单链表的首节点
if (pre != NULL)
{
p = pre->nextarc;
while (p != NULL)//释放第i个单链表的所有边节点
{
free(pre);
pre = p; p = p->nextarc;
}
free(pre);
}
}
free(G);//释放头节点数组
}
//------------------------------------------------------------