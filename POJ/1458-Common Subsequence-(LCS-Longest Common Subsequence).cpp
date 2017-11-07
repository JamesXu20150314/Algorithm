/*
POJ http://poj.org/problem?id=1458
LCS 最长公共子序列 
Author: Zhimin Xu
  Time: 2017-11-07 14:13 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max(a,b) a>b?a:b
#define MAX 1005

int dp[MAX][MAX] ={0};

int LCS(char * a, char * b) {//最长公共子序列 
	int i=0, j=0;
	
	memset(dp, 0, sizeof(dp));
	
	for(i=0;i<strlen(a);i++) {
		for(j=0;j<strlen(b);j++) {
			a[i]==b[j] ? dp[i+1][j+1] = dp[i][j] + 1 : dp[i+1][j+1] = Max(dp[i][j+1],dp[i+1][j]);
		}
	}
	
	return dp[i][j];
}

int main() {
	char str1[MAX]={'\0'};
	char str2[MAX]={'\0'};
	
	while(scanf("%s %s",str1,str2)!=EOF) {
		printf("%d\n",LCS(str1, str2));
	}
	
	return 0;
}
