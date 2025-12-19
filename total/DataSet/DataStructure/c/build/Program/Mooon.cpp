#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <fstream> // 文件流
#include <string>
#include <cstring>

using namespace std;

typedef char VertexType;//点
typedef int EdgeType;//边
const int MAX = INT_MAX - 4; // 防止溢出
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

//栈相关函数
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

// ========== 图操作函数 ==========

// 辅助函数：从文件读取图数据
bool loadMapFromFile(Map *p, const string &filename)
{
    ifstream inFile(filename); // 创建一个 ifstream 类型的对象 inFile
    if (!inFile)
    {
        cerr << "错误：无法打开文件 " << filename << endl;
        return false;
    }

    inFile >> p->vertexNum >> p->edgeNum;

    p->vertexes = (VertexType *)malloc(p->vertexNum * sizeof(VertexType));

    for (int i = 0; i < p->vertexNum; i++)
    {
        inFile >> p->vertexes[i];//读取点数据
    }

    
    //申请邻接矩阵空间，并初始化
    p->edges = (EdgeType **)malloc(p->vertexNum * sizeof(EdgeType *));
    p->edges[0] = (EdgeType *)malloc(p->vertexNum * p->vertexNum * sizeof(EdgeType));

    for (int i = 1; i < p->vertexNum; i++)
    {
        p->edges[i] = p->edges[0] + i * p->vertexNum;
    }

    for (int i = 0; i < p->vertexNum; i++)
    {
        for (int j = 0; j < p->vertexNum; j++)
        {
            p->edges[i][j] = MAX;
        }
    }

    //对角线赋值成零
    for (int i = 0; i < p->vertexNum; i++)
    {
        p->edges[i][i] = 0;
    }
    
    //将能到达的点赋上权重
    for (int i = 0; i < p->edgeNum; i++)
    {
        char start, end;
        int weight;
        inFile >> start >> end >> weight;

        int startIdx = -1, endIdx = -1;
        for (int j = 0; j < p->vertexNum; j++)
        {
            if (p->vertexes[j] == start)
                startIdx = j;
            if (p->vertexes[j] == end)
                endIdx = j;
        }

        if (startIdx != -1 && endIdx != -1)
        {
            p->edges[startIdx][endIdx] = weight;
        }

        if(startIdx == -1){
            printf("起点不存在，请重新输入正确的起点：");
            char change;
            scanf("%c",&change);
            for(int t=0;t<p->vertexNum;t++){
                if(p->vertexes[t]==change){
                    startIdx = t;
                    break;
                }
                p->edges[startIdx][endIdx] = weight;
            }
        }
        if(endIdx == -1){
            printf("起点不存在，请重新输入正确的起点：");
            char change;
            scanf("%c",&change);
            for(int t=0;t<p->vertexNum;t++){
                if(p->vertexes[t]==change){
                    endIdx = t;
                    break;
                }
                p->edges[startIdx][endIdx] = weight;
            }
        }
    }

    inFile.close();
    cout << "成功从文件 " << filename << " 读取图数据" << endl;
    return true;
}

// 辅助函数：保存图数据到文件
bool saveMapToFile(Map *p, const string &filename)
{

    //创建文件
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "错误：无法创建文件 " << filename << endl;
        return false;
    }

    outFile << p->vertexNum << " " << p->edgeNum << endl;

    for (int i = 0; i < p->vertexNum; i++)
    {
        outFile << p->vertexes[i];
        if (i < p->vertexNum - 1)
            outFile << " ";
    }
    outFile << endl;

    int edgeCount = 0;
    for (int i = 0; i < p->vertexNum; i++)
    {
        for (int j = 0; j < p->vertexNum; j++)
        {
            if (i != j && p->edges[i][j] < MAX)
            {
                outFile << p->vertexes[i] << " " << p->vertexes[j] << " " << p->edges[i][j] << endl;
                edgeCount++;
            }
        }
    }

    outFile.close();
    cout << "成功保存图数据到文件 " << filename << "（写入 " << edgeCount << " 条边）" << endl;
    return true;
}

