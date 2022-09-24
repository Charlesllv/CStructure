#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/*二叉树的二叉链表结点构造定义*/
/*结点结构*/
typedef struct BiTNode{
	TElemType data;	//结点数据
	struct BiTNode *lchild, *rchild;	//左右孩子指针
} BiTNode, *BiTree;

void PreOrder(BiTree T){
	if(T != NULL){
		visit(T);	//访问根节点
		PreOrder(T->lchild);	//递归遍历左子树
		PreOrder(T->rchild);	//递归遍历右子树
	}
}

void InOrder(BiTree T){
	if(T != NULL){
		InOrder(T->lchild);	//递归遍历左子树
		visit(T);	//访问根结点
		InOrder(T->rchild);	//递归遍历右子树
	}
}

void PostOrder(BiTree T){
	if(T != NULL){
		PostOrder(T->lchild);	//递归遍历左子树
		PostOrder(T->rchild);	//递归遍历右子树
		visit(T);	//访问根结点
	}
}

void InOrder2(BiTree T){
	InitStack(S);	//初始化栈S
	BiTree p = T;	//p是遍历指针
	while(p || !IsEmpty(S)){	//栈不空或p不空时循环
		if(p){
			Push(S, p);	//当前节点入栈
			p = p->lchild;	//左孩子不空，一直向左走
		}else{
			Pop(S, p);	//栈顶元素出栈
			visit(p);	//访问出栈结点
			p = p->rchild;	//向右子树走，p赋值为当前结点的右孩子
		}
	}
}

void PreOrder2(BiTree T){
	InitStack(S);	//初始化栈S
	BiTree p = T;	//p是遍历指针
	while(p || !IsEmpty(S)){	//栈不空或p不空时循环
		if(p){
			visit(p);	//访问出栈结点
			Push(S, p);	//当前节点入栈
			p = p->lchild;	//左孩子不空，一直向左走
		}else{
			Pop(S, p);	//栈顶元素出栈
			p = p->rchild;	//向右子树走，p赋值为当前结点的右孩子
		}
	}
}

void PostOrder2(BiTree T){
	InitStack(S);
	p = T;
	r = NULL;
	while(p || !IsEmpty(S)){
		if(p){	//走到最左边
			push(S, p);
			p = p->lchild;
		}else{	//向右
			GetTop(S, p);	//读栈顶元素（非出栈）
			//若右子树存在，且未被访问过
			if(p->rchild && p->rchild != r){
				p = p->rchild;	//转向右
				push(S, p);	//压入栈
				p = p->lchild;	//再走到最左
			}else{	//否则，弹出结点并访问
				pop(S, p);	//将结点弹出
				visit(p->data);	//访问该结点
				r = p;	//记录最近访问过的结点
				p = NULL;
			}
		}
	}
}

void LevelOrder(BiTree T){
	InitQueue(Q);	//初始化辅助队列
	BiTree p;
	EnQueue(Q, T);	//将根节点入队
	while(!IsEmpty(Q)){	//队列不空则循环
		DeQueue(Q, p);	//队头结点出队
		visit(p);	//访问出队结点
		if(p->lchild != NULL){
			EnQueue(Q, p->lchild);	//左子树不空，则左子树根节点入队
		}
		if(p->rchild != NULL){
			EnQueue(Q, p->rchild);	//右子树不空，则右子树根节点入队
		}
	}
}



//树---》二叉树：孩子兄弟表示法
//森林---》二叉树：孩子兄弟表示法 每棵树的根 无兄弟 空的，可以把后一棵树的根当成其兄弟 ，即转化为前一二叉树的右子树

/*先序遍历森林。若森林为非空，则按如下规则进行遍历:
●访问森林中第一棵树的根结点。
●先序遍历第一棵树中根结点的子树森林。
●先序遍历除去第一棵树之后剩余的树构成的森林。
后序遍历森林。森林为非空时，按如下规则进行遍历:
●后序遍历森林中第一棵树的根结点的子树森林。
●访问第一棵树的根结点。
●后序遍历除去第一棵树之后剩余的树构成的森林。
*/
