#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *pre;
    struct Node *next;
}Node, *List;

void InitList(List L){
    L = (Node *)malloc(sizeof(Node));
    L->pre = NULL;
    L->next = NULL;
}

void Insert(List L, Node *p, int x){
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = x;
    s->next = p->next; // 1
    p->next->pre = s;// 2
    s-> pre = p; //3
    p->next = s; //4 1、2必须在4 前
}

// List HeadCreat(List &L){
//     InitList(L);
//     int x;
//     scanf("%d", &x);
//     while(x!= 9999){
//         Node *s = (Node *)malloc(sizeof(Node));
//         s->data = x;
//         if(L->next == NULL){
//             s->next = NULL;
//             s->pre = L;
//             L-next = s;
//         }else{
//             s->next = L->next;
//             L->next->pre= s;
//             s->pre = L;
//             L->next = s;
//         }
//         scanf("%d", %x);
//     }
//     return L;

// }

List HeadCreat(List L){
    InitList(L);
    
    FILE *fp = fopen("nodes.txt","r+");
    int buf;
    while(!feof(fp)){
        fscanf(fp, "%d", &buf);
        Node *s = (Node *)malloc(sizeof(Node));
        s->data = buf;
        if(L->next == NULL){
            s->next = NULL;
            s->pre = L;
            L->next = s;
        }else{
            s->next = L->next;
            L->next->pre= s;
            s->pre = L;
            L->next = s;
        }
       
    }
    fclose(fp);
    return L;

}

List TailCreat(List L){
    InitList(L);
    Node *s, *r=L;
    FILE *fp = fopen("nodes.txt","r+");
    int buf=0;
    while(!feof(fp)){
        fscanf(fp, "%d", &buf);
        s = (Node *)malloc(sizeof(Node));
        s->data = buf;
        s->next = NULL;
        s->pre = r;
        r->next = s;
        r = s;       
    }
    fclose(fp);
    return L;

}

void PrintList(List L){
    int i=1;
    Node *p = L->next;
    while(p){
        printf("Node%d: %d\n", i++, p->data);
        p = p->next;
    }
}

int  Length(List L){
    Node *p = L->next;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

Node *LocateElem(List L, int x){
    Node *p = L->next;
    while(p && p->data != x){
        p = p->next;
    }
    return p;
}

Node *GetElem( List L ,int i ){
    int j = 1;
    Node *p = L->next;
    if(i == 0) return L;
    if(i < 1) return NULL;
    while(p && j < i){ //i>len 就会直接返回p = NULL
        p = p->next;
        j++;
    }
    return p;
}

void Delete(List L, int i ){
    if ( i < 1 || i > Length( L )){
        printf(" delete failed : index is wrong");
        return;
    }
    Node *p = GetElem( L, i-1);
    Node *q = p->next;
    p->next = q ->next;
    q->next->pre = p;
    free(q);
}

bool IsEmpty( List  L){
    if ( L->next == NULL){
        printf("List is NULL");
        return true;
    }else{
        printf( "List is  not NULL");
        return false;
    }
}





int main(int argc, char *argv[]){

    Node *H = (Node *)malloc(sizeof(Node));
    List L = TailCreat(H);
    PrintList(L);


    return 0;
}