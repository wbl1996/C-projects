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
	Vertextype  vex[MAXVEX];         //存放节点数据 
	Edgetype arc[MAXVEX][MAXVEX];    //存放两节点的权值 
	int numNodes;
	int numEdges;
}MGraph;
//输入城市名字，返回城市对应输入时的编号，方便程序调用
int name(MGraph *Gp, string a) {                
	int i;
	for (i = 0; i < Gp->numNodes; i++) {
		if (Gp->vex[i] == a)
			return i;
	}
}
void CreateMGraph(MGraph *Gp) {           //图的创建 
	int i, j;
	int m;
	cout << "请输入城市数量:";
	cin >> Gp->numNodes;
	string a;
	cout << "请输入城市名字(0-" << Gp->numNodes << "):" << endl;
	for (i = 0; i<Gp->numNodes; i++) {                         //输入网的各节点数据 
		cin >> a;
		Gp->vex[i] = a;
	}
	for (i = 0; i<Gp->numNodes; i++) {            //初始化邻接矩阵 
		for (j = 0; j<Gp->numNodes; j++) {
			Gp->arc[i][j] = MAXINT;
		}
	}
	string x,y;
	cout << "请输入两城市的名字及他们之间的距离(城市名字与距离之间均用空格隔开)(以城市名字为#结束）:"<<endl;
	//通过输入城市名字和对应权值，修改邻接矩阵中的数据 
	while (x != "#") {	                                               
		cin >> x >> y >> m;
		Gp->arc[name(Gp,x)][name(Gp, y)] = m;
	}
}
//dijkstra算法，
void dijkstra(MGraph *Gp, int v0, int path[], int dist[]) {        
	int i, j, k, mindist;
	int u;
	int s[MAXNUM];          //s[i]=1表示i已经选过 
	//初始 s，path,dist；path[i]表示i的前驱点，dist[i]表示从起始点到i点的权值
	for (i = 0; i<Gp->numNodes; i++) {      
		s[i] = 0;
		dist[i] = Gp->arc[v0][i];
		if (i != v0&&dist[i]<MAXINT) {
			path[i] = v0;
		}
		else
			path[i] = -1;
	}
	dist[v0] = 0;       //起始点到本身的权值为0 
	s[v0] = 1;          //先把起始点取出 
	u = v0;        //u是中间变量，始终存储权值最小的点 

	for (i = 0; i<Gp->numNodes - 1; i++) {
		mindist = MAXINT;
		for (j = 0; j<Gp->numNodes; j++) {
			if (!s[j] && dist[j]<mindist) {
				u = j;
				mindist = dist[j];
			}
		}
		s[u] = 1;
		/*如果从起始点到i点距离大于从起始
		点到中间点加上从中间点到i的距离，
		那就更新从起始点到i的权值*/ 
		for (k = 0; k<Gp->numNodes; k++) {    
			if (!s[k] && Gp->arc[u][k]<MAXINT && (dist[k]>mindist + Gp->arc[u][k])) {
				dist[k] = mindist + Gp->arc[u][k];
				path[k] = u;
			}
		}
	}
}
//输出要求的量城市的最短路径及最短距离
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
	cout << "请输入你要查询的两个城市:";
	cin >> a>>b;
	dijkstra(&G, name(&G,a), path, dist);
	cout << a << "到其他城市的最短距离的路线分别为:\n";
	display(&G, name(&G,a),name(&G,b), path, dist);
	getchar();
	cout<<"是否继续查询？Y/N:";
	cin>>c; 
}
	system("pause");
	return 0;
}
