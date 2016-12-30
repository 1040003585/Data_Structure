/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: ListCreat_L_FromHead.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 15:35
 * Description: 插法建立单链表
 */
#include<stdio.h>		//NULL
#include<malloc.h>		//malloc
#define ElemType int
typedef struct LNode{	//定义单链表结点类型 
	ElemType data;		//数据域 
	struct LNode *next;	//指针域 
}LNode,*LinkList;		//LinkList相当于LNode*，即：struct LNode*
//头插法建立单链表 
LinkList ListCreat_L_FromHead(){
	LinkList L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	int e,length=0;
	printf("请输入插法建立单链表元素（以-1结束）\n");
	scanf("%d",&e);
	while(e!=-1){
		LNode *s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=L->next;
		L->next=s;
		length++;
		scanf("%d",&e);
	}
	L->data=length;		//令头结点记录链表长度 
	return L;
}
int main(){
	LinkList L=ListCreat_L_FromHead();
	printf("单链表元素个数：%d 分别是：",L->data);
	for(LNode* N=L->next;N;N=N->next){
		printf("%d ",N->data);
	}
	return 0;
}
