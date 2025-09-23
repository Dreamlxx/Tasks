#include <stdio.h>
#include <stdlib.h> // malloc
#define MAXSIZE 100
typedef int Element;

typedef struct
{
    Element *data; // 用新初始化顺序表，就得把data[MAXSIZE]改成指针
    int length;
} SeqList;

// 初始化顺序表
// void InitList(SeqList *l){
//     l->length=0;
// }
SeqList *InitList()
{
    SeqList *l = (SeqList *)malloc(sizeof(SeqList));
    l->data = (Element *)malloc(MAXSIZE * sizeof(Element));
    l->length = 0;
    return l;
} // 这样初始化，直接传参即可，若用旧版初始化，传参时要取地址

// 尾部添加元素
int AddElementLast(SeqList *l, Element e)
{
    if (l->length == MAXSIZE)
    {
        printf("线性表已满，无法插入\n");
        return 0;
    }
    l->data[l->length] = e;
    l->length++;
    return 1;
}

// 遍历数组
void PrintList(SeqList *l)
{
    for (int i = 0; i < l->length; i++)
    {
        printf("%d ", l->data[i]);
    }
    printf("\n");
}

// 任意位置插入元素
int AddElement(SeqList *l, Element e, int pos)
{
    if (l->length == MAXSIZE)
    {
        printf("线性表已满，无法插入\n");
        return 0;
    }
    if (pos < 0 || pos > l->length)
    {
        printf("插入位置非法\n");
        return 0;
    }
    for (int i = l->length; i > pos; i--)
    {
        l->data[i] = l->data[i - 1];
    }
    l->data[pos] = e;
    l->length++;
    return 1;
}

// 删除顺序表元素
int DelElement(SeqList *l, int pos)
{
    if (pos < 0 || pos >= l->length)
    {
        printf("删除位置错误");
        return 0;
    }
    for (int i = pos; i < l->length; i++)
    {
        l->data[i - 1] = l->data[i];
    }
    l->length--;
    return 0;
}

int main()
{
    SeqList *l = InitList();
    AddElementLast(l, 1);
    AddElementLast(l, 2);
    AddElementLast(l, 3);
    PrintList(l);
    AddElement(l, 4, 1);
    PrintList(l);
    DelElement(l, 2);
    PrintList(l);
    return 0;
}