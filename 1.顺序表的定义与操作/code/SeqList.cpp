#include<stdio.h>
#include<stdlib.h>		
#define InitSize 100
#define ListIncrement 10
#define ElemType int
typedef struct{
	ElemType *data;
	int length,MaxSize;
}SeqList;
SeqList L,L1,Lc;
//1.������� 
bool ListInsert_Seq(SeqList &L,int i,ElemType e){//��i��λ�ã�1<=i<=L.length+1��
	if(i<1||i>L.length+1) return false;
	if(L.length>=L.MaxSize){
		ElemType *newbase=(ElemType*)realloc(L.data,sizeof(ElemType)*(InitSize+ListIncrement));//˳�������
		if(!newbase)return false;	//�洢����ʧ�� 
		L.data=newbase;				//�»�ַ 
		L.MaxSize+=ListIncrement;	//���Ӵ洢���� 	
	}
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;
	return true;
}
//2.ɾ������
bool ListDelete_Seq(SeqList &L,int i,ElemType& e){//��i��λ�ã�1<=i<=L.length��
	if(i<1||i>L.length)return false;
	e=L.data[i-1];
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true;
} 
//3.��ֵ����
int LocateElem_Seq(SeqList L,ElemType e){
	for(int i=1;i<=L.length;i++)
		if(L.data[i-1]==e)return i;
	return 0;
}
//## 2.4 ˳�����
void Union_Seq(SeqList &La,SeqList Lb){
	int La_len=La.length,Lb_len=Lb.length;
	for(int i=1;i<=Lb_len;i++){
		int e=Lb.data[i-1];					//ȡLb��i��Ԫ�ظ���e 
		if(!LocateElem_Seq(La,e)){			//��La���Ҳ���e,����� 
			ListInsert_Seq(La,++La_len,e);
		}
	}
} 
//## 2.5 ˳���ϲ�
void MergeList_Seq(SeqList La,SeqList Lb,SeqList &Lc){
	Lc.MaxSize=La.length+Lb.length;
	Lc.data=(ElemType*)malloc(sizeof(ElemType)*Lc.MaxSize);
	if(!Lc.data)exit(0);									//�洢����ʧ��
	int ai=0,bi=0,ci=0;
	while(ai<La.length&&bi<Lb.length){
		if(La.data[ai]<Lb.data[bi])							//���ǵݼ����й鲢 
			ListInsert_Seq(Lc,++ci,La.data[ai++]);
		else 
			ListInsert_Seq(Lc,++ci,Lb.data[bi++]);
	} 
	while(ai<La.length)ListInsert_Seq(Lc,++ci,La.data[ai++]);//����Laʣ��Ԫ�� 
	while(bi<Lb.length)ListInsert_Seq(Lc,++ci,Lb.data[bi++]);//����Lbʣ��Ԫ��
//	free(La.data);
//	delete(Lc.data);
}
int main(){
	L.data=(ElemType*)malloc(sizeof(ElemType)*InitSize);//C
	L1.data=new ElemType(InitSize);						//C++
	L.MaxSize=InitSize;
	L1.MaxSize=InitSize;
	ListInsert_Seq(L,1,40);
	ListInsert_Seq(L,1,30);
	ListInsert_Seq(L,1,20);
	ListInsert_Seq(L,1,10);
	ListInsert_Seq(L1,1,60);
	ListInsert_Seq(L1,1,30);
	ListInsert_Seq(L1,1,22);
	ListInsert_Seq(L1,1,10);
	MergeList_Seq(L,L1,Lc);
//	free(Lc.data);
	for(int i=0;i<Lc.length;i++)
		printf("%d ",Lc.data[i]);
	return 0;
}
