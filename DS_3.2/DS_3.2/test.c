#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//队列
//只允许在一端进行插入，在另一端删除的线性表

//队列的基本操作

//创、销
//①InitQueue(&Q)
//初始化队列，构造一个空队列Q
//②DestroyQueue(&Q)
//销毁队列，销毁并释放队列Q所占用的内存空间

//增、删
//③EnQueue(&Q, x)
//入队，若队列Q未满，将x加入，使之成为新的队尾
//④DeQueue(&Q, &x)
//出队，若队列Q非空，删除队头元素，并用x返回

//查
//⑤GetHead(Q, &x)
//读队头元素，若队列Q非空，则将队头元素赋值给x
//队列的使用场景中大多只访问队头元素

//其他常用操作
//QueueEmpty(Q)
//判断一个队列Q是否为空。若Q为空则返回true，否则返回false

//队列的顺序实现
//#define MaxSize 10//定义队列中元素的最大个数
//typedef struct
//{
//	ElemType data[MaxSize];//用静态数组存放队列元素
//	int front, rear;//队头指针和队尾指针
//}SqQueue;
//
////初始化队列
//void InitQueue(SqQueue& Q)
//{
//	//初始时，队头、队尾指针指向0
//	Q.rear = Q.front = 0;
//}
//
////判断队列是否为空
//bool QueueEmpty(SqQueue Q)
//{
//	if (Q.rear == Q.front)//队空条件
//		return true;
//	else
//		return false;
//}
//
//void TestQueue()
//{
//	SqQueue Q;//声明一个队列（顺序存储）
//	InitQueue(Q);
//	//...后续操作...
//}

////方案一：牺牲一个单元来区分队满和队空
//#define MaxSize 10//定义队列中元素的最大个数
//typedef struct
//{
//	ElemType data[MaxSize];//用静态数组存放队列元素
//	int front, rear;//队头指针和队尾指针
//}SqQueue;
//
////入队
//bool EnQueue(SqQueue& Q, ElemType x)
//{
//	if ((Q.rear + 1) % MaxSize == Q.front);
//		return false;//队满则报错
//	Q, data[Q.rear] = x;//将x插入队尾
//	Q.rear = (Q.rear + 1) % MaxSize;//队尾指针加1取模
//	return true;
//}
///*取模运算，即取余运算。两个整数a,b，a%b == a除以b的余
//数，模运算将无限的整数域映射到有限的整数集合
//{0, 1, 2, ..., b - 1}上，同理，{0, 1, 2, ..., MaxSize - 1}
//将存储空间在逻辑上变成了“环状”，即循环队列*/
//
////出队（删除一个队头元素，并用x返回）
//bool DeQueue(SqQueue& Q, ElemType& x)
//{
//	if (Q.rear == Q.front)
//		return false;//队空则报错
//	x = Q.data[Q.front];
//	Q.front = (Q.front + 1) % MaxSize;
//	return true;
//}
//
////获得队头元素的值，用x返回
//bool GetHead(SqQueue Q, ElemType& x)
//{
//	if (Q.rear == Q.front)
//		return false;//队空则报错
//	x = Q.data[Q.front];
//	return true;
//}
//
////队列元素个数：(rear + MaxSize - front) % MaxSize



////方案二：类型中增设表示元素个数的数据成员
//#define MaxSize 10
//typedef struct
//{
//	ElemType data[MaxSize];
//	int front, rear;
//	int size;//队列当前长度
//}SqQueue;
//
////初始化时rear = front = 0
////插入成功size++
////删除成功size--
////队满条件：size == MaxSize
////队空条件：size == 0



////方案三：类型中增设tag成员，以区分是队满还是队空
//#define MaxSize 10
//typedef struct
//{
//	ElemType data[MaxSize];
//	int front, rear;
//	int tag;//最近进行的是删除or插入
//};
//
////每次删除操作成功时，都令tag = 0
////每次插入操作成功时，都令tag = 1
////初始化时，rear = front = 0，tag = 0
////队满条件：front == rear && tag == 1
////队空条件：front == rear && tag == 0



//若rear指向队尾元素，则
//入队
/*Q.rear = (Q.rear + 1) % MaxSize;
Q.data[Q.rear] = x;*/

