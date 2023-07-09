#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//§5.4  树、森林
/*
一、双亲表示法（顺序存储）
1、每个结点中保存指向双亲的“指针”
2、“指针”——数组下标
3、新增数据元素，无需按逻辑上的次序存储

4、删除数据元素
1）方法一：将其双亲设置为-1（空数据导致遍历更慢）
2）方法二：将尾部元素挪至此处
3）若删除的不是叶子结点，则其子孙也要删除

5、查询数据元素
1）优点：查指定结点的双亲很方便
2）缺点：查指定结点的孩子只能从头遍历

*/

//#define MAX_TREE_SIZE 100//树中最多结点数
//typedef struct//树的结点定义
//{
//	ElemType data;//数据元素
//	int parent;//双亲位置域
//
//}PTNode;
//
//typedef struct//树的类型定义
//{
//	PTNode nodes[MAX_TREE_SIZE];//双亲表示
//	int n;//结点数
//}PTree;


/*
二、孩子表示法（顺序+链式存储）
1、顺序存储各个结点，每个结点中保存孩子链表头指针
*/

//struct CTNode
//{
//	int child;//孩子结点在数组中的位置
//	struct CTNode* next;//下一个孩子
//};
//
//typedef struct
//{
//	ElemType data;
//	struct CTNode* FirstChild;//第一个孩子
//}CTBox;
//
//typedef struct
//{
//	CTBox nodes[MAX_TREE_SIZE];
//	int n, r;//结点数和根的位置
//}CTree;


/*三、孩子兄弟表示法（链式存储）*/

//typedef struct CSNode
//{
//	ElemType data;//数据域
//	struct CSNode* FirstChild, * Nextsibling;
//	//第一个孩子和右兄弟指针
//}CSNode, * CSTree;


/*
四、树的遍历
1、树的先根遍历
1）若树非空，先访问根结点，再依次对每颗子树进行先根遍历
2）树的先根遍历序列与这棵树相应二叉树的先序序列相同

2、树的后根遍历
1）若树非空，先依次对每棵子树进行后根遍历，最后再访问根节点
2）树的后根遍历序列与这棵树相应二叉树的中序序列相同

3、树的层次遍历（用队列实现）
①若树非空，则根结点入队
②若队列非空，队头元素出队并访问，同时将该元素的孩子依次入
队
③重复②直到队列为空

1、2 → 树的深度优先遍历
3 → 树的广度优先遍历
*/

////树的先根遍历
//void PreOrder(TreeNode* R)
//{
//	if (R != NULL)
//	{
//		visit(R);//访问根结点
//		while (R还有下一个子树T)//根据不同的存储方式来定
//			PreOrder(T);//先遍历下一棵子树
//	}
//}
//
////树的后根遍历
//void PostOrder(TreeNode* R)
//{
//	if (R != NULL)
//	{
//		while (R还有下一个子树T)
//			PostOrder(T);//后根遍历下一棵子树
//		visit(R);//访问根节点
//	}
//}


/*
五、森林的遍历
1、森林的先序遍历
若森林非空，则按如下规则进行遍历：
①访问森林中第一棵树的根结点
②先序遍历第一棵树中根结点的子树森林
③先序遍历除去第一棵树之后剩余的树构成的森林
效果等同于依次对各个树进行先根遍历，对二叉树的先序遍历

2、森林的中序遍历
若森林非空，则按如下规则进行遍历：
①中序遍历森林中第一棵树的根结点的子树森林
②访问第一棵树的根结点
③中序遍历出去第一棵树之后剩余的树构成的森林
效果等同于依次对各个树进行后根遍历，对二叉树的中序遍历
*/



//§5.5  哈夫曼树
/*
“并查集”
1、“查”操作，找x所属集合，并返回x所属根节点
2、“并”操作，将两个集合合并为一个
*/

//树的存储——双亲表示法
//#define MAX_TREE_SIZE 100//树中最多节点数
//typedef struct//树中结点定义
//{
//	ElemType data;//数据元素
//	int parent;//双亲位置域
//}PTNode;
//
//typedef struct//树的定义类型
//{
//	PTNode nodes[MAX_TREE_SIZE];//双亲表示
//	int n;//结点数
//}PTree;


/*并查集的代码实现*/
//#define SIZE 15
//int UFSets[SIZE];//集合数组元素
////初始化并查集
//void Initial(int S[])
//{
//	for (int i = 0; i < SIZE; i++)
//		S[i] = -1;
//}
//
////并查集的“查”操作，最坏时间复杂度O(n)
//int Find(int S[], int x)
//{
//	while (S[x] >= 0)//循环寻找x的根
//		x = S[x];
//	return x;//根的S[]小于0
//}
//
////并查集的“并”操作，时间复杂度O(1)
//void Union(int S[], int Root1, int Root2)
//{
//	//要求Root1与Root2是不同的集合
//	if (Root1 == Root2)
//		return;
//	//将根Root2连接到另一根Root1下面
//	S[Root2] = Root1;
//}


/*
显然“查”这一操作的时间复杂度与树的高度有关，那么不妨可以
由此对该操作进行优化：
在每次Union操作构建树的时候，尽可能让树不长高，即
①用根结点的绝对值表示树的结点总数，以方便比较大小
②Union操作，让小树合并到大树

该方法构造的树高不超过⌊log₂n⌋ + 1
Union操作优化后，Find操作 最坏时间复杂度为O(log₂n)
*/

//“并”操作，小树合并到大树
//void Union(int S[], int Root1, int Root2)
//{
//	if (Root1 == Root2)
//		return;
//	if (S[Root2] > S[Root1])//Root2结点数更少
//	{
//		
//	}
//	else
//	{
//		S[Root2] += S[Root1];//累加结点总数
//		S[Root1] = Root2;//小树合并到大树
//	}
//}


/*
Find操作的优化（压缩路径）：
先找到根结点，再将查找路径上所有结点都挂到根节点下

每次Find操作，先找根，再“压缩路径”，可以使树的高度不超过
O(α(n))。α(n)是一个增长很缓慢的函数，对于常见的n值，通常
α(n)≤4，因此优化后并查集的Find、Union操作时间开销都很低
*/
//int Find(int S[], int x)
//{
//	int root = x;
//	while (S[root] >= 0)
//		root = S[root];//循环找到根
//	while (x != root)//压缩路径
//	{
//		int t = S[x];//t指向x的父结点
//		S[x] = root;//x直接挂到根结点下
//		x = t;
//	}
//}


















