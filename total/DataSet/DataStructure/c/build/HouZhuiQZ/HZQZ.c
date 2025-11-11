//后缀表达式求值，使用栈实现
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int element;
typedef struct{
    element *data;
    int top;
}Stack;

typedef enum
{
    LEFT_PAIR,
    RIGHT_PAIR,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    EOS,
    NUM
} contentType;

char expr[] = "82/2+56*-";

//初始化
Stack *initStack(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (element *)malloc(MAXSIZE * sizeof(element));
    s->top = -1;
    return s;
}

//判断栈是否为空
int isEmpty(Stack *s){
    if(s->top == -1){
        return 1;
    }
    else return 0;
}


//入栈
void push(Stack *s, element e){
    if(s->top == MAXSIZE - 1){
        printf("Stack is full\n");
        return;
    }
    s->data[++(s->top)] = e;
}

/* 出栈 */
int pop(Stack *s, element *e){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;  // 表示栈空
    }
    *e = s->data[(s->top)--];
    return 0;
}

//获取栈顶元素
int getTop(Stack *s, element *e){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;  // 表示栈空
    }
    *e = s->data[s->top];
    return 0;
}

contentType getToken(char *symbol,int *index){
    *symbol = expr[*index];
    (*index)++;
    switch(*symbol){
        case '(': return LEFT_PAIR;
        case ')': return RIGHT_PAIR;
        case '+': return ADD;
        case '-': return SUB;
        case '*': return MUL;
        case '/': return DIV;
        case '%': return MOD;
        case'\0': return EOS;
        default:  return NUM;
    }
}


int eval(Stack *s){
    char symbol;
    int op1, op2;
    int index = 0;
    contentType token;
    token = getToken(&sy mbol, &index);
    element result;
    while(token != EOS){
        if(token == NUM){
            push(s, symbol - '0');
    }
    else{
        pop(s, &op2);
        pop(s, &op1);

        switch(token)
        {
            case ADD:
                result = op1 + op2;
                break;
            case SUB:
                result = op1 - op2;
                break;
            case MUL:
                result = op1 * op2;
                break;
            case DIV:
                result = op1 / op2;
                break;
            case MOD:
                result = op1 % op2;
                break;
            default:
                break;
        }
        push(s, result);//将结果入栈
    }
    token = getToken(&symbol, &index);
    }
    pop(s, &result);
    printf("Result: %d\n", result);
    return 1;
}

int main(){
    Stack *s = initStack();
    eval(s);
    return 0;
}