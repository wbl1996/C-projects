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
	printf("请输入一组乱序的数！");
	printf("你要输入的数的个数:");
	scanf("%d",&a);
	for(i=0;i<a;i++){
		printf("第%d个:",(i+1));
		scanf("%d",&arr[i]);
	}
	while(m=='y'||m=='Y'){
	printf("请输入你要查找的数:");
	scanf("%d",&c);
	if((sq_find(arr,a,c))==-1){
		printf("未找到！\n");
	}
	else{
	printf("已找到，是第%d个。\n",sq_find(arr,a,c));
	}
	getchar();
	printf("是否继续查找？Y/N:");
	scanf("%c",&m);
}
	return 0;
}
