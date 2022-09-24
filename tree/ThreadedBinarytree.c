#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct ThreadNode{
	ElemType data;	//数据元素
	struct ThreadNode *lchild, *rchild;	//左、右孩子指针
	int ltag, rtag;	//左、右线索标志
}ThreadNode, *ThreadTree;

void InThread(ThreadTree p, ThreadTree pre){
	if(p != NULL){
		InThread(p->lchild, pre);	//递归，线索化左子树
		if(p->lchild == NULL){	//左子树为空，建立前驱线索
			p->lchild = pre;
			p->ltag = 1;
		}
		if(pre != NULL && pre->rchild == NULL){
			pre->rchild = p;	//建立前驱结点的后继线索
			pre->rtag = 1;
		}
		pre = p;	//标记当前结点成为刚刚访问过的结点
		InThread(p->rchild, pre);	//递归，线索化右子树
	}
}
