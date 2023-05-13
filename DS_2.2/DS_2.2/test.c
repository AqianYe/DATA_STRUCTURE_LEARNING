#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//顺序表的实现——静态分配
//#define MaxSize 10//定义最大长度
//typedef struct
//{
//	int data[MaxSize];//用静态的“数组”存放数据元素
//	int length;//顺序表的当前长度
//}SqList;//顺序表的类型定义
//
////基本操作——初始化一个顺序表
//void InitList(SqList* L)
//{
//	for (int i = 0; i < MaxSize; i++)
//		L->data[i] = 0;//将所有数据元素设置为默认初始值
//	L->length = 0;//顺序表初始长度为0
//}
//
//int main()
//{
//	SqList L;//声明一个顺序表
//	InitList(&L);//初始化顺序表
//	for (int i = 0; i < MaxSize; i++)
//		printf("data[%d]=%d\n", i, L.data[i]);
//	return 0;
//}

//顺序表的实现——动态分配
//#include<stdlib.h>
//#define InitSize 10//顺序表的初始长度
//typedef struct
//{
//	int* data;//指示动态分配数组的指针
//	int MaxSize;//顺序表的最大容量
//	int length;//顺序表的当前长度
//}SeqList;//顺序表的类型定义（动态分配方式）
//
//void InitList(SeqList* L)
//{
//	//用malloc函数申请一片连续的存储空间
//	L->data = (int*)malloc(InitSize * sizeof(int));
//	L->length = 0;
//	L->MaxSize = InitSize;
//}
//
////增加动态数组的长度
//void IncreaseSize(SeqList* L, int len)
//{
//	int* p = L->data;
//	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
//	for (int i = 0; i < L->length; i++)
//	{
//		L->data[i] = p[i];//将数据复制到新区域
//	}
//	L->MaxSize = L->MaxSize + len;
//	//顺序表最大长度增加len
//	free(p);//释放原来的内存空间
//}
//
//int main()
//{
//	SeqList L;//声明一个顺序表
//	InitList(&L);//初始化顺序表
//	//...往顺序表中随便插入几个元素...
//	IncreaseSize(&L, 5);
//	return 0;
//}

////顺序表的插入
//#define MaxSize 10//定义最大长度
//typedef struct
//{
//	int data[MaxSize];//用静态的“数组”存放数据元素
//	int length;//顺序表的当前长度
//}SqList;//顺序表的定义类型
//
//void ListInsert(SqList* L, int i, int e)
//{
//	//将第i个元素及之后的元素后移
//	for (int j = L->length; j >= i; j--)
//		L->data[j] = L->data[j - 1];
//	L->data[i - 1] = e;//在位置i处放入e
//	L->length++;//长度加1
//}
//
//void InitList(SqList* L)
//{
//	for (int i = 0; i < MaxSize; i++)
//		L->data[i] = 0;
//	int length = 0;
//}
//
//int ListInsert(SqList* L, int i, int e)
//{
//	//判断i的范围是否有效
//	if (i<1 || i>L->length + 1)
//		return 0;
//	//当前存储空间已满，不能插入
//	if (L->length >= MaxSize)
//		return 0;
//	for (int j = L->length; j >= i; j--)
//		L->data[j] = L->data[j - 1];
//	L->data[i - 1] = e;
//	L->length++;
//	return 1;
//}
//
//int main()
//{
//	SqList L;//声明一个顺序表
//	InitList(&L);//初始化顺序表
//	//...此处省略一些代码，插入几个元素
//	ListInsert(&L, 3, 3);
//	return 0;
//}

//顺序表的基本操作——插入
//#define MaxSize 10//定义最大长度
//typedef struct
//{
//	int data[MaxSize];//用静态的“数组”存放数据元素
//	int length;//顺序表的当前长度
//}SqList;//顺序表的类型定义
//
//int ListInsert(SqList* L, int i, int e)
//{
//	int ret = 1;
//	//判断i的范围是否有效
//	if (i<1 || i>L->length + 1)
//	{
//		ret = 0;
//		return 0;
//	}	
//	//当前存储空间已满，不能插入
//	if (L->length >= MaxSize)
//	{
//		ret = 0;
//		return 0;
//	}	
//	if (ret == 1)
//	{
//		//将第i个元素及之后的元素后移
//		for (int j = L->length; j >= i; j--)
//			L->data[j] = L->data[j - 1];
//		L->data[i - 1] = e;//在位置i处放入e
//		L->length++;//长度加1
//		return 1;
//	}
//}
//
//int main()
//{
//	SqList L = { {1,3,4,5},4 };
//	if (ListInsert(&L, 6, 2))
//	{
//		for (int i = 0; i < L.length; i++)
//		{
//			printf("data[%d] = %d\n", i, L.data[i]);
//		}
//	}
//	else
//		printf("位序i不合法，插入失败\n");
//	return 0;
//}

