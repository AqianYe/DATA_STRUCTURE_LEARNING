#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//����
//ֻ������һ�˽��в��룬����һ��ɾ�������Ա�

//���еĻ�������

//������
//��InitQueue(&Q)
//��ʼ�����У�����һ���ն���Q
//��DestroyQueue(&Q)
//���ٶ��У����ٲ��ͷŶ���Q��ռ�õ��ڴ�ռ�

//����ɾ
//��EnQueue(&Q, x)
//��ӣ�������Qδ������x���룬ʹ֮��Ϊ�µĶ�β
//��DeQueue(&Q, &x)
//���ӣ�������Q�ǿգ�ɾ����ͷԪ�أ�����x����

//��
//��GetHead(Q, &x)
//����ͷԪ�أ�������Q�ǿգ��򽫶�ͷԪ�ظ�ֵ��x
//���е�ʹ�ó����д��ֻ���ʶ�ͷԪ��

//�������ò���
//QueueEmpty(Q)
//�ж�һ������Q�Ƿ�Ϊ�ա���QΪ���򷵻�true�����򷵻�false

//���е�˳��ʵ��
//#define MaxSize 10//���������Ԫ�ص�������
//typedef struct
//{
//	ElemType data[MaxSize];//�þ�̬�����Ŷ���Ԫ��
//	int front, rear;//��ͷָ��Ͷ�βָ��
//}SqQueue;
//
////��ʼ������
//void InitQueue(SqQueue& Q)
//{
//	//��ʼʱ����ͷ����βָ��ָ��0
//	Q.rear = Q.front = 0;
//}
//
////�ж϶����Ƿ�Ϊ��
//bool QueueEmpty(SqQueue Q)
//{
//	if (Q.rear == Q.front)//�ӿ�����
//		return true;
//	else
//		return false;
//}
//
//void TestQueue()
//{
//	SqQueue Q;//����һ�����У�˳��洢��
//	InitQueue(Q);
//	//...��������...
//}

////����һ������һ����Ԫ�����ֶ����Ͷӿ�
//#define MaxSize 10//���������Ԫ�ص�������
//typedef struct
//{
//	ElemType data[MaxSize];//�þ�̬�����Ŷ���Ԫ��
//	int front, rear;//��ͷָ��Ͷ�βָ��
//}SqQueue;
//
////���
//bool EnQueue(SqQueue& Q, ElemType x)
//{
//	if ((Q.rear + 1) % MaxSize == Q.front);
//		return false;//�����򱨴�
//	Q, data[Q.rear] = x;//��x�����β
//	Q.rear = (Q.rear + 1) % MaxSize;//��βָ���1ȡģ
//	return true;
//}
///*ȡģ���㣬��ȡ�����㡣��������a,b��a%b == a����b����
//����ģ���㽫���޵�������ӳ�䵽���޵���������
//{0, 1, 2, ..., b - 1}�ϣ�ͬ��{0, 1, 2, ..., MaxSize - 1}
//���洢�ռ����߼��ϱ���ˡ���״������ѭ������*/
//
////���ӣ�ɾ��һ����ͷԪ�أ�����x���أ�
//bool DeQueue(SqQueue& Q, ElemType& x)
//{
//	if (Q.rear == Q.front)
//		return false;//�ӿ��򱨴�
//	x = Q.data[Q.front];
//	Q.front = (Q.front + 1) % MaxSize;
//	return true;
//}
//
////��ö�ͷԪ�ص�ֵ����x����
//bool GetHead(SqQueue Q, ElemType& x)
//{
//	if (Q.rear == Q.front)
//		return false;//�ӿ��򱨴�
//	x = Q.data[Q.front];
//	return true;
//}
//
////����Ԫ�ظ�����(rear + MaxSize - front) % MaxSize



////�������������������ʾԪ�ظ��������ݳ�Ա
//#define MaxSize 10
//typedef struct
//{
//	ElemType data[MaxSize];
//	int front, rear;
//	int size;//���е�ǰ����
//}SqQueue;
//
////��ʼ��ʱrear = front = 0
////����ɹ�size++
////ɾ���ɹ�size--
////����������size == MaxSize
////�ӿ�������size == 0



////������������������tag��Ա���������Ƕ������Ƕӿ�
//#define MaxSize 10
//typedef struct
//{
//	ElemType data[MaxSize];
//	int front, rear;
//	int tag;//������е���ɾ��or����
//};
//
////ÿ��ɾ�������ɹ�ʱ������tag = 0
////ÿ�β�������ɹ�ʱ������tag = 1
////��ʼ��ʱ��rear = front = 0��tag = 0
////����������front == rear && tag == 1
////�ӿ�������front == rear && tag == 0



