#define MaxVertexNum 100
#define VertexType int
#define InfoType double
//## 1.3 ����ͼ��ʮ�������巨
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


int main(){
	return 0;
}
