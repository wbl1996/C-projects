#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node{
	Elemtype data;
	struct node *next;
}Lnode; 
void creat(Lnode *head,int n){
	Lnode *p1,*s;
	int i;
	p1=head; 
	for(i=1;i<=n;i++){
		s=(Lnode*)malloc(sizeof(Lnode));
		printf("��%d���ڵ�����:",i);
		scanf("%d",&s->data);
		p1->next=s;
		p1=s; 
	}
	p1->next=NULL;
} 
void print(Lnode *head){
	Lnode *p;
	p=head->next;
	if(p==NULL){
		printf("����Ϊ�գ�");
	}
	while(p!=NULL){
		printf("����:%d\t\n",p->data);
		p=p->next;
	}
}
void destroy(Lnode *head){
	Lnode *p;
	Lnode *q;
	p=head;
	while(p->next!=NULL){
		q=p->next;
		free(p);
		p=q;
	}
}
void insert(Lnode *head,int a,int e){
	int i;
	Lnode *p;
	Lnode *q;
	Lnode *s;
	p=head;
	q=p->next;
	s=(Lnode *)malloc(sizeof(Lnode));
	s->data=e;
	for(i=1;i<a;i++){
		p=q;
		q=q->next;
	}
	s->next=q;
	p->next=s;
}
void deletee(Lnode *head,int m){
	int i;
	Lnode *p;
	Lnode *q;
	p=head;
	q=p->next;
	for(i=1;i<m;i++){
		p=q;
		q=q->next;
	}
	p->next=q->next;
	free(q);
}
int main(){
	int m,n;
	Lnode *head;
	int a,b,c;
	char w,r,s;
	w='Y';
	r='Y';
	s='Y';
	head=(Lnode*)malloc(sizeof(Lnode));
	printf("��������\n");
	printf("��������Ҫ������������:");
	scanf("%d",&m);
	creat(head,m);
	while(w=='Y'||w=='y'){
	printf("��ѡ����Ҫ���еĲ�����\n");
	printf("1��������������������\n");
	printf("2����������������ɾ��\n"); 
	printf("������:");
	scanf("%d",&n);
	switch(n){
		case 1:
		while(r=='Y'||r=='y'){
		printf("��������Ҫ����Ԫ�ص�λ��:");
		scanf("%d",&a);
		if(a<1||a>m){
			printf("�����������!");
			getchar();
			printf("�Ƿ������Y/N��");
			scanf("%c",&r); 
					}
		else{
		printf("��������Ҫ����Ԫ�ص�ֵ:");
		scanf("%d",&b);insert(head,a,b);print(head); break;
		}
		}break;
		case 2:
		while(s=='Y'||s=='y'){
		if(head->next==NULL){
			printf("����Ϊ�գ��޷�ɾ����");
			break;
		}
		else{
		printf("��������Ҫɾ����Ԫ�ص�λ��:");
		scanf("%d",&c);
		if(c<1||c>m){
			printf("�����������");
			getchar();
			printf("�Ƿ������Y/N��");
			scanf("%c",&s);
		}
		else{
		deletee(head,c);print(head);break;
	}
	}
	}break;
	default :printf("�����������");
	}
	getchar();
	printf("�Ƿ������Y/N:");
	scanf("%c",&w);
}
	printf("������ֹͣ���У�"); 
	destroy(head);
	return 0;
	
} 
