#include<stdio.h> 
#include<stdlib.h>
#define null 0
//1表示int，2表示double，3表示char
typedef struct Node_S
{
    int type;
    void *pData;
    struct Node_S *pNext;

 } *pList;

 //创建空链表
pList CreateList(void) {
    pList l;
    l=(pList)malloc(sizeof(Node_S));
    if(l==null) 
	{
        printf("Out of space!!\n");
        return null;
	}
    l->pNext=null;//指针初始化，防止它乱指 
    l->pData=null;
    return l;
 }
 
 //链头插入(包含一个空表头 
pList InsertFro(pList l) {
	
    pList q;
    q=(pList)malloc(sizeof(Node_S));
    printf("链头插入：请输入新节点的类型(int请输1、double请输2、char请输3)\n");
    scanf("%d",&q->type);
    printf("请输入新节点的数据\n");
    if(q->type==1) {
        q->pData=(int*)malloc(sizeof(int)) ;
        scanf("%d",q->pData);//有输入的话就需要类型 
	}
    else if (q->type==2) {
        q->pData=(double*)malloc(sizeof(double))  ;
        scanf("%lf",q->pData);
	}
    else if (q->type==3) {
        q->pData=(char*)malloc(sizeof(char)) ;
        getchar();
        *(char*)(q->pData)=getchar();
	}
    else {
        printf("不存在该类型！\n");
        return l;
	}
	
    q->pNext=l->pNext;
    l->pNext=q;
    //printf("\n"); 
    return l;
}

//链尾插入
pList InsertBack(pList l)  {
    pList q,p;
    q=(pList)malloc(sizeof(Node_S));
    printf("链尾插入：请输入新节点的类型(int请输1、double请输2、char请输3)\n");
    scanf("%d",&q->type);
    printf("请输入新节点的数据\n");
    if(q->type==1) {
        q->pData=(int*)malloc(sizeof(int)) ;
        scanf("%d",q->pData);//有输入的话就需要类型 
	}
    else if (q->type==2) {
        q->pData=(double*)malloc(sizeof(double))  ;
        scanf("%lf",q->pData);
	}
    else if (q->type==3) {
        q->pData=(char*)malloc(sizeof(char)) ;
        getchar();
        *(char*)(q->pData)=getchar();
	}
    else {
        printf("不存在该类型！\n");
        return l;
	}
    p=l;
    while(p->pNext!=null) {
        p=p->pNext;
	}
    p->pNext=q;
    q->pNext=null;
   // printf("\n");
    return l;
}

//遍历链表输出
void PrintList(pList l)   {
    pList q;
    q=l->pNext;//因为有空表头 
    if(q==null) {
        printf("链表为空！");
	}
    else{
    printf("链表中数据为： "); 
    while(q!=null) {
        if(q->type==1) {
            printf("%d  ",*(int*)(q->pData));
		 }
        else if(q->type==2) {
            printf("%f  ",*(double*)(q->pData));
		 	
		 }
        else if(q->type==3) {
            printf("%c  ",*(char*)(q->pData));
		 }
        q=q->pNext;
	}}
    printf("\n");
   // printf("\n");
}

//链头节点删除
pList DeleteFro(pList l)  {
    pList q;
    q=l->pNext;
    if(q==null) {
        printf("链表为空！\n"); 
        return l;
	}
    else {
    l->pNext=q->pNext;
    free(q);//free的是变量q还是q中的内容，也就是说原来的链头 
    printf("链头节点已删除！\n");
    return l;
}
}


//链尾删除
pList DeleteBack(pList l)  {
    pList q,p;
    q=l;
    if(q->pNext==null) {
        printf("链表为空！\n"); 
        printf("\n");
        return l;
	}
    else  {
        while(q->pNext!=null) {
            p=q;
            q=q->pNext;
		}
        p->pNext=null;
        free(q);
        printf("链尾节点已删除！\n");
       // printf("\n");
        return l;
	} 
}


