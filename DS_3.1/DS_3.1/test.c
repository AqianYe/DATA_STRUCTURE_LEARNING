#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//栈的基本操作

//创、销
//①InitStack(&S)
//初始化栈。构造一个空栈S，并分配内存空间
//②DestroyStack(&L) 
//销毁栈。销毁并释放栈S所占用的内存空间

//增、删
//③Push(&S, x)
//进栈，若栈S未满，则将x加入使之成为新栈顶
//④Pop(&S, &x)
//出栈，若栈S非空，则用x返回栈顶元素（删除栈顶元素）

//查
//⑤GetTop(S, &x)
//读栈顶元素。若栈S非空，则用x返回栈顶元素

//其他常用操作
//StackEmpty(S)
//判断一个栈S是否为空。若S为空，则返回true，否则返回false

//顺序栈的定义
//#define MaxSize 10//定义栈中元素的最大个数
//typedef struct
//{
//	ElemType data[MaxSize];//静态数组存放栈中元素
//	int top;//栈顶指针
//}SqStack;
//
////初始化栈
//void InitStack(SqStack& S)
//{
//	S.top = -1;//初始化栈顶指针
//}
//
////判断栈空
//bool StackEmpty(SqStack S)
//{
//	if (S.top == -1)//栈空
//		return true;
//	else//不空
//		return false;
//}
//
//void TestStack()
//{
//	SqStack S;//声明一个顺序栈（分配空间）
//	//...后续操作...
//}
//
////新元素入栈
//bool Push(SqStack& S, ElemType x)
//{
//	if (S.top == MaxSize - 1)//栈满，报错
//		return false;
//	S.top = S.top + 1;//指针先加1
//	S.data[S.top] = x;//新元素入栈
//	//S.data[++S.top] = x;
//	return true;
//}
//
////出栈操作
////数据还残留在内存中，只是逻辑上删除了
//bool Pop(SqStack& S, ElemType& x)
//{
//	if (S.top == -1)//栈空，报错
//		return false;
//	x = S.data[S.top];//栈顶元素先出栈
//	S.top = S.top - 1;//指针再减1
//	//x = S.data[S.top--];
//	return true;
//}

////共享栈：两个栈共享同一片空间
//#define MaxSize 10//定义栈中元素的最大个数
//typedef struct
//{
//	ElemType data[MaxSize];//静态数组存放栈中元素
//	int top0;//0号栈栈顶指针
//	int top1;//1号栈栈顶指针
//}ShStack;
//
////初始化栈
//void InitStack(ShStack& S)
//{
//	//初始化栈顶指针
//	S.top0 = -1;
//	S.top1 = MaxSize;	
//}
////栈满的条件：top0 + 1 == top1;

////链栈的定义
//typedef struct LinkNode
//{
//	ElemType data;//数据域
//	struct LinkNode* next;//指针域
//}*LiStack;//栈类型定义
//
////链栈的基本操作
//
////不带头结点
////链栈的初始化
//bool InitLiStack(LiStack& S)
//{
//	S = NULL;//空栈，暂时还没有任何结点
//	return true;
//}
//
////判断栈空1
//bool LiStackEmpty(LiStack S)
//{
//	if (S == NULL)
//		return true;
//	else
//		return false;
//}
//
////判断栈空2
//bool LiStackEmpty(LiStack S)
//{
//	return(S == NULL);
//}