#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//单链表的定义
//typedef struct LNode//定义单链表结构类型
//{
//	ElemType data;//每个节点存放一个数据元素
//	struct LNode* next;//指针指向下一个结点
//}LNode, * LinkList;

//LNode* p = (struct LNode*)malloc(sizeof(LNode));

//LNode* GetElem(LinkList L, int i)
//{
//	int j = 1;
//	LNode* p = L->next;
//	if (i == 0)
//		return L;
//	if (i < 1)
//		return NULL;
//	while (p != NULL && j < i)
//	{
//		p = p->next;
//		j++;
//	}
//	return p;
//}
//强调这是一个单链表——使用LinkList
//强调这是一个结点——使用LNode*

//初始化一个空的单链表
//bool InitList(LinkList& L)
//{
//	L = NULL;//空表，暂时还没有任何结点，防止脏数据
//	return true;
//}

//void test()
//{
//	LinkList L;//声明一个指向单链表的指针
//	//此处并没有创建一个结点
//	InitList(L);//初始化一个空表
//}

//初始化一个单链表（带头结点）
//bool InitList(LinkList& L)
//{
//	L = (LNode*)malloc(sizeof(LNode));//分配一个头结点
//	if (L == NULL)
//		return false;
//	L->next = NULL;//头结点之后暂时还没有结点
//	return true;
//}

//单链表的插入
//在第i个位置插入元素e（带头结点）
//bool ListInsert(LinkList& L, int i, ElemType e)
//{
//	if (n < 1)
//		return false;
//	LNode* p;//指针p指向当前扫描到的结点
//	int j = 0;//当前p指向的是第几个结点
//	p = L;//L指向头结点，头结点是第0个结点（不存数据）
//	while (p != NULL && j < i - 1)//循环找到第i-1个结点
//	{
//		p = p->Next;
//		j++;
//	}
//	if (p == NULL)
//		return false;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;//将结点s连到p之后
//	return true;//插入成功
//}

//在第i个位置插入元素e（不带头结点）
//bool ListInsert(LinkList& L, int i, ElemType e)
//{
//	if (i < 1)
//		return false;
//	if (i == 1)//插入第1个结点的操作与其他结点操作不同
//	{
//		LNode* s = (LNode*)malloc(sizeof(LNode));
//		s->data = e;
//		s->next = L;
//		L = s;//头指针指向新结点
//		return true;
//	}
//	LNode* p;//指针p指向当前扫描到的结点
//	int j = 1;//当前p指向的是第几个结点
//	p = L;//p指向第1个结点（注意：不是头结点）
//	while (p != NULL && j < i - 1)//循环找到第i-1个结点
//	{
//		p = p->next;
//		j++;
//	}
//	if (p == NULL)//i值不合法
//		return false;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	s->data = e;
//	s - next = p->next;
//	p->next = s;
//	return true;//插入成功
//}

//指定结点的后插操作：在p结点之后插入元素e
//bool InsertNextNode(LNode* p; ElemType e)
//{
//	if (p == NULL)
//		return false;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	if (s == NULL)//内存分配失败
//		return false;
//	s->data = e;//用结点s保存数据元素e
//	s->next = p->next;
//	p->next = s;//将结点s连到p之后
//	return true;
//}

//指定结点的前插操作：在p结点之前插入元素e
//bool InsertPriorNode(LNode* p, ElemType e)
//{
//	if (p = NULL)
//		return false;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	if (s == NULL)//内存分配失败
//		return false;
//	s->next = p->next;
//	p->next = s;//新结点s连到p之后
//	s->data = p->data;//将p中元素复制到s中
//	p->data = e;//p中元素覆盖为e
//	return true;
//}

//按位序删除（带头结点）
//bool ListDelete(LinkList& L, int i, ElemType& e)
//{
//	if (i < 1)
//		return false;
//	LNode* p;//指针p指向当前扫描到的结点
//	int j = 0;//当前p指向的是第几个结点
//	p = L;//L指向头结点，头结点是第0个结点（不存数据）
//	while (p != NULL && j < i - 1)//循环找到第i-1个结点
//	{
//		p = p->next;
//		j++;
//	}
//	if (p == NULL)//i值不合法
//		return false;
//	if (p->next = NULL)//第i-1个结点之后已无其他结点
//		return false;
//	LNode* q = p->next;//令q指向被删除结点
//	e = q->data;//用e返回元素的值
//	p->next = q->next;//将*q结点从链中“断开”
//	free(q);//释放结点的存储空间
//	return true;//删除成功
//}

