#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//栈的应用——括号匹配
// ( ( (  (  )  ) ) )
//最后出现的左括号最先被匹配（LIFO）

// ( (  ( )  ) ( ) )
//每出现一个右括号，就“消耗”一个左括号（出栈）
//每遇到左括号就压入栈中，遇到右括号就把栈顶的左括号弹出

//#define MaxSize 10//定义栈中元素的最大个数
//typedef struct
//{
//	char data[MaxSize];//静态数组存放栈中指针
//	int top;//栈顶指针
//}Sqstack;
//
////初始化栈
//void IninStack(SqStack& S)
//
////判断栈是否为空
//bool StackEmpty(SqStack S)
//
////新元素入栈
//bool Push(SqStack& S, char x)
//
////栈顶元素出栈，用x返回
//bool Pop(SqStack& S, char& x)
//
//bool BracketCheck(char str[], int length)
//{
//	SqStack S;
//	InitStack S;//初始化一个栈
//	for (int i = 0; i < length; i++)
//	{
//		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
//		{
//			Push(S, str[i]);//扫描到左括号，入栈
//		}
//		else
//		{
//			if (StackEmpty(S))//扫描到右括号且当前栈空
//				return false;//匹配失败
//			char topElem;
//			Pop(S, topElem);//栈顶元素出栈
//			if (str[i] == ')' && topElem != '(')
//				return false;
//			if (str[i] == ']' && topElem != '[')
//				return false;
//			if (str[i] == '}' && topElem != '{')
//				return false;
//		}
//	}
//	return StackEmpty(S);//检索完全部括号后，栈空说明匹配成功
//}
//
////实际开发时可用链栈以防溢出


////不使用栈的方式，改用数组实现
//#define MaxSize 10
//int BrankCheck(char data[], int sz)
//{
//	char arr[MaxSize] = { 0 };
//	int top = -1;
//	for (int i = 0; i < sz; i++)
//	{
//		if (data[i] == '{' || data[i] == '(' || data[i] == '[')
//		{
//			arr[++top] = data[i];
//		}
//		else
//		{
//			if (top == -1)//扫描到右括号且当前数组为空
//			{
//				return 0;//匹配失败
//				break;
//			}
//			if (data[i] == ')' && arr[top] != '(')
//			{
//				return 0;//匹配失败
//				break;
//			}
//			if (data[i] == '[' && arr[top] != ']')
//			{
//				return 0;//匹配失败
//				break;
//			}
//			if (data[i] == '{' && arr[top] != '}')
//			{
//				return 0;//匹配失败
//				break;
//			}
//			else
//			{
//				arr[top--] = 0;
//				if (top == -1)
//					return 1;
//			}
//		}
//	}
//	if (top == -1)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	char data[] = "{()[]}";
//	int sz = strlen(data);
//	int ret = BrankCheck(data, sz);
//	if (ret == 1)
//		printf("匹配成功\n");
//	else
//		printf("匹配失败\n");
//	return 0;
//}


/*
1、用栈实现括号匹配：
依次扫描所有字符，遇到左括号进栈,
遇到右括号则弹出栈顶元素检查是否匹配

2、匹配失败情况
①左括号单身
②右括号单身
③左右括号不匹配
*/




//栈的应用——表达式求值
/*
中缀表达式：运算符在两个操作数中间
eg:
a+b
a+b-c
a+b-c*d

后缀表达式：运算符在两个操作数后面（又叫逆波兰表达式）
eg:
ab+
ab+c-
ab+cd*-

前缀表达式：运算符在两个操作数前面（又叫波兰表达式）
eg:
+ab
-+abc
-+ab*cd
*/

/*
中缀表达式转后缀表达式（手算）
①确定中缀表达式中各个运算符的运算顺序
②选择下一个运算符，按照【左操作数 右操作数 运算符】的方式
  组合成一个新的操作数
③如果还有运算符没被处理，就继续②

eg:
A + B * (C - D) - E / F
  ③  ②   ①   ⑤   ④（运算1）

  ↓

ABCD - *+EF / -
     ①②③   ④⑤


A + B * (C - D) - E / F
  ⑤  ③   ②    ④  ①（运算2）

  ↓

ABCD - *EF / -+
      ②③  ①④⑤

（客观来看两种都正确，只是“机算”结果是前者）


♪“左优先”原则：
   只要左边的运算符能先计算，就优先算左边的

♪后缀表达式的手算方法：
  从左往右扫描，每遇到一个运算符，就让运算符前面最近的两个
操作数执行对应运算，合体为一个操作数

♪注意：两个操作数的左右顺序

*/


/*
后缀表达式的计算（机算）
♪手算方法特点：最后出现的操作数先被运算

用栈实现后缀表达式的计算：
①从左往右扫描下一个元素，直到处理完所有元素
②若扫描到操作数则压入栈，并回到①；否则执行③
③若扫描到运算符，则弹出两个栈顶元素，执行相应运算，运算结
  果压回栈顶，回到①

♪注意：先出栈的是“右操作数”

♪若表达式合法，则最后栈中只会留下一个元素，即最终结果

♪后缀表达式适用于基于栈的编程语言，如：Forth、PostScript
*/










