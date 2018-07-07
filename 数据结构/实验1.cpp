#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
#define max 100
typedef int Elemtype;
typedef struct btnode{
	Elemtype data;
	struct btnode *lchild;
	struct btnode *rchild;
}BTnode;
BTnode *p[MAXSIZE+1];
BTnode *creat(){
	int i,j;
	char ch;
	BTnode *t,*s;
	printf("\nenter(i,ch)until enter(0,#):\n");
	printf("enter i,ch:");
	scanf("%d,%c",&i,&ch);
	while(i!=0&&ch!='#'){
		s=(BTnode*)malloc(sizeof(BTnode));
		s->data = ch;
		s->lchild = s->rchild = NULL;
		p[i]=s;
		if(i==1){
			t=s; 
		}
		else{
			j=i/2;
			if(i%2==0){
				p[j]->lchild=s;
			}
			else{
				p[j]->rchild=s;
			}
		}
		printf("enter i,ch:");
		scanf("%d,%c",&i,&ch);
	}
	return t;
} 
void preOrder(BTnode *s){
	printf("%c",s->data);
	if(s->lchild!=NULL){
		preOrder(s->lchild);
	}
	if(s->rchild!=NULL){
		preOrder(s->rchild);
	}
}
void change(BTnode *t){
	BTnode *m;
	if(t){
	m=t->lchild;
	t->lchild=t->rchild;
	t->rchild=m;
	if(t->lchild!=NULL){
		change(t->lchild);
	}
	if(t->rchild!=NULL){
		change(t->rchild);
	}
}
}
void inOrder(BTnode *s){
	if(s==NULL){
		return;
	} 
	if(s->lchild!=NULL){
		inOrder(s->lchild);
	}
	printf("%c",s->data);
	if(s->rchild!=NULL){
		inOrder(s->rchild);
	}
}
void levelOrder(BTnode *t){
	BTnode *p,*q[max];
	int front,rear;
	front=rear=0;
	rear=(rear+1)%max;
	q[rear]=t;
	while(front!=rear){
		front=(front+1)%max;
		p=q[front];
		printf("%c",p->data);
		if(p->lchild){
			rear=(rear+1)%max;
			q[rear]=p->lchild;
		}
		if(p->rchild){
		rear=(rear+1)%max;
		q[rear]=p->rchild; 
	}
}
}
int main(){
	BTnode *s;
	s=creat();
	int num;
	char m;
	m='Y'; 
	while(m=='y'||m=='Y'){
	printf("请输入你要执行的操作：1、按层次遍历；2、交换左右孩子后按层次遍历:");
	scanf("%d",&num);
	switch(num){
		case 1:printf("按层次遍历:");
		       levelOrder(s);
		       break;
		case 2:printf("交换左右孩子后按层次遍历:");
		       change(s);levelOrder(s);
		       break;
		default:break;
	}
	getchar();
	printf("是否继续？Y/N:");
	scanf("%c",&m);
}
	return 0;
}
