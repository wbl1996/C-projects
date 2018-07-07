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
int main(){
	BTnode *s;
	s = creat();
	printf("先序遍历:");
	preOrder(s); 
	printf("中序遍历:");
	inOrder(s);
	return 0;
}
