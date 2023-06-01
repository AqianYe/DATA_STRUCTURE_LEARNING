#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//§4.2  串的模式匹配
//一、朴素模式匹配算法
/*
主串长度为n，模式串长度为m
将主串中所有长度为m的子串依次与模式串对比，直到找到一个完
全匹配的子串，或所有的字串都不匹配为止*/

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
//	SString sub;//用于暂存子串
//	while (i <= n - m + 1)
//	{
//		SubString(sub, S, i, m);
//		if (StrCompare(sub, T) != 0)
//			++i;
//		else return i;//返回子串在主串中的位置
//	}
//	return 0;//S中不存在与T相等的子串
//}


/*接下来，尝试不使用字符串的基本操作，直接通过数组下标实现
朴素模式匹配算法*/

//int Index(SString S, SString T)
//{
//	int i = 1, j = 1;
//	while (i <= S.length && j <= T.length)
//	{
//		if (S.ch[i] == T.ch[i])
//		{
//			++i; ++j;//继续比较后继字符
//		}
//		else
//		{
//			i = i - j + 2;
//			j = 1;//指针后退重新开始匹配
//		}
//	}
//	if (j > T.length)
//		return i = T.length;
//	else
//		return 0;
//}

/*
设主串长度为n，模式串长度为m，最坏的情况，每个子串都要对比
m个子串，复杂度 = O( (n-m+1)m ) = O(nm)
*/



//二、KMP算法
/*
根据模式串T，求出next数组
↓
利用next数组进行匹配（主串指针不回溯）
*/

//int Index_KMP(SString S, SString T, int next[])
//{
//	int i = 1, j = 1;
//	while (i <= S.length && j <= T.length)
//	{
//		if (j == 0 || S.ch[i] == T.ch[j])
//		{
//			++i;
//			++j;//继续比较后继字符
//		}
//		else
//			j = next[j];//模式串向后移动
//	}
//	if (j > T.length)
//		return i - T.length;//匹配成功
//	else
//		return 0;
//}

/*
设主串长度为n，模式串长度为m，最坏的情况，求next数组时间复
杂为O(m)，模式匹配过程时间复杂度为O(n)，故而KMP算法最坏时间
复杂度 = O(m) + O(n) = O(m+n)
*/



//三、求模式串的next数组
/*
next数组的作用：当模式串的第j个字符失配时，j转从模式串的第
next[j]个数字继续往后匹配

对任意字符串，next[1]均为0，next[2]均为1
*/



//四、KMP算法的进一步优化
//int Index_KMP(SString S, SString T, int nextval[])
//{
//	int i = 1, j = 1;
//	while (i <= S.length && i <= T.length)
//	{
//		if (j == 0 || S.ch[i] == T.ch[j])
//		{
//			++i;
//			++j;//继续比较后继字符
//		}
//		else
//			j = nextval[j];//模式串向后移动
//	}
//	if (j > T.length)
//		return i - T.length;//匹配成功
//	else
//		return 0;
//}

/*求nextval数组*/
//nextval[1] = 0;
//for (int j = 2, ; j <= T.length; j++)
//{
//	if (T.ch[next[j]] == T.ch[j])
//		nextval[j] = nextval[next[j]];
//	else
//		nextval[j] = next[j];
//}