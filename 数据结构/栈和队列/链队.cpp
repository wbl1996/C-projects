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
		printf("����Ϊ�գ���ͷԪ�أ�\n");
	}
	else{
	printf("ͷԪ��Ϊ:%d\n",q->front->data);
}
}
Del(LQueue q){
	if(q->length==0){
		printf("����Ϊ�գ��޷�ɾ����\n");
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
	printf("��������գ�\n");
}
print(LQueue q){
	Lnode p;
	p=q->front;
	if(q->length==0){
		printf("����Ϊ��!\n"); 
	}
	else{
	printf("��ǰ����Ԫ��Ϊ:\n");
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
	printf("��������Ҫ��ӵ�Ԫ�ظ���:");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		printf("��������Ҫ��ӵĵ�%d��Ԫ�أ�",(i+1));
		scanf("%d",&n);
		Insert(q,n);
	}
	print(q);
	getHead(q);
	printf("���г���Ϊ:%d\n",getLength(q));
	for(i=0;i<m;i++){
		Del(q);
		print(q);
		getHead(q);
		printf("���г���Ϊ:%d\n",getLength(q));
	}
	clear(q);
	return 0;
	
}
