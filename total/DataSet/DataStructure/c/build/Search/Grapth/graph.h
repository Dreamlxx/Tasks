// graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100

typedef struct
{
    VertexType vertex[MAXSIZE];     // 顶点表
    EdgeType arc[MAXSIZE][MAXSIZE]; // 邻接矩阵
    int vertexNum, arcNum;          // 图的当前顶点数和边数
} Mat_Grph;

// 全局变量声明
extern int visited[MAXSIZE]; // 访问标志数组
extern int front;            // 队列头指针
extern int rear;             // 队列尾指针
extern int queue[MAXSIZE];   // 队列数组

// 函数声明
void initVisited(int n);
void createGraph(Mat_Grph *g);
void bfs(Mat_Grph g);        // BFS函数声明
void dfs(Mat_Grph g, int i); // DFS函数声明

#endif