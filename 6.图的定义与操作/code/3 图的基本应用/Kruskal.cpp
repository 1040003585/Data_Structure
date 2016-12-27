#include<stdio.h>
#include<algorithm>
#define MaxVertexNum 100
//## 1.1 图的邻接矩阵定义法
using namespace std;
typedef struct{
	int a,b,w;
}Road;
typedef struct{
	int vexnum,arcnum;
	Road road[MaxVertexNum];
}MGraph;
	int sum=0;
	MGraph G;
	int v[MaxVertexNum];
int getRoot(int n){
	while(n!=v[n])
		n=v[n];
	return n;
}
bool cmp(Road r1,Road r2){
	return r1.w<r2.w;
}
void Kruskal(MGraph g,int &sum,Road road[]){
	int N=g.vexnum,E=g.arcnum;
	sum=0;
	for(int i=1;i<=N;i++){
		v[i]=i;
	}
	sort(road+1,road+E+1,cmp);
	//sort(v,v+MaxVertexNum);
	for(int i=1;i<=E;i++){
		int a1=road[i].a;
		int b1=road[i].b;
		int ra=getRoot(a1);
		int rb=getRoot(b1);
		if(ra!=rb){
			v[ra]=rb;sum+=road[i].w;
		}
	}
}
void input(){
	printf("input vexnum arcnum:");
	scanf("%d %d",&G.vexnum,&G.arcnum);
	for(int i=1;i<=G.arcnum;i++){
		scanf("%d %d %d",&G.road[i].a,&G.road[i].b,&G.road[i].w);
	}
}
int main(){
	input();
	Kruskal(G,sum,G.road);
	printf("%d\n",sum);
	for(int i=1;i<=G.arcnum;i++){
		printf("%d ",G.road[i].w);
	}
	return 0;
}
/*
input
6 10
1 2 6
1 4 5
2 3 5
2 5 3
4 3 5
4 6 2
3 5 6
3 6 4
5 6 6
1 3 1
*/
