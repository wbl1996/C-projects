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
		printf("����Ϊ�գ���ͷԪ��!\n"); 
	}
	else
		printf("ͷԪ��Ϊ:%d\n",q->data[q->front]);
}
int getLength(SqQueue q){
	return q->rear-q->front;
}
Insert(SqQueue q,Elemtype e){
	if(q->rear== MAX-1){
		printf("�������޷�����Ԫ�أ�\n");
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
		printf("����Ϊ�գ��޷�ɾ����\n");
	}
	y=q->data[q->front];
	q->front++;
}
void clear(SqQueue q){
	q->front=q->rear=-1;
	printf("��������գ�\n");
}
void destroy(SqQueue q){
	free(q);
	printf("���������٣�\n"); 
} 
print(SqQueue q){
	if(q->front==q->rear){
		printf("����Ϊ�գ�\n");
	}
	else{
	int i;
	printf("����Ԫ�ش�ͷ��βΪ:\n");
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
	printf("��������Ҫ���еĲ���:1,��ӣ�2,����:");
	scanf("%d",&k);
	switch(k){
		case 1:
	printf("��������Ҫ��ӵ�Ԫ�ظ���:");
	scanf("%d",&m);
	while(b=='Y'||b=='y'){
	if(m>MAX){
		printf("Ҫ��ӵ�Ԫ�ظ������ڶ��г��ȣ�\n");
		getchar();
		printf("�Ƿ���������Ҫ��ӵ�Ԫ�ظ�����Y/N��");
		scanf("%c",&a);
	}
	else break;
}
	for(i=0;i<m;i++){
		printf("��������Ҫ��ӵĵ�%d��Ԫ��:",(i+1));
		scanf("%d",&n);
		Insert(q,n);
	}
		getHead(q);
		
	print(q);
	printf("���г���Ϊ:%d\n",getLength(q));
	break;
	case 2:
	DelElement(q,y);
	print(q);
	getHead(q);
	printf("���г���Ϊ:%d\n",getLength(q));
	break;
	default: break;}
	getchar();
	printf("�Ƿ������Y/N:");
	scanf("%c",&a) ;
}
	clear(q);
	destroy(q);
	return 0;
	}
