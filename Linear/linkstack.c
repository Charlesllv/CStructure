#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPrt;

typedef struct LinkStack{
    LinkStackPrt top; //top element of stack
    int count;
}LinkStack;

int Push(LinkStack *S, ElemType e){
    LinkStackPrt p = (LinkStackPrt) malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;
    S->top= p;
    S->count++;
    return 0;
}

int Pop(LinkStack *S, ElemType *e){
    LinkStackPrt p;
    if(StackEmpty(*S)){
        return -1;
    }
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return 0;
}


//栈的应用 ： 递归   四则运算表达式求值 后缀 中缀 前缀