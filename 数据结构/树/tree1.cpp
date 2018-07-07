#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct tree{
	Elemtype data;
	struct tree *lchild;
	struct tree *rchild;
}BiTreeNode,*Bitree; 
void creatBiTree(Bitree &t){
	char data;
	data = getchar();
	if(data == '#'){
		t = NULL;
	}
	else{
		t = new BiTreeNode;
		t->data = data;
		creatBiTree(t->lchild);
		creatBiTree(t->rchild);
	}
}
void printBiTree(Bitree &t){
	if(t){
		printf("%d",t->data);
		if(t->lchild||t->rchild){
			printf("(");
			printBiTree(t->rchild);
			if(t->rchild){
				printf(",");
				printBiTree(t->rchild);
			}
			printf(")");
		}
	}
}
void preOrder(Bitree &t){
	if(t){
		printf("%c",t->data);
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}
void inOrder(Bitree &t){
	if(t){
		inOrder(t->lchild);
		printf("%c",t->data);
		inOrder(t->rchild);
	}
}
void lastOrder(Bitree &t){
	if(t){
		lastOrder(t->lchild);
		lastOrder(t->rchild);
		printf("%c",t->data); 
}
}
void destroyTree(Bitree &t){
	if(t){
		destroyTree(t->lchild);
		destroyTree(t->rchild);
		delete t;
		t=NULL;
	}
}
int main(){
	Bitree  t =NULL;
	creatBiTree(t);
	printf("二叉树创建成功！\n"); 
	printf("先序遍历:");
	preOrder(t);
	printf("\n");
	printf("中序遍历:");
	inOrder(t);
	printf("\n");
	printf("后序遍历:");//ABD#F##E##CG##H#I##
	lastOrder(t);
	printf("\n");
	destroyTree(t);
	printf("二叉树已销毁！"); 
	return 0;
}
