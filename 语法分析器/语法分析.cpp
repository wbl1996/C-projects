#include<iostream>
#include<vector>
#include<string>
#include<stack>

#define BEGIN_SYB 'E'

class Tab {                   //Ԥ��������е�������ʽ
public:
    Tab(char n,char e,std::string p):noend(n),end(e),prod(p) {};

    char noend;
    char end;
    std::string prod;
};

std::vector<Tab>  pTab;       //Ԥ�������
std::stack<char>  pStack;     //ջ
std::string       pStr;       //���봮
int               index = 0;  //���봮���±�
int               num = 0;    //�±�
char              X;          //��ջ��ȡ���ķ���
char              a;          //�ַ���Ŀǰ��������λ��
char array1[] = {'i','+','*','(',')','#'};
char array2[] = {'E','Z','T','Y','F'};
std::vector<char> VT(array1,array1+sizeof(array1)/sizeof(char)); 
std::vector<char> VN(array2,array2+sizeof(array2)/sizeof(char));
//std::vector<char> VT{'i','+','*','(',')','#'};    //�ս���ż���
//std::vector<char> VN{'E','Z','T','Y','F'};    //���ս���ż���

int isPartVT(char ch)
{	
    for(auto u : VT) {
        if(u == ch) {
            return 1;
        }
    }
    return 0;
}

int isPartVN(char ch)
{
    for(auto u:VN) {
        if(u == ch) {
            return 1;
        }
    }
    return 0;
}

void initpTab()
{
    pTab.push_back(Tab('E','i',"TZ"));       //Z��ʾE'
    pTab.push_back(Tab('E','(',"TZ"));
    pTab.push_back(Tab('Z','+',"+TZ"));
    pTab.push_back(Tab('Z',')',"$"));
    pTab.push_back(Tab('Z','#',"$"));
    pTab.push_back(Tab('T','i',"FY"));
    pTab.push_back(Tab('T','(',"FY"));       //Y��ʾT'
    pTab.push_back(Tab('Y','+',"$"));
    pTab.push_back(Tab('Y','*',"*FY"));
    pTab.push_back(Tab('Y',')',"$"));
    pTab.push_back(Tab('Y','#',"$"));
    pTab.push_back(Tab('F','i',"i"));
    pTab.push_back(Tab('F','(',"(E)"));
}

void printStack()
{
    std::stack<char> pTemp(pStack);
    while(pTemp.size() != 0) {
        std::cout << pTemp.top() << " ";
        pTemp.pop();
    }
    std::cout << "         ";
}

int synaly()
{
    pStack.push(pStr[index++]);
    pStack.push(BEGIN_SYB);
    a = pStr[index++];
    bool flag = true;
    while(flag) {
        std::cout << num++ << "        ";  //����к�
        printStack();
        if(pStack.size() != 0) {
            X = pStack.top();              //������ջ����X
            pStack.pop();
        }

        if(isPartVT(X)) {                  //������ս��
            if(X == '#' && a == '#') {
                flag = false;
            }else if(X == a){
                std::cout << std::endl;
                a = pStr[index++];
            }else {
                std::cout << "EROOR!" << std::endl;
                return 0;
            }

        }else if (X == '#') {
            if(X == a) {
                flag = false;
            }else {
                std::cout << "EROOR!" << std::endl;
                return 0;
            }

        }else if (isPartVN(X) && isPartVT(a)) {  //������ս��
            int type = 0;
            for(auto u:pTab) {
                if(u.noend == X && u.end == a) {
                    std::string tempProd = u.prod;
                    std::cout << X << "->" << tempProd << std::endl; 
                    if(tempProd == "$") {
                        type = 1;
                        break;
                    }else {
                        for(int i = tempProd.size()-1;i >= 0;--i) {
                            pStack.push(tempProd[i]);
                        }
                        type = 1;
                        break;
                    }
                }
            }
            if(type != 1) {
                std::cout << "EROOR!" << std::endl;
                return 0;

            }

        }else {
            std::cout << "EROOR!" << std::endl;
            return 0;
        }

    }
    return 1;
}

int main(int argc,char *argv[])
{
    initpTab();
    std::cout << "�������﷨��:";
    std::cin >> pStr;
    std::cout << "����" << "     " << "����ջ" << "      " << "���ò���ʽ" << std::endl;
    int flag = synaly();
    std::cout << std::endl;
    if(flag == 1) {
        std::cout << "�����ɹ�~~" << std::endl;
    }else {
        std::cout << "����ʧ��~~" << std::endl;
    }

    return 0;
}
