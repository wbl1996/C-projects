#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef char Datatype;
typedef struct{
	int key;
	Datatype oth;
}RcdType;
RcdType r[MAXSIZE-1];
void InsertSort(RcdType r[],int n){
	int i,j; 
	for(i=1;i<=n;i++){
		r[0]=r[i];
		j=i-1;
		while(r[0].key<r[j].key){
			r[j+1]=r[j];
			j--;
			r[j+1]=r[0];
		}
	}
	for(i=1;i<=n;i++){
		printf("%d,%c\n",r[i].key,r[i].oth);
	}
}
int main(){
	int i,a;
	printf("��������Ҫ���������Ԫ�ظ���:");
	scanf("%d",&a);
	for(i=0;i<a;i++){
		printf("��%d��Ԫ�صļ�ֵ:",(i+1));
		scanf("%d",&r[i+1].key); 
		printf("��%d��Ԫ�ص�����:",(i+1));
		scanf("%s",&r[i+1].oth); 
	}
	InsertSort(r,a);
	return 0;
}
