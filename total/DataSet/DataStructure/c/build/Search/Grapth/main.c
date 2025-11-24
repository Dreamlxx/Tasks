// main.c
#include "graph.h"
#include <stdio.h>

int main()
{
    Mat_Grph g;

    // 创建图
    createGraph(&g);

    // 测试DFS
    printf("DFS's result: ");
    initVisited(g.vertexNum);
    dfs(g, 0);
    printf("\n");

    // 测试BFS
    printf("BFS's result: ");
    initVisited(g.vertexNum); // 重新初始化访问数组
    bfs(g);
    printf("\n");

    return 0;
}