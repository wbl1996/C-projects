#include<stdio.h>
#include<stdlib.h>
#define MAX 30
typedef char DataType;
typedef struct
{
    int key;
    char data;
}RcdType;
RcdType r[MAX-1];
void Heap(RcdType r[],int i,int m)
{
    
    int j;
    RcdType x;
    x=r[i];
    j=2*i;
    while(j<=m){
    	if(j<m){
    		if(r[j].key>r[j+1].key)
    			j++;
    		if(r[j].key<x.key){
    			r[i]=r[j];
    			i=j;
    			j=2*i;
			}
			else break;
		}
		else{
			if(r[i].key>r[j].key){
				r[i]=r[j];
				i=j;
				j=2*i;
			}
			else break;
		}
	}
    r[i]=x;
}
void HeapSort(RcdType r[],int n){
	int i;
	RcdType x;
	for(i=n/2;i>=1;i--){
		Heap(r,i,n);
	}
	for(i=n;i>=1;i--){
		x=r[1];
		r[1]=r[i];
		r[i]=x;
		Heap(r,1,i-1);
	}
}
int main()
{
   int i;
   int a;
   printf("请输入要进行排序的元素个数:");
   scanf("%d",&a);
   for(i=1;i<=a;i++){
   	printf("请输入第%d个元素的键值:",i);
   	scanf("%d",&r[i].key);
   	printf("请输入第%d个元素的数据:",i);
   	scanf("%s",&r[i].data);
   }
   printf("堆排序之前的顺序:");
   for(i=1;i<=a;i++){
   	printf("%d,%c\t",r[i].key,r[i].data);
   }
   printf("\n堆排序之后的顺序:"); 
   HeapSort(r,a);
   for(i=a;i>=1;i--){
   	printf("%d,%c\t",r[i].key,r[i].data);
   }
   return 0;
   
}
