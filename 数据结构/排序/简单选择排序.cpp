#include<stdio.h>
#include<stdlib.h>
#define MAX 30
typedef char Datatype;
typedef struct{
	int key;
	Datatype data; 
}RcdType;
RcdType r[MAX-1];
void SelectSort(RcdType r[],int n){
	int i,j,k;
	RcdType t; 
	for(i=1;i<n;i++){
		k=i;
		for(j=i+1;j<=n;j++){
			if(r[j].key<r[k].key)
				k=j;
			if(i!=k){
				t=r[i];
				r[i]=r[k];
				r[k]=t;
			}
		}
	}
	for(i=1;i<=n;i++){
		printf("%d,%c\n",r[i].key,r[i].data); 
	}
} 
int main(){
	int i,a;
	RcdType r[MAX-1];
	printf("��������Ҫ���������Ԫ�ظ���:");
	scanf("%d",&a);
	for(i=0;i<a;i++){
		printf("�������%d��Ԫ�ؼ�ֵ:",(i+1));
		scanf("%d",&r[i+1].key);
		printf("�������%d��Ԫ�ص�����:",(i+1));
		scanf("%s",&r[i+1].data);
	}
	SelectSort(r,a);
	return 0;
}

