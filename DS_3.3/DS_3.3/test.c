#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>

//一、栈的应用——括号匹配
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




//二、栈的应用——表达式求值
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



/*
中缀表达式转前缀表达式（手算）
①确定中缀表达式各个运算符的运算顺序
②选择下一个运算符，按照【运算符 左操作数 右操作数】的方式
  组合成一个新的操作数
③如果还有运算符没被处理，就继续②

eg:
A + B * (C - D) - E / F
  ③  ②   ①   ⑤   ④（运算1）

  ↓

-+A * B - CD / EF
⑤③ ②  ①    ④


A + B * (C - D) - E / F
  ⑤  ③   ②    ④  ①（运算2）

  ↓

+A - *B - CD / EF
⑤ ④ ③ ②    ① 

（客观来看两种都正确，只是“机算”结果是后者）


♪“右优先”原则：
   只要右边的运算符能先计算，就优先算右边的
*/


/*
用栈实现前缀表达式的计算：
①从右往左扫描下一个元素，直到处理完所有元素
②若扫描到操作数则压入栈，并回到①；否则执行③
③若扫描到运算符，则弹出两个栈顶元素，执行相应运算，运算结
  果压回栈顶，回到①

♪注意：先出栈的是“左操作数”

♪前缀表达式应用较少
*/



/*
中缀表达式转后缀表达式（机算）
1、初始化一个栈，用于保存暂时还不能确定运算顺序的运算符。
2、从左到右处理各个元素，直到末尾。可能遇到三种情况：

①遇到操作数。直接加入后缀表达式。

②遇到界限符。遇到"("直接入栈；遇到")"则依次弹出栈内运算符
  并加入后缀表达式，直到弹出"("为止。
注意："("不加入后缀表达式

③遇到运算符。依次弹出栈中优先级高于或等于当前运算符的所有
  运算符，并加入后缀表达式，若碰到"("或栈空则停止。之后再
  把当前运算符入栈。

3、按上述方法处理完所有字符之后，将栈中剩余运算符依次弹出，
并加入后缀表达式。

*/

//伪代码
//void Change(SqStack* S, ElemType str[])
//{
//    int i = 0;
//    ElemType e;
//    InitStack(S);
//    while (str[i] != '\0')
//    {
//        while (isdigit(str[i]))
//        {
//            /*过滤数字字符，直接输出，直到下一位不是数字字
//            符打印空格跳出循环*/
//            printf("%c", str[i++]);
//            if (!isdigit(str[i]))
//            {
//                printf(" ");
//            }
//        }
//        /*加减运算符优先级最低，如果栈顶元素为空则直接入栈
//        否则将栈中存储的运算符全部弹栈，如果遇到左括号则停
//        止，将弹出的左括号重新压栈，因为左括号要和右括号匹
//        配时弹出，这个后面单独讨论，弹出后将优先级低的运算
//        符弹入栈中*/
//        if (str[i] == '+' || str[i] == '-')
//        {
//            if (!StackLength(S))
//            {
//                PushStack(S, str[i]);
//            }
//            else
//            {
//                /*do...while先执行后判断，至少会执行一次*/
//                do
//                {
//                    PopStack(S, &e);
//                    if (e == '(')
//                    {
//                        PushStack(S, e);
//                    }
//                    else
//                    {
//                        printf("%c", e);
//                    }
//                } while (StackLength(S) && e != '(');
//                PushStack(S, str[i]);
//            }
//        }
//        /*当遇到右括号时，把括号里剩余的运算符弹出，直到匹
//        配到左括号为止，左括号只弹出不打印（右括号也不压栈
//        ）*/
//        else if (str[i] == ')')
//        {
//            PopStack(S, &e);
//            while (e != '(')
//            {
//                printf("%c", e);
//                PopStack(S, &e);
//            }
//        }
//        /*乘、除、左括号都是优先级最高的，直接压栈*/
//        else if (str[i] == '*' || str[i] == '/' || str[i] == '(')
//        {
//            PushStack(S, str[i]);
//        }
//        else if (str[i] == '\0')
//        {
//            break;
//        }
//        else
//        {
//            printf("\n输入格式错误!\n");
//            return;
//        }
//        i++;
//    }
//    /*最后把栈中剩余的运算符依次弹栈打印*/
//    while (StackLength(S))
//    {
//        PopStack(S, &e);
//        printf("%c", e);
//    }
//}

