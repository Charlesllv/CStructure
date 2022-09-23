#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node,*LinkList;

LinkList LinkListCreatH(){
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    if( !L ){
        printf("failed!");
        exit(0);
    }
    L->next=NULL; //带头节点�?

    int x;
    // while(scanf("%d", &x) != EOF ){ //ctrl+z
    // while(scanf("%d", &x) && (x!=9999)){
    //     Node *p;
    //     p = (Node *)malloc(sizeof(Node));
    //     p->data = x;
    //     p->next = L->next;
    //     L->next = p;
    // }
    FILE *fp = fopen("nodes.txt","r+");
    int buf;

    while(!feof(fp)){
        //memset(buf,0,sizeof(buf));
        fscanf(fp, "%d", &buf);
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = buf;
        p->next = L->next;
        L->next = p;
    }
    fclose(fp);

    return L;
}

LinkList LinkListCreatT(){
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    
    Node *r;
    r = L;
    // int x;
    // while(scanf("%d", &x) && (x!=9999)){
    //     Node *p;
    //     p = (Node *)malloc(sizeof(Node));
    //     p->data = x;

    //     r->next = p;
    //     r = p;
    // }
    FILE *fp = fopen("nodes.txt","r+");
    int buf = 0;

    while(!feof(fp)){
        //memset(buf,0,sizeof(buf));
        fscanf(fp, "%d", &buf);
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = buf;
        r->next = p;
        r = p;
    }
    fclose(fp);
    r->next = NULL;
    return L;
}

void printList( LinkList L){
    Node *p = L->next;
    int  i=0;
    while(p){
        printf("Node%d:%d\n", ++i, p->data);
        p = p->next;
    }
}

LinkList LinkListReplace(LinkList L,int v, int r){
    Node *p = L->next;
    int i=1;
    while(p){
        if(p->data == v){
            p->data = r;
            printf("Node%d:%d-->%d",i ,v ,r);
        }
        i++;
        p = p->next;
    }
    return L;
}

LinkList LinkListInsert( LinkList L, int i ,int x){
    Node *pre;
    pre = L;
    for(int tmp=1;tmp < i ;tmp++){//找到Node i �? 前驱
        pre = pre->next;   
    }
    
    Node *p;//新增节点
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    
    p->next = pre->next;
    pre->next = p;
    printf("position %d--> + Node=%d\n", i, x);
    return L;
}

LinkList LinkListDelete(LinkList L, int x){
    Node *p, *pre;
    p = L->next;
    while(p->data != x){  //按值找到要删的节点
        pre = p;
        p = p->next;
    }
    pre->next = p->next;
    free(p);
    return L;
}

int main(int argc, char *argv[]){
    // Node *L = LinkListCreatH();
    // printList( L );
    Node *L2= LinkListCreatT();
    printList( L2 );
    // LinkListReplace( L2, 3, 3333);

    // LinkListInsert( L2, 3,3333 );
    // printList( L2 );

    // LinkListDelete(L2, 5);
    // printList(L2);

   
    return 0;
    

}
