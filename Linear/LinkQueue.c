#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int Elemtype;
typedef struct{
    Elemtype data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue *Q){
    Q->front = Q->rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL; 
}

int EnQueue(LinkQueue *Q, Elemtype e){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL; //入到队尾
    Q->rear->next = s;
    Q->rear = s;//成为新的队尾
    return 0;
}

int DeQueue(LinkQueue *Q, Elemtype *e){
    LinkNode *p;
    if(Q->front == Q->rear){
        return -1;
    }
    p = Q->front->next; 
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear ==p ){
        Q->rear == Q->front;
    }
    free(p);
    return 0;
}

