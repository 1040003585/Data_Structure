/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: ListMerge_L.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 17:55
 * Description: �ϲ���������
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
	printf("\n\n������巨����������Ԫ�أ���-1������\n");
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
//�ϲ��������� 
void ListMerge_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	LNode* pa=La->next,*pb=Lb->next;
	LNode* pc=Lc=La;				//��Laͷ�����ΪLc��ͷ��� 
	Lc->data=La->data+Lb->data;		//Lc�ĳ���ΪLa������Lb����֮��
	while(pa&&pb){
		if(pa->data<pb->data){		//���ǵݼ��鲢 
			pc->next=pa;pc=pa;pa=pa->next;
		}else{
			pc->next=pb;pc=pb;pb=pb->next;
		}
	} 
	pc->next=pa?pa:pb;				//����ʣ��� 
	free(Lb);						//�ͷ�Lb��ͷ��� 
}

int main(){
	LinkList L1;
	ListCreat_L_FromTail(L1);
	printf("������L1Ԫ�ظ�����%d �ֱ��ǣ�",L1->data);
	for(LNode* N=L1->next;N;N=N->next){
		printf("%d ",N->data);
	}
	
	LinkList L2;
	ListCreat_L_FromTail(L2);
	printf("������L2Ԫ�ظ�����%d �ֱ��ǣ�",L2->data);
	for(LNode* N=L2->next;N;N=N->next){
		printf("%d ",N->data);
	}
	
	LinkList L3;
	ListMerge_L(L1,L2,L3);
	printf("\n\n������L3Ԫ�ظ�����%d �ֱ��ǣ�",L3->data);
	for(LNode* N=L3->next;N;N=N->next){
		printf("%d ",N->data);
	}
	return 0;
}
