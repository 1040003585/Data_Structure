/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: ListDelete_L.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 15:38
 * Description: //删除结点操作 
 */
#include<stdio.h>		//NULL
#include<malloc.h>		//malloc
#define ElemType int
typedef struct LNode{	//定义单链表结点类型 
	ElemType data;		//数据域 
	struct LNode *next;	//指针域 
}LNode,*LinkList;		//LinkList相当于LNode*，即：struct LNode*
//尾插法建立单链表 
void ListCreat_L_FromTail(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
	L->data=0;L->next=NULL;	//L->data为链表长度 
	LNode *r=L;				//r为表尾指针 
	printf("请输入插法建立单链表元素（以-1结束）\n");
	int e;scanf("%d",&e);
	while(e!=-1){
		LNode *s=(LNode*)malloc(sizeof(LNode));
		s->data=e;s->next=NULL;
		r->next=s;
		r=r->next;
		L->data++;			//链表长度+1
		scanf("%d",&e);
	}
}
//按序号查找第i个结点 
LNode* ListGetElem_L(LinkList L,int i){
	LNode* p=L->next;		//p为首元结点
	if(i==0)return L;		//返回头结点
	if(i<0)return NULL;		//i无效返回NULL
	for(int j=1;j<i&&p;j++){
		p=p->next;
	} 
	return p;	//返回第i个结点指针；若i>表长则返回的是NULL 
}
//删除结点操作 
bool ListDelete_L(LinkList &L,int i,int &e){
	LNode* p=ListGetElem_L(L,i-1);	//查找删除位置的前驱结点 
	if(p||p->next)return false;	//i定位无效，删除失败返回false 
	LNode* s=p->next;			//将s指向预删除结点p->next
	e=s->data;					//将预删除结点s的值赋给e引用传回
	p->next=p->next->next;		//将前驱结点p指向预删除结点的后继结点
	free(s);
	return true;				//删除成功返回true 
}
int main(){
	LinkList L;
	ListCreat_L_FromTail(L);
	printf("单链表元素个数：%d 分别是：",L->data);
	for(LNode* N=L->next;N;N=N->next){
		printf("%d ",N->data);
	}
	
	//删除结点操作
	printf("\n请输入要删除的位置i：");
	int i,e;scanf("%d",&i);
	bool b=ListDelete_L(L,i,e);
	if(b){
		printf("删除成功！%d\n",e);
		printf("单链表元素个数：%d 分别是：",L->data);
		for(LNode* N=L->next;N;N=N->next){
			printf("%d ",N->data);
		}
	}else{
		printf("删除失败！\n");
	}
	
	
	return 0;
}
