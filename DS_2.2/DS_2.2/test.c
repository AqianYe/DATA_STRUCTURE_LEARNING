#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//˳����ʵ�֡�����̬����
//#define MaxSize 10//������󳤶�
//typedef struct
//{
//	int data[MaxSize];//�þ�̬�ġ����顱�������Ԫ��
//	int length;//˳���ĵ�ǰ����
//}SqList;//˳�������Ͷ���
//
////��������������ʼ��һ��˳���
//void InitList(SqList* L)
//{
//	for (int i = 0; i < MaxSize; i++)
//		L->data[i] = 0;//����������Ԫ������ΪĬ�ϳ�ʼֵ
//	L->length = 0;//˳����ʼ����Ϊ0
//}
//
//int main()
//{
//	SqList L;//����һ��˳���
//	InitList(&L);//��ʼ��˳���
//	for (int i = 0; i < MaxSize; i++)
//		printf("data[%d]=%d\n", i, L.data[i]);
//	return 0;
//}

//˳����ʵ�֡�����̬����
//#include<stdlib.h>
//#define InitSize 10//˳���ĳ�ʼ����
//typedef struct
//{
//	int* data;//ָʾ��̬���������ָ��
//	int MaxSize;//˳�����������
//	int length;//˳���ĵ�ǰ����
//}SeqList;//˳�������Ͷ��壨��̬���䷽ʽ��
//
//void InitList(SeqList* L)
//{
//	//��malloc��������һƬ�����Ĵ洢�ռ�
//	L->data = (int*)malloc(InitSize * sizeof(int));
//	L->length = 0;
//	L->MaxSize = InitSize;
//}
//
////���Ӷ�̬����ĳ���
//void IncreaseSize(SeqList* L, int len)
//{
//	int* p = L->data;
//	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
//	for (int i = 0; i < L->length; i++)
//	{
//		L->data[i] = p[i];//�����ݸ��Ƶ�������
//	}
//	L->MaxSize = L->MaxSize + len;
//	//˳�����󳤶�����len
//	free(p);//�ͷ�ԭ�����ڴ�ռ�
//}
//
//int main()
//{
//	SeqList L;//����һ��˳���
//	InitList(&L);//��ʼ��˳���
//	//...��˳����������뼸��Ԫ��...
//	IncreaseSize(&L, 5);
//	return 0;
//}

////˳���Ĳ���
//#define MaxSize 10//������󳤶�
//typedef struct
//{
//	int data[MaxSize];//�þ�̬�ġ����顱�������Ԫ��
//	int length;//˳���ĵ�ǰ����
//}SqList;//˳���Ķ�������
//
//void ListInsert(SqList* L, int i, int e)
//{
//	//����i��Ԫ�ؼ�֮���Ԫ�غ���
//	for (int j = L->length; j >= i; j--)
//		L->data[j] = L->data[j - 1];
//	L->data[i - 1] = e;//��λ��i������e
//	L->length++;//���ȼ�1
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
//	//�ж�i�ķ�Χ�Ƿ���Ч
//	if (i<1 || i>L->length + 1)
//		return 0;
//	//��ǰ�洢�ռ����������ܲ���
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
//	SqList L;//����һ��˳���
//	InitList(&L);//��ʼ��˳���
//	//...�˴�ʡ��һЩ���룬���뼸��Ԫ��
//	ListInsert(&L, 3, 3);
//	return 0;
//}

//˳���Ļ���������������
//#define MaxSize 10//������󳤶�
//typedef struct
//{
//	int data[MaxSize];//�þ�̬�ġ����顱�������Ԫ��
//	int length;//˳���ĵ�ǰ����
//}SqList;//˳�������Ͷ���
//
//int ListInsert(SqList* L, int i, int e)
//{
//	int ret = 1;
//	//�ж�i�ķ�Χ�Ƿ���Ч
//	if (i<1 || i>L->length + 1)
//	{
//		ret = 0;
//		return 0;
//	}	
//	//��ǰ�洢�ռ����������ܲ���
//	if (L->length >= MaxSize)
//	{
//		ret = 0;
//		return 0;
//	}	
//	if (ret == 1)
//	{
//		//����i��Ԫ�ؼ�֮���Ԫ�غ���
//		for (int j = L->length; j >= i; j--)
//			L->data[j] = L->data[j - 1];
//		L->data[i - 1] = e;//��λ��i������e
//		L->length++;//���ȼ�1
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
//		printf("λ��i���Ϸ�������ʧ��\n");
//	return 0;
//}

