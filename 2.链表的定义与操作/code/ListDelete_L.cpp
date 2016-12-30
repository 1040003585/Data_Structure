/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: ListDelete_L.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 15:38
 * Description: //ɾ�������� 
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
//����Ų��ҵ�i����� 
LNode* ListGetElem_L(LinkList L,int i){
	LNode* p=L->next;		//pΪ��Ԫ���
	if(i==0)return L;		//����ͷ���
	if(i<0)return NULL;		//i��Ч����NULL
	for(int j=1;j<i&&p;j++){
		p=p->next;
	} 
	return p;	//���ص�i�����ָ�룻��i>���򷵻ص���NULL 
}
//ɾ�������� 
bool ListDelete_L(LinkList &L,int i,int &e){
	LNode* p=ListGetElem_L(L,i-1);	//����ɾ��λ�õ�ǰ����� 
	if(p||p->next)return false;	//i��λ��Ч��ɾ��ʧ�ܷ���false 
	LNode* s=p->next;			//��sָ��Ԥɾ�����p->next
	e=s->data;					//��Ԥɾ�����s��ֵ����e���ô���
	p->next=p->next->next;		//��ǰ�����pָ��Ԥɾ�����ĺ�̽��
	free(s);
	return true;				//ɾ���ɹ�����true 
}
int main(){
	LinkList L;
	ListCreat_L_FromTail(L);
	printf("������Ԫ�ظ�����%d �ֱ��ǣ�",L->data);
	for(LNode* N=L->next;N;N=N->next){
		printf("%d ",N->data);
	}
	
	//ɾ��������
	printf("\n������Ҫɾ����λ��i��");
	int i,e;scanf("%d",&i);
	bool b=ListDelete_L(L,i,e);
	if(b){
		printf("ɾ���ɹ���%d\n",e);
		printf("������Ԫ�ظ�����%d �ֱ��ǣ�",L->data);
		for(LNode* N=L->next;N;N=N->next){
			printf("%d ",N->data);
		}
	}else{
		printf("ɾ��ʧ�ܣ�\n");
	}
	
	
	return 0;
}
