#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#define size 3
#define MAX 10000
using namespace std;
typedef struct Car {  //�洢������Ϣ�Ľṹ�壬�������ƺź�ʻ��ʱ�� 
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
	LinkQueue(struct node *p) {  //������ 
		len = 0;
		p->next = NULL;
		front = rear = p;
	}
	~LinkQueue() {}
	void EnQueue(Car xc) {  //��� 
		struct node *p = (struct node *)malloc(sizeof(struct node));
		p->c = xc;
		rear->next = p;
		rear = rear->next;
		len++;
		rear->next = NULL;
	}
	Car DelQueue() {// ��ͷ�ڵ������ 
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
	void show() { //��ʾ����г����ĳ��ƺ� 
		struct node *p;
		p = front->next;
		string a;
		if(!IsEmpty()){
		cout << "����г������ƺŴ�ͷ��βΪ:" << endl;
		while (p != NULL) {
			a = p->c.number;
			cout << a << endl;
			p = p->next;
		}
		}
		else{
			cout<<"���Ϊ�գ�\n";
	}
	}
}; 
class Stack { //ջ 
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
Car Stack::pop() { //����ֵΪCar���ͣ�����ֱ����Ϊ��ʱͣ������ջ����ջ�����Ĳ����� 
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
void Stack::print() {//��ʾ�����г����ĳ��ƺ� 
	int i;
	Car c;
	if (!isEmpty()) {
		cout << "�����д�ǰ�������ĳ��ƺ�Ϊ:" << endl;
		for (i = top; i >= 0; i--) {
			c = data[i];
			cout << c.number << endl;
		}
	}
	else {
		cout << "����Ϊ�գ�" << endl;
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
		cout << "                                �������ﻶӭʹ�ó������ϵͳ�������" << endl;
		cout << "                                ��                                          ��" << endl;
		cout << "                                ��           ****1,��ʾͣ����״̬****       ��" << endl;
		cout << "                                ��           ****2,��������      ****       ��" << endl;
		cout << "                                ��           ****3,�����뿪      ****       ��" << endl;
		cout << "                                ��           ****4,�˳�          ****       ��" << endl;
		cout << "                                ��                                          ��" << endl;
		cout << "                                ������������������������" << endl;
		cout << "��������Ҫ���еĲ���:";
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
					cout << "����δ������ʻ�복�⣡" << endl;
					cout << "��������ĳ��ƺ�:";
					cin >> x;
					strcpy(c1.number, x);
					cout << "�����������ʱ��ʱ��:";
					cin >> b;
					c1.firtime = b;
					s1.push(c1);
					z++;
					cout<<"���ڳ���������"<<z<<"����!"<<endl;
					
				}
				else {
					cout << "������������ʻ������" << endl;
					cout << "��������ĳ��ƺ�:";
					cin >> x;
					strcpy(c1.number, x);
					cout << "�����������ʱ��ʱ��:";
					cin >> b;
					c1.firtime = b;
					lq->EnQueue(c1);
				}
				cout << "�Ƿ������Y/N:";
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
							cout << "�����е�" << rander2 << "�������⣡" << endl;
							z--;
							Car car1;
							for (i = 1; i < rander2; i++) {
								s2.push(s1.pop());
							}
							car1 = s1.pop();
							for (i = 1; i < rander2; i++) {
								s1.push(s2.pop());
							}
							cout << "�����������뿪ʱ��:";
							cin >> leavetime;
							if (leavetime - car1.firtime < 100) {
								cout << "��ʹ�ó����ʱ��С��һСʱ������ȡ���ã�" << endl;
							}
							else {
								cout << "�������ʹ�ó���ķ��ã�����Ϊ:" << ((leavetime - car1.firtime) / 100) * 10 << endl;
							}
							if (!lq->IsEmpty()) {
								cout << "����ϵĵ�һ������⣡" << endl;
								c = lq->DelQueue();
								c.firtime = leavetime + 1;
								s1.push(c);
							}
						}
						else {
							cout << "����������뿪������ȡ���ã�" << endl;
							lq->DelQueue();
						}
					}
					else {
						int rander2 = rand() % z + 1;
						cout << "�����е�" << rander2 << "�������⣡" << endl;
						z--;
						Car car1;
						for (i = 1; i < rander2; i++) {
							s2.push(s1.pop());
						}
						car1 = s1.pop();
						for (i = 1; i < rander2; i++) {
							s1.push(s2.pop());
						}
						cout << "�����������뿪ʱ��:";
						cin >> leavetime;
						if (leavetime - car1.firtime < 100) {
							cout << "��ʹ�ó����ʱ��С��һСʱ������ȡ���ã�" << endl;
						}
						else {
							cout << "�������ʹ�ó���ķ��ã�����Ϊ:" << ((leavetime - car1.firtime) / 100) * 10<<endl;
						}
					}
					cout << "�Ƿ������Y/N:";
					cin >> g;
				}
				else {
					cout << "�����ѿգ�" << endl;break; 
				}
			}
		}
		break;
		case 4:
			cout<<"ллʹ�ó������ϵͳ��"<<endl;
			break; 
		}
		getchar();
		cout << "�Ƿ�����鿴��Y/N:";
		cin >> k;
		system("cls");
	}
	system("pause");
	return 0;
}