// 辅助函数：从标准输入读取图数据
void createMapFromInput(Map *p)
{
    cout << "请输入点的个数和边的个数:" << endl;
    cin >> p->vertexNum >> p->edgeNum;

    cout << "请输入点的信息（每个点一个字符，用空格或换行分隔）:" << endl;
    p->vertexes = (VertexType *)malloc(p->vertexNum * sizeof(VertexType));

    for (int i = 0; i < p->vertexNum; i++)
    {
        cin >> p->vertexes[i];
    }

    p->edges = (EdgeType **)malloc(p->vertexNum * sizeof(EdgeType *));
    p->edges[0] = (EdgeType *)malloc(p->vertexNum * p->vertexNum * sizeof(EdgeType));
    for (int i = 1; i < p->vertexNum; i++)
    {
        p->edges[i] = p->edges[0] + i * p->vertexNum;
    }

    for (int i = 0; i < p->vertexNum; i++)
    {
        for (int j = 0; j < p->vertexNum; j++)
        {
            p->edges[i][j] = MAX;
        }
    }

    for (int i = 0; i < p->vertexNum; i++)
    {
        p->edges[i][i] = 0;
    }

    cout << "请输入边的信息（格式：起点 终点 权重）:" << endl;
    for (int i = 0; i < p->edgeNum; i++)
    {
        char start, end;
        int weight;
        cin >> start >> end >> weight;

        int startIdx = -1, endIdx = -1;
        for (int j = 0; j < p->vertexNum; j++)
        {
            if (p->vertexes[j] == start)
                startIdx = j;
            if (p->vertexes[j] == end)
                endIdx = j;
        }

        if (startIdx != -1 && endIdx != -1)
        {
            p->edges[startIdx][endIdx] = weight;
        }
        else
        {
            cout << "警告：边 " << start << "->" << end << " 的顶点不存在，已跳过" << endl;
        }
    }

    cout << "成功从标准输入创建图" << endl;
}

// 主函数：保持原函数名不变
void createMap(Map *p)
{
    int choice;

    cout << "\n=== 交通图数据管理 ===" << endl;
    cout << "1. 从标准输入创建新图" << endl;
    cout << "2. 从文件读取图数据" << endl;
    cout << "请选择操作(1-2): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        createMapFromInput(p);
        break;

    case 2:
    {
        string filename;
        cout << "请输入要读取的文件名: ";
        cin >> filename;

        if (!loadMapFromFile(p, filename))
        {
            cout << "文件读取失败，请检查文件名是否正确" << endl;
        }
        break;
    }

    default:
        cout << "无效选择，将使用默认方式（从标准输入创建新图）" << endl;
        createMapFromInput(p);
        break;
    }
}

// 辅助函数：释放图内存
void freeMap(Map *p)
{
    if (p->vertexes != NULL)
    {
        free(p->vertexes);
        p->vertexes = NULL;
    }

    if (p->edges != NULL)
    {
        if (p->edges[0] != NULL)
        {
            free(p->edges[0]);
        }
        free(p->edges);
        p->edges = NULL;
    }

    p->vertexNum = 0;
    p->edgeNum = 0;
}

//==============算法函数============================

