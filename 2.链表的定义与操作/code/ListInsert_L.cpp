/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 15:37
 * Description: //插入结点操作
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
//插入结点操作 
bool ListInsert_L(LinkList &L,int i,int e){
	LNode* p=ListGetElem_L(L,i-1);	//查找插入位置的前驱结点 
	if(p==NULL)return false;	//i定位无效，插入失败返回false 
	LNode* s=(LNode*)malloc(sizeof(LNode));	//为新值分配结点 
	s->next=p->next;			//1.把新结点s挂接后继结点p->next
	s->data=e;					//新结点赋值
	p->next=s;					//2.把新结点挂在前驱结点p
	return true;				//插入成功返回true 
}
int main(){
	LinkList L;
	ListCreat_L_FromTail(L);
	printf("单链表元素个数：%d 分别是：",L->data);
	for(LNode* N=L->next;N;N=N->next){
		printf("%d ",N->data);
	}
	
	//插入结点操作
	printf("\n请输入要插入的位置i和值e：");
	int i,e;scanf("%d %d",&i,&e);
	bool b=ListInsert_L(L,i,e);
	if(b){
		printf("插入成功！\n");
		printf("单链表元素个数：%d 分别是：",L->data);
		for(LNode* N=L->next;N;N=N->next){
			printf("%d ",N->data);
		}
	}else{
		printf("插入失败！\n");
	}
	
	
	return 0;
}
