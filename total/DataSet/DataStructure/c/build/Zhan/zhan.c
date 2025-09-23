#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct {
    element data[MAXSIZE];//数组存储栈中元素
    int top;
} Stack;

//初始化栈
void initStack(Stack* s) {
    s->top = -1;
}

//判断栈是否为空
int isEmpty(Stack* s) {
    return s->top == -1;
}

//进栈/压栈
int push(Stack* s,element e){
    if(s->top >= MAXSIZE-1){
        printf("满了，无法进栈\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

//出栈/弹栈
int pop(Stack* s,element* e){
    if(isEmpty(s)){
        printf("空了，无法出栈\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

int top(Stack* s,element* e){
    if(isEmpty(s)){
        printf("空了，无法获取栈顶元素\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

int main(){
    Stack* s = (Stack*)malloc(sizeof(Stack));//这样创建栈，下面用函数是不需要取地址符号
    initStack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    element e;
    top(s,&e);
    printf("栈顶元素为:%d\n",e);
    while(!isEmpty(s)){
        pop(s,&e);
        printf("%d ",e);
    }
    free(s);
    return 0;
}