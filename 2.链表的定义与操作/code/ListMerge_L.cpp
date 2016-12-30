/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: ListMerge_L.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 17:55
 * Description: 合并有序链表
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
	printf("\n\n请输入插法建立单链表元素（以-1结束）\n");
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
//合并有序链表 
void ListMerge_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	LNode* pa=La->next,*pb=Lb->next;
	LNode* pc=Lc=La;				//用La头结点作为Lc的头结点 
	Lc->data=La->data+Lb->data;		//Lc的长度为La长度与Lb长度之和
	while(pa&&pb){
		if(pa->data<pb->data){		//按非递减归并 
			pc->next=pa;pc=pa;pa=pa->next;
		}else{
			pc->next=pb;pc=pb;pb=pb->next;
		}
	} 
	pc->next=pa?pa:pb;				//插入剩余段 
	free(Lb);						//释放Lb的头结点 
}

int main(){
	LinkList L1;
	ListCreat_L_FromTail(L1);
	printf("单链表L1元素个数：%d 分别是：",L1->data);
	for(LNode* N=L1->next;N;N=N->next){
		printf("%d ",N->data);
	}
	
	LinkList L2;
	ListCreat_L_FromTail(L2);
	printf("单链表L2元素个数：%d 分别是：",L2->data);
	for(LNode* N=L2->next;N;N=N->next){
		printf("%d ",N->data);
	}
	
	LinkList L3;
	ListMerge_L(L1,L2,L3);
	printf("\n\n单链表L3元素个数：%d 分别是：",L3->data);
	for(LNode* N=L3->next;N;N=N->next){
		printf("%d ",N->data);
	}
	return 0;
}