//顺序表的基本操作 ——删除
//#define MaxSize 10//定义最大长度
//typedef struct
//{
//	int data[MaxSize];//用静态的“数组”存放数据元素
//	int length;//顺序表的当前长度
//}SqList;//顺序表的类型定义
//
//int ListDelete(SqList* L, int i, int* p)
//{
//	int ret = 1;
//	//判断i的范围是否有效
//	if (i<1 || i>L->length)
//	{
//		ret = 0;
//		return 0;
//	}	
//	if (ret == 1)
//	{
//		*p = L->data[i - 1];//将被删除的元素赋值给e
//		//将第i个位置之后的元素前移
//		for (int j = i; j < L->length; j++)
//			L->data[j - 1] = L->data[j];
//		L->length--;//线性表长度减1
//		return 1;
//	}
//}
//
//int main()
//{
//	SqList L = { {1,2,3,4,5},5 };
//	int e = -1;//用变量e把删除的元素“带回来”
//	int* p = &e;
//	if (ListDelete(&L, 3, p))
//		printf("已删除第3个元素，删除元素值为%d\n", e);
//	else
//		printf("位序i不合法，删除失败\n");
//	return 0;
//}

//顺序表的按位查找
//#define MaxSize 10//定义最大长度
//typedef struct
//{
//	int data[MaxSize];//用静态的“数组”存放数据元素
//	int length;//顺序表的当前长度
//}SqList;//顺序表的类型定义（静态分配方式）
//
//int GetElem(SqList L, int i)
//{
//	//判断i的范围是否有效
//	if (i<1 || i>L.length)
//		return 0;
//	return L.data[i - 1];
//}
//
//int main()
//{
//	SqList L = { {1,2,3,4,5},5 };
//	int ret = GetElem(L, 4);
//	if (ret == 0)
//		printf("位序i不合法，查找失败\n");
//	else
//		printf("表L中第4个元素的值为%d\n", ret);
//	return 0;
//}

//#include<stdlib.h>
//#define InitSize 10//顺序表的初始长度
//typedef struct
//{
//	int* data;//指示动态分配数组的指针
//	int MaxSize;//顺序表的最大容量
//	int length;//顺序表的当前长度
//}SeqList;//顺序表的类型定义（动态分配方式）
//
//int GetElem(SeqList L, int i)
//{
//	//判断i的范围是否有效
//	if (i<1 || i>L.length)
//		return 0;
//	return L.data[i - 1];
//}
//
//int main()
//{
//	SeqList L;
//	L.data = (int*)malloc(InitSize * sizeof(int));
//	L.MaxSize = InitSize;
//	L.length = 5;
//	for (int j = 0; j < 5; j++)
//	{
//		scanf("%d", &L.data[j]);
//	}
//	int i = 0;
//	scanf("%d", &i);
//	int ret = GetElem(L, i);
//	if (ret == 0)
//		printf("位序i不合法，查找失败\n");
//	else
//		printf("表L中第%d个元素的值为%d\n", i, ret);
//	free(L.data);
//	return 0;
//}
//若该位元素的值恰好为0，该如何处理？

//顺序表的按值查找
//#include<stdlib.h>
//#define InitSize 10//顺序表的初始长度
//typedef struct
//{
//	int* data;//指示动态分配数组的指针
//	int MaxSize;//顺序表的最大容量
//	int length;//顺序表的当前长度
//}SeqList;//顺序表的类型定义（动态分配方式）
//
////在顺序表L中查找第一个元素值等于e的元素
////并返回其位序
//int LocateElem(SeqList L, int e)
//{
//	for (int i = 0; i < L.length; i++)
//		if (L.data[i] == e)
//			return i + 1;
//	       //数组下标为i的元素值等于e
//	       //返回其位序需要+1
//	return 0;
//}
//
//int main()
//{
//	SeqList L;
//	L.data = (int*)malloc(InitSize * sizeof(int));
//	L.MaxSize = InitSize;
//	L.length = 5;
//	for (int j = 0; j < L.length; j++)
//	{
//		scanf_s("%d", &L.data[j]);
//	}
//	int e = 0;
//	scanf_s("%d", &e);
//	int ret = LocateElem(L, e);
//	if (ret == 0)
//		printf("查找失败\n");
//	else
//		printf("第%d个元素的值为%d\n", ret, e);
//	return 0;
//}