//完整代码
//#define InitSize 20
//#define Increment 10
//#define MaxBuffer 20
//#define Len sizeof(ElemType)
//
///*栈的动态分配存储结构*/
//typedef char ElemType;
//typedef struct
//{
//    ElemType* base;
//    ElemType* top;
//    int StackSize;
//}SqStack;
//
///*初始化栈*/
//void InitStack(SqStack* S)
//{
//    S->base = (ElemType*)malloc(Len * InitSize);
//    assert(S->base != NULL);
//    S->top = S->base;
//    S->StackSize = InitSize;
//}
//
///*压栈操作*/
//void PushStack(SqStack* S, ElemType c)
//{
//    if (S->top - S->base >= S->StackSize)
//    {
//        S->base = (ElemType*)realloc(S->base, Len * (S->StackSize + Increment));
//        assert(S->base != NULL);
//        S->top = S->base + S->StackSize;
//        S->StackSize += Increment;
//    }
//    *S->top++ = c;
//}
//
///*求栈长*/
//int StackLength(SqStack* S)
//{
//    return(S->top - S->base);
//}
//
///*弹栈操作*/
//int PopStack(SqStack* S, ElemType* c)
//{
//    if (!StackLength(S))
//    {
//        return 0;
//    }
//    *c = *--S->top;
//    return 1;
//}
//
///*中缀转后缀函数*/
//void Change(SqStack* S, ElemType str[])
//{
//    int i = 0;
//    ElemType e;
//    InitStack(S);
//    while (str[i] != '\0')
//    {
//        while (isdigit(str[i]))
//        {
//            /*过滤数字字符，直接输出，直到下一位不是数字字
//            符打印空格跳出循环*/
//            printf("%c", str[i++]);
//            if (!isdigit(str[i]))
//            {
//                printf(" ");
//            }
//        }
//        /*加减运算符优先级最低，如果栈顶元素为空则直接入栈
//        否则将栈中存储的运算符全部弹栈，如果遇到左括号则停
//        止，将弹出的左括号重新压栈，因为左括号要和右括号匹
//        配时弹出，这个后面单独讨论，弹出后将优先级低的运算
//        符弹入栈中*/
//        if (str[i] == '+' || str[i] == '-')
//        {
//            if (!StackLength(S))
//            {
//                PushStack(S, str[i]);
//            }
//            else
//            {
//                /*do...while先执行后判断，至少会执行一次*/
//                do
//                {
//                    PopStack(S, &e);
//                    if (e == '(')
//                    {
//                        PushStack(S, e);
//                    }
//                    else
//                    {
//                        printf("%c", e);
//                    }
//                } while (StackLength(S) && e != '(');
//                PushStack(S, str[i]);
//            }
//        }
//        /*当遇到右括号时，把括号里剩余的运算符弹出，直到匹
//        配到左括号为止，左括号只弹出不打印（右括号也不压栈
//        ）*/
//        else if (str[i] == ')')
//        {
//            PopStack(S, &e);
//            while (e != '(')
//            {
//                printf("%c", e);
//                PopStack(S, &e);
//            }
//        }
//        /*乘、除、左括号都是优先级最高的，直接压栈*/
//        else if (str[i] == '*' || str[i] == '/' || str[i] == '(')
//        {
//            PushStack(S, str[i]);
//        }
//        else if (str[i] == '\0')
//        {
//            break;
//        }
//        else
//        {
//            printf("\n输入格式错误!\n");
//            return;
//        }
//        i++;
//    }
//    /*最后把栈中剩余的运算符依次弹栈打印*/
//    while (StackLength(S))
//    {
//        PopStack(S, &e);
//        printf("%c", e);
//    }
//}
//
//int main()
//{
//    ElemType str[MaxBuffer];
//    SqStack S;
//    gets(str);
//    Change(&S, str);
//    return 0;
//}




//中缀表达式的计算（用栈实现）
/*
♪中缀转后缀 + 后缀表达式求值两个算法的结合

用栈实现中缀表达式的计算：
①初始化两个栈，操作数栈和运算符栈
②若扫描到操作数，压入操作数栈
③若扫描到运算符或界限符，则按照“中缀转后缀”相同的逻辑压
  入运算符栈（期间也会弹出运算符，每当弹出一个运算符时，就
  需要再弹出两个操作数栈的栈顶元素并执行相应运算，运算结果
  再压回操作数栈）

*/

//三、栈的应用——递归
/*
函数调用的特点：最后被调用的函数最先执行结束（LIFO）

函数调用时，需要用一个栈存储：
①调用返回地址
②实参
③局部变量
*/


/*
适合用“递归”算法解决：
可以把原始问题转换为属性相同，但规模较小的问题
*/

//例1：递归算法求阶乘
//int factorial(int n)
//{
//    if (n == 0 || n == 1)
//        return 1;
//    else
//        return n * factorial(n - 1);
//}
//
//int main()
//{
//    int x = factorial(10);
//    printf("%d\n", x);
//}
/*
递归调用时，函数调用栈可称为“递归工作栈”
每进入一次递归，就将递归调用所需信息压入栈顶
每退出一层递归，就从栈顶弹出对应信息

缺点：效率低，太多层递归可能会导致栈溢出
*/

//例2：递归算法求斐波那契数列
//int Fib(int n)
//{
//    if (n == 0)
//        return 0;
//    else if (n == 1)
//        return 1;
//    else
//        return Fib(n - 1) + Fib(n - 2);
//}
//
//int main()
//{
//    int x = Fib(4);
//    printf("%d\n", x);
//}
/*
缺点：可能包含很多重复计算
*/




//四、队列应用——树的层次遍历


//五、队列应用——图的广度优先遍历


//六、队列在操作系统中的应用
/*
多个进程争抢着使用有限的系统资源时，FCFS(First Come First
Service，先来先服务)是一种常用策略。

♪类似于队列的先进先出
*/