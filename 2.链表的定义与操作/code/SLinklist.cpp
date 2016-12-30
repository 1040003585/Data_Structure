/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: SLinklist.cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date/Time: 29-12-16 16:41
 * Description: ��̬���� �󼯺�(A-B)||(B-A)����A��û��B��Ԫ�������,����ɾ��A�и�Ԫ�� 
 */
#include<stdio.h>
#define MAXSIZE 11 				//��ȥ���������ռ����������ͷָ�룬��MAXSIZE-2�����п��Է��� 
#define ElemType char
typedef struct{
	ElemType data;				//ֵ�� 
	int cur;					//�α� 
}component,SLinklist[MAXSIZE];

	int s;
	SLinklist SL;
void Print();	//���� Print���� 

/*��ʼ��һά����spaceΪ��������space[0].curΪͷָ��*/
void InitSpace_SL(SLinklist &space){
	for(int i=0;i<MAXSIZE;i++)
		space[i].cur=i+1;
	space[MAXSIZE-1].cur=0;	
}
/*�ӿ����������һ���ռ����±�i����,��������ռ䲻���򷵻�0*/
int Malloc_SL(SLinklist &space){
	int i=space[0].cur;
	if(space[0].cur)space[0].cur=space[i].cur;
	return i;
}
//�����±�Ϊk�Ŀ��н�㵽�������� 
void Free_SL(SLinklist &space,int k){
	space[k].cur=space[0].cur;
	space[0].cur=k;
}

/*�󼯺�(A-B)||(B-A)*/
void difference(SLinklist &space,int &S){
	InitSpace_SL(space);			//��ʼ���������� 
	S=Malloc_SL(space);				//����ռ������S��ͷ��� 
	int m,n,r=S;					//r��ʾռ������S��ǰ����� 
	printf("input the number of A and B: ");
	scanf("%d %d",&m,&n);getchar();	//����A��B��Ԫ�ظ��� 
	
	/*��AԪ�ؼ���ռ������ */
	for(int j=1;j<=m;j++){			
		int i=Malloc_SL(space);
		printf("input the data of A one by one with a Enter: ");
		scanf("%c",&space[i].data);getchar();//
		space[r].cur=i;		r=i;
		//Print();//
	}
	space[r].cur=0;					//β���ָ����Ϊ0 
	Print();//
	
	/*��������B��Ԫ�أ������ڵ�ǰռ������S�У�����룻����ɾ�� */
	for(int j=1;j<=n;j++){			
		printf("input the data of B one by one with a Enter: ");
		ElemType b;scanf("%c",&b);getchar();//
		int p=S;
		int k=space[S].cur;
		while(k!=space[r].cur&&space[k].data!=b){
			p=k;k=space[k].cur;	//p��ʾk��ǰһ��Ԫ�� 
		}
		if(k==space[r].cur){	//��Ԫ�ز���ռ������S�У�����֮ 
			int i=Malloc_SL(space);
			space[i].data=b;
			space[i].cur=space[r].cur;
			space[r].cur=i;
			r=i;				//��βrָ������Ԫ�� 
		}else{					//��Ԫ������ռ������S�У�ɾ��֮ 
			space[k].data=' ';	//��ɾ����ֵ��� 
			space[p].cur=space[k].cur;
			Free_SL(space,k);
			if(r==k)r=p;		//��ɾ������r����㣬�����޸�βָ�� 
		}
		
		Print();//
	}//for
}

int main(int argc,char ** argv){
	difference(SL,s);
	printf("data head index s: %d\n",s);
	return 0;
}

/*���� Print���� */
void Print(){
	printf("index:\t");
	for(int i=0;i<MAXSIZE;i++){
		printf("%d\t",i);
	}printf("\n");
	printf("data:\t");
	for(int i=0;i<MAXSIZE;i++){
		printf("%c\t",SL[i].data);
	}printf("\n");
	printf("cur:\t");
	for(int i=0;i<MAXSIZE;i++){
		printf("%d\t",SL[i].cur);
	}printf("\n\n");
	printf(":----------------------------------\n");

}
