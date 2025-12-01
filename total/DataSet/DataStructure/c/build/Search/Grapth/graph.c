// graph.c
#include "graph.h"

// 全局变量定义
int visited[MAXSIZE];
int front = 0;
int rear = 0;
int queue[MAXSIZE];

// 初始化访问标志数组
void initVisited(int n)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
}

void createGraph(Mat_Grph *g)
{
    int i, j;
    printf("Please enter vertex's and edge's count: \n ");
    scanf("%d %d", &g->vertexNum, &g->arcNum);

    printf("Please enter vertex information: \n");
    for (i = 0; i < g->vertexNum; i++)
    {
        scanf(" %c", &g->vertex[i]);
    }

    // 初始化邻接矩阵
    for (i = 0; i < g->vertexNum; i++)
    {
        for (j = 0; j < g->vertexNum; j++)
        {
            g->arc[i][j] = 0;
        }
    }

    printf("Please enter edge information (format: start end): \n");
    
    //构建有向图
    for (i = 0; i < g->arcNum; i++)
    {
        char start, end;
        scanf(" %c %c", &start, &end);
        int m, n;
        // 查找顶点对应的下标
        for (m = 0; m < g->vertexNum; m++)
        {
            if (g->vertex[m] == start)
                break;
        }
        for (n = 0; n < g->vertexNum; n++)
        {
            if (g->vertex[n] == end)
                break;
        }
        g->arc[m][n] = 1;
    }

    // 转换为无向图
    for (i = 0; i < g->vertexNum; i++)
    {
        for (j = 0; j < g->vertexNum; j++)
        {
            if (g->arc[i][j] == 1)
            {
                g->arc[j][i] = 1;
            }
        }
    }
}

// 广度优先算法（层序遍历）
void bfs(Mat_Grph g)
{
    // 重置队列指针
    front = 0;
    rear = 0;

    int i = 0; // 从第0个节点开始
    visited[i] = 1;
    printf("%c ", g.vertex[i]);
    queue[rear++] = i;//初始化队列，以进入下列的循环

    while (front < rear){//队列不为空
        int u = queue[front++]; // 出队列，初次本质是记录上方i的值
        for (int v = 0; v < g.vertexNum; v++)
        {
            if (g.arc[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                printf("%c ", g.vertex[v]);
                queue[rear++] = v; // 入队列
            }
        }
    }
}

// 深度优先算法（前序遍历）
void dfs(Mat_Grph g, int i)
{
    visited[i] = 1;
    printf("%c ", g.vertex[i]);
    for (int j = 0; j < g.vertexNum; j++)
    {
        if (g.arc[i][j] == 1 && visited[j] == 0)
        {
            dfs(g, j);
        }
    }
}