//删除指定结点p
//bool DeleteNode(LNode* p)
//{
//	if (p == NULL)
//		return false;
//	LNode* q = p->next;//令q指向*p的后继结点
//	p->data = p->next->data;//和后继结点交换数据域
//	p->next = q->next;//将*q结点从链中“断开”
//	free(q);//释放后继结点的存储空间
//	return true;
//}

//按位查找，返回第i个元素（带头结点）
//LNode* GetElem(LinkList L, int i)
//{
//	if (i < 0)
//		return NULL;
//	LNode* p;//指针p指向当前扫描到的结点
//	int j = 0;//当前p指向的是第几个结点
//	p = L;//L指向头节点，头结点是第0个结点（不存数据）
//	while (p != NULL && j < i)//循环找到第i个结点
//	{
//		p = p->next;
//		j++;
//	}
//	return p;
//}

//按值查找，找到数据域==e的结点
//LNode* LocateElem(LinkList L, ElemType e)
//{
//	LNode* p = L->next;
//	//从第1个结点开始查找数据域为e的结点
//	while (p != NULL && p->data != e)
//		p = p->next;
//	return p;//找到之后返回该结点，否则返回NULL
//}

//求表的长度
//int Length(LinkList L)
//{
//	int len = 0;//统计表长
//	LNode* p = L;
//	while (p->next != NULL)
//	{
//		p = p->next;
//		len++;
//	}
//	return len;
//}

//尾插法建立单链表
//typedef struct LNode//定义单链表结点类型
//{
//	ElemType data;//每个结点存放一个数据元素
//	struct LNode* next;//指针指向下一个结点
//}LNode,*LinkList;
//
////初始化一个单链表（带头结点）
//bool InitList(LinkList& L)
//{
//	L = (LNode*)malloc(sizeof(LNode));//分配一个头结点
//	if (L == NULL)//内存不足，分配失败
//		return false;
//	L->next = NULL;//头结点之后暂时还没有结点
//	return true;
//}
//
//void test()
//{
//	LinkList L;//声明一个指向单链表的指针
//	InitList(L);//初始化一个空表
//}

////在第i个位置插入元素e（带头结点）
//bool ListInsert(LinkList& L, int i, ElemType e)
//{
//	if (i < 1)
//		return false;
//	LNode* p;//指针p指向当前扫描到的结点
//	int j = 0;//当前p指向的是第几个结点
//	p = L;//L指向头节点，头结点是第0个结点（不存数据）
//	while (p != NULL && j < i - 1)//循环找到第i-1个结点
//	{
//		p = p->next;
//		j++;
//	}
//	if (p == NULL)//i值不合法
//		return false;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;//将结点s连到p之后
//	return true;//插入成功
//}

//正向建立单链表
//LinkList List_TailInsert(LinkList& L)
//{
//	int x;//设ElemType为整型
//	L = (LinkList)malloc(sizeof(LNode));//设立头结点
//	LNode* s, * r = L;//r为表尾指针
//	scanf("%d", &x);//输入结点的值
//	while (x != 9999)//输入9999表示结束
//	{
//		s = (LNode*)malloc(sizeof(LNode));
//		s->data = x;
//		r->next = s;
//		r = s;//r指向新的表尾结点
//		scanf("%d", &x);
//	}
//	r->next = NULL;//尾结点指针置空
//	return L;
//}

//逆向建立单链表
//LinkList List_HeadInsert(LinkList& L)
//{
//	LNode* s;
//	int x;
//	L = (LinkList)malloc(sizeof(LNode));//创建头结点
//	L->next = NULL;//初始为空链表
//	scanf("%d", &x);//输入结点的值
//	while (x != 9999)//输入9999表示结束
//	{
//		s = (LNode*)malloc(sizeof(LNode));//创建新结点
//		s->data = x;
//		s->next = L->next;
//		L->next = s;//将新结点插入表中，L为头指针
//		scanf("%d", &x);
//	}
//	return L;
//}

