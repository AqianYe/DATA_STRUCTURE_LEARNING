#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
§6.2  图的存储及基本操作
一、图的存储
1、邻接矩阵法
1）用二维数组即可表示
2）如何求顶点的度、入度、出度？
①第i个结点的度 = 第i行（或第i列）的非零元素个数 → O(|v|)
②第i个结点的出度 = 第i行的非零元素个数 → O(|v|)
③第i个结点的入度 = 第i列的非零元素个数 → O(|v|)
④第i个结点的度 = 第i行、第i列的非零元素个数之和 → O(|v|)
3）邻接矩阵法的性能分析
①空间复杂度：O(|v|) + O(|v|*|v|) = O(|v|^2)，即空间复杂度
  只与顶点有关，和实际的边数无关
②适合用于存储稠密图
③无向图的邻接矩阵是对称矩阵，可以压缩存储
 （只存储上三角区或下三角区）
*/

//图的存储——邻接矩阵法
//#define MaxVertexNum 100//顶点数目的最大值
//typedef struct
//{
//	char Vex[MaxVertexNum];
//	/*顶点表，顶点中可以存储更复杂的信息*/
//	int Edge[MaxVertexNum][MaxVertexNum];
//	/*邻接矩阵，边表，可以用bool型或枚举型变量表示边*/
//	int vexnum, arcnum;//图的当前顶点数和边数（弧树）
//}MGraph;

//邻接矩阵法存储带权图（网）
//#define MaxVertexNum 100//顶点数目的最大值
//#define INFINITY 最大的int值//宏定义常量“无穷”
//typedef char VertexType;//顶点的数据类型
//typedef int EdgeType;//带权图中边上权值的数据类型
//typedef struct
//{
//	VertexType Vex[MaxVertexNum];//顶点
//	EdgeType Edge[MaxVertexNum][MaxVertexNum];//边的权
//	int vexnum, arcnum;//图的当前顶点数和弧数
//}MGraph;


/*
2、邻接表法（顺序+链式存储）
1）表示无向图时，边结点的数量是2|E|，整体空间复杂度为
   O(|v| + 2|E|)
2）表示有向图时，边结点的数量是|E|，整体空间复杂度为
   O(|v| + |E|)
3）图的邻接表表示方式并不唯一
*/

//“顶点”
//typedef struct VNode
//{
//	VertexType data;//顶点信息
//	ArcNode* first;//第一条边（弧）
//}VNode, AdjList[MaxVertexNum];

//用邻接表存储的图
//typedef struct
//{
//	AdjList vertices;
//	int vexnum, arcnum;
//}ALGraph;

//“边（弧）”
//typedef struct ArcNode
//{
//	int adjvex;//边（弧）指向哪个节点
//	struct ArcNode* next;//指向下一条弧的指针
//	//InfoType info;     //边权值
//}ArcNode;


/*
3、十字链表存储有向图
1）空间复杂度：O(|V| + |E|)
2）注意：十字链表只用于存储有向图
*/


/*
4、邻接多重表存储无向图
1）空间复杂度：O(|V| + |E|)
2）删除边、删除结点等操作很方便
3）注意：邻接多重表只用于存储无向图
*/


