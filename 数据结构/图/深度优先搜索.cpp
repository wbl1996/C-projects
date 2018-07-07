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
void CreateMGraph(MGraph *Gp){
	int i,j,k;
	printf("�����붥����:");
	scanf("%d",&Gp->numNodes);
	printf("���������:");
	scanf("%d",&Gp->numEdges);
	printf("�����붥����Ϣ:\n");
	for(i=0;i<Gp->numNodes;i++){
		scanf("%s",&Gp->vex[i]);
	} 
	for(i=0;i<Gp->numNodes;i++){ 
		for(j=0;j<Gp->numNodes;j++){ 
			Gp->arc[i][j]=0;
			}
	}
	for(k=0;k<Gp->numEdges;k++){
		printf("�������(vi,vj)�ı��i,j:");
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
int visited[MAXVEX] = {0}; 
void DFS(MGraph *Gp,int i){
	int j;
	visited[i]=1;
	printf("%c",Gp->vex[i]);
	for(j=0;j<Gp->numNodes;j++){
		if(Gp->arc[i][j]==1&&visited[j]==0){
			DFS(Gp,j);
		}
	}
}
int main(){
	MGraph G;
	int i;
	CreateMGraph(&G);
	printf("�����������:");
	DFS(&G,0);
}
