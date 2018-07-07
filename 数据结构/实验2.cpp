#include<iostream> 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#define MAXVEX 100
#define MAXSIZE 100
#define MAXINT 32767
#define MAXNUM 10
using namespace std;
typedef int Edgetype;
typedef int Elemtype;
typedef string Vertextype;
typedef struct graph {
	Vertextype  vex[MAXVEX];         //��Žڵ����� 
	Edgetype arc[MAXVEX][MAXVEX];    //������ڵ��Ȩֵ 
	int numNodes;
	int numEdges;
}MGraph;
//����������֣����س��ж�Ӧ����ʱ�ı�ţ�����������
int name(MGraph *Gp, string a) {                
	int i;
	for (i = 0; i < Gp->numNodes; i++) {
		if (Gp->vex[i] == a)
			return i;
	}
}
void CreateMGraph(MGraph *Gp) {           //ͼ�Ĵ��� 
	int i, j;
	int m;
	cout << "�������������:";
	cin >> Gp->numNodes;
	string a;
	cout << "�������������(0-" << Gp->numNodes << "):" << endl;
	for (i = 0; i<Gp->numNodes; i++) {                         //�������ĸ��ڵ����� 
		cin >> a;
		Gp->vex[i] = a;
	}
	for (i = 0; i<Gp->numNodes; i++) {            //��ʼ���ڽӾ��� 
		for (j = 0; j<Gp->numNodes; j++) {
			Gp->arc[i][j] = MAXINT;
		}
	}
	string x,y;
	cout << "�����������е����ּ�����֮��ľ���(�������������֮����ÿո����)(�Գ�������Ϊ#������:"<<endl;
	//ͨ������������ֺͶ�ӦȨֵ���޸��ڽӾ����е����� 
	while (x != "#") {	                                               
		cin >> x >> y >> m;
		Gp->arc[name(Gp,x)][name(Gp, y)] = m;
	}
}
//dijkstra�㷨��
void dijkstra(MGraph *Gp, int v0, int path[], int dist[]) {        
	int i, j, k, mindist;
	int u;
	int s[MAXNUM];          //s[i]=1��ʾi�Ѿ�ѡ�� 
	//��ʼ s��path,dist��path[i]��ʾi��ǰ���㣬dist[i]��ʾ����ʼ�㵽i���Ȩֵ
	for (i = 0; i<Gp->numNodes; i++) {      
		s[i] = 0;
		dist[i] = Gp->arc[v0][i];
		if (i != v0&&dist[i]<MAXINT) {
			path[i] = v0;
		}
		else
			path[i] = -1;
	}
	dist[v0] = 0;       //��ʼ�㵽�����ȨֵΪ0 
	s[v0] = 1;          //�Ȱ���ʼ��ȡ�� 
	u = v0;        //u���м������ʼ�մ洢Ȩֵ��С�ĵ� 

	for (i = 0; i<Gp->numNodes - 1; i++) {
		mindist = MAXINT;
		for (j = 0; j<Gp->numNodes; j++) {
			if (!s[j] && dist[j]<mindist) {
				u = j;
				mindist = dist[j];
			}
		}
		s[u] = 1;
		/*�������ʼ�㵽i�������ڴ���ʼ
		�㵽�м����ϴ��м�㵽i�ľ��룬
		�Ǿ͸��´���ʼ�㵽i��Ȩֵ*/ 
		for (k = 0; k<Gp->numNodes; k++) {    
			if (!s[k] && Gp->arc[u][k]<MAXINT && (dist[k]>mindist + Gp->arc[u][k])) {
				dist[k] = mindist + Gp->arc[u][k];
				path[k] = u;
			}
		}
	}
}
//���Ҫ��������е����·������̾���
void display(MGraph *Gp,int v0,int v1,int path[], int dist[]) { 
	int i, next;
	for (i = 0; i<Gp->numNodes; i++) {
		if(i==v1){
		if (dist[i] < MAXINT&&i != v0) {
			cout << Gp->vex[i] << "<--";
			next = path[i];
			while (next != v0) {
				cout << Gp->vex[next] << "<--";
				next = path[next];
			}
			cout << Gp->vex[v0] << ":" << dist[i] << endl;
		}
		else
			if (i != v0) cout << Gp->vex[i] << "<--" << Gp->vex[v0] << ":no path" << endl;
	}
}
}
int main() {
	int path[MAXNUM];
	int dist[MAXNUM];
	string a;
	MGraph G;
	string b;
	CreateMGraph(&G);
	char c='y';
	while(c=='y'||c=='Y'){
	cout << "��������Ҫ��ѯ����������:";
	cin >> a>>b;
	dijkstra(&G, name(&G,a), path, dist);
	cout << a << "���������е���̾����·�߷ֱ�Ϊ:\n";
	display(&G, name(&G,a),name(&G,b), path, dist);
	getchar();
	cout<<"�Ƿ������ѯ��Y/N:";
	cin>>c; 
}
	system("pause");
	return 0;
}
