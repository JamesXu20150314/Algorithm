/*
������Ӵ� O(n)
Author: Zhimin Xu
  Time: 2017-11-07 14:45
  
manacher�㷨ΪO(n) https://articles.leetcode.com/longest-palindromic-substring-part-ii/

*/
#include<iostream>
#include<string>
#include<vector> 
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
		if(i<s.size()-1 && s.at(i) == s.at(i+1)) { //��Ҫ��֪����б�в��ܵ��� 
			d[i][i+1]=1;
			max_length=2;
			start = i;
		}
	}
	
	for(int len=3; len<=s.size(); len++) { //len ��ζ�Ű��նԽ��������� 
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
/*
����������㷨Manacher��s Algorithm����������һ���ַ�����������Ӵ������Է�������һ����Manacher������1975�귢���ģ��������������������ڽ�ʱ�临�Ӷ������������ԣ����Ƿǳ��˲���ġ����ڻ��Ĵ���ش�Ҷ���İ������������������һ�����ַ��������� "bob", "level", "noon" �ȵȣ���ô�����һ���ַ������ҳ�������Ӵ��أ�������ÿһ���ַ�Ϊ���ģ�������Ѱ�һ����Ӵ����ڱ�������������󣬾Ϳ����ҵ���Ļ����Ӵ����������������ʱ�临�Ӷ�ΪO(n*n)�������Ǻܸ�Ч��������������ʱ�临�Ӷ�ΪO(n)���������㷨��

���ڻ��Ĵ��ĳ��ȿ����ż������"bob"��������ʽ�Ļ��ģ�"noon"����ż����ʽ�Ļ��ģ��������㷨�ĵ�һ����Ԥ������������ÿһ���ַ������Ҷ�����һ�������ַ����������'#'����ô

bob    -->    #b#o#b#

noon    -->    #n#o#o#n# 

�������ĺô��ǲ���ԭ�ַ�������������ż����������֮��õ����ַ����ĸ��������������������Ͳ��÷���������ˣ�������һ��㶨�����������ǻ���Ҫ�ʹ������ַ���t�ȳ�������p������p[i]��ʾ��t[i]�ַ�Ϊ���ĵĻ����Ӵ��İ뾶����p[i] = 1����û����Ӵ�����t[i]������ô��������һ���򵥵����ӣ�

# 1 # 2 # 2 # 1 # 2 # 2 #
1 2 1 2 5 2 1 6 1 2 3 2 1

���ڵ�һ�������һ���ַ�����#�ţ���Ҳ��Ҫ�������ģ�Ϊ�˷�ֹԽ�磬���ǻ���Ҫ����β�ټ��Ϸ�#���ַ���ʵ�ʲ���ʱ����ֻ�����ͷ���ϸ���#���ַ�����β���üӵ�ԭ�����ַ����Ľ�β��ʶΪ'\0'������Ĭ�ϼӹ��ˡ�ͨ��p�������ǾͿ����ҵ������ֵ����λ�ã�����ȷ��������Ӵ��ˣ���ô�������Ǿ����������p���飬��Ҫ����������������mx��id������idΪ�������Ӵ����ĵ�λ�ã�mx�ǻ��Ĵ������쵽�����Ҷ˵�λ�ã�����㷨������ĵ�һ�����£�

 

p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
 

������ô˵������Ҫ������ˣ���ô�������㷨�����Ͼ�ûɶ�����ˣ���ô��һ�д������������

���mx > i, �� p[i] = min(p[2 * id - i], mx - i)

���� p[i] = 1

�� mx - i > P[j] ��ʱ����S[j]Ϊ���ĵĻ����Ӵ���������S[id]Ϊ���ĵĻ����Ӵ��У����� i �� j �Գƣ���S[i]Ϊ���ĵĻ����Ӵ���Ȼ��������S[id]Ϊ���ĵĻ����Ӵ��У����Ա��� P[i] = P[j]

�� P[j] >= mx - i ��ʱ����S[j]Ϊ���ĵĻ����Ӵ���һ����ȫ��������S[id]Ϊ���ĵĻ����Ӵ��У����ǻ��ڶԳ��Կ�֪����ͼ�������̿�����Χ�Ĳ�������ͬ�ģ�Ҳ����˵��S[i]Ϊ���ĵĻ����Ӵ������������ٻ����ŵ�mx��λ�ã�Ҳ����˵ P[i] >= mx - i������mx֮��Ĳ����Ƿ�Գƣ���ֻ������ʵʵȥƥ���ˡ�

���� mx <= i ��������޷��� P[i]������ļ��裬ֻ��P[i] = 1��Ȼ����ȥƥ����

*/

//https://www.cnblogs.com/grandyang/p/4475985.html
string Manacher(string s) { //�������㷨  Manacher
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    cout<<t<<endl;
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);
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
		cout<<"��̬�滮"<<PS(s)<<endl;
		cout<<"Manacher:"<<Manacher(s)<<endl;
		print(s);
	}
	
	
	return 0;
}
