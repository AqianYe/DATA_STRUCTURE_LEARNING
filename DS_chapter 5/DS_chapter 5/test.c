﻿#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//§5.2  二叉树的存储结构

//一、二叉树的顺序存储
//#define MaxSize 100
//struct TreeNode
//{
//	ElemType value;//结点中的数据元素
//	bool IsEmpty;//结点是否为空
//};
//
//TreeNode t[MaxSize];
/*
定义一个长度为MaxSize的数组t，按照从上至下、从左至右的
顺序依次存储完全二叉树中的各个节点
*/

//for (int i = 0; i < MaxSize; i++)
//{
//	t[i].IsEmpty = true;
//}//初始化时所有结点标记为空

//可以让第一个位置空缺，保证数组下标和结点编号一致

/*
几个重要常考的基本操作：
i的左孩子 → 2i
i的右孩子 → 2i + 1
i的父节点 → ⌈log2(n + 1)⌉ 或 ⌊log2n⌋ + 1
*/

/*
完全二叉树中共有n个结点，则
判断i是否有左孩子 → 2i ≤ n ？
判断i是否有右孩子 → 2i + 1 ≤ n ？
判断i是否是叶子/分支节点 → i > ⌊n/2⌋ ？
*/

/*
二叉树的顺序存储中，一定要把二叉树的结点编号与完全二叉树对
应起来

最坏情况：
高度为h且只有h个结点的单支树（所有结点只有右孩子），也至少
需要2^h - 1个存储单元

结论：
二叉树的顺序存储结构，只适合存储完全二叉树
*/



//二、二叉树的链式存储
//struct ElemType
//{
//	int value;
//};
//
//typedef struct BiTNode
//{
//	ElemType data;//数据域
//	struct BiTNode* lchild, * rchild;//左右孩子指针
//}BiTNode, * BiTree;
//
////定义一棵空树
//BiTree root = NULL;
//
////插入根节点
//root = (BiTree)malloc(sizeof(BiTNode));
//root->data = { 1 };
//root->lchild = NULL;
//root->rchild = NULL;
//
////插入新结点
//BiTree* p = (BiTNode*)malloc(sizeof(BiTNode));
//p->data = 2;
//p->lchild = NULL;
//p->rchild = NULL;
//root->lchild = p;//作为根结点的左孩子


//三叉链表——方便找父结点
//typedef struct BiTNode
//{
//	ElemType data;//数据域
//	struct BiTNode* lchild, * rchild;//左、右孩子指针
//	struct BiTNode* parent;//父节点指针
//}BiTNode, * BiTree;





//§5.3  二叉树的遍历和线索二叉树

//一、二叉树的遍历
/*
先序遍历 → 前缀表达式
中序遍历 → 中缀表达式（需要加界限符）
后序遍历 → 后缀表达式 
*/

//typedef struct BiTNode
//{
//	ElemType data;
//	struct BiTNode* lchild, * rchild;
//}BiTNode,*BiTree;

//先序遍历（第一次路过时访问结点）
/*
操作过程：
①若二叉树为空，则什么也不做
②若二叉树非空：
  访问根节点 → 先序遍历左子树 → 先序遍历右子树
*/
//void PreOrder(BiTree T)
//{
//	if (T != NULL)
//	{
//		visit(T);//访问根节点
//		PreOrder(T->lchild);//递归遍历左子树
//		PreOrder(T->rchild);//递归遍历右子树
//	}
//}


//中序遍历（第二次路过时访问结点）
/*
操作过程：
①若二叉树为空，则什么也不做
②若二叉树非空：
  先序遍历左子树 → 访问根节点 → 先序遍历右子树
*/
//void InOrder(BiTree T)
//{
//	if (T != NULL)
//	{
//		InOrder(T->lchild);//递归遍历左子树
//		visit(T);//访问根节点
//		InOrder(T->rchild);//递归遍历右子树
//	}	
//}


//后序遍历（第三次路过时访问结点）
/*
操作过程：
①若二叉树为空，则什么也不做
②若二叉树非空：
  先序遍历左子树 → 先序遍历右子树 → 访问根节点
*/
//void PostOrder(BiTree T)
//{
//	if (T != NULL)
//	{
//		PostOrder(T->lchild);//递归遍历左子树
//		PostOrder(T->rchild);//递归遍历右子树
//		visit(T);//访问根节点
//	}
//}

//空间复杂度：O(h+1) → O(h)

//例：求树的深度（应用）
//int TreeDepth(BiTree T)
//{
//	if (T == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		int l = TreeDepth(T->lchild);
//		int r = TreeDepth(T->rchild);
//		//树的深度 = Max(左子树深度，右子树深度) + 1
//		return l > r ? l + 1 : r + 1;
//	}
//}



