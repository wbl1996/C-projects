#include<stdio.h>
int sq_find(int arr[],int n,int key){
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==key)
			return (i+1);
	}
	return -1;
} 
int main(){
	int i;
	int a,c;
	int arr[100];
	char m;
	m='y';
	printf("������һ�����������");
	printf("��Ҫ��������ĸ���:");
	scanf("%d",&a);
	for(i=0;i<a;i++){
		printf("��%d��:",(i+1));
		scanf("%d",&arr[i]);
	}
	while(m=='y'||m=='Y'){
	printf("��������Ҫ���ҵ���:");
	scanf("%d",&c);
	if((sq_find(arr,a,c))==-1){
		printf("δ�ҵ���\n");
	}
	else{
	printf("���ҵ����ǵ�%d����\n",sq_find(arr,a,c));
	}
	getchar();
	printf("�Ƿ�������ң�Y/N:");
	scanf("%c",&m);
}
	return 0;
}
