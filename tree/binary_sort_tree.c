// 二叉排序树： 左子树 < 根 < 右子树 中序遍历后---》递增序列
/*二叉树的二叉链表结点结构定义*/
typedef struct BiTNode
{
	int data;	//结点数据
	struct BiTNode *lchild, *rchild;	//左右孩子指针
} BiTNode, *BiTree;

/*
递归查找二叉排序树T中是否存在key
指针f指向T的双亲，其初始调用值为NULL
若查找成功，则指针p指向该数据元素结点，并返回TRUE
否则指针p指向查找路径上访问的最后一个结点并返回FALSE
*/
bool SearchBST(BiTree T, int key, BiTree f, BiTree *p){
	if(!T){
		*p = f;
		return FALSE;
	}else if(key == T->data){
		//查找成功
		*p = T;
		return TRUE;
	}else if(key < T->data){
		return SearchBST(T->lchild, key, T, p);	//在左子树继续查找
	}else{
		return SearchBST(T->rchild, key, T, p);	//在右子树继续查找
	}
}

/*
当二叉排序树T中不存在关键字等于key的数据元素时
插入key并返回TRUE，否则返回FALSE
*/
bool InsertBST(BiTree *T, int key){
	BiTree p, s;
	if(!SearchBST(*T, key, NULL, &p)){
		//查找不成功
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if(!p){
			*T = s;	//插入s为新的根节点
		}else if(key < p->data){
			p->lchild = s;	//插入s为左孩子
		}else{
			p->rchild = s;	//插入s为右孩子
		}
		return TRUE;
		}else{
			return FALSE;	//树种已有关键字相同的结点，不再插入
		}
}

/*
当二叉排序树T中不存在关键字等于key的数据元素时
插入key并返回TRUE，否则返回FALSE
*/
bool InsertBST(BiTree *T, int key){
	BiTree p, s;
	if(!SearchBST(*T, key, NULL, &p)){
		//查找不成功
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if(!p){
			*T = s;	//插入s为新的根节点
		}else if(key < p->data){
			p->lchild = s;	//插入s为左孩子
		}else{
			p->rchild = s;	//插入s为右孩子
		}
		return TRUE;
		}else{
			return FALSE;	//树种已有关键字相同的结点，不再插入
		}
}

int i;
int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
BiTree T = NULL;
for(i = 0; i<10; i++){
	InsertBST(&T, a[i]);
}


