#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//ջ�Ļ�������

//������
//��InitStack(&S)
//��ʼ��ջ������һ����ջS���������ڴ�ռ�
//��DestroyStack(&L) 
//����ջ�����ٲ��ͷ�ջS��ռ�õ��ڴ�ռ�

//����ɾ
//��Push(&S, x)
//��ջ����ջSδ������x����ʹ֮��Ϊ��ջ��
//��Pop(&S, &x)
//��ջ����ջS�ǿգ�����x����ջ��Ԫ�أ�ɾ��ջ��Ԫ�أ�

//��
//��GetTop(S, &x)
//��ջ��Ԫ�ء���ջS�ǿգ�����x����ջ��Ԫ��

//�������ò���
//StackEmpty(S)
//�ж�һ��ջS�Ƿ�Ϊ�ա���SΪ�գ��򷵻�true�����򷵻�false

//˳��ջ�Ķ���
//#define MaxSize 10//����ջ��Ԫ�ص�������
//typedef struct
//{
//	ElemType data[MaxSize];//��̬������ջ��Ԫ��
//	int top;//ջ��ָ��
//}SqStack;
//
////��ʼ��ջ
//void InitStack(SqStack& S)
//{
//	S.top = -1;//��ʼ��ջ��ָ��
//}
//
////�ж�ջ��
//bool StackEmpty(SqStack S)
//{
//	if (S.top == -1)//ջ��
//		return true;
//	else//����
//		return false;
//}
//
//void TestStack()
//{
//	SqStack S;//����һ��˳��ջ������ռ䣩
//	//...��������...
//}
//
////��Ԫ����ջ
//bool Push(SqStack& S, ElemType x)
//{
//	if (S.top == MaxSize - 1)//ջ��������
//		return false;
//	S.top = S.top + 1;//ָ���ȼ�1
//	S.data[S.top] = x;//��Ԫ����ջ
//	//S.data[++S.top] = x;
//	return true;
//}
//
////��ջ����
////���ݻ��������ڴ��У�ֻ���߼���ɾ����
//bool Pop(SqStack& S, ElemType& x)
//{
//	if (S.top == -1)//ջ�գ�����
//		return false;
//	x = S.data[S.top];//ջ��Ԫ���ȳ�ջ
//	S.top = S.top - 1;//ָ���ټ�1
//	//x = S.data[S.top--];
//	return true;
//}

////����ջ������ջ����ͬһƬ�ռ�
//#define MaxSize 10//����ջ��Ԫ�ص�������
//typedef struct
//{
//	ElemType data[MaxSize];//��̬������ջ��Ԫ��
//	int top0;//0��ջջ��ָ��
//	int top1;//1��ջջ��ָ��
//}ShStack;
//
////��ʼ��ջ
//void InitStack(ShStack& S)
//{
//	//��ʼ��ջ��ָ��
//	S.top0 = -1;
//	S.top1 = MaxSize;	
//}
////ջ����������top0 + 1 == top1;

////��ջ�Ķ���
//typedef struct LinkNode
//{
//	ElemType data;//������
//	struct LinkNode* next;//ָ����
//}*LiStack;//ջ���Ͷ���
//
////��ջ�Ļ�������
//
////����ͷ���
////��ջ�ĳ�ʼ��
//bool InitLiStack(LiStack& S)
//{
//	S = NULL;//��ջ����ʱ��û���κν��
//	return true;
//}
//
////�ж�ջ��1
//bool LiStackEmpty(LiStack S)
//{
//	if (S == NULL)
//		return true;
//	else
//		return false;
//}
//
////�ж�ջ��2
//bool LiStackEmpty(LiStack S)
//{
//	return(S == NULL);
//}