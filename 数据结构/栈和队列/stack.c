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
        printf("栈满！");
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
        printf("栈空！无法执行出栈操作！\n");
    }
    else
    {
        s->top--;
        s->len--;
        if(s->len==0){
        	printf("栈空！\n");
		}else{
        printf("已删除栈顶元素！");
    }
    }
}
void getTop(SqStack *s)
{
	if(s->len==0){
		printf("栈为空，无头元素！\n");
	}
	else{
    printf("栈顶元素为:%d\n",*(s->top-1));
}
}
void display(SqStack *s)
{
    Elemtype *p=s->top;
    if(s->len==0){
    	printf("栈为空，无法打印！\n");
	}
	else{
    printf("栈自顶向下的元素为:\n");
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
    printf("*******栈的基本操作*******\n");
    printf("*********1、入栈**********\n");
    printf("*********2、出栈**********\n");
    while(a2=='Y'||a2=='y'){
    printf("请输入你要进行的操作:");
    scanf("%d",&a);
    switch(a){
        case 1:
    printf("请输入你要入栈的元素:");
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
    default:printf("你的输入有误！");
    break;
    }
    getchar();
    printf("是否继续？Y/N:");
    scanf("%c",&a2);
}
printf("程序已停止运行！");
    return 0;
}
