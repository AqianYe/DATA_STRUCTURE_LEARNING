#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

//§8.2  插入排序
/*
一、直接插入排序
1、算法思想：每次将一个待排序的记录按其关键字大小插入到前
面已排好序的子序列中，直到全部记录插入完成。
2、空间复杂度O(1)（i，j，temp）
3、时间复杂度：主要来自对比关键字、移动元素
1）若有n个元素，则需要n-1趟处理
2）最好情况：全部有序，共n-1趟处理，每一趟只需要对比关键字1次，不用移动元素
   最好时间复杂度O(n)
3）最坏情况：全部逆序，O(n^2)
4）平均时间复杂度( O(n)+O(n^2) ) / 2 = O(n^2)

4、优化——折半插入排序
1）先用折半查找找到应该插入的位置，再移动元素
2）当low > high时折半查找停止，应将[low,i-1]内的元素全部右移，并将A[0]复制到low所指位置
3）当A[mid] == A[0]时，为保证算法的“稳定性”（以防有多个相同的元素），继续在mid所指位置右边寻找插入位置,即转向2）
4）整体来看时间复杂度依然是O(n^2)

5、对链表进行插入排序
移动元素的次数变少了，但是关键字对比的次数依然是O(n^2)数量
级，整体来看时间复杂度依然是O(n^2)
*/

//直接插入排序
//void InsertSort(int A[], int n)
//{
//	int i, j, temp;
//	for (i = 1; i < n; i++)//将各元素插入已排好序的序列中
//	{
//		if (A[i] < A[i - 1])//若A[i]关键字小于前驱
//		{
//			temp = A[i];//用temp暂存A[i]
//			for (j = i - 1; j >= 0 && A[j] > temp; --j)//检查所有前面已排好序的元素
//				A[j + 1] = A[j];//所有大于temp的元素都向后挪位
//			A[j + 1] = temp;//复制到插入位置
//		}
//	}
//}


//优化——折半排序
//void InsertSort(int A[], int n)
//{
//	int i, j, low, high, mid;
//	for (i = 2; i < n; i++)//依次将A[2] - A[n]插入前面的已排序序列
//	{
//		A[0] = A[i];//将A[i]暂存到A[0]
//		low = 1; high = i - 1;//设置折半查找的范围
//		while (low <= high)//折半查找（默认递增有序）
//		{
//			mid = (low + high) / 2;//取中间点
//			if (A[mid] > A[0])
//				high = mid - 1;//查找左半子表
//			else
//				low = mid + 1;//查找右半子表
//		}
//		for (int j = i - 1; j >= high + 1; --j)
//			A[j + 1] = A[j];//统一后移元素，空出插入位置
//		A[high + 1] = A[0];//插入操作
//	}
//}


//对链表进行插入排序
//#include<malloc.h>
//
//typedef struct LNode//单链表的结构定义 
//{        
//	int data;//定义int类型的数据域 
//	struct LNode* next;//定义指针域 
//}LNode, * LinkList;
//
////初始化单链表 并设置为空表
//LNode* InitList(LNode* L)
//{
//	L = (LNode*)malloc(sizeof(LNode));
//	L->next = NULL;
//	//使头结点的指针域为空，建立一个空的单链表 
//	return L;
//}
//
////利用尾插法建立单链表（带头结点）
//void List_TailInsert(LNode* L)
//{
//	LNode* r;
//	//建立一个尾指针，始终指向当前链表的尾结点
//	int i;//i用于指代输入的整数，将要放进链表的数据元素
//	//也用来控制while循环，当输入i的值为9999时结束
//	r = L;
//	//令尾指针r指向头结点L，便于做尾插入 
//	scanf_s("%d", &i);//输入插入的整数
//	while (i != 9999)
//	{
//		LNode* p = (LNode*)malloc(sizeof(LNode));
//		//建立一个新结点，用于存储数据元素
//		p->data = i;
//		r->next = p;
//		r = p;
//		scanf_s("%d", &i);
//	}
//	r->next = NULL;
//}
//
////单链表打印
//void ListPrint(LNode* L) 
//{ 
//	while (L->next != NULL)
//	{
//		printf("%d ", L->next->data);
//		L = L->next;
//	}
//	printf("\n");
//}
//
////对链表进行插入排序
//void ListInsertSort(LNode* L)
//{
//	LNode* p, * q, * r, * u;//p、u指针用来处理原链表，q、r指针用来在有序链表中找到合适的插入位置
//	p = L->next;// 指向原链表，通过while(p)，迭代将每个结点插入到有序链表中
//	L->next = NULL;// L->next = NULL,链表置为空，等待插入有序节点
//	while (p)//循环处理直到原链表处理完
//	{
//		// 从有序链表的链表头开始比较，r始终在q前一位
//		// 新节点就插入在r、q之间
//		r = L;
//		q = L->next;
//		while (q && q->data <= p->data)//循环第一次的时候q值为null，没有执行此循环
//		{
//			r = q;
//			q = q->next;
//		}
//		u = p->next;//先保留原来指针的信息
//		// 完成插入的过程
//		p->next = q;
//		r->next = p;
//		p = u;//插入完成后，p指针指向原链表下一个，继续处理
//	}	
//}
//
//int main() 
//{
//	LNode* L = NULL;
//	L = InitList(L);
//	printf("单链表已初始化\n");
//	printf("用尾插法插入链表L：\n");
//	List_TailInsert(L);
//	printf("所得单链表为：\n");
//	ListPrint(L);
//	ListInsertSort(L);
//	printf("排序后的单链表为：\n");
//	ListPrint(L);
//	return 0;
//}


