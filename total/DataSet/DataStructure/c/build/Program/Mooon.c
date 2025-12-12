#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef char VertexType;//点
typedef int EdgeType;//边
#define MAX INT_MAX

typedef struct
{
    VertexType *vertexes;
    EdgeType **edges;//邻接矩阵
    int vertexNum, edgeNum;
} Map;

void createMap(Map *p){
    int i, j;
    printf("请输入点的个数和边的个数:\n");
    scanf("%d %d", &p->vertexNum, &p->edgeNum);

    printf("请输入点的信息:\n");
    p->vertexes = (VertexType *)malloc(p->vertexNum * sizeof(VertexType));

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

    //构建有向带权图
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

int main(){
    
}