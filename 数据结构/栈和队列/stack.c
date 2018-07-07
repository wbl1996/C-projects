#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define ADDSIZE 10
typedef int Elemtype;
typedef struct stack
{
    int len;
    Elemtype *top;
    Elemtype *base;
}SqStack;
void initstack(SqStack *s)
{
    s->base=(Elemtype *)malloc(MAXSIZE*sizeof(Elemtype));
    if(!s->base) printf("ERROR");
    s->top=s->base;
    s->len=s->top-s->base;
    
}
void push(SqStack *s,Elemtype e)
{
    if(s->top-s->base==MAXSIZE){
        printf("ջ����");
        s->base=(Elemtype *)realloc(s->base,(ADDSIZE+s->len)*sizeof(Elemtype));
        if(!s->base) printf("ERROR!");
        s->top=s->base+ADDSIZE;
    }
    else{
    *(s->top)=e;
    s->top++;
    s->len++;
}
}
void pop(SqStack *s)
{
    if(s->len==0)
    {
        printf("ջ�գ��޷�ִ�г�ջ������\n");
    }
    else
    {
        s->top--;
        s->len--;
        if(s->len==0){
        	printf("ջ�գ�\n");
		}else{
        printf("��ɾ��ջ��Ԫ�أ�");
    }
    }
}
void getTop(SqStack *s)
{
	if(s->len==0){
		printf("ջΪ�գ���ͷԪ�أ�\n");
	}
	else{
    printf("ջ��Ԫ��Ϊ:%d\n",*(s->top-1));
}
}
void display(SqStack *s)
{
    Elemtype *p=s->top;
    if(s->len==0){
    	printf("ջΪ�գ��޷���ӡ��\n");
	}
	else{
    printf("ջ�Զ����µ�Ԫ��Ϊ:\n");
    while(p!=s->base)
    {
        p--;
        printf("%d",*p);
        printf("\n");
    }
}
}
int main()
{
    int i=0;
    int m,n,a,b;
    char a1,a2,a3,a4;
    a1='Y';
    a2='Y';
    a3='Y';
    a4='Y';
    SqStack *s =(SqStack *)malloc(sizeof(SqStack));
    initstack(s);
    printf("*******ջ�Ļ�������*******\n");
    printf("*********1����ջ**********\n");
    printf("*********2����ջ**********\n");
    while(a2=='Y'||a2=='y'){
    printf("��������Ҫ���еĲ���:");
    scanf("%d",&a);
    switch(a){
        case 1:
    printf("��������Ҫ��ջ��Ԫ��:");
    scanf("%d",&n);
    push(s,n);
    getTop(s);
    display(s);
    break;
    case 2:
    pop(s);
    getTop(s);
    display(s);
    break;
    default:printf("�����������");
    break;
    }
    getchar();
    printf("�Ƿ������Y/N:");
    scanf("%c",&a2);
}
printf("������ֹͣ���У�");
    return 0;
}