// 基于栈的SPFA算法（Shortest Path Faster Algorithm）
void SPFAByNode(Map *p, int start, int end)
{
    int *dist = (int *)malloc(p->vertexNum * sizeof(int));//记录从起点到这个点的最短距离
    int *prev = (int *)malloc(p->vertexNum * sizeof(int));//记录每一个顶点的前驱
    int *inNode = (int *)calloc(p->vertexNum, sizeof(int));//类似于visit，但是允许重复进栈

    // 初始化
    for (int i = 0; i < p->vertexNum; i++)
    {
        dist[i] = MAX;//所有都是最大，起点到自己为零
        prev[i] = -1;//所有都初始化-1，表示目前没有前驱
    }
    dist[start] = 0;//起点到自己为零

    // 创建栈
    Node s;
    initNode(&s);
    s.data = (int *)malloc(p->vertexNum * sizeof(int));

    // 起点入栈
    push(&s, start);
    inNode[start] = 1;

    while (s.top != -1)
    {
        int u;
        pop(&s, &u);
        inNode[u] = 0;

        // 从起点开始找小的
        for (int v = 0; v < p->vertexNum; v++)
        {
            if (p->edges[u][v] < MAX)
            {
                if (dist[u] + p->edges[u][v] < dist[v])
                {
                    dist[v] = dist[u] + p->edges[u][v];
                    prev[v] = u;

                    if (!inNode[v])//只要小且现在不在栈中就入栈
                    {
                        push(&s, v);
                        inNode[v] = 1;
                    }
                }
            }
        }
    }

    // 输出结果，若有路可走
    if (dist[end] < MAX)
    {
        printf("最短距离: %d\n", dist[end]);

        // 反向构建路径，因为是栈
        Node pathStack;
        initNode(&pathStack);
        pathStack.data = (int *)malloc(p->vertexNum * sizeof(int));

        int current = end;

        //从end到start一个一个入栈
        while (current != -1)
        {
            push(&pathStack, current);
            current = prev[current];//找到七点起点前驱是-1
        }

        // 打印路径，出栈
        printf("路径: ");
        while (pathStack.top != -1)
        {
            int node;//接
            pop(&pathStack, &node);
            printf("%c ", p->vertexes[node]);
        }
        printf("\n");

        free(pathStack.data);
    }
    
    else
    {
        printf("无法到达终点\n");
    }

    free(s.data);
    free(dist);
    free(prev);
    free(inNode);
}

