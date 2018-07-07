#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node{
	Elemtype data;
	struct node *next;
}*Lnode;
typedef struct queue{
	Lnode front;
	Lnode rear;
	Elemtype length;
}*LQueue;
LQueue creat(LQueue q){
	//q=(LQueue)malloc(sizeof(LQueue));
	q->front=NULL;
	q->rear=NULL;
	q->length=0;
} 
int getLength(LQueue q){
	return q->length;
}
int IsEmpty(LQueue q){
	if(q->length==0)
		return 1;
	return 0;
	}
Insert(LQueue q,Elemtype e){
	Lnode n = (Lnode)malloc(sizeof(Lnode));
	n->data=e;
	n->next=NULL;
	if(q->length==0){
		q->front=n;
		q->rear=n;
	}
	else{
		q->rear->next=n;
		q->rear=n;
	}
	q->length++;
}
void getHead(LQueue q){
	if(IsEmpty(q)){
		printf("队列为空，无头元素！\n");
	}
	else{
	printf("头元素为:%d\n",q->front->data);
}
}
Del(LQueue q){
	if(q->length==0){
		printf("队列为空，无法删除！\n");
	}
	Lnode p;
	p=q->front;
	q->front=p->next;
	q->length--;
}
void clear(LQueue q){
	q->front=NULL;
	q->rear=NULL;
	q->length=0;
	printf("队列已清空！\n");
}
print(LQueue q){
	Lnode p;
	p=q->front;
	if(q->length==0){
		printf("队列为空!\n"); 
	}
	else{
	printf("当前队列元素为:\n");
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next; 
	}
}
}
int main(){
	int i;
	int m,n,y;
	LQueue q;
	q=(LQueue)malloc(sizeof(LQueue));
	creat(q);
	Lnode a;
	a=q->front;
	printf("请输入你要入队的元素个数:");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		printf("请输入你要入队的第%d个元素：",(i+1));
		scanf("%d",&n);
		Insert(q,n);
	}
	print(q);
	getHead(q);
	printf("队列长度为:%d\n",getLength(q));
	for(i=0;i<m;i++){
		Del(q);
		print(q);
		getHead(q);
		printf("队列长度为:%d\n",getLength(q));
	}
	clear(q);
	return 0;
	
}