//二、二叉树的层序遍历
/*
算法思想：
①初始化一个辅助队列
②根结点入队
③若队列非空，则队头结点出队，访问该结点，并将其左、右孩子
  插入队尾（如果有的话）
④重复③直至队列为空
*/

//二叉树的结点（链式存储）
//typedef struct BiTNode
//{
//	char data;
//	struct BiTNode* lchild, * rchild;
//}BiTNode, * BiTree;
//
////链式队列结点
//typedef struct LinkNode
//{
//	BiTNode* data;//存指针而不是结点
//	struct LinkNode* next;
//}LinkNode;
//
//typedef struct
//{
//	LinkNode* front, * rear;//队头队尾
//}LinkQueue;
//
////层序遍历
//void LevelOrder(BiTree T)
//{
//	LinkQueue Q;
//	InitQueue(Q);//初始化辅助队列
//	BiTree p;
//	EnQueue(Q, T);//将根结点入队
//	while (!IsEmpty(Q))//队列不空则循环
//	{
//		DeQueue(Q, p);//队头结点出队
//		visit(p);//访问出队结点
//		if (p->lchild != NULL)
//			EnQueue(Q, p->lchild);//左孩子入队
//		if (p->rchild != NULL)
//			EnQueue(Q, p->rchild);//右孩子入队
//	}
//}



//三、由遍历序列构造二叉树（重点）
/*
一个中序遍历序列可能对应多种二叉树形态
一个前序遍历序列可能对应多种二叉树形态
一个后序遍历序列可能对应多种二叉树形态
一个层序遍历序列可能对应多种二叉树形态

→若只给出一棵二叉树的前/中/后/层序遍历序列中的一种，不能
  唯一确定一棵二叉树

→由二叉树的遍历序列构造二叉树
1）前序 + 中序遍历序列
2）后序 + 中序遍历序列
3）层序 + 中序遍历序列
*/



//四、线索二叉树（重点）
/*
n个结点的二叉树，有n+1个空链域，可用来记录前驱、后继的信息
*/
//二叉树的结点（链式存储）
//typedef struct BitTNode
//{
//	ElemType data;
//	struct BiTNode* lchild, * rchild;
//}BiTNode, * BiTree;

//1、线索二叉树
//typedef struct ThreadNode
//{
//	ElemType data;
//	struct ThreadNode* lchild, * rchild;
//	int ltag, rtag;//左右线索标志
//	//tag==0，表示指针指向孩子
//	//tag==1，表示指针是“线索”
//}ThreadNode, * ThreadTree;


//2、用土办法找到中序前驱
//中序遍历
//void InOrder(BiTree T)
//{
//	if (T != NULL)
//	{
//		InOrder(T->lchild);//递归遍历左子树
//		visit(T);//访问根节点
//		InOrder(T->rchild);//递归遍历右子树
//	}
//}
////访问结点q
//void visit(BiTNode* q)
//{
//	if (q == p)//当前访问结点刚好是结点p
//		final = pre;//找到p的前驱
//	else
//		pre = q;//pre指向当前访问的结点
//}
////辅助全局变量，用于查找结点p的前驱
//BiTNode* p;//p指向目标结点
//BiTNode* pre = NULL;//指向当前访问结点的前驱
//BiTNode* final = NULL;//用于记录最终结果
//
//
////3、中序线索化
////全局变量pre，指向当前访问结点的前驱
//TreadNode* pre = NULL;
////中序线索化二叉树
//void CreateInTread(ThreadTree T)
//{
//	pre = NULL;//pre初始为NULL
//	if (T != NULL)//非空二叉树才能线索化
//	{
//		InTread(T);//中序线索化二叉树
//		if (pre->rchild == NULL)
//			pre->rtag = 1;//处理遍历的最后一个节点
//	}
//}
////线索二叉树结点
//typedef struct ThreadNode
//{
//	ElemType data;
//	struct ThreadNode* lchild, * rchild;
//	int ltag, rtag;//左、右线索标志
//}ThreadNode, * ThreadTree;
////中序遍历二叉树，一边遍历一边线索化
//void InTread(TreadTree T)
//{
//	if (T != NULL)
//	{
//		InTread(T->lchild);//中序遍历左子树
//		visit(T);//访问根节点
//		InTread(T->rchild);//中序遍历右子树
//	}
//}
//void visit(ThreadNode* q)
//{
//	if (q->lchild == NULL)
//	{
//		//左子树为空，建立前驱线索
//		q->lchild = pre;
//		q->ltag = 1;
//	}
//	if (pre != NULL && pre->rchild == NULL)
//		//'pre!=NULL'是为了限制中序遍历处理第一个结点
//	{
//		//建立前驱节点的后继线索
//		pre->rchild = q;
//		pre->rtag = 1;
//	}
//	pre = q;
//}