//typedef struct LNode//单链表的结构定义 
//{        
//	int data;//定义int类型的数据域 
//	struct LNode* next;//定义指针域 
//}LNode, * LinkList;
//
////初始化单链表 并设置为空表
//LNode* InitList(LNode* L)
//{
//	L = (LNode*)malloc(sizeof(LNode));
//	L->next = NULL;
//	//使头结点的指针域为空，建立一个空的单链表 
//	return L;
//}
//
////利用头插法建立单链表
//void List_HeadInsert(LNode* L)
//{
//	LNode* p;
//	//新建一个结点指针,永远指向当前链表的头结点
//	int i;
//	scanf_s("%d", &i);
//	//输入i，用于指代输入的整数，将要放进链表的数据元素
//	//也用来控制while循环，当输入i的值为9999时结束
//	while (i != 9999) 
//	{
//		p = (LNode*)malloc(sizeof(LNode));//新建一个结点
//		p->data = i;//把输入的值赋值给新结点的指针域
//		p->next = L->next;//把新结点插入到表头
//		L->next = p;//头结点要始终放在最前面
//		scanf_s("%d", &i);
//	}
//}
//
////利用尾插法建立单链表
//void List_TailInsert(LNode* L)
//{
//	LNode* r;
//	//建立一个尾指针，始终指向当前链表的尾结点
//	int i;//i用于指代输入的整数，将要放进链表的数据元素
//	//也用来控制while循环，当输入i的值为9999时结束
//	r = L;
//	//令尾指针r指向头结点L，便于做尾插入 
//	scanf_s("%d", &i);//输入插入的整数
//	while (i != 9999)
//	{
//		LNode* p = (LNode*)malloc(sizeof(LNode));
//		//建立一个新结点，用于存储数据元素
//		p->data = i;
//		r->next = p;
//		r = p;
//		scanf_s("%d", &i);
//	}
//	r->next = NULL;
//}
//
////单链表打印
//void ListPrint(LNode* L) 
//{ 
//	printf("该链表的内容为：");
//	while (L->next != NULL)
//	{
//		printf("%d ", L->next->data);
//		L = L->next;
//	}
//	printf("\n");
//}
//
////单链表逆置
//void ListReverse(LNode* L)
//{
//	LNode* p, * r;
//	p = L->next;
//	L->next = NULL;
//	while (p != NULL)
//	{
//		r = p->next;
//		p->next = L->next;
//		L->next = p;
//		p = r;
//	}
//	return L;
//}
//
//int main() 
//{
//	LNode* L = NULL;
//	L = InitList(L);
//	printf("单链表已初始化\n");
//	printf("用尾插法插入链表L：\n");
//	List_TailInsert(L);
//	ListPrint(L);
//	printf("逆置此单链表\n");
//	ListReverse(L);
//	ListPrint(L);
//	return 0;
//}



//双链表
//typedef struct DNode//定义双链表结点类型
//{
//	ElemType data;//数据域
//	struct DNode* prior, * next;//前驱和后继指针
//}DNode,*DLinkList;

//初始化双链表
//bool InitLink(DLinkList& L)
//{
//	L = (DNode*)malloc(sizeof(DNode));//分配一个头结点
//	if (L == NULL)//内存不足，分配失败
//		return false;
//	L->prior = NULL;//头结点的prior永远指向NULL
//	L->next = NULL;//头结点之后暂时还没有结点
//	return true;
//}

//void testDLinkList
//{
//	//初始化双链表
//	DLinkList L;
//	InitDLinkList(L);
//	//后续代码...
//}

//判断双链表是否为空（带头结点）
//bool Empty(DLinkList L)
//{
//	if (L->next == NULL)
//		return true;
//	else
//		return false;
//}

//双链表的插入
//在p结点之后插入s结点
//bool InsertNextDNode(DNode* p, DNode* s)
//{
//	s->next = p->next;//将结点*s插入到*p之后
//	p->next->prior = s;
//	s->prior = p;
//	p->next = s;
//}
//若p恰好为最后一个结点，则第二句无法执行
//故而此段代码可修改为
//bool InsertNexrDNode(DNode* p, DNode* s)
//{
//	if (p == NULL || s == NULL)//非法参数
//		return false;
//	s->next = p->next;
//	if (p->next != NULL)//如果p结点有后继点
//		p->next->prior = s;
//	s->prior = p;
//	p->next = s;
//	return true;
//}

