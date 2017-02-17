#include<stdio.h>
#define MaxVertexNum 100
#define VertexType int
#define WeightType double
#define InfoType double

int visited[MaxVertexNum];

//## 1.1 图的邻接矩阵定义法
typedef struct{
	VertexType vexs[MaxVertexNum];
	int arc[MaxVertexNum][MaxVertexNum];
	int vexnum,arcnum;
}MGraph;

//## 1.2 图的邻接表定义法
typedef struct ArcNode{
	int nodeindex;
	WeightType cost;
	struct ArcNode *nextarc;
	//ArcNode *nextarc;//Successful
	//AdjNode *nextarc;//[Error] 'AdjNode' does not name a type
}AdjNode;
typedef struct{
	VertexType data;
	AdjNode *firstarc;
}VNode,AdjList[MaxVertexNum];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph,Graph;

void DFS_M(MGraph G,int i){
	visited[i]=1;
	printf("%d ",i);//
	for(int j=0;j<G.vexnum;j++){
		if(visited[j]==0&&G.arc[i][j]==1){
			DFS_M(G,j);
		}
	}
}
void DFS_AL(ALGraph G,int i){
	visited[i]=1;
	printf("%d ",i);//
	for(ArcNode *p=G.vertices[i].firstarc;p;p=p->nextarc){
		int ind=p->nodeindex;
		if(visited[ind]==0){
			DFS_AL(G,ind);
		}
	}
}

void DFSTraverse(Graph G){
	for(int i=0;i<G.vexnum;i++){
		visited[i]=0;
	}
	for(int i=0;i<G.vexnum;i++){
		if(visited[i]==0){
//			DFS_M(G,i);//
			DFS_AL(G,i);//
		}
	}
}

void BFS_AL(ALGraph G,int i){
	visited[i]=1;
	printf("%d ",i);
	InitQueue(Q);
	EnQueue(Q,i);
	while(!IsEmpty(Q)){
		int v;
		DeQueue(Q,v);
		for(ArcNode* p=G.vertices[v].firstarc;p;p=p->nextarc){
			int ind=p->nodeindex;
			if(visited[ind]==0){
				printf("%d ",ind);
				visited[ind]=1;
				EnQueue(Q,ind);
			}
		}
	}
}
void BFS_M(MGraph G,int i){
	visited[i]=1;
	printf("%d ",i);
	InitQueue(Q);
	EnQueue(Q,i);
	while(!IsEmpty(Q)){
		int v;
		DeQueue(Q,v);
		for(int ind=0;ind<G.vexnum;ind++){
			if(visited[ind]==0&&G.arc[v][ind]==1){
				printf("%d ",ind);
				visited[ind]=1;
				EnQueue(Q,ind);
			}
		}
	}
}
void BFSTraverse(Graph G){
	for(int i=0;i<G.vexnum;i++){
		visited[i]=0;
	}
	for(int i=0;i<G.vexnum;i++){
		if(!visited[i]){
//			DFS_M(G,i);//
			DFS_AL(G,i);//
		}
	}
}



int main(){
	return 0;
}