//4、先序线索化
//全局变量pre，指向当前访问结点的前驱
//TreadNode* pre = NULL;
////先序线索化二叉树
//void CreatePreThread(ThreadTree T)
//{
//	pre = NULL;//pre初始化为NULL
//	if (T != NULL)//非空二叉树才能线索化
//	{
//		PreThread(T);//先序线索化二叉树
//		if (pre->rchild == NULL)
//			pre->rtag = 1;//处理遍历的最后一个结点
//	}
//}
//先序遍历二叉树，一边遍历一边线索化
///*
//void PreThread(TreadTree T)
//{
//	if (T != NULL)
//	{
//		visit(T);//先处理根节点
//		PreThread(T->lchild);
//		PreThread(T->rchild);
//	}
//}
//*/
///*
//防止出现左子树为空指向pre后，处理PreTread(T->lchild)时无限
//循环，故更改为如下代码：
//*/
//void PreThread(ThreadTree T)
//{
//	if (T != NULL)
//	{
//		visit(T);//先处理根节点
//		if (T->ltag == 0)//lchild不是前驱线索
//			PreThread(T->lchild);
//		PreThread(T->rchild);
//	}
//}
//void visit(ThreadNode* q)
//{
//	if (q->lchild = NULL)
//	{
//		//左子树为空，建立前驱线索
//		q - lchild = pre;
//		q->ltag = 1;
//	}
//	if (pre != NULL && pre->rchild == NULL)
//	{
//		pre->rchild = q;//建立前驱节点的后继线索
//		pre->rtag = 1;
//	}
//	pre = q;
//}


//5、后序线索化
//全局变量pre，指向当前访问结点的前驱
//TreadNode* pre = NULL;
//后序线索化二叉树
//void CreatePostThread(ThreadTree T)
//{
//	pre = NULL;//pre初始化为NULL
//	if (T != NULL)//非空二叉树才能线索化
//	{
//		PostThread(T);//先序线索化二叉树
//		if (pre->rchild == NULL)
//			pre->rtag = 1;//处理遍历的最后一个结点
//	}
//}
////后序遍历二叉树，一边遍历一边线索化
//void PostThread(ThreadTree T)
//{
//	if (T != NULL)
//	{
//		PostThread(T->lchild);//后序遍历左子树
//		PostThread(T->rchild);//后序遍历右子树
//		visit(T);//访问根节点
//	}
//}
//void visit(ThreadNode* q)
//{
//	if (q->lchild == NULL)
//	{
//		//左子树为空，建立前驱线索
//		q->lchild = pre;
//		q->ltag = 1;
//	}
//	if (pre != NULL && pre->rchild = NULL)
//	{
//		pre->rchild = q;//建立前驱节点的后继线索
//		pre->rtag = 1;
//	}
//	pre = q;
//}



//五、线索二叉树找前驱/后继
//1、中序线索二叉树找中序后继
/*
在中序线索二叉树中找到指定结点*p的中序后继next
①若p->rtag == 1，则next = p->rchild
②若p->rtag == 0，则next = p的右子树中最左下结点
*/

//找到以P为根的子树中，第一个被中序遍历的结点
//ThreadNode* FirstNode(ThreadNode* p)
//{
//	//循环找到最左下结点（不一定是叶结点）
//	while (p->ltag == 0)
//		p = p->lchild;
//	return p;
//}

//在中序线索二叉树中找到结点p的后继结点
//ThreadNode* NextNode(ThreadNode* p)
//{
//	//右子树中最左下结点
//	if (p->rtag == 0)
//		return FirstNode(p->rchild);
//	else
//		return p->rchild;//rtag==1直接返回后继线索
//}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
//void Inorder(ThreadNode* T)
//{
//	for (ThreadNode* p = Firstnode(T); p != NULL; p = NextNode(p))
//		visit(p);
//}//空间复杂度O(1)


//2、中序线索二叉树找中序前驱
/*
在中序线索二叉树中找到指定结点*p的中序前驱pre
①若p->rtag == 1，则pre = p->lchild
②若p->rtag == 0，则pre = p的左子树中最右下结点
*/

//找到以P为根的子树中，最后一个被中序遍历的结点
//ThreadNode* LastNode(ThreadNode* p)
//{
//	//循环找到最右下结点（不一定是叶结点）
//	while (p->rtag == 0)
//		p = p->rchild;
//	return p;
//}