//双链表的删除
//删除p的后继结点q
//bool DeleteNextDNode(DNode* p)
//{
//	if (p = NULL)
//		return false;
//	DNode* q = p->next;//找到p的后继结点q
//	if (q == NULL)
//		return false;//p没有后继
//	p->next = q->next;
//	if (q->next != NULL)
//		q->next->prior = p;
//	free(q);//释放结点空间
//	return true;
//}

//void DestroyList(DLinkList& L)
//{
//	//循环释放各个数据节点
//	while (L->next != NULL)
//		DeleteNextDNode(L);
//	free(L);//释放头结点
//	L = NULL;//头指针指向NULL
//}

//双链表的遍历
//后向遍历
//while (p != NULL)
//{
//	//对结点p做相应处理，如打印
//	p = p->next;
//}
////前向遍历
//while(p!=NULL)
//{
//	//对结点p做相应处理
//	p = p->prior;
//}
////前向遍历（跳过头结点）
//while (p->prior != NULL)
//{
//	//对结点p做相应处理
//	p = p->prior;
//}
//双链表不可随机存取，按位查找、按值查找操作都只能用
//遍历的方式实现，时间复杂度为O(n)



//循环链表
//循环单链表
//typedef struct LNode//定义单链表结点类型
//{
//	ElemType data;//每个结点存放一个数据元素
//	struct LNode* next;//指针指向下一个结点
//}LNode，* LinkList;
//
//初始化一个循环单链表
//bool InitList(LinkList& L)
//{
//	L = (LNode*)malloc(sizeof(LNode));//分配一个头结点
//	if (L == NULL)//内存不足，分配失败
//		return false;
//	L->next = L;//头结点next指向头结点
//	return true;
//}
//
////判断循环单链表是否为空
//bool Empty(LinkList L)
//{
//	if (L->next == L)
//		return true;
//	else
//		return false;
//}
//
////判断结点p是否为循环单链表的表尾结点
//bool IsTail(LinkList L, LNode* p)
//{
//	if (p->next == L)
//		return true;
//	else
//		return false;
//}

//循环双链表
//typedef struct DNode
//{
//	ElemTyoe data;
//	struct DNode* prior, * next;
//}DNode, * DLinkList;
//
////初始化空的循环双链表
//bool InitDLinkList(DLinkList& L)
//{
//	L = (DNode*)malloc(sizeof(DNode));//分配一个头结点
//	if (L == NULL)
//		return false;
//	L->prior = L;//头结点的prior指向头结点
//	L->next = L;//头结点的next指向头结点
//	return true;
//}
//
//判断循环双链表是否为空
//bool Empty(DLinkList L)
//{
//	if (L->next == L)
//		return true;
//	else
//		return false;
//}
//
//void TestDLinkList()
//{
//	//初始化循环双链表
//	DLinkList L;
//	InitDLinkList(L);
////...后续代码...
//}
//
//判断结点p是否为循环双链表的表尾结点
//bool IsTail(DLinkList L, DNode* p)
//{
//	if (p->next == L)
//		return true;
//	else
//		return false;
//}
//
//循环双链表的插入
//在p结点之后插入s结点
//bool InsertNextDNode(DNode* p, DNode* s)
//{
//	s->next = p->next;//将结点*s插入到结点*p之后
//	p->next->prior = s;
//	s->prior = p;
//	p->next = s;
//    return true;
//}

//循环双链表的删除
//删除p的后继结点q
//bool DeleteNextDNode(DNode* p)
//{
//	DNode* q = p->next;//找到p的后继结点q
//	p->next = q->next;
//	q->next->prior = p;
//	free(q);//释放结点空间
//	return true;
//}

//静态链表
//静态链表的结构类型描述
#define MaxSize 50//静态链表的最大长度
//静态链表结构类型的定义1
//struct Node
//{
//	ElemType data;//存储数据元素
//	int next;//下一个元素的数组下标
//};
//
//void TestLinkList()
//{
//	struct Node a[MaxSize];
//	//...后续代码
//}

