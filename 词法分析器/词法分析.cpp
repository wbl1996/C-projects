#include<iostream>  
#include<fstream>  
using namespace std;  
int main()  
{  
char a[200];  
string b[200];  
static int j=0;  
int i;  
int count;  
int flag;  
ifstream infile("C:/Users/wbl/Desktop/new.txt ",ios::in);//�����Լ��趨·�������ļ�   
ofstream outfile("C:/Users/wbl/Desktop/old.txt",ios::out);//�����Լ��趨·������ļ�   
for(i=0;i<200;i++)  
{  
 a[i]=infile.get();//�����ļ���ȡ������a[]��    
    }  
    for(i=0;i<200;i++)//��ʼ��������a[]���ַ�ʶ��   
    {  
 switch(a[i])  
 {  
 	 case '{':
 	{
 		b[j] = a[i];
 		outfile<<"<0(1),"<<b[j]<<">"<<endl;
	 };break;
	 
	 case '}':
 	{
 		b[j] = a[i];
 		outfile<<"<0(2),"<<b[j]<<">"<<endl;
	 };break;
     case '('://ʶ����ţ�   
  {  
  b[j]=a[i];  
  outfile<<"<1,"<<b[j]<<">"<<endl;  
  } ;break;  
    
     case ')'://ʶ����ţ�   
  {  
  b[j]=a[i];  
  outfile<<"<2,"<<b[j]<<">"<<endl;  
  } ;break;  
    
     case '+':  
 {  
if(a[i+1]=='=')//ʶ�����+=   
{  
b[j]=a[i];  
b[j]+=a[i+1];  
i++;  
outfile<<"<3,"<<b[j]<<">"<<endl;  
}  
        else if(a[i+1]=='+')//ʶ�����++   
{  
b[j]=a[i];  
b[j]+=a[i+1];  
i++;  
outfile<<"<22,"<<b[j]<<">"<<endl;  
}  
else//ʶ�����+   
{  
b[j]+=a[i];  
outfile<<"<4,"<<b[j]<<">"<<endl;  
}   
};break;  
  
   case '-':  
 {  
if(a[i+1]=='=')//ʶ�����-=   
{  
b[j]=a[i];  
b[j]+=a[i+1];  
i++;  
outfile<<"<5,"<<b[j]<<">"<<endl;  
}  
else if(a[i+1]=='-')//ʶ�����--  
{  
b[j]=a[i];  
b[j]+=a[i+1];  
i++;  
outfile<<"<23,"<<b[j]<<">"<<endl;  
}  
else//ʶ�����-   
{  
b[j]+=a[i];  
outfile<<"<6,"<<b[j]<<">"<<endl;  
}   
};break;   
    case '*':  
 {  
if(a[i+1]=='=')//ʶ�����*=   
{  
b[j]=a[i];  
b[j]+=a[i+1];  
i++;  
outfile<<"<7,"<<b[j]<<">"<<endl;  
}  
    else//ʶ�����*   
  {  
b[j]+=a[i];  
outfile<<"<8,"<<b[j]<<">"<<endl;  
}   
};break;  
  
     case '/':  
 {  
if(a[i+1]=='=')//ʶ����� /=   
{  
b[j]=a[i];  
b[j]+=a[i+1];  
i++;  
outfile<<"<9,"<<b[j]<<">"<<endl;  
}  
else if(a[i+1]=='/')////ʶ����� //   
{  
while(a[i+2]!='\n')  
  {  
  i++;  
  }outfile<<"<10(1),"<<"ע��"<<">"<<endl;   
}  
else////ʶ����� /   
{  
b[j]+=a[i];  
outfile<<"<10,"<<b[j]<<">"<<endl;  
}   
};break;  
  
  case ';'://ʶ����� ��   
 {  
  b[j]=a[i];  
  outfile<<"<11,"<<b[j]<<">"<<endl;  
 };break;  
   
  case '<':  
 {  
if(a[i+1]=='=')//ʶ�����<=   
{  
b[j]=a[i];  
b[j]+=a[i+1];  
i++;  
outfile<<"<12,"<<b[j]<<">"<<endl;  
}  
else//ʶ����� <  
{  
b[j]+=a[i];  
outfile<<"<13,"<<b[j]<<">"<<endl;  
}   
};break;  
  
   case '>':  
 {  
if(a[i+1]=='=')//ʶ����� >=  
{  
b[j]=a[i];  
b[j]+=a[i+1];  
i++;  
outfile<<"<14,"<<b[j]<<">"<<endl;  
}  
else//ʶ����� >  
{  
b[j]+=a[i];  
outfile<<"<15,"<<b[j]<<">"<<endl;  
}   
};break;  
  
 case '=':  
 {  
if(a[i+1]=='=')//ʶ����� ==  
{  
b[j]=a[i];  
b[j]+=a[i+1];  
i++;  
outfile<<"<16,"<<b[j]<<">"<<endl;  
}  
else//ʶ����� =  
{  
b[j]+=a[i];  
outfile<<"<17,"<<b[j]<<">"<<endl;  
}   
};break;  
 }  
   
  if (a[i]==' '||a[i]=='\n') //ʶ����ſո񼰻���   
  {  
  j++;  
  }  
    
  if(a[i]>='0'&&a[i]<='9'||a[i]=='.')//ʶ��С��������    
  {  
 b[j]+=a[i];  
  
  if(a[i+1]==' '||a[i+1]=='\n')//ʶ��С��������������λ������   
 {  
 if(a[i-1]=='.'||a[i-2]=='.'||a[i-3]=='.'||a[i-4]=='.'||a[i-5]=='.'||a[i-6]=='.')  
outfile<<"<18(1),"<<b[j]<<">"<<endl;  
  else  
  outfile<<"<18,"<<b[j]<<">"<<endl;//ʶ������  
  
  }  
 }  
       if(a[i]>='a'&&a[i]<='z') //�ؼ���ʶ���Լ������Ҫ�Ĺؼ���   
        {  
  b[j]+=a[i];  
  if(a[i+1]==' '||a[i+1]=='\n')  
  {  
  if(b[j]=="while")  
  outfile<<"<19(1),"<<b[j]<<">"<<endl;  
  else if(b[j]=="int")  
  outfile<<"<19(2),"<<b[j]<<">"<<endl;  
  else if(b[j]=="float")  
  outfile<<"<19(3),"<<b[j]<<">"<<endl;  
  else if(b[j]=="do")  
  outfile<<"<19(4),"<<b[j]<<">"<<endl;  
  else if(b[j]=="public")  
  outfile<<"<19(5),"<<b[j]<<">"<<endl;  
  else if(b[j]=="void")  
  outfile<<"<19(6),"<<b[j]<<">"<<endl;  
  else if(b[j]=="if")  
  outfile<<"<19(7),"<<b[j]<<">"<<endl;  
  else  
  outfile<<"<19,"<<b[j]<<">"<<endl;//ʶ���Զ������   
  }  
   
  }  
  if(a[i]==':')  
  {  
  if(a[i+1]=='=')//ʶ����� :=   
{  
b[j]=a[i];  
b[j]+=a[i+1];  
outfile<<"<20,"<<b[j]<<">"<<endl;  
   i++;  
}  
else//ʶ����� :  
{  
b[j]+=a[i];  
outfile<<"<21,"<<b[j]<<">"<<endl;  
}   
  }    
    }  
  
  
    cout<<"�������"; //dos������ʾ,��ʷ�ʶ��ɹ�   
    outfile.close();//�ر��ļ�   
    infile.close();//�ر��ļ�   
return 0;   
}   
