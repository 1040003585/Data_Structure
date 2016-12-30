/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: ListCreat_L_FromTail.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 15:39
 * Description: //尾插法建立单链表
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
int main(){
	LinkList L;
	ListCreat_L_FromTail(L);
	printf("单链表元素个数：%d 分别是：",L->data);
	for(LNode* N=L->next;N;N=N->next){
		printf("%d ",N->data);
	}
	return 0;
}