//生生流转,弗洛伊德
void floyd(Map *p,int **dist,int **next)
{
    int i, j, k;
    int n = p->vertexNum;
    for (i = 0;i<n;i++)
    {
        for (j = 0;j<n;j++)
        {
            dist[i][j] = p->edges[i][j];
            
            if(p->edges[i][j]<MAX&&j!=i)
            {
                next[i][j] = j;
            }
            else
            {
                next[i][j] = -1;
            }
        }
    }

    for (k = 0; k < n;k++){
        for (i = 0;i<n;i++){
            for (j = 0; j < n;j++){
                if (dist[i][k] < MAX && dist[k][j] < MAX && dist[i][k] + dist[k][j]<dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printFloyd(Map p, int **next, int start,int end){
    if(next[start][end]>=MAX){
        printf("无法到达终点\n");
        return;
    }
    printf("Road is:%c", p.vertexes[start]);
    int now=start;
    while(now!=end)
    {
        now = next[now][end];
        printf(" → %c", p.vertexes[now]);
    }
}

//找到两点间最短路径，spfa的使用
void findShortestPath(Map *p)
{
    char start, end;
    int startIdx = -1, endIdx = -1;
    int i;

    printf("请输入起点和终点(例如: A B): ");
    scanf(" %c %c", &start, &end);

    // 查找顶点索引
    for (i = 0; i < p->vertexNum; i++)
    {
        if (p->vertexes[i] == start)
            startIdx = i;
        if (p->vertexes[i] == end)
            endIdx = i;
    }

    if (startIdx == -1 || endIdx == -1)
    {
        printf("起点或终点不存在！\n");
        return;
    }

    // 使用你的SPFAByNode函数查询最短路径
    SPFAByNode(p, startIdx, endIdx);
}

// 平均距离最小
void Smallest1(Map *p)
{
    int i, j;
    int n = p->vertexNum;

    // 分配内存
    int **dist = (int **)malloc(n * sizeof(int *));
    int **next = (int **)malloc(n * sizeof(int *));
    double *FinalCnt = (double *)malloc(n * sizeof(double));

    for (i = 0; i < n; i++)
    {
        dist[i] = (int *)malloc(n * sizeof(int));
        next[i] = (int *)malloc(n * sizeof(int));
        FinalCnt[i] = 1e9; // 计算每个点作为总部大家到它的距离的平均
    }

    // 计算所有点对最短路径
    floyd(p, dist, next);

    // 对每个站点作为总部进行计算
    for (i = 0; i < n; i++)
    {
        int total = 0;//计算一个路权重总和
        int Count = 0;//求平均数用

        // 计算所有其他站点（j）到i的距离
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (dist[j][i] < MAX)
                { // 可达
                    total += dist[j][i];
                    Count++;
                }
                else
                {
                    // 有一个站点不可达，这个i就不能作为总部
                    total = -1;
                    break;
                }
            }
        }

        // 如果所有站点都可达，计算平均距离
        if (Count == n - 1)
        {
            FinalCnt[i] = (double)total / Count;//强制转化
        }
    }

    // 找出最佳站点
    double minPoint = 1e9;//用来计算平均数
    int bestPoint = -1;

    for (i = 0; i < n; i++)
    {
        if (FinalCnt[i] < minPoint)
        {
            minPoint = FinalCnt[i];
            bestPoint = i;
        }
    }

    // 输出结果
    if (bestPoint != -1 && minPoint < 1e9)
    {
        printf("选择%c站点最合适, 平均路径长度为%.2f\n",
               p->vertexes[bestPoint], minPoint);
    }
    else
    {
        printf("没有合适的选址\n");
    }

    // 释放内存
    for (i = 0; i < n; i++)
    {
        free(dist[i]);
        free(next[i]);
    }
    free(dist);
    free(next);
    free(FinalCnt);
}

// 寻找使所有站点能到达总部的最短距离中的最长者最小的选址方案；
void Smallest2(Map *p)
{
    int i, j;
    int n = p->vertexNum;

    // 分配内存
    int **dist = (int **)malloc(n * sizeof(int *));
    int **next = (int **)malloc(n * sizeof(int *));
    int *x = (int *)malloc(n * sizeof(int)); //存储每个站点作为总部时的最远距离

    for (i = 0; i < n; i++)
    {
        dist[i] = (int *)malloc(n * sizeof(int));
        next[i] = (int *)malloc(n * sizeof(int));
        x[i] = MAX;
    }

    // 计算所有点对最短路径
    floyd(p, dist, next);

    // 对每个站点作为总部进行计算，对应到矩阵上都是一列一列找
    for (i = 0; i < n; i++)
    {
        int max = 0;          // 记录最远距离
        int could = 1; // 标记是否所有站点可达

        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (dist[j][i] >= MAX)// 不可达
                { 
                    could = 0;
                    break; // 跳出内层循环
                }
                if (dist[j][i] > max)
                {
                    max = dist[j][i];
                }
            }
        }

        if (could)
        {
            x[i] = max; // 所有站点可达，记录最远距离
        }
        // 否则保持x[i]=MAX，表示无效
    }

    // 找出最远距离最小的站点
    int min = MAX;
    int bestSite = -1;
    for (i = 0; i < n; i++)
    {
        if (x[i] < min)
        {
            min = x[i];
            bestSite = i;
        }
    }

    if (bestSite != -1 && min < MAX)
    {
        printf("合适的站点为%c,最远距离为%d\n", p->vertexes[bestSite], min);
    }
    else
        printf("无合适站点\n");

    // 释放内存
    for (i = 0; i < n; i++)
    {
        free(dist[i]);
        free(next[i]);
    }
    free(dist);
    free(next);
    free(x);
}

// ========== 菜单函数 ==========
void clearScreen()
{
    cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
    cout << endl;cout << endl;cout << endl;cout << endl;
}

void displayMainMenu()
{
    cout << "\n============ 主菜单 ============" << endl;
    cout << "1. 创建/加载交通图数据" << endl;
    cout << "2. 查询站点间最短路径" << endl;
    cout << "3. 选址功能" << endl;
    cout << "4. 保存图数据到文件" << endl;
    cout << "5. 清屏" << endl;
    cout << "6. 退出系统" << endl;
    cout << "=================================" << endl;
    cout << "请输入您的选择 (1-6): ";
}

void saveCurrentMap(Map *map)
{
    if (map->vertexes == NULL || map->edges == NULL)
    {
        cout << "当前没有加载任何图数据！请先选择选项1创建或加载图。" << endl;
        return;
    }

    string filename;
    cout << "\n请输入要保存的文件名（例如: map.txt）: ";
    cin >> filename;

    if (saveMapToFile(map, filename))
    {
        cout << "图数据已成功保存到文件: " << filename << endl;
    }
    else
    {
        cout << "保存失败，请检查文件名和路径！" << endl;
    }
}

void inputGraphData(Map *map)
{
    cout << "\n=== 创建/加载交通图数据 ===" << endl;
    cout << "注意：图要求至少有8个顶点，15条边" << endl;
    cout << "=============================" << endl;

    freeMap(map);
    createMap(map);

    if (map->vertexes != NULL && map->edges != NULL)
    {
        cout << "\n图数据加载/创建成功！" << endl;
        if (map->vertexNum < 8)
        {
            cout << "警告：当前图只有 " << map->vertexNum << " 个顶点，建议至少8个顶点！" << endl;
        }
        if (map->edgeNum < 15)
        {
            cout << "警告：当前图只有 " << map->edgeNum << " 条边，建议至少15条边！" << endl;
        }
    }
}

void queryShortestPath(Map *map)
{
    if (map->vertexes == NULL || map->edges == NULL)
    {
        cout << "当前没有加载任何图数据！请先选择选项1创建或加载图。" << endl;
        return;
    }

    cout << "\n=== 最短路径查询 ===" << endl;
    cout << "当前图中的顶点: ";
    for (int i = 0; i < map->vertexNum; i++)
    {
        cout << map->vertexes[i];
        if (i < map->vertexNum - 1)
            cout << ", ";
    }
    cout << endl;

    findShortestPath(map);
}

void locationSelectionMenu(Map *map)
{
    if (map->vertexes == NULL || map->edges == NULL)
    {
        cout << "当前没有加载任何图数据！请先选择选项1创建或加载图。" << endl;
        return;
    }

    int choice;
    cout << "\n=== 选址功能 ===" << endl;
    cout << "1. 寻找平均距离最小的选址方案" << endl;
    cout << "2. 寻找最短距离中最长者最小的选址方案" << endl;
    cout << "3. 返回主菜单" << endl;
    cout << "==================" << endl;
    cout << "请输入您的选择 (1-3): ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n正在计算平均距离最小的选址方案..." << endl;
        Smallest1(map);
        break;
    case 2:
        cout << "\n正在计算最短距离中最长者最小的选址方案..." << endl;
        Smallest2(map);
        break;
    case 3:
        cout << "返回主菜单..." << endl;
        break;
    default:
        cout << "无效的选择！" << endl;
        break;
    }
}

