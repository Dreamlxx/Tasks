#include <stdio.h>
#include<stdlib.h>

typedef char element;


//键值对结构体
typedef struct entry
{
    int value;//传入的实际数据值，可以重复
    int key;//寻找的真正关键，不可重复
}entry;

//链表定义
typedef struct{
    entry e;
    List* next;
}List;


//哈希表定义
typedef struct{
    List** HashList;
    int capacity;//容量
    int size;//现在里面拥有的数据量
}HashMap;


//将传入的数转化为哈希数
int hashNum(int key,int capacity){
    return key % capacity;
}

//哈希表创建与初始
HashMap *creatHashmao(int capacity){

    //创建哈希表并初始化
    HashMap *b=(HashMap*)malloc(sizeof(HashMap));
    b->capacity=capacity;
    b->size=0;


    //给哈希表创建空间
    b->HashList=(List**)calloc(capacity,sizeof(List*));
    for(int i=0;i<b->capacity;i++){
        b->HashList[i]->next=NULL;
    }
    if(!b->HashList) {
        free(b);
        return 0;
    }
    return b;
}



//--------------哈希表操作函数----------------

//基础插入
int insetHah(HashMap*p,int key,int value){
    if(!p){
        printf("HashMap is NULL");
    }

    //找到传入的key在哈希表里的哈希数的位置
    int index = hashNum(key,p->capacity);
    //创建一个新的链表指针来接它
    List *newList=(List**)calloc(p->capacity,sizeof(List*));

    //如果key已经存在，则覆盖原哈希表中的value
    if(p->HashList[index]->e.key == key){
        p->HashList[index]->e.value = value;
        return 1;
    }

    //若是没有key
    if(!newList->e.key){
        newList->e.key=key;
        newList->e.value=value;
        
        //头插法
        newList->next=p->HashList[index]->next;
        p->HashList[index]->next=newList;
        return 1;
    }
    
}