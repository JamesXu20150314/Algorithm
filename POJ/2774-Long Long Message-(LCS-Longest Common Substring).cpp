/*
POJ 2774 http://poj.org/problem?id=2774 
Author: Zhimin Xu
  Time: 2017-11-07 14:50
���xi == yj��  �� c[i][j] = c[i-1][j-1]+1
���xi ! = yj,  ��ôc[i][j] = 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max(a,b) a>b?a:b
#define MAX 100005

int dp[2][MAX] ={0};//����MAX����2��ϵͳ���ж��޷�������ô����ڴ�ռ� 

int LCS(char * a, char * b) {//������Ӵ� 
	int i=0, j=0;
	
	int max = 0; 
	
	memset(dp, 0, sizeof(dp));
	
	for(i=0;i<strlen(a);i++) {
		for(j=0;j<strlen(b);j++) {
			//a[i]==b[j] ? dp[i+1][j+1] = dp[i][j] + 1 : dp[i+1][j+1] = Max(dp[i][j+1],dp[i+1][j]); //����������е��ƹ�ʽ 
			if(i%2==0) {
				a[i]==b[j] ? dp[1][j+1] = dp[0][j] + 1 : dp[1][j+1] = 0; //������Ӵ����ƹ�ʽ
				max = Max(max, dp[1][j+1]);//��¼��Ӵ�
			} else {
				a[i]==b[j] ? dp[0][j+1] = dp[1][j] + 1 : dp[0][j+1] = 0; //������Ӵ����ƹ�ʽ
				max = Max(max, dp[0][j+1]);//��¼��Ӵ�
			}			 
		}
	}
	
	return max;
}

int main() {
	char str1[MAX]={'\0'};
	char str2[MAX]={'\0'};
	
	scanf("%s %s",str1,str2);
	
	printf("%d\n",LCS(str1, str2));
	
	return 0;
}
