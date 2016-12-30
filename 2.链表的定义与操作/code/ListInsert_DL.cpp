/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: DLinkList.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 21:23
 * Description:
*/
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct DLNode{
	ElemType data;
	struct DLNode *prior,*next;
}DLNode,*DLinkList;

//˫ѭ��˫�����i��λ�ò���e 
bool ListInsert_DL(DLinkList &L,int i,ElemType e){
	if(i<=0)return false;
	DLNode *p=L;
//	for(int j=1;j<i;j++,p=p->next);			//��ʽһ��p��s��ǰ�� 
	for(int j=0;j<i;j++,p=p->next);			//��ʽ����p��s�ĺ�� 
	//for(int j=0;j<i&&p!=L;j++,p=p->next);
	//if(p==L)return false;
	DLNode* s=(DLNode*)malloc(sizeof(DLNode));
	if(!s)return false;
	s->data=e;
//	s->next=p->next;s->prior=p->next->prior;//��ʽһ��p��s��ǰ�� 
//	p->next->prior=s;p->next=s;
	s->prior=p->prior;p->prior->next=s;		//��ʽ����p��s�ĺ�� 
	s->next=p;p->prior=s;
	return true;
}
int main(int argc,char ** argv ){
	DLinkList L=(DLinkList)malloc(sizeof(DLNode));
	L->next=L->prior=L;		//ά��ѭ��˫������� 
	printf("������Ҫ����Ԫ�صĸ�����");
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("����������%��Ԫ��λ�ú�ֵ��",i);
		int j,e;scanf("%d %d",&j,&e);
		ListInsert_DL(L,j,e);
	}
	for(DLNode *p=L->next;p!=L;p=p->next){
		printf("%d ",p->data);
	}
	return 0;
}
