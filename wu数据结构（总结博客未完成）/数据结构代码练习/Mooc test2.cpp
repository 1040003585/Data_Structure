/*
3
（5分）

改写二分查找算法，将“中值点”改为“黄金分割”点，即0.618处（而非0.5处）。

*/

#define ElemType int //预定义数据类型为int
int BinarySeartch_gold(ElemType data[],int first,int last,int d){
	int gold=(first+last)/0.618;       //“黄金分割”点
	while(first<last){
		if(data[gold]<d){first=gold+1;}
		else if(data[gold]>d){last=gold-1;}
		return gold;
	}
}



/*

（10分）

线性表存储在数组a[N]的前num个分量中，且递增有序，试编写算法，将x插入到线性表使其仍有序。

*/
#define ElemType int 	//预定义数据类型为int
#define N 100 			//预定义线性表存储容量大小N为100
typedef struct{
	ElemType data[N];
	int length;
}Sqlist;
void Insert_order(Sqlist &L,ElemType x){ //插入后保持递增有序
	int i=0;
	for(i=L.length-1;i>=0;i--){			//
		if(L.data[i]>x)L.data[i+1]=L.data[i];
	}
	L.data[i]=x;
	L.length++;
}


/*3
（15分）

设A是一个长度为n的线性表，x是表的首元素。按下述要求，分别试写一个算法，
将A分裂成两个线性表B和C。使得A表中小于x的元素都放在B表中，而大于或等于x的元素都放在C表中。要求：

（1）若A，B，C分别用数组a[n]，b[n]和c[n]顺序存储。

（2）若A用数组a[n]顺序存储，但B和C不另外存储，而是将B的元素存储在数组的前半段，C存储在后半段。
*/
#define ElemType int 	//预定义数据类型为int
void Separate_1(ElemType A[],ElemType B[],ElemType C[],int n){//A是一个长度为n的线性表
	int x=A[0],bi=0,ci=0; //bi为B的长度，ci为C的长度
	for(int i=1;i<n;i++){
		if(A[i]<x)Insert_order(B,A[i],bi);
		else 	  Insert_order(C,A[i],ci);
	}
	Insert_order(C,x,ci); //表的首元素x也要插入
}
void Insert_order(ElemType L[],ElemType x,int &length){ //插入后保持递增有序
	int i=0;
	for(i=length-1;i>=0;i--){			
		if(L[i]>x)L[i+1]=L[i];
	}
	L[i]=x;
	length++;
}

/*	用快速排序的原理*/
void Separate_2(ElemType a[],int n){//A是一个长度为n的线性表
	int lo=0;int hi=n;
	int i = lo, j = hi+1; 	// 从左右两边扫描的下标
	ElemType x = a[lo]; 	// 
	while (true)
	{ // 
		while (a[++i]<x) if (i == hi) break;
		while (x<a[--j]) if (j == lo) break;
		if (i >= j) break;
		exch(a, i, j);
	}
	exch(a, lo, j); // 第一个数也要插入
}
void exch(ElemType a,int i,int j){
	int t=a[i];a[i]=a[j];a[j]=t;
}
