#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//������Ķ���
//typedef struct LNode//���嵥����ṹ����
//{
//	ElemType data;//ÿ���ڵ���һ������Ԫ��
//	struct LNode* next;//ָ��ָ����һ�����
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
//ǿ������һ����������ʹ��LinkList
//ǿ������һ����㡪��ʹ��LNode*

//��ʼ��һ���յĵ�����
//bool InitList(LinkList& L)
//{
//	L = NULL;//�ձ���ʱ��û���κν�㣬��ֹ������
//	return true;
//}

//void test()
//{
//	LinkList L;//����һ��ָ�������ָ��
//	//�˴���û�д���һ�����
//	InitList(L);//��ʼ��һ���ձ�
//}

//��ʼ��һ����������ͷ��㣩
//bool InitList(LinkList& L)
//{
//	L = (LNode*)malloc(sizeof(LNode));//����һ��ͷ���
//	if (L == NULL)
//		return false;
//	L->next = NULL;//ͷ���֮����ʱ��û�н��
//	return true;
//}

//������Ĳ���
//�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩
//bool ListInsert(LinkList& L, int i, ElemType e)
//{
//	if (n < 1)
//		return false;
//	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
//	int j = 0;//��ǰpָ����ǵڼ������
//	p = L;//Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
//	while (p != NULL && j < i - 1)//ѭ���ҵ���i-1�����
//	{
//		p = p->Next;
//		j++;
//	}
//	if (p == NULL)
//		return false;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;//�����s����p֮��
//	return true;//����ɹ�
//}

//�ڵ�i��λ�ò���Ԫ��e������ͷ��㣩
//bool ListInsert(LinkList& L, int i, ElemType e)
//{
//	if (i < 1)
//		return false;
//	if (i == 1)//�����1�����Ĳ�����������������ͬ
//	{
//		LNode* s = (LNode*)malloc(sizeof(LNode));
//		s->data = e;
//		s->next = L;
//		L = s;//ͷָ��ָ���½��
//		return true;
//	}
//	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
//	int j = 1;//��ǰpָ����ǵڼ������
//	p = L;//pָ���1����㣨ע�⣺����ͷ��㣩
//	while (p != NULL && j < i - 1)//ѭ���ҵ���i-1�����
//	{
//		p = p->next;
//		j++;
//	}
//	if (p == NULL)//iֵ���Ϸ�
//		return false;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	s->data = e;
//	s - next = p->next;
//	p->next = s;
//	return true;//����ɹ�
//}

//ָ�����ĺ���������p���֮�����Ԫ��e
//bool InsertNextNode(LNode* p; ElemType e)
//{
//	if (p == NULL)
//		return false;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	if (s == NULL)//�ڴ����ʧ��
//		return false;
//	s->data = e;//�ý��s��������Ԫ��e
//	s->next = p->next;
//	p->next = s;//�����s����p֮��
//	return true;
//}

//ָ������ǰ���������p���֮ǰ����Ԫ��e
//bool InsertPriorNode(LNode* p, ElemType e)
//{
//	if (p = NULL)
//		return false;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	if (s == NULL)//�ڴ����ʧ��
//		return false;
//	s->next = p->next;
//	p->next = s;//�½��s����p֮��
//	s->data = p->data;//��p��Ԫ�ظ��Ƶ�s��
//	p->data = e;//p��Ԫ�ظ���Ϊe
//	return true;
//}

//��λ��ɾ������ͷ��㣩
//bool ListDelete(LinkList& L, int i, ElemType& e)
//{
//	if (i < 1)
//		return false;
//	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
//	int j = 0;//��ǰpָ����ǵڼ������
//	p = L;//Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
//	while (p != NULL && j < i - 1)//ѭ���ҵ���i-1�����
//	{
//		p = p->next;
//		j++;
//	}
//	if (p == NULL)//iֵ���Ϸ�
//		return false;
//	if (p->next = NULL)//��i-1�����֮�������������
//		return false;
//	LNode* q = p->next;//��qָ��ɾ�����
//	e = q->data;//��e����Ԫ�ص�ֵ
//	p->next = q->next;//��*q�������С��Ͽ���
//	free(q);//�ͷŽ��Ĵ洢�ռ�
//	return true;//ɾ���ɹ�
//}

