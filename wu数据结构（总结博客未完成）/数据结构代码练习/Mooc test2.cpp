/*
3
��5�֣�

��д���ֲ����㷨��������ֵ�㡱��Ϊ���ƽ�ָ�㣬��0.618��������0.5������

*/

#define ElemType int //Ԥ������������Ϊint
int BinarySeartch_gold(ElemType data[],int first,int last,int d){
	int gold=(first+last)/0.618;       //���ƽ�ָ��
	while(first<last){
		if(data[gold]<d){first=gold+1;}
		else if(data[gold]>d){last=gold-1;}
		return gold;
	}
}



/*

��10�֣�

���Ա�洢������a[N]��ǰnum�������У��ҵ��������Ա�д�㷨����x���뵽���Ա�ʹ��������

*/
#define ElemType int 	//Ԥ������������Ϊint
#define N 100 			//Ԥ�������Ա�洢������СNΪ100
typedef struct{
	ElemType data[N];
	int length;
}Sqlist;
void Insert_order(Sqlist &L,ElemType x){ //����󱣳ֵ�������
	int i=0;
	for(i=L.length-1;i>=0;i--){			//
		if(L.data[i]>x)L.data[i+1]=L.data[i];
	}
	L.data[i]=x;
	L.length++;
}


/*3
��15�֣�

��A��һ������Ϊn�����Ա�x�Ǳ����Ԫ�ء�������Ҫ�󣬷ֱ���дһ���㷨��
��A���ѳ��������Ա�B��C��ʹ��A����С��x��Ԫ�ض�����B���У������ڻ����x��Ԫ�ض�����C���С�Ҫ��

��1����A��B��C�ֱ�������a[n]��b[n]��c[n]˳��洢��

��2����A������a[n]˳��洢����B��C������洢�����ǽ�B��Ԫ�ش洢�������ǰ��Σ�C�洢�ں��Ρ�
*/
#define ElemType int 	//Ԥ������������Ϊint
void Separate_1(ElemType A[],ElemType B[],ElemType C[],int n){//A��һ������Ϊn�����Ա�
	int x=A[0],bi=0,ci=0; //biΪB�ĳ��ȣ�ciΪC�ĳ���
	for(int i=1;i<n;i++){
		if(A[i]<x)Insert_order(B,A[i],bi);
		else 	  Insert_order(C,A[i],ci);
	}
	Insert_order(C,x,ci); //�����Ԫ��xҲҪ����
}
void Insert_order(ElemType L[],ElemType x,int &length){ //����󱣳ֵ�������
	int i=0;
	for(i=length-1;i>=0;i--){			
		if(L[i]>x)L[i+1]=L[i];
	}
	L[i]=x;
	length++;
}

/*	�ÿ��������ԭ��*/
void Separate_2(ElemType a[],int n){//A��һ������Ϊn�����Ա�
	int lo=0;int hi=n;
	int i = lo, j = hi+1; 	// ����������ɨ����±�
	ElemType x = a[lo]; 	// 
	while (true)
	{ // 
		while (a[++i]<x) if (i == hi) break;
		while (x<a[--j]) if (j == lo) break;
		if (i >= j) break;
		exch(a, i, j);
	}
	exch(a, lo, j); // ��һ����ҲҪ����
}
void exch(ElemType a,int i,int j){
	int t=a[i];a[i]=a[j];a[j]=t;
}
