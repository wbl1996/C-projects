#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct list
{
    int elem[MAXSIZE];
    int len;
}*Linklist;
void creat(Linklist L,int length)
{
    int i;
    L->len=length;
    int value;
    for(i=0;i<L->len;i++)
    {
        printf("第%d个：",(i+1));
        scanf("%d",&value);
        L->elem[i]=value;
    }
}
void insert(Linklist L,int m,int e)
{
    int i;
    for(i=L->len-1;i>=m-1;i--)
    {
        L->elem[i+1]=L->elem[i];
    }
    L->len++;
    L->elem[i+1]=e;
}
void deletedata(Linklist L,int n)
{
    int i;
    for(i=n;i<L->len;i++)
    {
        L->elem[i-1]=L->elem[i];
    }
    L->len--;
}
int main()
{
    int i;
    int a,b,c,len,l,h;
    char m,n;
    m='Y';
    n='Y';
    h='Y';
    Linklist L=(Linklist*)malloc(sizeof(struct list));
    printf("请输入你要创建的顺序表的长度:");
	scanf("%d",&len) ;
    creat(L,len);
    for(i=0;i<L->len;i++)
    {
        printf("%d\n",L->elem[i]);
    }
    while(h=='Y'||h=='y'){
    printf("请输入你要执行的操作：1、插入元素;2、删除元素:");
	scanf("%d",&l); 
    switch(l){
	case 1:
	while(m=='Y'||m=='y'){
    printf("请输入你要插入的元素位置：");
    scanf("%d",&a);
    if(a<1||a>len){
    	printf("你的输入有误！");
    	getchar();
    	printf("是否继续？Y/N:");
		scanf("%c",&m);
	}
	else{
    printf("请输入你要插入元素的值:");
	scanf("%d",&b) ;
    insert(L,a,b);
    for(i=0;i<L->len;i++)
    {
        printf("%d\n",L->elem[i]);
    }
	}break;
	}break;
    case 2:
    while(n=='Y'||n=='y'){
    printf("请输入你要删除的元素位置：");
    scanf("%d",&c);
    if(c<1||c>len){
	printf("输入错误！");
	getchar();
	printf("是否继续？Y/N：");
	scanf("%c",&n);
	}
	else{
    deletedata(L,c);
    for(i=0;i<L->len;i++)
        printf("%d\n",L->elem[i]);
    break;
}
}
break;
default :printf("你的输入有误!");
}
	getchar();
	printf("是否继续？Y/N：");
	scanf("%c",&h);
}
    return 0;
}