//初始化
/*front = 0;
rear = MaxSize - 1;*/

//判空
/*(Q.rear + 1) % MaxSize == Q.front;*/

//判满
//" (Q.rear + 1) % MaxSize == Q.front "判断失效
//方案一：牺牲一个存储单元（差两个位置）
//方案二：增加辅助变量



////队列的链式实现（链队列）
//typedef struct LinkNode//链式结点
//{
//	ElemType data;
//	struct LinkNode* next;
//}LinkNode;
//
//typedef struct//链式队列
//{
//	LinkNode* front, * rear;//队列的队头和队尾指针
//}LinkQueue;
//

////初始化队列(带头结点)
//void InitQueue(LinkQueue& Q)
//{
//	//初始时front、rear都指向头结点
//	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
//	Q.front->next = NULL;
//}
//
////判断队列是否为空(带头结点)
//bool IsEmpty(LinkQueue Q)
//{
//	if (Q.front == Q.rear)
//	//if(Q.front->next == NULL)
//		return true;
//	else
//		return false;
//}
//
//void TestLinkQueue()
//{
//	LinkQueue Q;//声明一个队列
//	InitQueue(Q);//初始化队列
//	//...后续操作...
//}



////初始化队列（不带头结点）
//void InitQueue(LinkQueue& Q)
//{
//	//初始时front、rear都指向NULL
//	Q.front = NULL;
//	Q.rear = NULL;
//}
//
////判断队列是否为空（不带头结点）
//bool IsEmpty(LinkQueue Q)
//{
//	if (Q.front == NULL)
//		return true;
//	else
//		return false;
//}



////新元素入队（带头结点）
//void EnQueue(LinkQueue& Q, ElemType x)
//{
//	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
//	s->data = x;
//	s->next = NULL;
//	Q.rear->next = s;//新结点插入到rear之后
//	Q.rear = s;//修改表尾指针
//}
//
////新元素入队（不带头结点）
////不带头结点的队列，第一个元素入队时需要特别处理
//void EnQueue(LinkQueue& Q, ElemType x)
//{
//	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
//	s->data = x;
//	s->next = NULL;
//	if (Q.front == NULL)//在空队列中插入第一个元素
//	{
//		//修改队头队尾指针
//		Q.front = s;
//		Q.rear = s;
//	}
//	else
//	{
//		Q.rear->next = s;//新结点插入到rear结点之后
//		Q.rear = s;//修改rear指针
//	}
//}
//
////队头元素出队（带头结点）
//bool DeQueue(LinkNode& Q, ElemType& x)
//{
//	if (Q, front == Q.rear)
//		return false;//空队
//	LinkNode* p = Q.front->next;
//	x = p->data;//用变量x返回队头元素
//	Q.front->next = p->next;//修改头结点的next指针
//	if (Q.rear == p)//此次是最后一个结点出队
//		Q.rear = Q.front;//修改rear指针
//	free(p);//释放结点空间
//	return true;
//}
//
////队头元素出队（不带头结点）
//bool DeQueue(LinkQueue& Q, ElemType& x)
//{
//	if (Q.front = NULL)
//		return false;//空队
//	LinkNode* p = Q.front;//p指向此次出队的结点
//	x = p->data;//用变量x返回队头元素
//	Q.front = p->next;//修改front指针
//	if (Q.rear == p)//此次是最后一个结点出队
//	{
//		Q.front = NULL;//front指向NULL
//		Q.rear = NULL;//rear指向NULL
//	}
//	free(p);//释放结点空间
//	return true;
//}

//队列满的条件
/*
顺序存储——预分配的空间耗尽时队满
链式存储——一般不会队满，除非内存不足
*/



//双端队列
/*
栈：只允许从一端插入和删除的线性表
队列：只允许从一端插入、另一端删除的线性表
双端队列：只允许从两端插入、两端删除的线性表
*/

//双端队列若只使用其中一端的插入、删除操作，则效果等同于栈

/*
输入受限的双端队列：只允许从一端插入、两端删除的线性表
输出受限的双端队列：只允许从两端插入、一段删除的线性表
*/