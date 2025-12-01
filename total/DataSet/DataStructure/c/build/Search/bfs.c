#include<stdio.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100

typedef struct {
    VertexType vertex[MAXSIZE];//顶点表
    EdgeType arc[MAXSIZE][MAXSIZE];//邻接矩阵
    int vertexNum, arcNum;//图的当前顶点数和边数
} Mat_Grph;

int visited[MAXSIZE];//访问标志数组

//初始化访问标志数组
void initVisited(int n){
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
}


void createGraph(Mat_Grph *g){
    int i, j;
    printf("请输入顶点数和边数: ");
    scanf("%d %d", &g->vertexNum, &g->arcNum);

    printf("请输入各顶点信息: \n");
    for(i = 0; i < g->vertexNum; i++){
        scanf(" %c", &g->vertex[i]);
    }

    // 初始化邻接矩阵
    for(i = 0; i < g->vertexNum; i++){
        for(j = 0; j < g->vertexNum; j++){
            g->arc[i][j] = 0;
        }
    }

    printf("请输入各边的信息(格式: 起点 终点): \n");
    for(i = 0; i < g->arcNum; i++){
        char start, end;
        scanf(" %c %c", &start, &end);
        int m, n;
        // 查找顶点对应的下标
        for(m = 0; m < g->vertexNum; m++){
            if(g->vertex[m] == start) break;
        }
        for(n = 0; n < g->vertexNum; n++){
            if(g->vertex[n] == end) break;
        }
        g->arc[m][n] = 1; // 有向图
    }

    for (i = 0; i < g->vertexNum;i++){
        for (j = 0; j < g->vertexNum;j++){
            if(g->arc[i][j]==1){
                g->arc[j][i]=1; //无向图
            }
        }
    }
}


//虚假的队列实现，功能类似
int front = 0;
int rear = 0;
int queue[MAXSIZE];


//广度优先算法核心代码
void bfs(Mat_Grph g){
    int i = 0; //从第0个节点开始
    visited[i] = 1;
    printf("%c ", g.vertex[i]);
    queue[rear++] = i; // 入队列,先引用rear，再加1；++rear是先加1，再引用;队尾指针永远指向下一个可用位置

    while (front < rear) { //队列不为空
        int u = queue[front++]; //出队列
        for (int v = 0; v < g.vertexNum; v++) {
            if (g.arc[u][v] == 1 && !visited[v]) { //遍历u层，并且忽略掉已经访问过的节点，用v做到
                visited[v] = 1;
                printf("%c ", g.vertex[v]);
                queue[rear++] = v; //入队列
            }
        }
    }
}
