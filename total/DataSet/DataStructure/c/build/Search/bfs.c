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

void initVisited(int n){
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
}//初始化访问标志数组


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