/*
二、希尔排序
1、空间复杂度O(1)
2、时间复杂度和增量序列d1，d2，d3...的选择有关，目前无法用
数学手段证明确切的时间复杂度，最坏时间复杂度（第一趟就设置
d = 1，即退化为直接插入排序）为O(n^2)，当n在某个范围内，可
达O(n^1.3)
3、稳定性：不稳定
4、适用性：仅适用于顺序表，不适用于链表
*/

//void ShellSort(int A[], int n)
//{
//	int d, i, j;//A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
//	for (d = n / 2; d >= 1; d = d / 2)
//	{
//		for (i = d + 1; i <= n; ++i)
//		{
//			if (A[i] < A[i - d])//需将A[i]插入有序增子量表
//			{
//				A[0] = A[i];//暂存在A[0]
//				for (j = i - d; j > 0 && A[0] < A[j]; j -= d)
//					A[j + d] = A[j];//记录后移，查找插入的位置
//				A[j + d] = A[0];//插入
//			}
//		}
//	}
//
//}



//§8.3  交换排序
/*
一、冒泡排序
1、从后往前（或从前往后）两两比较相邻元素的值，若为逆序（即
A[i-1] > A[i]），则交换它们，直到序列比较完。称这样过程为“
一趟”冒泡排序
2、空间复杂度：O(1)
3、时间复杂度
1）最好情况下，全部有序，比较次数 = n-1，交换次数为0，时间复杂度为O(n)
2）最坏情况下，全部逆序
   比较次数 = (n-1)+(n-2)+...+1 = n(n-1)/2 = 交换次数
   时间复杂度为O(n^2)
   注：若考虑移动元素次数，则还需考虑Swap函数中每次交换都需要移动元素3次
3）平均时间复杂度为O(n^2)
4、稳定性：稳定
5、冒泡排序同样适用于链表
*/

//交换
//void Swap(int* a, int* b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////冒泡排序
//void BubbleSort(int A[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		bool flag = false;//表示本趟冒泡是否发生交换的标志
//		for (int j = n - 1; j > i; j--)//一趟冒泡排序
//		{
//			if (A[j - 1] > A[j])//若为逆序
//			{
//				Swap(A[j - 1], A[j]);//交换
//				flag = true;
//			}
//		}
//		if (flag == false)
//			return;//本趟遍历后没有发生交换，说明表已经有序
//	}
//}


/*
二、快速排序
1、算法效率分析：
1）每一层的QuickSort只需要处理剩余的待排序元素，时间复杂度不超过O(n)
   时间复杂度 = O(n * 递归层数)
2）空间复杂度等于O(递归层数)

把n个元素组织成二叉树，二叉树的层数就是递归调用的层数。
n个节点的二叉树，最小高度 = ⌊log₂n⌋ + 1，最大高度 = n
↓
最好时间复杂度 = O(nlog₂n)
最坏时间复杂度 = O(n²)
最好空间复杂度 = O(log₂n)
最坏空间复杂度 = O(n)

2、稳定性——不稳定
*/

//快速排序
//void QuickSort(int A[], int low, int high)
//{
//	if (low < high)//递归执行的条件
//	{
//		int pivotpos = Partition(A, low, high);//划分
//		QuickSort(A, low, pivotpos - 1);//划分左子表
//		QuickSort(A, pivotpos + 1, high);//划分右子表
//	}
//}
//
////用第一个元素将待排序序列划分成左右两个部分
//int Partition(int A[], int low, int high)
//{
//	int pivot = A[low];//用第一个元素作为枢纽
//	while (low < high)//用low、high搜索枢轴的最终位置
//	{
//		while (low < high && A[high] >= pivot)
//			--high;
//		A[low] = A[high];//比枢轴小的元素移动到左端
//		while (low < high && A[low] <= pivot)
//			++low;
//		A[high] = A[low];//比枢轴大的元素移动到右端
//	}
//	A[low] = pivot;//枢轴元素存放到最终位置
//	return low;//返回存放枢轴的最终位置
//}
//
//int main()
//{
//	int A[] = { 49,38,65,97,76,13,27,49 };
//	QuickSort(A, 0, 7);
//	for (int i = 0; i <= 7; i++)
//		printf("%d ", A[i]);
//	return 0;
//}



//§8.4  选择排序
/*
一、简单选择排序
1、选择排序：每一趟在待排序元素中选取关键字最小（或最大）的元素加入有序子序列
2、空间复杂度：O(1)
   时间复杂度：O(n²)
3、稳定性——不稳定
4、适用性——既可以用于顺序表，也可用于链表
*/

