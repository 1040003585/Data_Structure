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

int main(int argc,char ** argv ){
	DLinkList L=(DLinkList)malloc(sizeof(DLNode));
	L->next=L->prior=L;		//维护循环双链表规则 
	return 0;
}
