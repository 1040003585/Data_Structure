void get_next(char T[],int next[]){
	//T[0]���T�ĳ��� 
	int i=1;
	next[1]=0;
	j=0;
	while(i<=T[0]){
		if(j==0||T[i]==T[j]){
			i++;j++;next[i]=j;
		}else{
			j=next[j];
		}
	}
}
int KMP(char S[],char T[],int next[],int pos){
//1<=pos<=strlen(s) ��������posλ�ÿ�ʼ 
	i=pos;j=1;
	while(i<=S[0]&&j<=T[0]){
		if(j==0||S[i]==T[j]){
			i++;j++;
		}else{
			j=next[j];
		}
	}
}
