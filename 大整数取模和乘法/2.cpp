#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
int multi(int *sum,int *a,int *b,int la,int lb){           //a��b�����ǵ��Ŵ洢��
/*		1234 * 5678 = 7006652 
			4   3   2   1
		    8   7   6   5
		--------------------- 
		   32  28  24  20
		       24  21  18  15
		           16  14  12  10
		               8   7    6   5
		   32  52  61  60  34  16   5         ### 
				3  5   6   6	4   2        ��λ�� 
		   2   5   6   6   0    0   7 
*/ 
	int i=1,j=1,k=0;
	int len=0;
	int t=0;
	memset(sum,0,sizeof(sum));           //sumȫ��Ϊ0 
	for(i=1;i<=la;i++){					//ִ�г˷���a�е�ÿ�����ֱ��b�е�ÿ����ˣ��õ���sum ��ע���е�###�� 
		for(j=1,len=i-1;j<=lb;j++){
			len++;
			sum[len] = sum[len]+ a[i]*b[j];
		}
	}
	for(i=1;i<len;i++){                 //���ѭ��������sum�����һλ�����н�λ�Ĳ��� 
		if(sum[i]>=10){
			sum[i+1] = sum[i+1] + sum[i]/10;
			sum [i] = sum[i]%10;
		}
	}
	if(sum[len]>=10){                 //ִ��sum�����һλ�Ľ�λ���� 
		t = sum[len];
		sum[len] = t/10;
		len++;
		sum[len] = t%10;
	}
	return len;
} 
int getMod(int *sum,int m,int size){        //����˵����sum���������飬m��ģ��size������ĳ��� 
	int ans = 0;
	int i=1;
	for(i=1;i<=size;i++){
		ans = ((ans *10)%m+sum[i]%m)%m;
		printf("%d",ans);
		printf("\n");
	}
	return ans;
}
int main(){
	int a[MAX] = {0};
	int b[MAX] = {0};
	int la=0;
	int lb=0;
	int len = 0;
	int sum[MAX*2]={0};
	char chara[MAX],charb[MAX];
	int i=0,j=0;
	printf("������a:");
	scanf("%s",&chara);
	printf("������b:");
	scanf("%s",&charb);
	la = strlen(chara);
	lb = strlen(charb);
	/*
	������ַ�������ת�������͵����鲢ȡ�� 
	��:  a�ĵ�һλΪ4����Ӧ��ascii��Ϊ52����ȥ0��ascii��48���õ���4�������ͱ���
		�ַ����мӼ�ת����ascii���ټӼ� 
	*/ 
	for(i=1,j=la-1;i<=la;i++,j--){
		a[i] = chara[j] - '0';                       
	}
	for(i=1,j=lb-1;i<=lb;i++,j--){
		b[i] = charb[j] - '0';
	}
	len = multi(sum,a,b,la,lb);
	printf("a*b=");
	int result[2*MAX];
	for(i=1;i<=len;i++){              //�õ����մ洢��������飬��ʱ�������� 
		result[i] = sum[len-i+1];
		printf("%d",result[i]);
	}
	printf("\n");                       
	int ans = getMod(result,8,len);      
	printf("\nȡģλ��%d",ans);
	return 0;
}
