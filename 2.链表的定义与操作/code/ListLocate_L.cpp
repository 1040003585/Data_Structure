/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: ListLocate_L.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 15:37
 * Description: ��ֵe���ұ���
 */
#include<stdio.h>		//NULL
#include<malloc.h>		//malloc
#define ElemType int
typedef struct LNode{	//���嵥���������� 
	ElemType data;		//������ 
	struct LNode *next;	//ָ���� 
}LNode,*LinkList;		//LinkList�൱��LNode*������struct LNode*
//β�巨���������� 
void ListCreat_L_FromTail(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
	L->data=0;L->next=NULL;	//L->dataΪ������ 
	LNode *r=L;				//rΪ��βָ�� 
	printf("������巨����������Ԫ�أ���-1������\n");
	int e;scanf("%d",&e);
	while(e!=-1){
		LNode *s=(LNode*)malloc(sizeof(LNode));
		s->data=e;s->next=NULL;
		r->next=s;
		r=r->next;
		L->data++;			//������+1
		scanf("%d",&e);
	}
}
//��ֵe���ұ��� 
LNode* ListLocate_L(LinkList L,int e){
	LNode* p=L->next;		//pΪ��Ԫ���
	while(p->data!=e&&p){
		p=p->next;
	} 
	return p;				//���ص�i�����ָ�룻��i>���򷵻ص���NULL 
}
int main(){
	LinkList L;
	ListCreat_L_FromTail(L);
	printf("������Ԫ�ظ�����%d �ֱ��ǣ�",L->data);
	for(LNode* N=L->next;N;N=N->next){
		printf("%d ",N->data);
	}
	
	//��ֵe���ұ��� 
	printf("\n������Ҫ����ֵe��");
	int e;scanf("%d",&e);
	LNode* d=ListLocate_L(L,e);
	printf("������Ԫ��ֵe�ǣ�%d",d->data);
	
	return 0;
}
