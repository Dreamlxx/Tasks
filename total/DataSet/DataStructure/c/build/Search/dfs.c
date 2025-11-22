#include<stdio.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100

typedef struct {
    VertexType vertex[MAXSIZE];//顶点表
    EdgeType arc[MAXSIZE][MAXSIZE];//邻接矩阵
    int vertexNum, arcNum;//图的当前顶点数和边数
} Mat_Grph;//邻接矩阵表示的图

int visited[MAXSIZE];//访问标志数组

void initVisited(int n)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
} // 初始化访问标志数组



//深度优先算法核心代码
void dfs(Mat_Grph g,int i){
    visited[i] = 1;
    printf("%c",g.vertex[i]);
    for(int j = 0; j < g.vertexNum; j++){
        if(g.arc[i][j] == 1 && !visited[j]){//遍历i层，并且忽略掉已经访问过的节点，用j做到
            dfs(g, j);
        }
    }
}

