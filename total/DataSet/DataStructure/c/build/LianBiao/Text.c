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
        free(p);
    } 
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


//判断循环链表是否有环且输出环的起始节点
void findStart(Node* l) {
    Node *slow = l;
    Node *fast = l;
    while(slow != fast||fast==NULL||fast->next==NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    int cnt = 1;
    Node* q = slow->next;
    while (q != slow){
        q = q->next;
        cnt++;
    }
    int s = 0;
    slow = l;
    fast = l;
    while(s<cnt){
        fast = fast->next;
        s++;
    }
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("环的起始节点为:%d\n",slow->data);
}

int main(){
    Node* list = initList();
    insertHead(list,2);
    insertHead(list,1);
    insertElementTail(list,3);
    insertEver(list,0,4);
    printList(list);
    findK_Point(list,2);
    reverseList(list);
    return 0;
}