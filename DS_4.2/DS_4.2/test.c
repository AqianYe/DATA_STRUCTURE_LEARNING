#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//��4.2  ����ģʽƥ��
//һ������ģʽƥ���㷨
/*
��������Ϊn��ģʽ������Ϊm
�����������г���Ϊm���Ӵ�������ģʽ���Աȣ�ֱ���ҵ�һ����
ȫƥ����Ӵ��������е��ִ�����ƥ��Ϊֹ*/

//#define MaxSize 10
//typedef struct
//{
//	char ch[MaxSize];
//	int length;
//}SString;
//
//int Index(SString S, SString T)
//{
//	int i = 1, n = StrLength(S), m = StrLength(T);
//	SString sub;//�����ݴ��Ӵ�
//	while (i <= n - m + 1)
//	{
//		SubString(sub, S, i, m);
//		if (StrCompare(sub, T) != 0)
//			++i;
//		else return i;//�����Ӵ��������е�λ��
//	}
//	return 0;//S�в�������T��ȵ��Ӵ�
//}


/*�����������Բ�ʹ���ַ����Ļ���������ֱ��ͨ�������±�ʵ��
����ģʽƥ���㷨*/

//int Index(SString S, SString T)
//{
//	int i = 1, j = 1;
//	while (i <= S.length && j <= T.length)
//	{
//		if (S.ch[i] == T.ch[i])
//		{
//			++i; ++j;//�����ȽϺ���ַ�
//		}
//		else
//		{
//			i = i - j + 2;
//			j = 1;//ָ��������¿�ʼƥ��
//		}
//	}
//	if (j > T.length)
//		return i = T.length;
//	else
//		return 0;
//}

/*
����������Ϊn��ģʽ������Ϊm����������ÿ���Ӵ���Ҫ�Ա�
m���Ӵ������Ӷ� = O( (n-m+1)m ) = O(nm)
*/



//����KMP�㷨
/*
����ģʽ��T�����next����
��
����next�������ƥ�䣨����ָ�벻���ݣ�
*/

//int Index_KMP(SString S, SString T, int next[])
//{
//	int i = 1, j = 1;
//	while (i <= S.length && j <= T.length)
//	{
//		if (j == 0 || S.ch[i] == T.ch[j])
//		{
//			++i;
//			++j;//�����ȽϺ���ַ�
//		}
//		else
//			j = next[j];//ģʽ������ƶ�
//	}
//	if (j > T.length)
//		return i - T.length;//ƥ��ɹ�
//	else
//		return 0;
//}

/*
����������Ϊn��ģʽ������Ϊm������������next����ʱ�临
��ΪO(m)��ģʽƥ�����ʱ�临�Ӷ�ΪO(n)���ʶ�KMP�㷨�ʱ��
���Ӷ� = O(m) + O(n) = O(m+n)
*/



//������ģʽ����next����
/*
next��������ã���ģʽ���ĵ�j���ַ�ʧ��ʱ��jת��ģʽ���ĵ�
next[j]�����ּ�������ƥ��

�������ַ�����next[1]��Ϊ0��next[2]��Ϊ1
*/



//�ġ�KMP�㷨�Ľ�һ���Ż�
//int Index_KMP(SString S, SString T, int nextval[])
//{
//	int i = 1, j = 1;
//	while (i <= S.length && i <= T.length)
//	{
//		if (j == 0 || S.ch[i] == T.ch[j])
//		{
//			++i;
//			++j;//�����ȽϺ���ַ�
//		}
//		else
//			j = nextval[j];//ģʽ������ƶ�
//	}
//	if (j > T.length)
//		return i - T.length;//ƥ��ɹ�
//	else
//		return 0;
//}

/*��nextval����*/
//nextval[1] = 0;
//for (int j = 2, ; j <= T.length; j++)
//{
//	if (T.ch[next[j]] == T.ch[j])
//		nextval[j] = nextval[next[j]];
//	else
//		nextval[j] = next[j];
//}