//ɾ��ָ�����p
//bool DeleteNode(LNode* p)
//{
//	if (p == NULL)
//		return false;
//	LNode* q = p->next;//��qָ��*p�ĺ�̽��
//	p->data = p->next->data;//�ͺ�̽�㽻��������
//	p->next = q->next;//��*q�������С��Ͽ���
//	free(q);//�ͷź�̽��Ĵ洢�ռ�
//	return true;
//}

//��λ���ң����ص�i��Ԫ�أ���ͷ��㣩
//LNode* GetElem(LinkList L, int i)
//{
//	if (i < 0)
//		return NULL;
//	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
//	int j = 0;//��ǰpָ����ǵڼ������
//	p = L;//Lָ��ͷ�ڵ㣬ͷ����ǵ�0����㣨�������ݣ�
//	while (p != NULL && j < i)//ѭ���ҵ���i�����
//	{
//		p = p->next;
//		j++;
//	}
//	return p;
//}

//��ֵ���ң��ҵ�������==e�Ľ��
//LNode* LocateElem(LinkList L, ElemType e)
//{
//	LNode* p = L->next;
//	//�ӵ�1����㿪ʼ����������Ϊe�Ľ��
//	while (p != NULL && p->data != e)
//		p = p->next;
//	return p;//�ҵ�֮�󷵻ظý�㣬���򷵻�NULL
//}

//���ĳ���
//int Length(LinkList L)
//{
//	int len = 0;//ͳ�Ʊ�
//	LNode* p = L;
//	while (p->next != NULL)
//	{
//		p = p->next;
//		len++;
//	}
//	return len;
//}

//β�巨����������
//typedef struct LNode//���嵥����������
//{
//	ElemType data;//ÿ�������һ������Ԫ��
//	struct LNode* next;//ָ��ָ����һ�����
//}LNode,*LinkList;
//
////��ʼ��һ����������ͷ��㣩
//bool InitList(LinkList& L)
//{
//	L = (LNode*)malloc(sizeof(LNode));//����һ��ͷ���
//	if (L == NULL)//�ڴ治�㣬����ʧ��
//		return false;
//	L->next = NULL;//ͷ���֮����ʱ��û�н��
//	return true;
//}
//
//void test()
//{
//	LinkList L;//����һ��ָ�������ָ��
//	InitList(L);//��ʼ��һ���ձ�
//}

////�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩
//bool ListInsert(LinkList& L, int i, ElemType e)
//{
//	if (i < 1)
//		return false;
//	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
//	int j = 0;//��ǰpָ����ǵڼ������
//	p = L;//Lָ��ͷ�ڵ㣬ͷ����ǵ�0����㣨�������ݣ�
//	while (p != NULL && j < i - 1)//ѭ���ҵ���i-1�����
//	{
//		p = p->next;
//		j++;
//	}
//	if (p == NULL)//iֵ���Ϸ�
//		return false;
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;//�����s����p֮��
//	return true;//����ɹ�
//}

//������������
//LinkList List_TailInsert(LinkList& L)
//{
//	int x;//��ElemTypeΪ����
//	L = (LinkList)malloc(sizeof(LNode));//����ͷ���
//	LNode* s, * r = L;//rΪ��βָ��
//	scanf("%d", &x);//�������ֵ
//	while (x != 9999)//����9999��ʾ����
//	{
//		s = (LNode*)malloc(sizeof(LNode));
//		s->data = x;
//		r->next = s;
//		r = s;//rָ���µı�β���
//		scanf("%d", &x);
//	}
//	r->next = NULL;//β���ָ���ÿ�
//	return L;
//}

//������������
//LinkList List_HeadInsert(LinkList& L)
//{
//	LNode* s;
//	int x;
//	L = (LinkList)malloc(sizeof(LNode));//����ͷ���
//	L->next = NULL;//��ʼΪ������
//	scanf("%d", &x);//�������ֵ
//	while (x != 9999)//����9999��ʾ����
//	{
//		s = (LNode*)malloc(sizeof(LNode));//�����½��
//		s->data = x;
//		s->next = L->next;
//		L->next = s;//���½�������У�LΪͷָ��
//		scanf("%d", &x);
//	}
//	return L;
//}