//˳���Ļ������� ����ɾ��
//#define MaxSize 10//������󳤶�
//typedef struct
//{
//	int data[MaxSize];//�þ�̬�ġ����顱�������Ԫ��
//	int length;//˳���ĵ�ǰ����
//}SqList;//˳�������Ͷ���
//
//int ListDelete(SqList* L, int i, int* p)
//{
//	int ret = 1;
//	//�ж�i�ķ�Χ�Ƿ���Ч
//	if (i<1 || i>L->length)
//	{
//		ret = 0;
//		return 0;
//	}	
//	if (ret == 1)
//	{
//		*p = L->data[i - 1];//����ɾ����Ԫ�ظ�ֵ��e
//		//����i��λ��֮���Ԫ��ǰ��
//		for (int j = i; j < L->length; j++)
//			L->data[j - 1] = L->data[j];
//		L->length--;//���Ա��ȼ�1
//		return 1;
//	}
//}
//
//int main()
//{
//	SqList L = { {1,2,3,4,5},5 };
//	int e = -1;//�ñ���e��ɾ����Ԫ�ء���������
//	int* p = &e;
//	if (ListDelete(&L, 3, p))
//		printf("��ɾ����3��Ԫ�أ�ɾ��Ԫ��ֵΪ%d\n", e);
//	else
//		printf("λ��i���Ϸ���ɾ��ʧ��\n");
//	return 0;
//}

//˳���İ�λ����
//#define MaxSize 10//������󳤶�
//typedef struct
//{
//	int data[MaxSize];//�þ�̬�ġ����顱�������Ԫ��
//	int length;//˳���ĵ�ǰ����
//}SqList;//˳�������Ͷ��壨��̬���䷽ʽ��
//
//int GetElem(SqList L, int i)
//{
//	//�ж�i�ķ�Χ�Ƿ���Ч
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
//		printf("λ��i���Ϸ�������ʧ��\n");
//	else
//		printf("��L�е�4��Ԫ�ص�ֵΪ%d\n", ret);
//	return 0;
//}

//#include<stdlib.h>
//#define InitSize 10//˳���ĳ�ʼ����
//typedef struct
//{
//	int* data;//ָʾ��̬���������ָ��
//	int MaxSize;//˳�����������
//	int length;//˳���ĵ�ǰ����
//}SeqList;//˳�������Ͷ��壨��̬���䷽ʽ��
//
//int GetElem(SeqList L, int i)
//{
//	//�ж�i�ķ�Χ�Ƿ���Ч
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
//		printf("λ��i���Ϸ�������ʧ��\n");
//	else
//		printf("��L�е�%d��Ԫ�ص�ֵΪ%d\n", i, ret);
//	free(L.data);
//	return 0;
//}
//����λԪ�ص�ֵǡ��Ϊ0������δ���

//˳���İ�ֵ����
//#include<stdlib.h>
//#define InitSize 10//˳���ĳ�ʼ����
//typedef struct
//{
//	int* data;//ָʾ��̬���������ָ��
//	int MaxSize;//˳�����������
//	int length;//˳���ĵ�ǰ����
//}SeqList;//˳�������Ͷ��壨��̬���䷽ʽ��
//
////��˳���L�в��ҵ�һ��Ԫ��ֵ����e��Ԫ��
////��������λ��
//int LocateElem(SeqList L, int e)
//{
//	for (int i = 0; i < L.length; i++)
//		if (L.data[i] == e)
//			return i + 1;
//	       //�����±�Ϊi��Ԫ��ֵ����e
//	       //������λ����Ҫ+1
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
//		printf("����ʧ��\n");
//	else
//		printf("��%d��Ԫ�ص�ֵΪ%d\n", ret, e);
//	return 0;
//}