//��rearָ���βԪ�أ���
//���
/*Q.rear = (Q.rear + 1) % MaxSize;
Q.data[Q.rear] = x;*/

//��ʼ��
/*front = 0;
rear = MaxSize - 1;*/

//�п�
/*(Q.rear + 1) % MaxSize == Q.front;*/

//����
//" (Q.rear + 1) % MaxSize == Q.front "�ж�ʧЧ
//����һ������һ���洢��Ԫ��������λ�ã�
//�����������Ӹ�������



////���е���ʽʵ�֣������У�
//typedef struct LinkNode//��ʽ���
//{
//	ElemType data;
//	struct LinkNode* next;
//}LinkNode;
//
//typedef struct//��ʽ����
//{
//	LinkNode* front, * rear;//���еĶ�ͷ�Ͷ�βָ��
//}LinkQueue;
//

////��ʼ������(��ͷ���)
//void InitQueue(LinkQueue& Q)
//{
//	//��ʼʱfront��rear��ָ��ͷ���
//	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
//	Q.front->next = NULL;
//}
//
////�ж϶����Ƿ�Ϊ��(��ͷ���)
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
//	LinkQueue Q;//����һ������
//	InitQueue(Q);//��ʼ������
//	//...��������...
//}



////��ʼ�����У�����ͷ��㣩
//void InitQueue(LinkQueue& Q)
//{
//	//��ʼʱfront��rear��ָ��NULL
//	Q.front = NULL;
//	Q.rear = NULL;
//}
//
////�ж϶����Ƿ�Ϊ�գ�����ͷ��㣩
//bool IsEmpty(LinkQueue Q)
//{
//	if (Q.front == NULL)
//		return true;
//	else
//		return false;
//}



////��Ԫ����ӣ���ͷ��㣩
//void EnQueue(LinkQueue& Q, ElemType x)
//{
//	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
//	s->data = x;
//	s->next = NULL;
//	Q.rear->next = s;//�½����뵽rear֮��
//	Q.rear = s;//�޸ı�βָ��
//}
//
////��Ԫ����ӣ�����ͷ��㣩
////����ͷ���Ķ��У���һ��Ԫ�����ʱ��Ҫ�ر���
//void EnQueue(LinkQueue& Q, ElemType x)
//{
//	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
//	s->data = x;
//	s->next = NULL;
//	if (Q.front == NULL)//�ڿն����в����һ��Ԫ��
//	{
//		//�޸Ķ�ͷ��βָ��
//		Q.front = s;
//		Q.rear = s;
//	}
//	else
//	{
//		Q.rear->next = s;//�½����뵽rear���֮��
//		Q.rear = s;//�޸�rearָ��
//	}
//}
//
////��ͷԪ�س��ӣ���ͷ��㣩
//bool DeQueue(LinkNode& Q, ElemType& x)
//{
//	if (Q, front == Q.rear)
//		return false;//�ն�
//	LinkNode* p = Q.front->next;
//	x = p->data;//�ñ���x���ض�ͷԪ��
//	Q.front->next = p->next;//�޸�ͷ����nextָ��
//	if (Q.rear == p)//�˴������һ��������
//		Q.rear = Q.front;//�޸�rearָ��
//	free(p);//�ͷŽ��ռ�
//	return true;
//}
//
////��ͷԪ�س��ӣ�����ͷ��㣩
//bool DeQueue(LinkQueue& Q, ElemType& x)
//{
//	if (Q.front = NULL)
//		return false;//�ն�
//	LinkNode* p = Q.front;//pָ��˴γ��ӵĽ��
//	x = p->data;//�ñ���x���ض�ͷԪ��
//	Q.front = p->next;//�޸�frontָ��
//	if (Q.rear == p)//�˴������һ��������
//	{
//		Q.front = NULL;//frontָ��NULL
//		Q.rear = NULL;//rearָ��NULL
//	}
//	free(p);//�ͷŽ��ռ�
//	return true;
//}

//������������
/*
˳��洢����Ԥ����Ŀռ�ľ�ʱ����
��ʽ�洢����һ�㲻������������ڴ治��
*/



//˫�˶���
/*
ջ��ֻ�����һ�˲����ɾ�������Ա�
���У�ֻ�����һ�˲��롢��һ��ɾ�������Ա�
˫�˶��У�ֻ��������˲��롢����ɾ�������Ա�
*/

//˫�˶�����ֻʹ������һ�˵Ĳ��롢ɾ����������Ч����ͬ��ջ

/*
�������޵�˫�˶��У�ֻ�����һ�˲��롢����ɾ�������Ա�
������޵�˫�˶��У�ֻ��������˲��롢һ��ɾ�������Ա�
*/