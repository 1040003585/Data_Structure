#define MaxVertexNum 100
#define VertexType int
#define WeightType double
#define InfoType double

//## 1.1 图的邻接矩阵定义法
typedef struct{
	VertexType vexs[MaxVertexNum];
	int arc[MaxVertexNum][MaxVertexNum];
	int vexnum,arcnum;
}MGraph;

//## 1.2 图的邻接表定义法
typedef struct ArcNode{
	int adjvex;
	WeightType cost;
	//struct ArcNode *nextarc;
	ArcNode *nextarc;//Successful
	//AdjNode *nextarc;//[Error] 'AdjNode' does not name a type
}ArcNode;
typedef struct{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MaxVertexNum];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

//## 1.3 有向图的十字链表定义法
typedef struct XArcNode{
	int tailvex,headvex;
	struct XArcNode *hlink,*tlink;
	//XArcNode *hlink,*tlink;//Successful
	//InfoType info;
}XArcNode;
typedef struct{
	VertexType data;
	XArcNode *firstin,*firstout;
}XVNode;
typedef struct{
	XVNode xlist[MaxVertexNum];
	int vernum,arcnum;
}XLGraph;

//## 1.4 无向图的邻接多重表定义法
int main(){
	return 0;
}
