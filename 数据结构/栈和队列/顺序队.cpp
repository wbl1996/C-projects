#include<stdio.h>
#include<stdlib.h>
#define MAX 30 
typedef int Elemtype;
typedef struct queue{
	Elemtype front;
	Elemtype rear;
	Elemtype data[MAX];
}*SqQueue;
SqQueue InitQueue(){
	SqQueue q;
	q=(SqQueue)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
	return q;
}
void getHead(SqQueue q){
	if(q->front==q->rear){
		printf("队列为空，无头元素!\n"); 
	}
	else
		printf("头元素为:%d\n",q->data[q->front]);
}
int getLength(SqQueue q){
	return q->rear-q->front;
}
Insert(SqQueue q,Elemtype e){
	if(q->rear== MAX-1){
		printf("队满，无法插入元素！\n");
	}
	if(q->front==q->rear){
		q->front = q->rear=0;
		q->data[q->rear]=e;
		q->rear++;
	}
	else{
		q->data[q->rear]=e;
		q->rear++;
	}
}
void DelElement(SqQueue q,Elemtype y){
	if(q->front==q->rear){
		printf("队列为空，无法删除！\n");
	}
	y=q->data[q->front];
	q->front++;
}
void clear(SqQueue q){
	q->front=q->rear=-1;
	printf("队列已清空！\n");
}
void destroy(SqQueue q){
	free(q);
	printf("队列已销毁！\n"); 
} 
print(SqQueue q){
	if(q->front==q->rear){
		printf("队列为空！\n");
	}
	else{
	int i;
	printf("队列元素从头到尾为:\n");
	for(i=q->front;i<q->rear;i++){
		printf("%d\n",q->data[i]);
	}
}
}
int main(){
	int i;
	int m,n,y;
	char a,b;
	int k; 
	a='y';
	b='y';
	SqQueue q=InitQueue();
	while(a=='y'||a=='Y'){
	printf("请输入你要进行的操作:1,入队；2,出队:");
	scanf("%d",&k);
	switch(k){
		case 1:
	printf("请输入你要入队的元素个数:");
	scanf("%d",&m);
	while(b=='Y'||b=='y'){
	if(m>MAX){
		printf("要入队的元素个数大于队列长度！\n");
		getchar();
		printf("是否重新输入要入队的元素个数？Y/N：");
		scanf("%c",&a);
	}
	else break;
}
	for(i=0;i<m;i++){
		printf("请输入你要入队的第%d个元素:",(i+1));
		scanf("%d",&n);
		Insert(q,n);
	}
		getHead(q);
		
	print(q);
	printf("队列长度为:%d\n",getLength(q));
	break;
	case 2:
	DelElement(q,y);
	print(q);
	getHead(q);
	printf("队列长度为:%d\n",getLength(q));
	break;
	default: break;}
	getchar();
	printf("是否继续？Y/N:");
	scanf("%c",&a) ;
}
	clear(q);
	destroy(q);
	return 0;
	}
