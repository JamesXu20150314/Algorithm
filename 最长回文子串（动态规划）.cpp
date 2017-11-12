/*
最长回文子串 O(n^2)
Author: Zhimin Xu
  Time: 2017-11-07 14:45
  
据说有一个 manacher算法为O(n) http://www.cnblogs.com/Lyush/p/3221503.html

*/
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

#define Max 1005

int d[Max][Max] = {0};

string PS(string s) {
	if(s.size()==0) {
		return "";
	}
	
	string subs;	
	int start = 0;
	int max_length = 0;
	int i,j;
	
	memset(d, 0, sizeof(d));
	
	for(i=0;i<s.size();i++) {
		d[i][i] = 1;
		if(i<s.size()-1 && s.at(i) == s.at(i+1)) { //需要先知道两斜行才能递推 
			d[i][i+1]=1;
			max_length=2;
			start = i;
		}
	}
	
	for(int len=3; len<=s.size(); len++) { //len 意味着按照对角线求解遍历 
		for(i=0; i<=s.size()-len; i++) {
			j = i+len-1;
			if(d[i+1][j-1] == 1 && s.at(i)==s.at(j)) {
				d[i][j] = 1;
				max_length = len;
				start = i;
			}
		}
	}
	if(max_length>=2) 
		subs = s.substr(start, max_length);
	else
	    subs = s.substr(0,1);
	return subs;
}

void print(string a) {
	
	int i=0, j=0;
	for(i=0;i<a.size();i++) {
		for(j=0;j<a.size();j++) {
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
	
	return ;
}

int main() {
	string s;
	while(cin>>s)
	{
		cout<<PS(s)<<endl;
		print(s);
	}
	
	
	return 0;
}
