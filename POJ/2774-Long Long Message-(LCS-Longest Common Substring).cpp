/*
POJ 2774 http://poj.org/problem?id=2774 
Author: Zhimin Xu
  Time: 2017-11-07 14:50
如果xi == yj，  则 c[i][j] = c[i-1][j-1]+1
如果xi ! = yj,  那么c[i][j] = 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max(a,b) a>b?a:b
#define MAX 100005

int dp[2][MAX] ={0};//不用MAX而用2，系统会判定无法申请那么大的内存空间 

int LCS(char * a, char * b) {//最长公共子串 
	int i=0, j=0;
	
	int max = 0; 
	
	memset(dp, 0, sizeof(dp));
	
	for(i=0;i<strlen(a);i++) {
		for(j=0;j<strlen(b);j++) {
			//a[i]==b[j] ? dp[i+1][j+1] = dp[i][j] + 1 : dp[i+1][j+1] = Max(dp[i][j+1],dp[i+1][j]); //最长公共子序列递推公式 
			if(i%2==0) {
				a[i]==b[j] ? dp[1][j+1] = dp[0][j] + 1 : dp[1][j+1] = 0; //最长公共子串递推公式
				max = Max(max, dp[1][j+1]);//记录最长子串
			} else {
				a[i]==b[j] ? dp[0][j+1] = dp[1][j] + 1 : dp[0][j+1] = 0; //最长公共子串递推公式
				max = Max(max, dp[0][j+1]);//记录最长子串
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