void handleUserChoice(Map *map)
{
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        inputGraphData(map);
        break;
    case 2:
        queryShortestPath(map);
        break;
    case 3:
        locationSelectionMenu(map);
        break;
    case 4:
        saveCurrentMap(map);
        break;
    case 5:
        clearScreen();
        break;
    case 6:
        cout << "感谢使用，再见！" << endl;
        exit(0);
        break;
    default:
        cout << "无效的选择，请重新输入！" << endl;
        break;
    }
}

// ========== 主函数 ==========
int main()
{
    //创建地图初始化
    Map myMap;
    myMap.vertexes = NULL;
    myMap.edges = NULL;
    myMap.vertexNum = 0;
    myMap.edgeNum = 0;

    int running = 1;

    cout << "=== 交通图管理与路径分析系统 ===" << endl;
    cout << "作者: 可爱之帅气之李响" << endl;
    cout << "=================================" << endl;

    while (running)
    {
        displayMainMenu();
        handleUserChoice(&myMap);

        if (running)
        {
            char continueChoice;
            cout << "\n是否返回主菜单? (y/n): ";

            cin >> continueChoice;
            if (continueChoice == 'y' || continueChoice == 'Y')
            {
                clearScreen();
                continue; // 继续循环，显示主菜单
            }
            else if (continueChoice == 'n' || continueChoice == 'N')
            {
                running = 0;
                cout << "感谢使用，再见！" << endl;
            }
            else
            {
                cout << "输入无效，默认返回主菜单" << endl;
                clearScreen();
            }
        }
    }

    freeMap(&myMap);
    return 0;
}