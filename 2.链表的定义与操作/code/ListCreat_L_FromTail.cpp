/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: ListCreat_L_FromTail.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 15:39
 * Description: //β�巨����������
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
int main(){
	LinkList L;
	ListCreat_L_FromTail(L);
	printf("������Ԫ�ظ�����%d �ֱ��ǣ�",L->data);
	for(LNode* N=L->next;N;N=N->next){
		printf("%d ",N->data);
	}
	return 0;
}