//静态链表结构类型的定义2
//typedef struct//静态链表结构类型的定义
//{
//	ElemType data;//存储数据元素
//	int next;//下一个元素的数组下标
//}SLinkList[MaxSize];
//
//void TestSLinkList()
//{
//	SLinkList a;
//	//...后续代码
//}

//初始化静态链表：把a[0]的next设为-1

//查找：从头结点出发挨个往后遍历结点

/*插入位序为i的结点：
  1.找到一个空的结点，存入数据元素
    如何判断结点是否为空？
    可让next为某个特殊值，如-2
  2.从头结点出发找到位序为i-1的结点
  3.修改新结点的next*/

/* 删除某个结点：
   1.从头结点出发找到前驱节点
   2.修改前驱节点的游标
   3.被删除结点的next设为-2 */

//大话数据结构示例
//#define MaxSize 1000
//typedef struct
//{
//	ElemType data;
//	int cur;
//}Component,SLinkList[MaxSize];
//
////将一维数组space中各分量链成一备用链表
////space[0].cur为头指针，"0"表示空指针
//bool InitList(SLinkList space)
//{
//	int i;
//	for (i = 0; i < MaxSize - 1; i++)
//		space[i].cur = i + 1;
//	space[MaxSize - 1].cur = 0;
//	//目前静态链表为空，最后一个元素的cur为0
//	return true;
//}
//
////静态链表的插入与删除
//
///*为了辨明数组中哪些分量未被使用，解决的办法是将所有未被
//使用过的及已被删除的分量用游标链链成一个备用的链表，每当
//进行插入时，便可以从备用链表上取得第一个结点作为待插入的
//新结点*/
//
////若备用空间链表非空，则返回分配的结点下标，否则返回0
//int Malloc_SLL(SLinkList space)
//{
//	int i = space[0].cur;
//	/*当前数组的第一个元素的cur存的值,就是要返回的第一个
//	备用的空闲的下标*/
//	if (space[0].cur)
//		space[0].cur = space[i].cur;
//	/*由于要拿出一个分量来使用了，所以得把它的下一个分量
//	用来做备用*/
//	return i;
//}
//
////在L中第i个元素之前插入新的数据元素e
//bool ListInsert(SLinkList L, int i, ElemType e)
//{
//	int j, k, l;
//	k = MaxSize - 1;//注意k首先是最后一个元素的下标
//	if (i<1 || i>ListLength(L) + 1)
//		return false;
//	j = Malloc_SSL(L);//获得空闲分量的下标
//	if (j)
//	{
//		L[j].data = e;//将数据赋值给此份量的data
//		//找到第i个元素之前的位置
//		for (l = 1; l < i - 1; l++)
//			k = L[k].cur;
//		//把第i个元素之前的cur赋值给新元素的cur
//		L[j].cur = L[k].cur;
//		//把新元素的下标赋值给第i个元素之前元素的cur
//		L[k].cur = j;
//		return true;
//	}
//	return false;
//}
//
////将下标为k的空间结点回收到备用链表
//void Free_SSL(SLinkList space, int k)
//{
//	//把第一个元素cur值赋给要删除的分量cur
//	space[k].cur = space[0].cur;
//	//把要删除的分量下标赋值给第一个元素的cur
//	space[0].cur = k;
//}
//
////删除在L中第i个数据元素e
//bool ListDelete(SLinkList L, int i)
//{
//	int j, k;
//	if (i<1 || i>ListLength(L))
//		return false;
//	k = MaxSize - 1;
//	for (j = 1; j <= i - 1; j++)
//		k = L[k].cur;
//	j = L[k].cur;
//	L[k].cur = L[j].cur;
//	Free_SSL(L, j);
//	return true;
//}
//
///* 初始条件：静态链表L已存在
//   操作结果：返回L中数据元素个数  */
//int ListLength(SLinkList L)
//{
//	int j = 0;
//	int i = L[MaxSize - 1].cur;
//	while (i)
//	{
//		i = L[i].cur;
//		j++;
//	}
//	return j;
//}