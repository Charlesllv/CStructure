#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 20

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int front, rear;
}SqQueue;

/*初始状态（队空条件）：Q->front == Q->rear == 0。
进队操作：队不满时，先送值到队尾元素，再将队尾指针加1。
出队操作：队不空时，先取队头元素值，再将队头指针加1。*/

/*循环队列
初始时：Q->front = Q->rear=0。
队首指针进1：Q->front = (Q->front + 1) % MAXSIZE。
队尾指针进1：Q->rear = (Q->rear + 1) % MAXSIZE。
队列长度：(Q->rear - Q->front + MAXSIZE) % MAXSIZE*/

//循环队列
int InitQueue(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
    return 0;
}

bool isEmpty(SqQueue *Q){
    if(Q->rear == Q->front){
        return true;
    }else{
        return false;
    }
}

int QueueLength( SqQueue Q){
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

int EnQueue(SqQueue *Q, ElemType e){
    if((Q->rear+1)%MAXSIZE == Q->front){
        printf("is full");
        return -1;
    }
    Q->data[Q->rear] = e;
    Q->rear = ( Q->rear + 1) % MAXSIZE;
    return 0;

}

int DeQueue( SqQueue *Q, ElemType *e){
    if(isEmpty(Q)){
        printf("is empty");
        return -1;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
}