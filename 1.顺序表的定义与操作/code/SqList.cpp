#include<stdio.h>
#define MaxSize 50
#define ElemType int
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;
//1.������� 
bool ListInsert(SqList &L,int i,ElemType e){//��i��λ�ã�1<=i<=L.length+1��
	if(i<1||i>L.length+1) return false;
	if(L.length>=MaxSize) return false;
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;
	return true;
}
//2.ɾ������
bool ListDelete(SqList &L,int i,ElemType& e){//��i��λ�ã�1<=i<=L.length��
	if(i<1||i>L.length)return false;
	e=L.data[i-1];
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true;
} 
//3.��ֵ����
int LocateElem(SqList L,ElemType e){
	int i=0;
	for(;i<L.length;i++)
		if(L.data[i]==e)return i+1;
	return 0;
}

int main(){
	SqList L;L.length=0;
	printf("%d\n",L.length);
	return 0;
}
