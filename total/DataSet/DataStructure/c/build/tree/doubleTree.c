#include <stdio.h>
#include <stdlib.h> // 用于malloc函数
#define MAXSIZE 100
typedef char Element;


typedef struct TreeNode{
    Element data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

typedef TreeNode* BiTree;//指针

typedef struct
{
    BiTree data[MAXSIZE]; // 数组存储栈中元素
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
    return s->top == -1;
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





char str[]="ABDH#K###E##CFI###G#J##";//用#表示空节点


void creatTree(BiTree * T){
    static int index = 0;//不加静态出现翁恺错误
    Element ch= str[index++];
    if(ch=='#'){
        *T = NULL;//空节点,解引用指针
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
    while (p!=0||isEmpty(&s)!=1)
    {
        if(p!=0){
            printf("%c", p->data);
            push(&s, p);
            p=p->lchild;//遍历左子树
        }
        else{
            pop(&s, &p);//弹出栈顶元素，回到右子树，进而
            p=p->rchild;
        }
    }
    printf("\n");
}//nb

int cnt = 0;

void isLeaf(BiTree T){
    
    if(T==NULL){
        return;
    }
    if(T->lchild==NULL&&T->rchild==NULL){
        printf("%c ",T->data);
        cnt++;
    }
    isLeaf(T->lchild);
    isLeaf(T->rchild);
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

    // 叶子节点统计
    printf("叶子节点: ");
    isLeaf(root);
    printf("\n");
    printf("叶子节点个数: ");
    printf("%d", cnt);
    return 0;
}
