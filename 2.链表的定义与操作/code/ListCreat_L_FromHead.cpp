/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: ListCreat_L_FromHead.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 15:35
 * Description: �巨����������
 */
#include<stdio.h>		//NULL
#include<malloc.h>		//malloc
#define ElemType int
typedef struct LNode{	//���嵥���������� 
	ElemType data;		//������ 
	struct LNode *next;	//ָ���� 
}LNode,*LinkList;		//LinkList�൱��LNode*������struct LNode*
//ͷ�巨���������� 
LinkList ListCreat_L_FromHead(){
	LinkList L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	int e,length=0;
	printf("������巨����������Ԫ�أ���-1������\n");
	scanf("%d",&e);
	while(e!=-1){
		LNode *s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=L->next;
		L->next=s;
		length++;
		scanf("%d",&e);
	}
	L->data=length;		//��ͷ����¼������ 
	return L;
}
int main(){
	LinkList L=ListCreat_L_FromHead();
	printf("������Ԫ�ظ�����%d �ֱ��ǣ�",L->data);
	for(LNode* N=L->next;N;N=N->next){
		printf("%d ",N->data);
	}
	return 0;
}
