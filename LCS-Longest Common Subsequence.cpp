/*
LCS 最长公共子序列 以及 最长公共字串 
Author: Zhimin Xu
  Time: 2017-11-07 10:04
ABCBDAB
BDCABA

* b B D C A B A
a 0 0 0 0 0 0 0
A 0 0 0 0 1 1 1
B 0 1 1 1 1 2 2
C 0 1 1 2 2 2 2
B 0 1 1 2 2 3 3
D 0 1 2 2 2 3 3
A 0 1 2 2 3 3 4
B 0 1 2 2 3 4 4

4
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max(a,b) a>b?a:b
#define MAX 1005

int dp[MAX][MAX] ={0};

int LCS(char * a, char * b) {//最长公共子序列 
	int i=0, j=0;
	
	for(i=0;i<strlen(a)+1;i++) {
		dp[i][0]=0;
	}
	for(j=0;j<strlen(b)+1;j++) {
		dp[0][j]=0;
	}
	
	for(i=0;i<strlen(a);i++) {
		for(j=0;j<strlen(b);j++) {
			a[i]==b[j] ? dp[i+1][j+1] = dp[i][j] + 1 : dp[i+1][j+1] = Max(dp[i][j+1],dp[i+1][j]);
		}
	}
	
	return dp[i][j];
}

void print(char * a, char * b) {
	
	int i=0, j=0;

	printf("* b ");
	for(j=0;j<strlen(b);j++) {
		printf("%c ", b[j]);
	}
	printf("\n");
	
	for(i=0;i<strlen(a)+1;i++) {
		i==0 ? printf("a ") : printf("%c ",a[i-1]);
		for(j=0;j<strlen(b)+1;j++) {
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	
	return ;
}

int main() {
	char str1[MAX]={'\0'};
	char str2[MAX]={'\0'};
	
	scanf("%s %s",str1,str2);
	
	print(str1, str2);
	printf("\n%d\n",LCS(str1, str2));
	
	return 0;
}
