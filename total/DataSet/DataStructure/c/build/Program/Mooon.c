#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef char VertexType;//点
typedef int EdgeType;//边
#define MAX INT_MAX
typedef char Small;

typedef struct
{
    VertexType *vertexes;//点表
    EdgeType **edges;//邻接矩阵
    int vertexNum, edgeNum;
} Map;
typedef struct{
    int *data;//记得申请空间
    int top;
} Node;

void initNode(Node *p)
{
    p->top = -1;
}

int push(Node *p,int x){
    if(p->top>=MAX-1){
        printf("FULL of Node\n");
        return 0;
    }
    p->top++;
    p->data[p->top] = x;
    return 1;
}

int pop(Node *p,int *e){
    if(p->top==-1){
        printf("FULL , pop error");
        return 0;
    }
    *e = p->data[p->top];
    p->top--;
    return 1;
}


void createMap(Map *p){
    int i, j;
    printf("请输入点的个数和边的个数:\n");
    scanf("%d %d", &p->vertexNum, &p->edgeNum);

    printf("请输入点的信息:\n");
    p->vertexes = (VertexType *)malloc(p->vertexNum * sizeof(VertexType));

    //一个一个输入点
    for(i = 0; i < p->vertexNum; i++){
        scanf(" %c", &p->vertexes[i]);
    }

    /* 
    p->edges = (EdgeType **)malloc(p->vertexNum * sizeof(EdgeType *));
    for(i = 0; i < p->vertexNum; i++){
        p->edges[i] = (EdgeType *)malloc(p->vertexNum * sizeof(EdgeType));
    }
    */

    p->edges = (EdgeType **)malloc(p->vertexNum * sizeof(EdgeType *));
    p->edges[0] = (EdgeType *)malloc(p->vertexNum * p->vertexNum * sizeof(EdgeType));
    for(i = 1; i < p->vertexNum; i++){
        p->edges[i] = p->edges[0] + i * p->vertexNum;
    }//使用完全连续的内存，更省空间

    //初始化邻接矩阵
    for(i = 0; i < p->vertexNum; i++){
        for(j = 0; j < p->vertexNum; j++){
            p->edges[i][j] = MAX;
        }
    }


    //对角线为零
    for(i = 0; i < p->vertexNum; i++){
        p->edges[i][i] = 0;
    } 
    
    
    // 构建有向带权图
        printf("请输入边的信息(格式: 起点 终点 权重):\n");
    for(i = 0; i < p->edgeNum; i++){
        char start, end;
        int s;
        scanf(" %c %c %d", &start, &end, &s);
        int m, n;
        //查找顶点对应的下标
        for(m = 0; m < p->vertexNum; m++){
            if(p->vertexes[m] == start)
                break;
        }
        for(n = 0; n < p->vertexNum; n++){
            if(p->vertexes[n] == end)
                break;
        }
        p->edges[m][n] = s;
    }
}

// 基于栈的SPFA算法（Shortest Path Faster Algorithm）
void SPFAByNode(Map p, int start, int end,int **distance,char **path)
{
    int *dist = (int *)malloc(p.vertexNum * sizeof(int));//记录从起点到这个点的最短距离
    int *prev = (int *)malloc(p.vertexNum * sizeof(int));//记录每一个顶点的前驱
    int *inNode = (int *)calloc(p.vertexNum, sizeof(int));//防止重复过节点

    // 初始化
    for (int i = 0; i < p.vertexNum; i++)
    {
        dist[i] = MAX;//所有都是最大，起点到自己为零
        prev[i] = -1;//所有都初始化-1，表示没有前驱
    }
    dist[start] = 0;//起点到自己为零

    // 创建栈
    Node s;
    initNode(&s);
    s.data = (int *)malloc(p.vertexNum * sizeof(int));

    // 起点入栈
    push(&s, start);
    inNode[start] = 1;

    while (s.top != -1)
    {
        int u;
        pop(&s, &u);
        inNode[u] = 0;

        // 松弛操作
        for (int v = 0; v < p.vertexNum; v++)
        {
            if (p.edges[u][v] < MAX)
            {
                if (dist[u] + p.edges[u][v] < dist[v])
                {
                    dist[v] = dist[u] + p.edges[u][v];
                    prev[v] = u;

                    if (!inNode[v])
                    {
                        push(&s, v);
                        inNode[v] = 1;
                    }
                }
            }
        }
    }

    distance = dist[end];

    // 构建路径字符串
    if (dist[end] < MAX)
    {
        // 反向构建路径
        Node pathStack;
        initNode(&pathStack);
        pathStack.data = (int *)malloc(p.vertexNum * sizeof(int));

        int current = end;
        while (current != -1)
        {
            push(&pathStack, current);
            current = prev[current];
        }

        // 计算路径字符串长度
        int pathLength = 0;
        for (int i = 0; i <= pathStack.top; i++)
        {
            pathLength += 4; // 顶点字符+空格+箭头+空格，估算4
        }

        // 分配内存并构建路径字符串
        *path = (char *)malloc(pathLength * sizeof(char));
        int pos = 0;

        while (pathStack.top != -1)
        {
            int node;
            pop(&pathStack, &node);

            // 添加顶点
            (*path)[pos++] = p.vertexes[node];

            // 如果不是最后一个，添加箭头
            if (pathStack.top != -1)
            {
                (*path)[pos++] = ' ';
                (*path)[pos++] = '-';
                (*path)[pos++] = '>';
                (*path)[pos++] = ' ';
            }
        }
        (*path)[pos] = '\0'; // 字符串结束符

        free(pathStack.data);
    }
    else
    {
        *path = NULL; // 无法到达
    }

    // 释放内存
    free(s.data);
    free(dist);
    free(prev);
    free(inNode);
}



int main()
{
    
}