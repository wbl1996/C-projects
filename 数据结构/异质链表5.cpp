#include<stdio.h> 
#include<stdlib.h>
#define null 0
//1��ʾint��2��ʾdouble��3��ʾchar
typedef struct Node_S
{
    int type;
    void *pData;
    struct Node_S *pNext;

 } *pList;

 //����������
pList CreateList(void) {
    pList l;
    l=(pList)malloc(sizeof(Node_S));
    if(l==null) 
	{
        printf("Out of space!!\n");
        return null;
	}
    l->pNext=null;//ָ���ʼ������ֹ����ָ 
    l->pData=null;
    return l;
 }
 
 //��ͷ����(����һ���ձ�ͷ 
pList InsertFro(pList l) {
	
    pList q;
    q=(pList)malloc(sizeof(Node_S));
    printf("��ͷ���룺�������½ڵ������(int����1��double����2��char����3)\n");
    scanf("%d",&q->type);
    printf("�������½ڵ������\n");
    if(q->type==1) {
        q->pData=(int*)malloc(sizeof(int)) ;
        scanf("%d",q->pData);//������Ļ�����Ҫ���� 
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
        printf("�����ڸ����ͣ�\n");
        return l;
	}
	
    q->pNext=l->pNext;
    l->pNext=q;
    //printf("\n"); 
    return l;
}

//��β����
pList InsertBack(pList l)  {
    pList q,p;
    q=(pList)malloc(sizeof(Node_S));
    printf("��β���룺�������½ڵ������(int����1��double����2��char����3)\n");
    scanf("%d",&q->type);
    printf("�������½ڵ������\n");
    if(q->type==1) {
        q->pData=(int*)malloc(sizeof(int)) ;
        scanf("%d",q->pData);//������Ļ�����Ҫ���� 
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
        printf("�����ڸ����ͣ�\n");
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

//�����������
void PrintList(pList l)   {
    pList q;
    q=l->pNext;//��Ϊ�пձ�ͷ 
    if(q==null) {
        printf("����Ϊ�գ�");
	}
    else{
    printf("����������Ϊ�� "); 
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

//��ͷ�ڵ�ɾ��
pList DeleteFro(pList l)  {
    pList q;
    q=l->pNext;
    if(q==null) {
        printf("����Ϊ�գ�\n"); 
        return l;
	}
    else {
    l->pNext=q->pNext;
    free(q);//free���Ǳ���q����q�е����ݣ�Ҳ����˵ԭ������ͷ 
    printf("��ͷ�ڵ���ɾ����\n");
    return l;
}
}


//��βɾ��
pList DeleteBack(pList l)  {
    pList q,p;
    q=l;
    if(q->pNext==null) {
        printf("����Ϊ�գ�\n"); 
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
        printf("��β�ڵ���ɾ����\n");
       // printf("\n");
        return l;
	} 
}


//��������� 
pList  Reverse(pList l) {
    pList q,p,t,m,n;
    q=l->pNext;
    n=q;
	
    if(q==null)  {
        printf("����Ϊ�գ�\n"); 
      //  printf("\n");
        return l;
	}
    else {
        p=q->pNext;
        if(p==null) {
            printf("���������ã�\n"); 
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
            printf("���������ã�\n"); 
            //printf("\n");
            return m;
	}}
}

//���������
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
    printf("���������٣�\n"); 
    //printf("\n");
} 

//��������ĺϲ�
pList Join(pList l,pList j)  {
    pList q;
    q=l;
    while(q->pNext!=null) {
        q=q->pNext;
	}
    q->pNext=j->pNext;
    free(j);
    printf("���������Ѻ϶�Ϊһ��\n"); 
    //printf("\n");
    return l;
}


//��ĳ��˳�����
pList InsertKth(pList l)  {
    pList q,p,t;
    int k,type,i;
    printf("������Ҫ�ڵڼ���λ�ò�������\n");
    scanf("%d",&k);
    q=(pList)malloc(sizeof(Node_S));
    printf("���������ڵ������\n");
    scanf("%d",&q->type);
    if(q->type==1) {
        q->pData=(int*)malloc(sizeof(int)) ;
        scanf("%d",q->pData);//������Ļ�����Ҫ���� 
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
        printf("�����ڸ����ͣ�\n");
        return l;
	}
	//q->pNext=null;
    p=l;
    for(i=0;i<k-1;i++) {
        if(p==null) {
            printf("û�е�%d��λ�ã�\n",k);
            return l;
		}
        else{
        p=p->pNext;
		}
	}
    if(p==null) {
        printf("û�е�%d��λ�ã�\n",k);
        return l;
	}
    else {
	
    t=p->pNext;
    p->pNext=q;
    q->pNext=t;
    printf("����ɹ���\n");
    return l;
	}
}


//����ĳ�������ڵ�ɾ�� 
pList DeleteKth(pList l) {
    pList q,p;
    int k,i;
    printf("������Ҫ�ڵڼ���λ��ɾ������\n");
    scanf("%d",&k);
    q=l;
    p=q->pNext;
    for(i=0;i<k-1;i++) {
        if(p==null)  {
            printf("û�е�%d��λ�ã�\n",k);
            return l;
		}
        else{
		
            q=p;
            p=p->pNext;
		}
	}
    if(p==null)  {
        printf("û�е�%d��λ�ã�\n",k);
        return l;
		}
    else {
		
        q->pNext=p->pNext;//ɾp 
        free(p);
        printf("ɾ���ɹ���\n");
	}
}


int main(void) {
    pList l,j;
    l=CreateList();
    printf("����һ��������:\n");
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
    
    
    printf("����һ��������:\n"); 
    j=CreateList();
    printf("���������в�������:\n") ;
    InsertBack(j);
    PrintList(j);
    Join(l,j);
    PrintList(l);
    DestroyList(l);
	
    return 0;
}