//在中序线索二叉树中找到结点p的前驱结点
//ThreadNode* PreNode(ThreadNode* p)
//{
//	//左子树中最右下结点
//	if (p -> ltag == 0)
//		return LastNode(p->lchild);
//	else
//		return p->lchild;//ltag==1直接返回前驱线索
//}

//对中序线索二叉树进行逆向中序遍历
//void RevInorder(ThreadNode* T)
//{
//	for (ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p))
//		visit(p);
//}


//3、先序线索二叉树找先序后继
/*
在先序线索二叉树中找到指定结点*p的先序后继next
①若p->rtag == 1，则next = p->rchild
②若p->rtag == 0，则（p必有右孩子）
1）若p有左孩子，则next = p -> lchild
2）若p无左孩子，则next = p -> rchild
*/
//ThreadNode* NextNode(ThreadNode* p)
//{
//	if (p->rtag == 1 || p->ltag == 1)
//		return T->rchild;
//	else
//		return T->lchild;
//}


//4、先序线索二叉树找先序前驱
/*
在先序线索二叉树中找到指定结点*p的先序前驱pre
①若p->ltag == 1，则pre = p->lchild
②若p->rtag == 0，则（p必有左孩子）
先序遍历中，左右子树中的结点只可能是根的后继，不可能是前驱
但可以将二叉链表拓展为三叉链表，也就是给各个节点设置一个指
向其父节点的指针
1）如果能找到p的父节点，且p是左孩子，则pre = p的父节点
2）如果能找到p的父节点，且p是右孩子，其左兄弟为空，则pre
= p的父节点
3）如果能找到p的父节点，且p是右孩子，其左兄弟非空，则pre
= p的左兄弟子树中最后一个被先序遍历的结点
4）如果p是根节点，则p没有先序前驱
*/


//5、后序线索二叉树找后序前驱
/*
在后序线索二叉树中找到指定结点*p的后序前驱pre
①若p -> ltag == 1，则pre = p -> lchild
②若p -> ltag == 0，则（p必有右孩子）
1）若p有右孩子，则next = p -> rchild
2）若p无右孩子，则next = p -> lchild
*/
//ThreadNode* PreNode(ThreadNode* p)
//{
//	if (p->ltag == 1 || p->rtag == 0)
//		return T->lchild;
//	else
//		return T->rchild;
//}


//6、后序线索二叉树找后序后继
/*
在后序线索二叉树中找到指定结点*p的后序后继next
①若p->rtag == 1，则next = p->rchild
②若p->rtag == 0，则（p必有右孩子）
后序遍历中，左右子树中的结点只可能是根的前驱，不可能是后继
但可以将二叉链表拓展为三叉链表，也就是给各个节点设置一个指
向其父节点的指针
1）如果能找到p的父节点，且p是右孩子，则next = p的父节点
2）如果能找到p的父节点，且p是左孩子，其右兄弟为空，则next
= p的父节点
3）如果能找到p的父节点，且p是左孩子，其右兄弟非空，则pre
= p的右兄弟子树中第一个被后序遍历的结点
4）如果p是根节点，则p没有后序后继
*/


//建立二叉树及先序遍历的完整代码
#include<malloc.h>
#define Max 100
int count = 0;
typedef struct TNode
{
	char data;
	struct TNode* lchild, * rchild;
}BT;

//按照先序遍历的方法建立二叉树
BT* CreateBTree()
{
	BT* t;
	char ch;
	scanf("%c", &ch);
	getchar();
	if (ch == '0')
	{
		t = NULL;
	}
	else
	{
		t = (BT*)malloc(sizeof(BT));
		t->data = ch;
		printf("请输入%c结点的左孩子结点：", t->data);
		t->lchild = CreateBTree();
		printf("请输入%c结点的右孩子结点：", t->data);
		t->rchild = CreateBTree();
	}
	return t;
}

//对二叉树进行先序遍历
void PreOrder(BT* T)
{
	if (T == NULL)
		return;
	else
	{
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//求二叉树的深度
int TreeDepth(BT* T)
{
	if (T == NULL)
		return 0;
	else
	{
		int l = TreeDepth(T->lchild);
		int r = TreeDepth(T->rchild);
		return l > r ? l + 1 : r + 1;
	}
}

int main()
{
	BT* T = NULL;
	printf("请按先序序列输入二叉树的结点：\n");
	printf("请输入根节点：");
	T = CreateBTree();
	printf("二叉树成功建立\n");
	printf("二叉树的先序遍历序列为：");
	PreOrder(T);
	printf("该二叉树的深度是%d", TreeDepth(T));
	return 0;
}
