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

typedef struct LNode//单链表的结构定义 
{        
	int data;//定义int类型的数据域 
	struct LNode* next;//定义指针域 
}LNode, * LinkList;

//初始化单链表 并设置为空表
LNode* InitList(LNode* L)
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	//使头结点的指针域为空，建立一个空的单链表 
	return L;
}

//利用头插法建立单链表
void List_HeadInsert(LNode* L)
{
	LNode* p;
	//新建一个结点指针,永远指向当前链表的头结点
	int i;
	scanf_s("%d", &i);
	//输入i，用于指代输入的整数，将要放进链表的数据元素
	//也用来控制while循环，当输入i的值为9999时结束
	while (i != 9999) 
	{
		p = (LNode*)malloc(sizeof(LNode));//新建一个结点
		p->data = i;//把输入的值赋值给新结点的指针域
		p->next = L->next;//把新结点插入到表头
		L->next = p;//头结点要始终放在最前面
		scanf_s("%d", &i);
	}
}

//利用尾插法建立单链表
void List_TailInsert(LNode* L)
{
	LNode* r;
	//建立一个尾指针，始终指向当前链表的尾结点
	int i;//i用于指代输入的整数，将要放进链表的数据元素
	//也用来控制while循环，当输入i的值为9999时结束
	r = L;
	//令尾指针r指向头结点L，便于做尾插入 
	scanf_s("%d", &i);//输入插入的整数
	while (i != 9999)
	{
		LNode* p = (LNode*)malloc(sizeof(LNode));
		//建立一个新结点，用于存储数据元素
		p->data = i;
		r->next = p;
		r = p;
		scanf_s("%d", &i);
	}
	r->next = NULL;
}

//单链表打印
void ListPrint(LNode* L) 
{ 
	printf("该链表的内容为：");
	while (L->next != NULL)
	{
		printf("%d ", L->next->data);
		L = L->next;
	}
	printf("\n");
}

//单链表逆置
void ListReverse(LNode* L)
{
	LNode* p, * r;
	p = L->next;
	L->next = NULL;
	while (p != NULL)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	return L;
}

int main() 
{
	LNode* L = NULL;
	L = InitList(L);
	printf("单链表已初始化\n");
	printf("用尾插法插入链表L：\n");
	List_TailInsert(L);
	ListPrint(L);
	printf("逆置此单链表\n");
	ListReverse(L);
	ListPrint(L);
	return 0;
}