//typedef struct LNode//������Ľṹ���� 
//{        
//	int data;//����int���͵������� 
//	struct LNode* next;//����ָ���� 
//}LNode, * LinkList;
//
////��ʼ�������� ������Ϊ�ձ�
//LNode* InitList(LNode* L)
//{
//	L = (LNode*)malloc(sizeof(LNode));
//	L->next = NULL;
//	//ʹͷ����ָ����Ϊ�գ�����һ���յĵ����� 
//	return L;
//}
//
////����ͷ�巨����������
//void List_HeadInsert(LNode* L)
//{
//	LNode* p;
//	//�½�һ�����ָ��,��Զָ��ǰ�����ͷ���
//	int i;
//	scanf_s("%d", &i);
//	//����i������ָ���������������Ҫ�Ž����������Ԫ��
//	//Ҳ��������whileѭ����������i��ֵΪ9999ʱ����
//	while (i != 9999) 
//	{
//		p = (LNode*)malloc(sizeof(LNode));//�½�һ�����
//		p->data = i;//�������ֵ��ֵ���½���ָ����
//		p->next = L->next;//���½����뵽��ͷ
//		L->next = p;//ͷ���Ҫʼ�շ�����ǰ��
//		scanf_s("%d", &i);
//	}
//}
//
////����β�巨����������
//void List_TailInsert(LNode* L)
//{
//	LNode* r;
//	//����һ��βָ�룬ʼ��ָ��ǰ�����β���
//	int i;//i����ָ���������������Ҫ�Ž����������Ԫ��
//	//Ҳ��������whileѭ����������i��ֵΪ9999ʱ����
//	r = L;
//	//��βָ��rָ��ͷ���L��������β���� 
//	scanf_s("%d", &i);//������������
//	while (i != 9999)
//	{
//		LNode* p = (LNode*)malloc(sizeof(LNode));
//		//����һ���½�㣬���ڴ洢����Ԫ��
//		p->data = i;
//		r->next = p;
//		r = p;
//		scanf_s("%d", &i);
//	}
//	r->next = NULL;
//}
//
////�������ӡ
//void ListPrint(LNode* L) 
//{ 
//	printf("�����������Ϊ��");
//	while (L->next != NULL)
//	{
//		printf("%d ", L->next->data);
//		L = L->next;
//	}
//	printf("\n");
//}
//
////����������
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
//	printf("�������ѳ�ʼ��\n");
//	printf("��β�巨��������L��\n");
//	List_TailInsert(L);
//	ListPrint(L);
//	printf("���ô˵�����\n");
//	ListReverse(L);
//	ListPrint(L);
//	return 0;
//}

//˫����
//typedef struct DNode//����˫����������
//{
//	ElemType data;//������
//	struct DNode* prior, * next;//ǰ���ͺ��ָ��
//}DNode,*DLinkList;

//��ʼ��˫����
//bool InitLink(DLinkList& L)
//{
//	L = (DNode*)malloc(sizeof(DNode));//����һ��ͷ���
//	if (L == NULL)//�ڴ治�㣬����ʧ��
//		return false;
//	L->prior = NULL;//ͷ����prior��Զָ��NULL
//	L->next = NULL;//ͷ���֮����ʱ��û�н��
//	return true;
//}

//void testDLinkList
//{
//	//��ʼ��˫����
//	DLinkList L;
//	InitDLinkList(L);
//	//��������...
//}

//�ж�˫�����Ƿ�Ϊ�գ���ͷ��㣩
//bool Empty(DLinkList L)
//{
//	if (L->next == NULL)
//		return true;
//	else
//		return false;
//}

//˫����Ĳ���
//��p���֮�����s���
//bool InsertNextDNode(DNode* p, DNode* s)
//{
//	s->next = p->next;//�����*s���뵽*p֮��
//	p->next->prior = s;
//	s->prior = p;
//	p->next = s;
//}
//��pǡ��Ϊ���һ����㣬��ڶ����޷�ִ��
//�ʶ��˶δ�����޸�Ϊ
//bool InsertNexrDNode(DNode* p, DNode* s)
//{
//	if (p == NULL || s == NULL)//�Ƿ�����
//		return false;
//	s->next = p->next;
//	if (p->next != NULL)//���p����к�̵�
//		p->next->prior = s;
//	s->prior = p;
//	p->next = s;
//	return true;
//}

//˫�����ɾ��
//ɾ��p�ĺ�̽��q
//bool DeleteNextDNode(DNode* p)
//{
//	if (p = NULL)
//		return false;
//	DNode* q = p->next;//�ҵ�p�ĺ�̽��q
//	if (q == NULL)
//		return false;//pû�к��
//	p->next = q->next;
//	if (q->next != NULL)
//		q->next->prior = p;
//	free(q);//�ͷŽ��ռ�
//	return true;
//}