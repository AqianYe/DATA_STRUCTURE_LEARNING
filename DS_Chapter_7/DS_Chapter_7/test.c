#define _CRT_SECURE_NO_WARNINGHS
#include<stdio.h>

//§7.2  顺序查找和折半查找
/*
一、顺序查找
1、又叫“线性查找”，通常用于线性表
2、算法思想：从头到尾挨个找
*/

//typedef struct//查找表的数据结构（顺序表）
//{
//	ElemType* elem;//动态数组基址
//	int TableLen;//表的长度
//}SSTable;
//
////顺序查找
//int Search_Seq(SSTable ST, Elemtype key)
//{
//	int i;
//	for (i = 0; i < ST.TableLen && ST.elem[i] != key; ++i)
//		//查找成功，则返回元素下标；查找失败，则返回-1
//	return i == ST.TableLen ? -1 : i;
//}


/*
二、折半查找
1、又称“二分查找”，仅适用于有序的顺序表
*/

//typedef struct//查找表的数据结构（顺序表）
//{
//	ElemType* elem;//动态数组基址
//	int TableLen;//表的长度
//}SSTable;
//
////折半查找
//int Binary_Search(SStable L, ElemType key)
//{
//	int low = 0, high = L.TableLen - 1, mid;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;//取中间位置
//		if (L.elem[mid] == key)
//			return mid;//查找成功则返回所在位置
//		else if (L.elem[mid] > key)
//			high = mid - 1;//从前半部分继续查找
//		else
//			low = high + 1;//从后半部分继续查找
//	}
//	return -1;//查找失败，返回-1
//}



//§7.3  树型查找
/*
一、二叉排序树（BTS）
1、左子树结点值<根结点值<右子树结点值
2、进行中序遍历，可以得到一个递增的有序序列
3、二叉排序树的查找
若树非空，将目标值与根结点的值比较：
若相等，则查找成功；
若小于根结点，则在左子树上查找，否则在右子树上查找
查找成功，返回结点指针；查找失败返回NULL

4、二叉排序树的插入
若原二叉排序树为空，则直接插入结点；否则若关键字k小于根结点
值，则插入到左子树，若关键字k大于根结点值，则插入到右子树
5、二叉排序树的构造
不同的关键字序列可能得到同款二叉排序树，也可能得到不同款二
叉排序树

6、二叉排序树的删除
先搜索到目标结点：
1）若被删除结点z是叶结点，则直接删除，不会破坏二叉排序树的
性质
2）若结点z只有一棵左子树或右子树，则让z的子树称为z父结点的
子树，替代z的位置
3）若结点z有左、右两棵子树，则令z的直接后继（或直接前驱）
替代z，然后从二叉排序树中删去这个直接后继（或直接前驱），
这样就转换成了第一或第二种情况
①z的后继：z的右子树中最左下结点（最小的结点，该结点一定没
有左子树）
②z的前驱：z的左子树中最右下结点（最大的结点，该结点一定没
有右子树）
*/

////二叉排序树结点
//typedef struct BSTNode
//{
//	int key;
//	struct BSTNode* lchild, * rchild;
//}BSTNode,*BSTree;
//
////在二叉排序树中查找值为key的结点
//BTSNode* BST_Search(BSTree T, int key)
//{
//	while (T != NULL && key != T->key)//若树空或等于根结点值，则结束循环
//	{
//		if (key < T->key)
//			T = T->lchild;//小于，则在左子树上查找
//		else
//			T = T->rchild;//大于，则在右子树上查找
//	}
//	return T;
//}//最坏空间复杂度O(1)
//
//
////在二叉排序树中查找值为key的结点（递归实现）
//BSTNode* BSTSearch(BSTree T, int key)
//{
//	if (T == NULL)
//		return NULL;//查找失败
//	if (key == T->key)
//		return T;//查找成功
//	else if (key < T->key)
//		return BSTSearch(T->lchild, key);//在左子树中找
//	else
//		return BSTSearch(T->rchild, key);//在右子树中找
//}//最坏空间复杂度O(h)
//
//
////在二叉排序树中插入关键字为k的新结点（递归实现）
//int BTS_Insert(BSTree& T, int k)
//{
//	if (T == NULL)//原树为空，新插入的结点为根结点
//	{
//		T = (BSTree)malloc(sizeof(BTSNode));
//		T->key = k;
//		T->lchild = T->rchild = NULL;
//		return 1;//返回1，插入成功
//	}
//	else if (k == T->key)
//		return 0;//树中存在相同关键字的结点，插入失败
//	else if (k < T->key)//插入到T的左子树
//		return BST_Insert(T->lchild, k);
//	else //插入到T的右子树
//		return BST_Insert(T->rchild, k);
//}//最坏空间复杂度O(h)
//
//
////按照str[]中的关键字序列建立二叉排序树
//void Create_BST(BSTree& T, int str[], int n)
//{
//	T = NULL;//初始时T为空树
//	int i = 0;
//	while (i < n)//依次将每个关键字插入到二叉排序树中
//	{
//		BST_Insert(T, str[i]);
//		i++;
//	}
//}


/*
二、平衡二叉树

*/

//平衡二叉树结点
//typedef struct AVLNode
//{
//	int key;//数据域
//	int balance;//平衡因子
//	struct AVLNode* lchild, * rchild;
//}AVLNode, * AVLTree;

//右旋操作
//f->lchild = p->rchild;
//p->rchild = f;
//gf->lchild / rchild = p;

//左旋操作
//f->rchild = p->lchild;
//p->lchild = f;
//gf->lchild / rchild = p;


/*
三、红黑树
*/

//struct RBNode//红黑树的结点定义
//{
//	int key;//关键字的值
//	RBNode* parent;//父结点指针
//	RBNode* lchild;//左孩子指针
//	RBNode* rchild;//右孩子指针
//	int color;//结点颜色，如可用0/1表示黑/红，也可使用枚举型enum表示颜色
//};



//§7.4  B树
/*
一、B树
*/

//二叉排序树结点
//typedef struct BSTNode
//{
//	int key;
//	struct BSTNode* lchild, * rchild;
//}BSTNode, * BSTree;

//五叉排序树
//struct Node
//{
//	ElemType key[4];//最多4个关键字
//	struct Node* child[5];//最多5个孩子
//	int num;//结点中有几个关键字
//};