/*
5、图的基本操作
1）Adjacent(G, x, y)：判断图G是否存在边<x，y>或(x,y)
有向图或无向图——
邻接矩阵时间复杂度：O(1)
邻接表时间复杂度：O(1) - O(|v|)

2）Neighbors(G, x)：列出图G中与结点x邻接的边
①无向图——
邻接矩阵时间复杂度：O(|v|)
邻接表时间复杂度：O(1) - O(|v|)
②有向图——
邻接矩阵时间复杂度：O(|v|)
邻接表出边时间复杂度：O(1) - O(|v|)
邻接表入边时间复杂度：O(|E|)

3）InsertVertex(G, x)：在图G中插入顶点x
无向图或有向图——
邻接矩阵时间复杂度：O(1)
（矩阵初始化时已经全部化为了0，故而时间开销只有在数组中插
入新的元素）
邻接表时间复杂度：O(1)

4）DeleteVertex(G, x)：在图G中删除顶点x
①无向图——
邻接矩阵时间复杂度：O(|v|)
（将其所在的行、列元素均设置为0，然后增加表示空顶点的标识）
邻接表时间复杂度：O(1) - O(|E|)
②有向图——
邻接矩阵时间复杂度：O(|v|)
邻接表出边时间复杂度：O(1) - O(|v|)
邻接表入边时间复杂度：O(|E|)

5）AddEdge(G, x, y)：若无向边(x,y)或有向边<x，y>不存在，
则向图G中添加该边
无向图或有向图——
邻接矩阵时间复杂度：O(1)
邻接表时间复杂度：O(1)（采用头插法）

6）RemoveEdge(G, x, y)：若无向边(x,y)或有向边<x，y>存在，
则从图G中删除该边
无向图或有向图——
邻接矩阵时间复杂度：O(1)
邻接表时间复杂度：O(1) - O(|v|)

7）FirstNeighbor(G, x)：求图G中顶点x的第一个邻接点，若有则
返回顶点号。若x没有邻接点或图中不存在x，则返回-1
①无向图——
邻接矩阵时间复杂度：O(1) - O(|v|)
邻接表时间复杂度：O(1)
②有向图——
邻接矩阵时间复杂度：O(1) - O(|v|)
邻接表出边时间复杂度：O(1)
邻接表入边时间复杂度：O(1) - O(|E|)（不常用）

8）NextNeighbor(G, x, y)：假设图G中顶点y是顶点x的第一个邻
接点，返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后
一个邻接点，则返回-1
无向图——
邻接矩阵时间复杂度：O(1) - O(|v|)
邻接表时间复杂度：O(1)

9）Get_edge_value(G, x, y)：获取图G中边(x,y)或<x，y>对应的
权值
10）Set_edge_value(G, x, y, v)：设置图G中边(x,y)或<x，y>对
应的权值
*/



/*
§6.3  图的遍历
一、图的广度优先遍历
1、同一个图的邻接矩阵表示方式唯一，因此广度优先遍历序列唯一
2、同一个图的邻接表表示方式不唯一，因此广度优先遍历序列不唯一
3、对于无向图，调用BFS函数的次数 = 连通分量数

4、性能分析
1）空间复杂度：最坏情况，辅助队列大小为O(|v|)
2）时间复杂度
①邻接矩阵存储的图：访问|v|个顶点需要O(|v|)的时间，查找每个
顶点的邻接点都需要O(|v|)的时间，而总共有|v|个顶点，故而时间
复杂度为O(|v|^2)
②邻接表存储的图：访问|v|个顶点需要O(|v|)的时间，查找各个顶
点的邻接点共需要O(|E|)的时间，故而时间复杂度为O(|v|+|E|)
*/

//bool visited[MAX_VERTEX_NUM];//访问标记数组，初始都为false

//广度优先遍历
//void BFS(Graph G, int v)
//{
//	visit(v);//访问初始顶点v
//	visited[v] = TRUE;//对v做已访问标记
//	Enqueue(Q, v);//顶点v入队列Q
//	while (!isEmpty(Q))
//	{
//		DeQueue(Q, v);//顶点v出队列
//		for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
//		{
//			//检测v所有邻接点
//			if (!visited[w])//w为v的尚未访问的邻接结点
//			{
//				visit(w);//访问顶点w
//				visit[w] = TRUE;//对w做已访问标记
//				EnQueue(Q, w);//顶点w入队列
//			}
//		}
//	}
//}

//如果是非连通图，则无法遍历完所有结点，故需增加如下代码
//void BFSTraverse(Graph G)//对图进行广度优先遍历
//{
//	for (int i = 0; i < G.vexnum; ++i)
//		visited[i] = FALSE;
//	InitQueue Q;//初始化辅助队列Q
//	for (int i = 0; i < G.vexnum; ++i)//从0号顶点开始遍历
//	{
//		if (!visited[i])//对每个连通分量调用一次BFS
//			BFS(G, i);//i未访问过，从i开始BFS
//	}
//}


