#define MaxVertexNum 100
#define VertexType int
//## 1.1 图的邻接矩阵定义法
typedef struct{
	VertexType vexs[MaxVertexNum];
	int arc[MaxVertexNum][MaxVertexNum];
	int vexnum,arcnum;
}MGraph;

int main(){
	return 0;
}
