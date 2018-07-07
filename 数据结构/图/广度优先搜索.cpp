#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXVEX 100
#define MAXSIZE 100
typedef int Edgetype;
typedef int Elemtype; 
typedef char Vertextype;  
typedef struct graph{
	Vertextype  vex[MAXVEX];
	Edgetype arc[MAXVEX][MAXVEX];
	int numNodes,numEdges;
}MGraph;
typedef struct queue{
	Elemtype front;
	Elemtype rear;
	Elemtype data[MAXSIZE];
}*SqQueue;
int isEmpty(SqQueue q){
	if(q->front=q->rear){
		return 1;
	}
	return 0;
}
SqQueue InitQueue(){
	SqQueue q;
	q=(SqQueue)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
	return q;
}
void Insert(SqQueue q,Elemtype e){
	if(q->rear== MAXSIZE-1){
		printf("队满，无法插入元素！\n");
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
		printf("队列为空，无法删除！\n");
	}
	y=q->data[q->front];
	q->front++;
}
void CreateMGraph(MGraph *Gp){
	int i,j,k;
	printf("请输入顶点数:");
	scanf("%d",&Gp->numNodes);
	printf("请输入边数:");
	scanf("%d",&Gp->numEdges);
	printf("请输入顶点信息:\n");
	for(i=0;i<Gp->numNodes;i++){
		scanf("%s",&Gp->vex[i]);
	} 
	for(i=0;i<Gp->numNodes;i++){ 
		for(j=0;j<Gp->numNodes;j++){ 
			Gp->arc[i][j]=0;
			}
		}
	for(k=0;k<Gp->numEdges;k++){
		printf("请输入边(vi,vj)的标号i,j:");
		scanf("%d%d",&i,&j);
		Gp->arc[i][j]=1;
		Gp->arc[j][i]=1;
	}
	for(i=0;i<Gp->numNodes;i++){
		for(j=0;j<Gp->numNodes;j++){
			printf("%d\t",Gp->arc[i][j]);
		}
		printf("\n");
	}
}
int visited[MAXVEX]; 
void BFS(MGraph *Gp){
	int i,j;
	int y;
	SqQueue q = InitQueue();
	for(i=0;i<Gp->numNodes;i++){
		if(visited[i]==0){
			visited[i]=1;
			printf("%c",Gp->vex[i]);
			Insert(q,i);
			while(!isEmpty(q)){
				DelElement(q,y);
				for(j=0;j<Gp->numNodes;j++){
					if(Gp->arc[i][j==1]&&visited[j]==0){
						visited[j]=1;
						printf("%d",Gp->vex[j]);
						Insert(q,j);
					}
				}
			}
		}
	}
}
int main(){
	MGraph MG;
	CreateMGraph(&MG);
	printf("广度优先搜索:");
	BFS(&MG);
	return 0;
}