//链表的逆置 
pList  Reverse(pList l) {
    pList q,p,t,m,n;
    q=l->pNext;
    n=q;
	
    if(q==null)  {
        printf("链表为空！\n"); 
      //  printf("\n");
        return l;
	}
    else {
        p=q->pNext;
        if(p==null) {
            printf("链表已逆置！\n"); 
            //printf("\n");
            return l;
		}
        else {
            while (p->pNext!=null) {
                t=p->pNext;
                p->pNext=q;
                q=p;
                p=t;
}
            m=CreateList();
            m->pNext=p;
            p->pNext=q;
            n->pNext=null;
            free(l);
            printf("链表已逆置！\n"); 
            //printf("\n");
            return m;
	}}
}

//链表的销毁
void DestroyList(pList l) {
    pList p,t;
    p=l->pNext;
    while(p!=null) {
        t=p->pNext;
        free(p->pData);
        free(p);
        p=t;
		
	}
    free(l);
    printf("链表已销毁！\n"); 
    //printf("\n");
} 

//两个链表的合并
pList Join(pList l,pList j)  {
    pList q;
    q=l;
    while(q->pNext!=null) {
        q=q->pNext;
	}
    q->pNext=j->pNext;
    free(j);
    printf("两个链表已合二为一！\n"); 
    //printf("\n");
    return l;
}


//按某种顺序插入
pList InsertKth(pList l)  {
    pList q,p,t;
    int k,type,i;
    printf("请输入要在第几个位置插入数据\n");
    scanf("%d",&k);
    q=(pList)malloc(sizeof(Node_S));
    printf("请输入插入节点的类型\n");
    scanf("%d",&q->type);
    if(q->type==1) {
        q->pData=(int*)malloc(sizeof(int)) ;
        scanf("%d",q->pData);//有输入的话就需要类型 
	}
    else if (q->type==2) {
        q->pData=(double*)malloc(sizeof(double))  ;
        scanf("%lf",q->pData);
	}
    else if (q->type==3) {
        q->pData=(char*)malloc(sizeof(char)) ;
        getchar();
        *(char*)(q->pData)=getchar();
	}
    else {
        printf("不存在该类型！\n");
        return l;
	}
	//q->pNext=null;
    p=l;
    for(i=0;i<k-1;i++) {
        if(p==null) {
            printf("没有第%d个位置！\n",k);
            return l;
		}
        else{
        p=p->pNext;
		}
	}
    if(p==null) {
        printf("没有第%d个位置！\n",k);
        return l;
	}
    else {
	
    t=p->pNext;
    p->pNext=q;
    q->pNext=t;
    printf("插入成功！\n");
    return l;
	}
}


//满足某种条件节点删除 
pList DeleteKth(pList l) {
    pList q,p;
    int k,i;
    printf("请输入要在第几个位置删除数据\n");
    scanf("%d",&k);
    q=l;
    p=q->pNext;
    for(i=0;i<k-1;i++) {
        if(p==null)  {
            printf("没有第%d个位置！\n",k);
            return l;
		}
        else{
		
            q=p;
            p=p->pNext;
		}
	}
    if(p==null)  {
        printf("没有第%d个位置！\n",k);
        return l;
		}
    else {
		
        q->pNext=p->pNext;//删p 
        free(p);
        printf("删除成功！\n");
	}
}


int main(void) {
    pList l,j;
    l=CreateList();
    printf("建立一个新链表:\n");
    InsertBack(l);
    InsertBack(l);
    PrintList(l);
    InsertFro(l);
    PrintList(l);
    InsertKth(l);
    PrintList(l);
    l=Reverse(l);
    PrintList(l);
    DeleteKth(l);
    PrintList(l);
    DeleteFro(l);
    PrintList(l);
    DeleteBack(l);
    PrintList(l);
    
    
    printf("建立一个新链表:\n"); 
    j=CreateList();
    printf("向新链表中插入数据:\n") ;
    InsertBack(j);
    PrintList(j);
    Join(l,j);
    PrintList(l);
    DestroyList(l);
	
    return 0;
}
