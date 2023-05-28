#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//§4.1 串的定义和实现
//一、串的定义
/*
串，即字符串（string）是由零个或多个字符组成的有限序列
一般记为S = 'a1a2...an'(n>0)

其中S是串名，单引号括起来的字符序列是串的值
ai可以是字母、数字或其他字符
串中字符的个数n称为串的长度
n = 0时的串称为空串（用φ表示）

eg:
S = "HelloWorld!"（有的地方用双引号，如java、c）
T = 'iPhone 11 Pro Max?'（有的地方用单引号，如python）

子串：串中任意个连续的字符组成的子序列
eg：'iPhone'、'Pro M'是串T的字串

主串：包含字串的串

字符在主串中的位置：字符在串中的序号（从1开始）

子串在主串中的位置：子串的第一个字符在主串中的位置

空串：''      空格串：'   '（每个空格字符占1B = 8bit）

串是一种特殊的线性表，数据元素之间呈线性关系

串的数据对象限定为字符集（如中、英文字符、数字字符、标点字符等）

串的基本操作，如增删改查通常以子串为操作对象
*/

/*假设有串T = "",S = "Elysia",W="Ely" */
/*
①StrAssign(&T, chars)
赋值操作，把串T赋值为chars

②StrCopy(&T, S)
复制操作，由串S复制得到串T

③StrEmpty(S)
判空操作，若S为空串，则返回true，否则返回false

④StrLength(S)
求串长，返回串S的元素个数

⑤ClearString(&S)
清空操作，将S清为空串

⑥DestroyString(&S)
销毁串，将串S销毁（回收存储空间）

⑦Concat(&T, S1, S2)
串联串，用T返回由S1和S2联接而成的新串

⑧SubString(&Sub, S, pos, len)
求子串，用Sub返回串S的第pos个字符起长度为len的子串

⑨Index(S, T)
定位操作，若主串S中存在与串T值相同的子串，则返回它在主串S
中第一次出现的位置；否则函数值为0

⑩StrCompare(S, T)
比较操作，若S>T，则返回值＞0；若S = T，则返回值 = 0；若
S＜T，则返回值＜0

♪从第一个字符开始往后依次对比，先出现更大字符的串就更大
♪长串的前缀与短串相同时，长串更大
♪只有两个串完全相同时才相等
*/

/*字符集编码*/
/*
♪任何数据存储到计算机中一定是二进制数
♪需要确定一个字符和二进制数的对应规则，这就是“编码”
♪“字符集”
   英文字符——ASCII字符集
   中英文——Unicode字符集
♪基于同一个字符集，可以有多个编码方案，如：UTF-8,UTF-16

注：采用不同的编码方式，每个字符所占空间不同，考验中只需默
    认每个字符占1B即可
*/




//二、串的存储结构

//1.串的顺序存储
//#define MAXLEN 255//预定义最大串长为255
//
///*静态数组实现（定长顺序存储）*/
//typedef struct
//{
//    char ch[MAXLEN];//每个分量存储一个字符
//    int length;//串的实际长度
//}SString;
//
///*动态数组实现（堆分配存储）*/
//typedef struct
//{
//    char* ch;//按串长分配存储区，ch指向串的基地址
//    int length;//串的长度
//}HString;
//
//HString S;
//S.ch = (char*)malloc(MAXLEN * sizeof(char));
//S.length = 0;
////用完需要手动free


////2.串的链式存储
//typedef struct StringNode
//{
//    char ch;//每个结点存一个字符
//    struct StringNode* next;
//}StringNode,*String;
////存储密度低，每个字符1B，每个指针4B
//
//typedef struct StringNode
//{
//    char ch[4];//每个结点存多个字符
//    struct StringNode* next;
//}StringNode,*String;
////存储密度提高


////3.基本操作的实现
//#define MAXLEN 255//预定义最大串长为255
//typedef struct
//{
//    char ch[MAXLEN];//每个分量存储一个字符
//    int length;//串的实际长度
//}SString;

////（1）求子串
//bool SubString(SString& Sub, SString S, int pos, int len)
//{
//    //子串范围越界
//    if (pos + len - 1 > S.length)
//        return false;
//    for (int i = pos; i < pos + len; i++)
//        Sub.ch[i - pos + 1] = S.ch[i];
//    Sub.length = len;
//    return true;
//}


////（2）比较操作
//int StrCompare(SString S, SString T)
//{
//    for (int i = 1; i <= S.length && i <= T.length; i++)
//    {
//        if (S.ch[i] != T.ch[i])
//            return S.ch[i] - T.ch[i];
//    }
//    //扫描过的所有字符都相同，则长度长的串更大
//    return S.length - T.length;
//}


////（3）定位操作
//int Index(SString S, SString T)
//{
//    int i = 1, n = StrLength(S), m = StrLength(T);
//    SString sub;//用于暂存子串
//    while (i <= n - m + 1)
//    {
//        SubString(sub, S, i, m);
//        if (StrCompare(sub, T) != 0)
//            ++i;
//        else
//            return i;//返回子串在主串中的位置
//    }
//    return 0;//S中不存在与T相等的子串
//}