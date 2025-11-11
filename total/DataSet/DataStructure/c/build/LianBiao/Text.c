#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct node{//这里的node不能少
    element data;
    struct node *next;//带struct
}Node;

//初始化链表
Node* initList() {
    Node* head =(Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法插入数据
int insertHead(Node* l,element e) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = l->next;
    l->next = p;
    return 1;
}

//打印链表
void printList(Node* l){
    for (Node *p = l->next ;p!=NULL;p=p->next) {
        printf("%d \n",p->data);
    }
}

//尾插法插入数据
void insertElementTail(Node *l, element e) {
    Node *p = (Node *)malloc(sizeof(Node));
    Node *q = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    q = l;
    for (;q->next!=NULL;q=q->next){
        continue;
    }
    q->next = p;
}

//清除链表中绝对值相同的元素,至多n个元素，相同数值只保留一个
void clearSame(Node* l,int n){
    Node *q = l;
    int k = 0;
    int *p = (int *)malloc((n + 1) * sizeof(int));//申请数组
    //初始化数组
    for (;k<n+1;k++){
        *(p + k) = 0;
    }
    //遍历链表
    while (q->next != NULL)
    {
        k=abs(q->next->data); 
        if(*(p + k) == 0){
            *(p + k) = 1;
            q = q->next;
        }
        else{
            Node *temp = q->next;
            q->next = temp->next;
            free(temp);
        }
    } 
    free(p);
}

//任意位置插入节点
int insertEver(Node* l,element e,int pos){
    int k=0;
    Node* p = (Node*)malloc(sizeof(Node));
    p = l;
    while (p!=NULL) {
        p = p->next;
        k++;
    }
    if(pos<0 || pos>k) {
        exit(printf("插入位置不合法\n"));
        return 0;
    }
    else{
        int y = 0;
        Node *s = (Node*)malloc(sizeof(Node));
        p = l;
        s->data = e;
        for (;y<pos-1;y++){//指向插入位置前一个位置
            p = p->next;
        }
        s->next = p->next;
        p->next = s;
        return 1;
    }
}

//定位到倒数第k个节点
int findK_Point(Node *l,int k){
    Node *p=(Node*)malloc(sizeof(Node));
    Node *q=(Node*)malloc(sizeof(Node));
    int n = 0;
    //q和p指向同一节点即可
    p=l->next;
    q=l->next;
    for ( n = 0; n < k; n++)
    {
        if (q == NULL) return 1;
        q = q->next;
    }
    //提前走k步
    while (q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    printf("倒数第%d个节点的值为:%d\n",k,p->data);
    return 0;
}

//反转链表
void reverseList(Node* l){
    Node *first = NULL;
    Node *second=l->next;
    Node *third=NULL;
    while (second != NULL){
        third = second->next;
        second->next = first;
        //指针后移
        first = second;
        second = third;
    }
    Node *p = initList();
    p->next = first;
    printList(p);
} 

//删除中间节点
void deleteMiddleNode(Node* l) {
    Node *p = (Node*)malloc(sizeof(Node));
    Node *q = (Node*)malloc(sizeof(Node));
    p = l;
    q = l;
    if (l->next == NULL || l->next->next == NULL) {
        printf("链表节点数小于3,无法删除中间节点\n");
        return;
    }
    while (q->next != NULL && q->next->next != NULL) {
        p = p->next;
        q = q->next->next;
    }
    Node *temp = p->next;
    p->next = temp->next;
    free(temp);
}


//判断循环链表是否有环且输出环的起始节点,弗洛伊德判圈算法
void findStart(Node* l) {
    if (l == NULL || l->next == NULL) {
        printf("链表为空或只有一个头节点,无环\n");
        return;
    }
    
    Node *slow = l->next;  // 慢指针从第一个实际节点开始
    Node *fast = l->next;  // 快指针从第一个实际节点开始
    
    // 第一步：检测是否有环
    int hasCycle = 0;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {  // 快慢指针相遇，说明有环
            hasCycle = 1;
            break;
        }
    }
    
    if(!hasCycle) {
        printf("链表无环\n");
        return;
    }
    
    // 第二步：找到环的起始节点
    slow = l->next;  // 慢指针回到起点
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    printf("环的起始节点为:%d\n", slow->data);
}

//合并链表
int togetherList(Node *l,Node *p,int n){
    Node *q = l;
    Node *r = p;
    if(q->next == NULL||r->next == NULL){
        printf("链表为空，无法合并\n");
        return 0;
    }
    for(int cnt=0;cnt<n;cnt++){
        q = q->next;
            if(q->next == NULL||r->next == NULL){
                printf("链表节点数不足n个,无法合并\n");
                return 0;
        }
    }
    Node *temp =p;
        while(temp->next!=NULL){
            temp = temp->next;
        }
    temp->next = q->next;
    q->next = r->next;
    return 1;
}

int main(){
    //主函数1：基础功能测试
    // printf("=== 基础功能测试 ===\n");
    // Node* list = initList();
    // insertHead(list, 1);
    // insertHead(list, 2);
    // insertHead(list, 3);
    // insertElementTail(list, 4);
    // insertElementTail(list, 5);
    // printf("原始链表:\n");
    // printList(list);
    
    // insertEver(list, 99, 2);
    // printf("在位置2插入99后:\n");
    // printList(list);
    
    // findK_Point(list, 2);
    // free(list);

    // 主函数2：清除重复元素测试
    // printf("\n=== 清除重复元素测试 ===\n");
    // Node* list2 = initList();
    // insertElementTail(list2, 1);
    // insertElementTail(list2, -1);
    // insertElementTail(list2, 2);
    // insertElementTail(list2, -2);
    // insertElementTail(list2, 3);
    // insertElementTail(list2, 1);
    // printf("清除前链表:\n");
    // printList(list2);
    
    // clearSame(list2, 10);
    // printf("清除重复后链表:\n");
    // printList(list2);
    // free(list2);

    // 主函数3：反转链表测试
    // printf("\n=== 反转链表测试 ===\n");
    // Node* list3 = initList();
    // for(int i = 1; i <= 5; i++) {
    //     insertElementTail(list3, i);
    // }
    // printf("原始链表:\n");
    // printList(list3);
    
    // printf("反转后链表:\n");
    // reverseList(list3);
    // free(list3);

    // 主函数4：删除中间节点测试
    // printf("\n=== 删除中间节点测试 ===\n");
    // Node* list4 = initList();
    // for(int i = 1; i <= 5; i++) {
    //     insertElementTail(list4, i);
    // }
    // printf("删除前链表:\n");
    // printList(list4);
    
    // deleteMiddleNode(list4);
    // printf("删除中间节点后链表:\n");
    // printList(list4);
    // free(list4);

    // 主函数5：循环链表测试（弗洛伊德判圈算法）
//     printf("\n=== 循环链表测试 ===\n");
//     Node* list5 = initList();

// // 创建带环的链表：1->2->3->4->5->3（形成环）
//     Node* node1 = (Node*)malloc(sizeof(Node));
//     Node* node2 = (Node*)malloc(sizeof(Node));
//     Node* node3 = (Node*)malloc(sizeof(Node));
//     Node* node4 = (Node*)malloc(sizeof(Node));
//     Node* node5 = (Node*)malloc(sizeof(Node));

//     node1->data = 1;
//     node2->data = 2;
//     node3->data = 3;
//     node4->data = 4;
//     node5->data = 5;

//     list5->next = node1;
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = node4;
//     node4->next = node5;
//     node5->next = node3;  // 形成环，指向node3

//     printf("已创建带环链表: 1->2->3->4->5->3(环)\n");

// // 使用修正后的弗洛伊德算法检测环的起始节点
//     findStart(list5);

// // 注意：由于有环，需要小心释放内存
// // 先打破环再释放
//     node5->next = NULL;
//     free(node1);
//     free(node2);
//     free(node3);
//     free(node4);
//     free(node5);
//     free(list5);

    // 主函数6：合并链表测试
    printf("\n=== 合并链表测试 ===\n");
    Node* list6a = initList();
    Node* list6b = initList();
    
    for(int i = 1; i <= 5; i++) {
        insertElementTail(list6a, i);
    }
    for(int i = 6; i <= 10; i++) {
        insertElementTail(list6b, i);
    }
    
    printf("链表A:\n");
    printList(list6a);
    printf("链表B:\n");
    printList(list6b);
    
    togetherList(list6a, list6b, 2);
    printf("合并后链表A:\n");
    printList(list6a);
    
    free(list6a);
    free(list6b);

    return 0;
}