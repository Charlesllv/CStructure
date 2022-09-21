#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *pre;
    struct Node *next;
}Node, *List;

void InitLine(List &L){
    L = (Node *)malloc(sizeof(Node));
    L->pre = NULL;
    L->next = NULL;
}

// void Insert(List &L, Node *p, int x){
//     Node *s = (Node *)malloc(sizeof(Node));
//     s->data = x;
//     s->next = p->next; // 1
//     p->next->pre = s;// 2
//     s-> pre = p; //3
//     p->next = s; //4 1、2必须在4 前
// }

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

List HeadCreat(List &L){
    InitList(L);
    
    FILE *fp = fopen("nodes.txt","r+");
    int buf=0;
    while(!feof){
        fscanf(fp, "%d", &buf);
        Node *s = (Node *)malloc(sizeof(Node));
        s->data = buf;
        if(L->next == NULL){
            s->next = NULL;
            s->pre = L;
            L-next = s;
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

List TailCreat(List &L){
    InitList(L);
    Node *s, *r=L;
    FILE *fp = fopen("nodes.txt","r+");
    int buf=0;
    while(!feof){
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
    Node *p = p->next;
    while(p){
        printf("Node%d: %d\n", i++, p->data);
        p = p->next;
    }
}


int main(int argc, char *argv[]){
    



    return o;
}