/*
二、图的深度优先遍历
1、空间复杂度（来自函数调用栈）
1）最坏情况：递归深度为O(|v|)
2）最好情况：O(1)

2、时间复杂度 = 访问各结点所需时间 + 探索各条边所需时间
1）邻接矩阵存储的图：访问|v|个顶点需要O(|v|)的时间，查找每
个顶点的邻接点都需要O(|v|)的时间，而总共有|v|个顶点，故而时
间复杂度为O(|v|^2)
2）邻接表存储的图：访问|v|个顶点需要O(|v|)的时间，查找各个
顶点的邻接点共需要O(|E|)的时间，故而时间复杂度为O(|v|+|E|)

3、同一个图的邻接矩阵表示方式唯一，因此广度优先遍历序列唯一
4、同一个图的邻接表表示方式不唯一，因此广度优先遍历序列不唯一
*/

//bool visited[MAX_VERTEX_NUM];//访问标记数组
//
//void DFS(Graph G, int v)//从顶点v出发，深度优先遍历图G
//{
//	visit(v);//访问顶点v
//	visited[v] = TRUE;//设已访问标记
//	for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
//	{
//		if (!visited[w])//w为u的尚未访问的邻接结点
//			DFS(G, w);
//	}
//}


//如果是非连通图，则无法遍历完所有结点，故需增加如下代码
//void BFSTraverse(Graph G)//对图G进行深度优先遍历
//{
//	for (int v = 0; v < G.vexnum; ++v)
//		visited[v] = FALSE;//初始化已访问标记数据
//	for (int v = 0; v < G.vexnum; ++i)//从0号顶点开始遍历
//	{
//		if (!visited[v])//对每个连通分量调用一次BFS
//			BFS(G, v);//v未访问过，从v开始BFS
//	}
//}



/*
§6.4  图的应用
一、最小生成树（会手算即可）
1、Prim算法（普利姆）
1）从某一个顶点开始构建生成树；每次将代价最小的新顶点纳入
生成树，直到所有顶点都纳入为止。
2）时间复杂度：O(|v|^2)，适合用于边稠密图

2、Kruskal算法（克鲁斯卡尔）
1）每次选择一条权值最小的边，使这两条边的两头连通（原本已
经连通的就不选），直到所有结点都连通。
2）时间复杂度：O(|E|log2|E|)，适合于边稀疏图
*/



/*
二、最短路径
1、单源最短路径
1）BFS算法（无权图）
2）Dijkstra算法（带权图、无权图）

2、各顶点间的最短路径
Floyd算法（带权图、无权图）
*/

/*
1、BFS求无权图的单源最短路径
*/

//bool visited[MAX_VERTEX_NUM];//访问标记数组

//广度优先遍历
//void BFS(Graph G, int v)//从顶点v出发，广度优先遍历图G
//{
//	visit(v);//访问初始顶点v
//	visited[v] = TRUE;//对v做已访问标记
//	EnQueue(Q, v);//顶点v入队列Q
//	while (!isEmpty(Q))
//	{
//		DeQueue(Q, v);//顶点v入队列Q
//		for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
//		{
//			//检测v所有邻接点
//			if (!visited[w])//w为v的尚未访问的邻接结点
//			{
//				visit(w);//访问顶点w
//				visit[w] = TRUE;//对w做已访问标记
//				EnQueue(Q, w);//顶点w入队列
//			}
//		}
//	}
//}

//↓

