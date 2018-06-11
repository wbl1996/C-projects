#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
int multi(int *sum,int *a,int *b,int la,int lb){           //a和b数组是倒着存储的
/*		1234 * 5678 = 7006652 
			4   3   2   1
		    8   7   6   5
		--------------------- 
		   32  28  24  20
		       24  21  18  15
		           16  14  12  10
		               8   7    6   5
		   32  52  61  60  34  16   5         ### 
				3  5   6   6	4   2        进位行 
		   2   5   6   6   0    0   7 
*/ 
	int i=1,j=1,k=0;
	int len=0;
	int t=0;
	memset(sum,0,sizeof(sum));           //sum全设为0 
	for(i=1;i<=la;i++){					//执行乘法，a中的每个，分别和b中的每个相乘，得到的sum 是注释中的###行 
		for(j=1,len=i-1;j<=lb;j++){
			len++;
			sum[len] = sum[len]+ a[i]*b[j];
		}
	}
	for(i=1;i<len;i++){                 //这个循环不考虑sum的最后一位，进行进位的操作 
		if(sum[i]>=10){
			sum[i+1] = sum[i+1] + sum[i]/10;
			sum [i] = sum[i]%10;
		}
	}
	if(sum[len]>=10){                 //执行sum的最后一位的进位操作 
		t = sum[len];
		sum[len] = t/10;
		len++;
		sum[len] = t%10;
	}
	return len;
} 
int getMod(int *sum,int m,int size){        //参数说明：sum是整型数组，m是模，size是数组的长度 
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
	printf("请输入a:");
	scanf("%s",&chara);
	printf("请输入b:");
	scanf("%s",&charb);
	la = strlen(chara);
	lb = strlen(charb);
	/*
	输入的字符型数组转换成整型的数组并取反 
	如:  a的第一位为4，对应的ascii码为52，减去0的ascii码48，得到的4赋给整型变量
		字符进行加减转换成ascii码再加减 
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
	for(i=1;i<=len;i++){              //得到最终存储结果的数组，此时数组正序 
		result[i] = sum[len-i+1];
		printf("%d",result[i]);
	}
	printf("\n");                       
	int ans = getMod(result,8,len);      
	printf("\n取模位：%d",ans);
	return 0;
}
