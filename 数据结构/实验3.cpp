#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#define size 3
#define MAX 10000
using namespace std;
typedef struct Car {  //存储汽车信息的结构体，包括车牌号和驶入时间 
	char number[10];
	int firtime;
}Car;
struct node {
	Car c;
	struct node *next;
};
class LinkQueue {
private:
	int len;
	struct node *front;
	struct node *rear;
public:
	LinkQueue(struct node *p) {  //链队列 
		len = 0;
		p->next = NULL;
		front = rear = p;
	}
	~LinkQueue() {}
	void EnQueue(Car xc) {  //入队 
		struct node *p = (struct node *)malloc(sizeof(struct node));
		p->c = xc;
		rear->next = p;
		rear = rear->next;
		len++;
		rear->next = NULL;
	}
	Car DelQueue() {// 带头节点的链队 
		Car xc;
		xc = front->next->c;
		front = front->next;
		len--;
		return xc;
	}
	int IsEmpty() {
		if (len == 0) {
			return 1;
		}
		return 0;
	}
	void show() { //显示便道中车辆的车牌号 
		struct node *p;
		p = front->next;
		string a;
		if(!IsEmpty()){
		cout << "便道中车辆车牌号从头到尾为:" << endl;
		while (p != NULL) {
			a = p->c.number;
			cout << a << endl;
			p = p->next;
		}
		}
		else{
			cout<<"便道为空！\n";
	}
	}
}; 
class Stack { //栈 
public:
	Stack() {
		top = -1;
	}
	bool push(Car c);
	Car pop();
	void clear();
	bool isEmpty();
	bool isFull();
	void print();
	~Stack() {}
private:
	Car data[size];
	int top;
};
bool Stack::push(Car c) { 
	if (top == size - 1) {
		return false;
	}
	top++;
	data[top] = c;
	return true;
}
Car Stack::pop() { //返回值为Car类型，可以直接作为临时停车区的栈的入栈函数的参数； 
	Car c;
	c = data[top--];
	return c;
}
void Stack::clear() {
	top = -1;
}

bool Stack::isEmpty() {
	if (top == -1) {
		return true;
	}
	return false;
}
bool Stack::isFull() {
	if (top == size - 1) {
		return true;
	}
	return false;
}
void Stack::print() {//显示车库中车辆的车牌号 
	int i;
	Car c;
	if (!isEmpty()) {
		cout << "车库中从前到后车辆的车牌号为:" << endl;
		for (i = top; i >= 0; i--) {
			c = data[i];
			cout << c.number << endl;
		}
	}
	else {
		cout << "车库为空！" << endl;
	}
}
int main() {
	int a, b;
	char c;
	c = 'y';
	Stack s1, s2;
	char k;
	k = 'y';
	int z;
	struct node *p = (struct node *)malloc(sizeof(struct node));
	LinkQueue *lq = new LinkQueue(p);
	char x[10];
	while (k == 'Y' || k == 'y') {
		cout << "                                ★★★★★★★欢迎使用车库管理系统★★★★★★" << endl;
		cout << "                                ★                                          ★" << endl;
		cout << "                                ★           ****1,显示停车场状态****       ★" << endl;
		cout << "                                ★           ****2,车辆到达      ****       ★" << endl;
		cout << "                                ★           ****3,车辆离开      ****       ★" << endl;
		cout << "                                ★           ****4,退出          ****       ★" << endl;
		cout << "                                ★                                          ★" << endl;
		cout << "                                ★★★★★★★★★★★★★★★★★★★★★★★" << endl;
		cout << "请输入你要进行的操作:";
		cin >> a;
		system("cls");
		switch (a) {
		case 1:
			s1.print();
			lq->show();
			break;
		case 2:
			int i;
			Car c1;
			for (i = 0; i<MAX; i++) {
				if (!s1.isFull()) {
					cout << "车库未满，请驶入车库！" << endl;
					cout << "请输入你的车牌号:";
					cin >> x;
					strcpy(c1.number, x);
					cout << "请输入你进入时的时间:";
					cin >> b;
					c1.firtime = b;
					s1.push(c1);
					z++;
					cout<<"现在车库里面有"<<z<<"辆车!"<<endl;
					
				}
				else {
					cout << "车库已满，请驶入便道！" << endl;
					cout << "请输入你的车牌号:";
					cin >> x;
					strcpy(c1.number, x);
					cout << "请输入你进入时的时间:";
					cin >> b;
					c1.firtime = b;
					lq->EnQueue(c1);
				}
				cout << "是否继续？Y/N:";
				cin >> c;
				if (c != 'Y'&&c != 'y')
					break;
			}
			break;
		case 3:
		{
			int i;
			char g='y';
			Car c;
			int leavetime;
			while(g=='y'||g=='Y'){
				if (!s1.isEmpty()) {
					int rander = rand() % 2;
					if (!lq->IsEmpty()) {
						if (rander == 1) {
							int rander2 = rand() % z + 1;
							cout << "车库中第" << rander2 << "辆车出库！" << endl;
							z--;
							Car car1;
							for (i = 1; i < rander2; i++) {
								s2.push(s1.pop());
							}
							car1 = s1.pop();
							for (i = 1; i < rander2; i++) {
								s1.push(s2.pop());
							}
							cout << "请输入您的离开时间:";
							cin >> leavetime;
							if (leavetime - car1.firtime < 100) {
								cout << "您使用车库的时间小于一小时，不收取费用！" << endl;
							}
							else {
								cout << "请缴纳您使用车库的费用，费用为:" << ((leavetime - car1.firtime) / 100) * 10 << endl;
							}
							if (!lq->IsEmpty()) {
								cout << "便道上的第一辆车入库！" << endl;
								c = lq->DelQueue();
								c.firtime = leavetime + 1;
								s1.push(c);
							}
						}
						else {
							cout << "便道上汽车离开，不收取费用！" << endl;
							lq->DelQueue();
						}
					}
					else {
						int rander2 = rand() % z + 1;
						cout << "车库中第" << rander2 << "辆车出库！" << endl;
						z--;
						Car car1;
						for (i = 1; i < rander2; i++) {
							s2.push(s1.pop());
						}
						car1 = s1.pop();
						for (i = 1; i < rander2; i++) {
							s1.push(s2.pop());
						}
						cout << "请输入您的离开时间:";
						cin >> leavetime;
						if (leavetime - car1.firtime < 100) {
							cout << "您使用车库的时间小于一小时，不收取费用！" << endl;
						}
						else {
							cout << "请缴纳您使用车库的费用，费用为:" << ((leavetime - car1.firtime) / 100) * 10<<endl;
						}
					}
					cout << "是否继续？Y/N:";
					cin >> g;
				}
				else {
					cout << "车库已空！" << endl;break; 
				}
			}
		}
		break;
		case 4:
			cout<<"谢谢使用车库管理系统！"<<endl;
			break; 
		}
		getchar();
		cout << "是否继续查看？Y/N:";
		cin >> k;
		system("cls");
	}
	system("pause");
	return 0;
}
