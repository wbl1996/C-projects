#include<stdio.h>
int bi_find(int arr[],int e,int begin ,int last){
	int mid;
	if(begin>last)
		return -1;
	while(begin<=last){
		mid=(begin+last)/2;
		if(e==arr[mid])
			return mid;
		else if(arr[mid]<e)
			begin = mid+1;
		else if(arr[mid]>e)
			last = mid-1;
	} 
	return -1;
} 
int main(){
	int a;
	int i,b;
	char c;
	c='y';
	int arr[100];
	printf("������һ���С����ĵ�����!\n");
	printf("�������������ĸ���:");
	scanf("%d",&b);
	for(i=0;i<b;i++){
		printf("��%d��:",(i+1));
		scanf("%d",&arr[i]); 
	}
	//int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	while(c=='y'||c=='Y'){
	printf("��������Ҫ���ҵ�Ԫ��:");
	scanf("%d",&a);
	if((bi_find(arr,a,0,b))==-1){
		printf("δ�ҵ���");
	}
	else{
	printf("���ҵ�,�ǵ�%d����\n",(bi_find(arr,a,0,b)+1));
	}
	getchar();
	printf("�Ƿ�������ң�Y/N:");
	scanf("%c",&c);
	}
	return 0;
}