//交换
//void Swap(int* a, int* b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////简单选择排序
//void SelectSort(int A[], int n)
//{
//	for (int i = 0; i < n - 1; i++)//一共进行n-1趟
//	{
//		int min = i;//记录最小元素位置
//		for (int j = i + 1; j < n; j++)//在A[i...n-1]中选择最小的元素
//		{
//			if (A[j] < min)
//				min = j;//更新最小元素位置
//		}
//		if (min != i)
//			Swap(A[i], A[min]);//封装的Swap( )函数共移动元素3次
//	}
//}


/*
二、堆排序
1、时间复杂度：O(nlog₂n)
   空间复杂度：O(1)
2、稳定性——不稳定
*/

//建立大根堆
//void BuildMaxHeap(int A[], int len)
//{
//	for (int i = len / 2; i > 0; i--)//从后往前调整所有非终端结点
//		HeadAdjust(A, i, len);
//}
//
////将以k为根的子树调整为大根堆
//void HeapAdjust(int A[], int k, int len)
//{
//	A[0] = A[k];//A[0]暂存子树的根结点
//	for (int i = 2 * k; i < len; i = i * 2)//沿k较大的子结点向下筛选
//	{
//		if (i < len && A[i] < A[i + 1])
//			i++;//取k较大的子结点的下标
//		if (A[0] >= A[i])
//			break;//筛选结束
//		else
//		{
//			A[k] = A[i];//将A[i]调整到双亲结点上
//			k = i;//修改k值，以便继续向下筛选
//		}
//	}
//	A[k] = A[0];//被筛选结点的值放入最终位置
//}
//
////堆排序的完整逻辑
//void HeapSort(int A[], int len)
//{
//	BuildMaxHeap(A, len);//初始建堆
//	for (int i = len; i > 1; i--)//n-1趟的交换和建堆过程
//	{
//		Swap(A[i], A[1]);//堆顶元素和堆底元素交换
//		HeadAdjust(A, 1, i - 1);//把剩余的待排序元素整理成堆
//	}
//}

//堆的插入
//#define MaxSize 20
//
//void HeapInsert(int arr[], int a, int len)
//{
//	arr[len] = a;
//	for (int i = len; i > 1; i = i / 2)
//	{
//		if (arr[i / 2] > arr[i])
//		{
//			int temp = arr[i / 2];
//			arr[i / 2] = arr[i];
//			arr[i] = temp;
//		}
//		else
//			break;
//	}
//}
//
//int main()
//{
//	int arr[MaxSize] = { 0,9,17,65,32,45,78,87,53 };
//	int a = 13;
//	int b = 46;
//	int len1 = 9;
//	HeapInsert(arr, a, len1);
//	for (int i = 1; i <= len1; i++)
//		printf("%d ", arr[i]);
//	int len2 = 10;
//	HeapInsert(arr, b, len2);
//	printf("\n");
//	for (int i = 1; i <= len2; i++)
//		printf("%d ", arr[i]);
//}


//堆的删除
//#define MaxSize 20
//
//void HeapDelete(int A[], int k, int len)
//{
//	A[k] = A[len];
//	A[0] = A[k];//A[0]暂存子树的根结点
//	for (int i = 2 * k; i < len-1; i = i * 2)//沿k较大的子结点向下筛选
//	{
//		if (i < len - 1 && A[i] > A[i + 1])
//			i++;//取k较小的子结点的下标
//		if (A[0] <= A[i])
//			break;//筛选结束
//		else
//		{
//			A[k] = A[i];//将A[i]调整到双亲结点上
//			k = i;//修改k值，以便继续向下筛选
//		}
//	}
//	A[k] = A[0];//被筛选结点的值放入最终位置
//}
//
//int main()
//{
//	int arr[MaxSize] = { 0,9,13,65,17,45,78,87,53,32,46 };
//	int k = 2;
//	int len = 10;
//	HeapDelete(arr, k, len);
//	for (int i = 1; i < len; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}



//§8.5  归并排序和基数排序
/*
一、归并排序
1、归并：把两个或多个已经有序的序列合并成一个
*/

////辅助数组B
//int* B = (int*)malloc(n * sizeof(int));
//
////A[low...mid]和A[mid+1...high]各自有序，将两个部分合并
//void Merge(int A[], int low, int mid, int high)
//{
//	int i, j, k;
//	for (k = low; k <= high; k++)
//		B[k] = A[k];//将A中所有元素复制到B中
//	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
//	{
//		if (B[i] <= B[j])
//			A[k] = B[i++];//将较小值复制到A中
//		else
//			A[k] = B[j++];
//	}
//	while (i <= mid)
//		A[k++] = B[i++];
//	while (j <= high)
//		A[k++] = B[j++];
//}
//
////归并排序
//void MergeSort(int A[], int low, int high)
//{
//	if (low < high)
//	{
//		int mid = (low + high) / 2;//从中间划分
//		MergeSort(A, low, mid);//对左半部分归并排序
//		MergeSort(A, mid + 1, high);//对右半部分归并排序
//		Merge(A, low, mid, high);//归并
//	}
//}
