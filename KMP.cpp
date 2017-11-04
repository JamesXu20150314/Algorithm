/*
Author: Zhimin Xu
  Time: 2017-11-04 01:19 AM
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX1 10005
#define MAX2 1000005

void get_next(char t [], int next []) {
	int length = strlen(t);
	int j = 0;
	int k = -1;
	next[0] = -1;
	
	while(j<length) {
		if((k == -1) || (t[j] == t[k])) { // k == -1 方便迭代更新next 
			j++;
			k++;
			next[j]=k; 
		}
		else {
			k = next[k];
		}
	}
	
	return; 
}

void print(char t [], int next []) {
	int length = strlen(t);
	
	for(int i=0; i<length; ++i) {
		printf("%d ",next[i]);
	}
	printf("\n");
	
	return;
}

int KMP(char s [], char t [], int next []) {
	
	int lens=strlen(s);
	int lent=strlen(t);
	int i=0;
	int j=0;
	int count = 0;
	
	while(i<lens && j<lent) {
		if((j==-1) || (s[i] == t[j])) {
			j++;
			i++;
		}
		else {
			j=next[j];
		}
	}
	
	if(j==lent) {
		return i - lent;//返回第一次出现的位置 
	}
	
	return count;
}

int main() {
	int next[MAX1] = {0};
	char s[MAX2] = {'\0'};
	char t[MAX1] = {'\0'};
	
	scanf("%s %s",s,t);//原始串与pattern串 
	get_next(t, next);
	//print(t, next);
	int count = KMP(s,t,next);
	printf("%d\n",count);
	
	return 0;
}