//求顶点u到其他顶点的最短路径
//void BFS_MIN_Distance(Graph G, int u)
//{
//	//d[i]表示从u到i结点的最短路径
//	for (i = 0; i < G.vexnum, ++i)
//	{
//		d[i] = ∞;//初始化路径长度
//		path[i] = -1;//最短路径从哪个顶点过来
//	}
//	d[u] = 0;
//	visited[u] = TRUE;
//	EnQueue(Q, u);
//	while (!isEmpty(Q))//BFS算法主过程
//	{
//		DeQueue(Q, u);//队头元素u出队
//		for (w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
//		{
//			if (!visited[w])//w为v的尚未访问的邻接结点
//			{
//				d[w] = d[u] + 1;//路径长度加1
//				path[w] = u;//最短路径应从u到w
//				visited[w] = TRUE;//设已访问标记
//				EnQueue(Q, w);//顶点w入队
//			}
//		}
//	}
//}



/*
2、Dijkstra算法（迪杰斯特拉）
手算——
1）循环遍历所有结点，找到还没确定最短路径，且dist最小的顶点
Vi，令final[i] = true
2）检查所有邻接自Vi的顶点，若其final值为false，则更新dist和
path信息

机算——
初始：若从V0开始，令final[0] = true; dist[0] = 0; path[0] =
-1，其余顶点final[k] = false; dist[k] = arcs[0][k]; path[k] =
(arcs[0][k] == ∞) ? -1 : 0

n-1轮处理：循环遍历所有顶点，找到还没确定最短路径，且dist
最小的顶点Vi，令final[i] = true。并检查所有邻接自Vi的顶点，
对于邻接自Vi的顶点Vj，若final[j]为false，且dist[i] + arcs[i][j] <
dist[j]，则令dist[j] = dist[i] + arcs[i][j]; path[j] = i。
注：arcs[i][j]表示Vi到Vj的弧的权值

时间复杂度：O(|v|^2)
Dijkstra算法不适用于有负权值的带权图
*/



/*
3、Floyd算法：求出每一对顶点之间的最短路径
时间复杂度：O(|v|^3)
空间复杂度：O(|v|^2)
不能解决带有“负权回路”的图（有负权值的边组成回路），这种
图可能没有最短路径
*/

//……准备工作，根据图的信息初始化矩阵A和path
//for (int k = 0; k < n; k++)//考虑以Vk作为中转点
//{
//	for (int i = 0; i < n; i++)//遍历整个矩阵，i为行号，j为列号
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (A[i][j] > A[i][k] + A[k][j])//以Vk作为中转点的路径更短
//			{
//				A[i][j] = A[i][k] + A[k][j];//更新最短路径长度
//				path[i][j] = k;//中转点
//			}
//		}
//	}
//}



/*
三、拓扑排序
1、AOV网
用DAG图（有向无环图）表示一个工程。顶点表示活动，有向边
<Vi, Vj>表示活动Vi必须先于活动Vj进行

2、拓扑排序的实现
①从AOV网中选择一个没有前驱的顶点并输出
②从网中删除该顶点和所有以它为起点的有向边
③重复①和②直到当前的AOV网为空或当前网中不存在无前驱的顶
点为止（说明有回路）
*/

//#define MaxVertexNum 100//途中顶点数目的最大值
//typedef struct ArcNode//边表结点
//{
//	int adjvex;//该弧所指向的顶点的位置
//	struct ArcNode* nextarc;//指向下一条弧的指针
//	//InfoType info;    //网的边权值
//}ArcNode;
//
//typedef struct VNode//顶点表结点
//{
//	VextexType data;//顶点信息
//	ArcNode* firstarc;//指向第一条依附该顶点的弧的指针
//}VNode, AdjList[MaxVertexNum];
//
//typedef struct
//{
//	AdjList vertices;//邻接表
//	int vexnum, arcnum;//图的顶点数和弧数
//}Graph;//Graph是以邻接表存储的图类型
//
//bool TopologicalSort(Graph G)
//{
//	InitStack(S);//初始化栈，存储入度为0的顶点
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		if (indegree[i] == 0)
//			Push(S, i);//将所有入度为0的顶点进栈
//	}
//	int count = 0;//计数，记录当前已经输出的顶点数
//	while (!IsEmpty(S))//栈不空，则存在入度为0的定都
//	{
//		Pop(S, i);//栈顶元素出栈
//		print[count++] = i;//输出顶点i
//		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
//		{
//			//将所有i指向的顶点入度减1，并且将入度减为0的顶点压入栈
//			v = p->adjvex;
//			if (!(--indegree[v]))
//				Push(S, v);//入度为0，则入栈
//		}
//	}
//	if (count < G.vexnum)
//		return false;//排序失败，有向图中有回路
//	else
//		return true;//拓扑排序成功
//}


