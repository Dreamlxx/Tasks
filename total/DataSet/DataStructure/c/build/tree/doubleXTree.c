#include <stdio.h>
#include <stdlib.h> // 用于malloc函数
#define MAXSIZE 100
typedef char Element;
typedef char TreeType;

typedef struct TreeNode{
    Element data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

typedef TreeNode* BiTree;//指针

//栈声明
typedef struct
{   BiTree data[MAXSIZE]; // 指针数组存储栈中元素
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s)
{
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s)
{    
    return s->top == -1;//为空返回1，不为空返回0
}

// 进栈/压栈
int push(Stack *s, BiTree e)
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("满了，无法进栈\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

// 出栈/弹栈
int pop(Stack *s, BiTree *e)
{
    if (isEmpty(s))
    {
        printf("空了，无法出栈\n");
        return 0;
    }
   *e = s->data[s->top];
    s->top--;
    return 1;
}

int top(Stack *s, BiTree *e)
{
    if (isEmpty(s))
    {
        printf("空了，无法获取栈顶元素\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

typedef TreeNode *ElemType;//指针

//队列声明
typedef struct{
    ElemType *data2;
    int front;
    int rear;
} Queue;

//初始化队列
Queue *initQueue(){
    Queue *q=(Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    q->data2 = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    return q;
}

//判断队列是否为空
int isQueueEmpty(Queue *q){
    if(q->front == q->rear){
        printf("队列为空，无法出队\n");
        return 1;
    }
    return 0;
}

//入队操作
int enqueue(Queue *q,ElemType e){
    if((q->rear+1) % MAXSIZE == q->front)// 检查尾指针rear的下一个位置是不是头指针front，如果是，则认为队列已满，从而避免和“队列为空”的状态混淆
    { 
        printf("队列已满，无法入队\n");
        return 0;
    }
    q->data2[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;//可以形成逻辑上的环，重复利用队列数据
    return 1;
}

//出队操作
int dequeue(Queue *q, ElemType *e) {
    if (isQueueEmpty(q)) {
        return 0;
    }
    *e = q->data2[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return 1;
}//出队操作移除头元素，front指针后移，取余也能形成逻辑环

//获取队头元素
int getFront(Queue *q, ElemType *e) {
    if (isQueueEmpty(q)) {
        return 0;
    }
    *e = q->data2[q->front];
    return 1;
}

//获取队列元素个数
int queueSize(Queue *q){
    if(!isQueueEmpty(q)){
        return (q->rear - q->front + MAXSIZE) % MAXSIZE;//取模运算避免负数
    }
    else{
        return 0;
    }
}

//层序遍历代码+计算二叉树的最大深度
int maxDepth(TreeNode* root){
    if(root==NULL){
        return 0;
    }

    int depth=0;
    Queue* q=initQueue();
    enqueue(q,root);

    //双层循环，外层循环控制层数，内层循环遍历当前层所有节点
    while(q->front!=q->rear)
    {
        int count=queueSize(q);//当前层节点数
        while(count>0)//遍历当层所有节点
        {
            TreeNode *curr;
            dequeue(q, &curr);//指针传递
            printf("%c ", curr->data);
            if(curr->lchild!=NULL){
                enqueue(q,curr->lchild);
            }
            if(curr->rchild!=NULL){
                enqueue(q,curr->rchild);
            }
            count--;
        }
        depth++;
    }
    return depth;//返回最大深度
}//队列的“先进先出”完美做到不影响下一层入队，并且输入这一层

char str[]="ABDH#K###E##CFI###G#J##";//用#表示空节点

//先序递归创建二叉树
void creatTree(BiTree * T){
    static int index = 0;//不加静态出现翁恺错误
    Element ch= str[index++];
    if(ch=='#'){
        *T = NULL;//空节点
    }
    else{
        *T=(BiTree)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        creatTree(&(*T)->lchild);//创建左子树
        creatTree(&(*T)->rchild);//创建右子树
    }
}

//前序遍历
void PreOrder(BiTree T){
    if(T==NULL){
        return;
    }
    printf("%c ",T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

//中序遍历
void InOrder(BiTree T){
    if(T==NULL){
        return;
    }
    InOrder(T->lchild);
    printf("%c ",T->data);
    InOrder(T->rchild);
}

//后序遍历
void PostOrder(BiTree T){
    if(T==NULL){
        return;
    }
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    printf("%c ",T->data);
}

//非递归的前序遍历
void iterPreOrder(BiTree T){
    Stack s;
    initStack(&s);
    BiTree p=T;
    while (p!=0||isEmpty(&s)!=1)//树不为空或者栈不为空
    {
        if(p!=0){
            printf("%c", p->data);
            push(&s, p);
            p=p->lchild;//遍历左子树
        }
        else{
            pop(&s, &p);//弹出栈顶元素，回到栈顶元素，进而往右子树走
            p=p->rchild;
        }
    }
    printf("\n");
}//nb


//非递归的中序遍历
void imerPreOrder(BiTree T){
    Stack s;
    initStack(&s); 
    BiTree p=T;
    while (p!=0||isEmpty(&s)!=1)//树不为空或者栈不为空
    {
        if(p!=0){
            
            push(&s, p);
            p=p->lchild;//遍历左子树
        }
        else{
            pop(&s, &p);//弹出栈顶元素，回到栈顶元素，进而往右子树走
            printf("%c", p->data);
            p=p->rchild;
        }
    }
    printf("\n");
}//nb

//非递归后续遍历
void ilerPreOrder(BiTree T){
    Stack s;
    initStack(&s);
    BiTree p=T;
    while (p!=0||isEmpty(&s)!=1)//树不为空或者栈不为空
    {
        if(p!=0){
            
            push(&s, p);
            p=p->lchild;//遍历左子树
        }
        else{
            pop(&s, &p);//弹出栈顶元素，回到栈顶元素，进而往右子树走
            if(p->rchild==NULL){//右子树为空，直接访问节点
                printf("%c", p->data);
                p=NULL;//防止重复访问
            }
            else{
                BiTree temp=p->rchild;
                p->rchild=NULL;//防止重复访问
                push(&s, p);//将根节点重新入栈
                p=temp;//遍历右子树
            }
        }
    }
    printf("\n");
}//nb


int cnt = 0;

//判断是否为叶子节点
void isLeaf(BiTree T){
    if(T==NULL){
        return;
    }
    if(T->lchild==NULL&&T->rchild==NULL){
        printf("%c ",T->data);
        cnt++;
    }

    else{
    isLeaf(T->lchild);
    isLeaf(T->rchild);
    }
}

// 主函数
int main()
{
    BiTree root = NULL;

    // 创建二叉树
    creatTree(&root);
    // 递归遍历
    printf("递归前序遍历: ");
    PreOrder(root);
    printf("\n");

    printf("递归中序遍历: ");
    InOrder(root);
    printf("\n");

    printf("递归后序遍历: ");
    PostOrder(root);
    printf("\n");

    // 非递归前序遍历
    printf("非递归前序遍历: ");
    iterPreOrder(root);
    printf("非递归中序遍历: ");
    imerPreOrder(root);
    printf("非递归后序遍历: ");
    ilerPreOrder(root);

    // 叶子节点统计
    printf("叶子节点: ");
    isLeaf(root);
    printf("\n");
    printf("叶子节点个数: ");
    printf("%d", cnt);

    printf("\n");
    // 计算二叉树的最大深度
    printf("层序遍历: ");
    int depth = maxDepth(root);
    printf("\n");
    printf("二叉树的最大深度: %d\n", depth);

    return 0;
}
