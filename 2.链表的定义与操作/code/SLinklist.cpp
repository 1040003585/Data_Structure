/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: SLinklist.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 16:41
 * Description: 静态链表 求集合(A-B)||(B-A)：即A中没有B的元素则插入,否则删除A中该元素 
 */
#include<stdio.h>
#define MAXSIZE 11 				//减去空闲链表和占用链表两个头指针，有MAXSIZE-2个空闲可以分配 
#define ElemType char
typedef struct{
	ElemType data;				//值域 
	int cur;					//游标 
}component,SLinklist[MAXSIZE];

	int s;
	SLinklist SL;
void Print();	//声明 Print函数 

/*初始化一维数组space为空闲链表，space[0].cur为头指针*/
void InitSpace_SL(SLinklist &space){
	for(int i=0;i<MAXSIZE;i++)
		space[i].cur=i+1;
	space[MAXSIZE-1].cur=0;	
}
/*从空闲链表分配一个空间以下标i返回,空闲链表空间不够则返回0*/
int Malloc_SL(SLinklist &space){
	int i=space[0].cur;
	if(space[0].cur)space[0].cur=space[i].cur;
	return i;
}
//回收下标为k的空闲结点到空闲链表 
void Free_SL(SLinklist &space,int k){
	space[k].cur=space[0].cur;
	space[0].cur=k;
}

/*求集合(A-B)||(B-A)*/
void difference(SLinklist &space,int &S){
	InitSpace_SL(space);			//初始化空闲链表 
	S=Malloc_SL(space);				//生成占用链表S的头结点 
	int m,n,r=S;					//r表示占用链表S当前最后结点 
	printf("input the number of A and B: ");
	scanf("%d %d",&m,&n);getchar();	//输入A和B的元素个数 
	
	/*将A元素加入占用链表 */
	for(int j=1;j<=m;j++){			
		int i=Malloc_SL(space);
		printf("input the data of A one by one with a Enter: ");
		scanf("%c",&space[i].data);getchar();//
		space[r].cur=i;		r=i;
		//Print();//
	}
	space[r].cur=0;					//尾结点指针域为0 
	Print();//
	
	/*依次输入B的元素，若不在当前占用链表S中，则插入；否则删除 */
	for(int j=1;j<=n;j++){			
		printf("input the data of B one by one with a Enter: ");
		ElemType b;scanf("%c",&b);getchar();//
		int p=S;
		int k=space[S].cur;
		while(k!=space[r].cur&&space[k].data!=b){
			p=k;k=space[k].cur;	//p表示k的前一个元素 
		}
		if(k==space[r].cur){	//该元素不在占用链表S中，插入之 
			int i=Malloc_SL(space);
			space[i].data=b;
			space[i].cur=space[r].cur;
			space[r].cur=i;
			r=i;				//表尾r指向最新元素 
		}else{					//该元素已在占用链表S中，删除之 
			space[k].data=' ';	//把删除的值清空 
			space[p].cur=space[k].cur;
			Free_SL(space,k);
			if(r==k)r=p;		//若删除的是r所结点，则需修改尾指针 
		}
		
		Print();//
	}//for
}

int main(int argc,char ** argv){
	difference(SL,s);
	printf("data head index s: %d\n",s);
	return 0;
}

/*定义 Print函数 */
void Print(){
	printf("index:\t");
	for(int i=0;i<MAXSIZE;i++){
		printf("%d\t",i);
	}printf("\n");
	printf("data:\t");
	for(int i=0;i<MAXSIZE;i++){
		printf("%c\t",SL[i].data);
	}printf("\n");
	printf("cur:\t");
	for(int i=0;i<MAXSIZE;i++){
		printf("%d\t",SL[i].cur);
	}printf("\n\n");
	printf(":----------------------------------\n");

}