/*
3、逆拓扑排序的实现
①从AOV网中选择一个没有后继（出度为0）的顶点并输出
②从网中删除该顶点和所有以它为终点的有向边
③重复①和②直到当前的AOV网为空
*/


/*
4、用DFS算法实现逆拓扑排序
*/

//void DFSTraverse(Graph G)//对图G进行深度优先遍历
//{
//	for (v = 0; v < G.vexnum; ++v)
//	{
//		visited[v] = FALSE;//初始化已访问标记数据
//		nowvisited[v] = FALSE;//初始化本轮已访问标记数据
//	}
//	for (v = 0; v < G.vexnum; ++v)
//	{	//本代码是从v = 0开始遍历
//		if (!visited[v])
//			DFS(G, v);
//	}	
//}
//
//void DFS(Graph G, int v)//从顶点v出发，深度优先遍历图G
//{
//	visit(v);//访问顶点v
//	visited[v] = TRUE;//设已访问标记
//	nowvisited[v] = TRUE;//设本轮已访问标记
//	for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
//	{
//		if (nowvisited[w] = TRUE)
//			return false;//出现环路
//		if (!visited[w])//w为u的尚未访问的邻接顶点
//			DFS(G, w);
//	}
//	print(v);//输出顶点
//	for (v = 0; v < G.vexnum; ++v)
//		nowvisited[v] = FALSE;//清空本轮已访问标记数据
//}



/*
四、关键路径
1、AOE网
在带权有向图中，以顶点表示事件，以有向边表示活动，以边上权
值表示完成该活动的开销（如完成活动所需的时间），称之为用边
表示活动的网络，简称AOE网

2、AOE网具有的性质
①只有在某顶点所代表的事件发生后，从该顶点出发的各有向边所
代表的活动才能开始；
②只有在进入某顶点的各有向边所代表的活动都已结束时，该顶点
所代表的事件才能发生。另外，有些活动是可以并行的。

3、关键路径
从源点到汇点的有向路径可能有多条，所有路径中，具有最大路径
长度的路径称为关键路径。

事件Vk的最早发生时间ve(k)——
决定了所有从vk开始的活动能够开工的最早时间

活动ai的最早开始时间e(i)——
指该活动弧的起点所表示的事件的最早发生时间

事件Vk事件Vk的最迟发生时间vl(k)——
它是指在不推迟整个工程完成的前提下，该事件最迟必须发生的时间

活动ai的最迟开始时间l(i)——
它是指该活动弧的终点所表示的事件的最迟发生时间与该活动所需时间之差

活动ai的时间余量d(i) = l(i) - e(i)——
表示在不增加完成整个工程所需总时间的情况下，活动ai可以拖延的时间

4、求关键路径的步骤
①求所有事件的最早发生时间ve()
按拓扑排序序列，依次求各个顶点的ve(k):
ve(源点) = 0
ve(k) = Max{ ve(j) + Weight(vj,vk) }，vj为vk的任意前驱

②求所有事件的最迟发生时间vl()
按逆拓扑排序序列，依次求各个顶点的vl(k)：
vl(汇点) = ve(汇点)
vl(k) = Min{ vl[j] - Weight(vk, vj) }，vj为vk的任意后继

③求所有活动的最早发生时间e()
若边<vk, vj>表示活动ai，则有e(i) = ve(k)

④求所有活动的最迟发生时间l()
若边<vk, vj>表示活动ai，则有l(i) = vl(j) - Weight(vk, vj)

⑤求所有活动的时间余量d() → d(i) = 0 的活动即关键活动
d(i) = l(i) - e(i)
*/