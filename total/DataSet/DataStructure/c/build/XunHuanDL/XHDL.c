#include <stdio.h>
#define elementType int

typedef struct QueueNode {
    elementType data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

//初始化
Queue* initQueue() {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    Queue* q = (Queue*)malloc(sizeof(Queue));
    node->next = NULL;
    node->data = 0;
    q->front = q->rear = node;
    return q;
}

//入队
void enqueue(Queue* q, elementType value) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = value;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

//出队
int dequeue(Queue* q, elementType* value) {
    if (q->front == q->rear) {
        return 0; //队列为空
    }
    QueueNode* temp = q->front->next;
    *value = temp->data;
    q->front->next = temp->next;
    if (q->rear == temp) {
        q->rear = q->front; //队列变空
    }
    free(temp);
    return 1; //成功出队
}