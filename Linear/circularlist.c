#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *List;

List *InitList(){
    Node *head = (Node *) malloc(sizeof(List));
    if( head == NULL){
        printf("init failed, exit");
        exit(0);
    }else{
        head->next = NULL;
        return head;
    }

}

int InsertList( List L){
    int data;
    printf("input data:");
    scanf("%d", &data);

    Node  *node = InitList();
    node->data = data;

    if(L){
        Node *p = L;
        while( p->next != L){ //找到L的最后一个节点
            p = p->next;
        }
        p->next = node;
        node->next = L;
        return 1;
    }else{
        printf("List is NULL\n");
        return 0;
    }   
}

List InsertList(List L, int pos, int data){
    Node *node = InitList();
    node->data = data;

    
    Node *t = L;

    if(L){
        for(int i=1; i<pos ;i++){//找到 pos处
            t = t->next;
        }
        node->next = t->next; // 1
        t->next = node; // 2
        return L;

    }
    return L;
}

int DeleteList( List L,int del){
    if(!L){
        printf(" List is NULL\n");
        return 0;        
    }
    Node *tmp = L; //p的前驱
    Node *p = L->next; //遍历找到del
    
    while(p != L){
        if(p->data == del){
            if (p->next = L){
            tmp->next = L;
            free(p);
            return 1;
            }
            tmp->next = p->next;
            free(p);
            return 1;
        }
        tmp = tmp->next;
        p = p->next; 
    }
    printf("can't find");
    return 0;
}
int main(int argc, char *argv[]){

    Node *H = (Node *)malloc(sizeof(Node));
    List L = TailCreat(H);
    PrintList(L);


    return 0;
}