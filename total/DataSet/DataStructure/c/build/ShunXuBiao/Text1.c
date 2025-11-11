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
     // 主函数1：基础功能测试
    // printf("=== 顺序表基础功能测试 ===\n");
    // SeqList* list = InitList();
    
    // // 尾部添加元素
    // AddElementLast(list, 10);
    // AddElementLast(list, 20);
    // AddElementLast(list, 30);
    // printf("尾部添加元素后: ");
    // PrintList(list);
    
    // // 任意位置插入元素
    // AddElement(list, 15, 1);
    // printf("在位置1插入15后: ");
    // PrintList(list);
    
    // AddElement(list, 5, 0);
    // printf("在位置0插入5后: ");
    // PrintList(list);
    
    // // 删除元素
    // DelElement(list, 2);
    // printf("删除位置2的元素后: ");
    // PrintList(list);
    
    // free(list->data);
    // free(list);

    // 主函数2：边界条件测试
    // printf("\n=== 边界条件测试 ===\n");
    // SeqList* list2 = InitList();
    
    // // 测试空表删除
    // printf("测试空表删除: ");
    // DelElement(list2, 0);
    
    // // 测试非法位置插入
    // printf("测试非法位置插入: ");
    // AddElement(list2, 100, -1);  // 位置为负
    // AddElement(list2, 100, 1);   // 位置超过长度
    
    // // 正常插入一些元素
    // AddElementLast(list2, 1);
    // AddElementLast(list2, 2);
    // printf("插入两个元素后: ");
    // PrintList(list2);
    
    // // 测试非法位置删除
    // printf("测试非法位置删除: ");
    // DelElement(list2, 5);  // 位置超过长度
    // DelElement(list2, -1); // 位置为负
    
    // free(list2->data);
    // free(list2);

    // 主函数3：容量测试
    // printf("\n=== 容量测试 ===\n");
    // SeqList* list3 = InitList();
    // 
    // // 填满顺序表
    // for(int i = 0; i < MAXSIZE; i++) {
    //     if(!AddElementLast(list3, i * 10)) {
    //         printf("插入第%d个元素失败\n", i);
    //         break;
    //     }
    // }
    // printf("填满后长度: %d\n", list3->length);
    // 
    // // 测试溢出
    // printf("测试溢出插入: ");
    // AddElementLast(list3, 9999);
    // 
    // free(list3->data);
    // free(list3);

    // 主函数4：综合操作测试
    // printf("\n=== 综合操作测试 ===\n");
    // SeqList* list4 = InitList();
    
    // // 批量添加元素
    // for(int i = 1; i <= 10; i++) {
    //     AddElementLast(list4, i);
    // }
    // printf("初始顺序表: ");
    // PrintList(list4);
    
    // // 在中间插入
    // AddElement(list4, 99, 5);
    // printf("在位置5插入99后: ");
    // PrintList(list4);
    
    // // 在开头插入
    // AddElement(list4, 0, 0);
    // printf("在位置0插入0后: ");
    // PrintList(list4);
    
    // // 连续删除
    // DelElement(list4, 3);
    // DelElement(list4, 6);
    // printf("删除位置3和6后: ");
    // PrintList(list4);
    
    // // 显示最终长度
    // printf("最终顺序表长度: %d\n", list4->length);
    
    // free(list4->data);
    // free(list4);

    // 主函数5：性能测试（大量操作）
    printf("\n=== 性能测试 ===\n");
    SeqList* list5 = InitList();
    
    // 大量插入操作
    for(int i = 0; i < 50; i++) {
        AddElementLast(list5, i);
    }
    printf("插入50个元素后长度: %d\n", list5->length);
    
    // 在多个位置插入
    for(int i = 0; i < 10; i++) {
        AddElement(list5, i * 100, i * 5);
    }
    printf("在多个位置插入后长度: %d\n", list5->length);
    
    // 批量删除
    for(int i = 0; i < 10; i++) {
        DelElement(list5, i * 2);
    }
    printf("批量删除后长度: %d\n", list5->length);
    
    free(list5);

    return 0;
}