#define MaxVertexNum 100
#define VertexType int
#define WeightType double
//## 1.2 ͼ���ڽӱ��巨
typedef struct ArcNode{
	int adjvex;
	WeightType cost;
	struct ArcNode *nextarc;
	//ArcNode *nextarc;//Successful
}ArcNode;
typedef struct{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MaxVertexNum];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

int main(){
	return 0;
}
