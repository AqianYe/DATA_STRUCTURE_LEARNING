#define _CRT_SECURE_NO_WARNINGHS
#include<stdio.h>

//��7.2  ˳����Һ��۰����
/*
һ��˳�����
1���ֽС����Բ��ҡ���ͨ���������Ա�
2���㷨˼�룺��ͷ��β������
*/

//typedef struct//���ұ�����ݽṹ��˳���
//{
//	ElemType* elem;//��̬�����ַ
//	int TableLen;//��ĳ���
//}SSTable;
//
////˳�����
//int Search_Seq(SSTable ST, Elemtype key)
//{
//	int i;
//	for (i = 0; i < ST.TableLen && ST.elem[i] != key; ++i)
//		//���ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�-1
//	return i == ST.TableLen ? -1 : i;
//}


/*
�����۰����
1���ֳơ����ֲ��ҡ����������������˳���
*/

//typedef struct//���ұ�����ݽṹ��˳���
//{
//	ElemType* elem;//��̬�����ַ
//	int TableLen;//��ĳ���
//}SSTable;
//
////�۰����
//int Binary_Search(SStable L, ElemType key)
//{
//	int low = 0, high = L.TableLen - 1, mid;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;//ȡ�м�λ��
//		if (L.elem[mid] == key)
//			return mid;//���ҳɹ��򷵻�����λ��
//		else if (L.elem[mid] > key)
//			high = mid - 1;//��ǰ�벿�ּ�������
//		else
//			low = high + 1;//�Ӻ�벿�ּ�������
//	}
//	return -1;//����ʧ�ܣ�����-1
//}



//��7.3  ���Ͳ���
/*
һ��������������BTS��
1�����������ֵ<�����ֵ<���������ֵ
2������������������Եõ�һ����������������
3�������������Ĳ���
�����ǿգ���Ŀ��ֵ�������ֵ�Ƚϣ�
����ȣ�����ҳɹ���
��С�ڸ���㣬�����������ϲ��ң��������������ϲ���
���ҳɹ������ؽ��ָ�룻����ʧ�ܷ���NULL

4�������������Ĳ���
��ԭ����������Ϊ�գ���ֱ�Ӳ����㣻�������ؼ���kС�ڸ����
ֵ������뵽�����������ؼ���k���ڸ����ֵ������뵽������
5�������������Ĺ���
��ͬ�Ĺؼ������п��ܵõ�ͬ�������������Ҳ���ܵõ���ͬ���
��������

6��������������ɾ��
��������Ŀ���㣺
1������ɾ�����z��Ҷ��㣬��ֱ��ɾ���������ƻ�������������
����
2�������zֻ��һ����������������������z��������Ϊz������
���������z��λ��
3�������z��������������������z��ֱ�Ӻ�̣���ֱ��ǰ����
���z��Ȼ��Ӷ�����������ɾȥ���ֱ�Ӻ�̣���ֱ��ǰ������
������ת�����˵�һ��ڶ������
��z�ĺ�̣�z���������������½�㣨��С�Ľ�㣬�ý��һ��û
����������
��z��ǰ����z���������������½�㣨���Ľ�㣬�ý��һ��û
����������
*/

////�������������
//typedef struct BSTNode
//{
//	int key;
//	struct BSTNode* lchild, * rchild;
//}BSTNode,*BSTree;
//
////�ڶ����������в���ֵΪkey�Ľ��
//BTSNode* BST_Search(BSTree T, int key)
//{
//	while (T != NULL && key != T->key)//�����ջ���ڸ����ֵ�������ѭ��
//	{
//		if (key < T->key)
//			T = T->lchild;//С�ڣ������������ϲ���
//		else
//			T = T->rchild;//���ڣ������������ϲ���
//	}
//	return T;
//}//��ռ临�Ӷ�O(1)
//
//
////�ڶ����������в���ֵΪkey�Ľ�㣨�ݹ�ʵ�֣�
//BSTNode* BSTSearch(BSTree T, int key)
//{
//	if (T == NULL)
//		return NULL;//����ʧ��
//	if (key == T->key)
//		return T;//���ҳɹ�
//	else if (key < T->key)
//		return BSTSearch(T->lchild, key);//������������
//	else
//		return BSTSearch(T->rchild, key);//������������
//}//��ռ临�Ӷ�O(h)
//
//
////�ڶ����������в���ؼ���Ϊk���½�㣨�ݹ�ʵ�֣�
//int BTS_Insert(BSTree& T, int k)
//{
//	if (T == NULL)//ԭ��Ϊ�գ��²���Ľ��Ϊ�����
//	{
//		T = (BSTree)malloc(sizeof(BTSNode));
//		T->key = k;
//		T->lchild = T->rchild = NULL;
//		return 1;//����1������ɹ�
//	}
//	else if (k == T->key)
//		return 0;//���д�����ͬ�ؼ��ֵĽ�㣬����ʧ��
//	else if (k < T->key)//���뵽T��������
//		return BST_Insert(T->lchild, k);
//	else //���뵽T��������
//		return BST_Insert(T->rchild, k);
//}//��ռ临�Ӷ�O(h)
//
//
////����str[]�еĹؼ������н�������������
//void Create_BST(BSTree& T, int str[], int n)
//{
//	T = NULL;//��ʼʱTΪ����
//	int i = 0;
//	while (i < n)//���ν�ÿ���ؼ��ֲ��뵽������������
//	{
//		BST_Insert(T, str[i]);
//		i++;
//	}
//}


/*
����ƽ�������

*/

//ƽ����������
//typedef struct AVLNode
//{
//	int key;//������
//	int balance;//ƽ������
//	struct AVLNode* lchild, * rchild;
//}AVLNode, * AVLTree;

//��������
//f->lchild = p->rchild;
//p->rchild = f;
//gf->lchild / rchild = p;

//��������
//f->rchild = p->lchild;
//p->lchild = f;
//gf->lchild / rchild = p;


/*
���������
*/

//struct RBNode//������Ľ�㶨��
//{
//	int key;//�ؼ��ֵ�ֵ
//	RBNode* parent;//�����ָ��
//	RBNode* lchild;//����ָ��
//	RBNode* rchild;//�Һ���ָ��
//	int color;//�����ɫ�������0/1��ʾ��/�죬Ҳ��ʹ��ö����enum��ʾ��ɫ
//};



//��7.4  B��
/*
һ��B��
*/

//�������������
//typedef struct BSTNode
//{
//	int key;
//	struct BSTNode* lchild, * rchild;
//}BSTNode, * BSTree;

//���������
//struct Node
//{
//	ElemType key[4];//���4���ؼ���
//	struct Node* child[5];//���5������
//	int num;//������м����ؼ���
//};