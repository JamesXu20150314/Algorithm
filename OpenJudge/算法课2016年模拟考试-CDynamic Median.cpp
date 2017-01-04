/*
��������2017-01-04
OpenJudge���㷨�����͸��������� / 2016��ģ�⿼�� C:Dynamic Median
http://algorithm.openjudge.cn/betaexam/C/
���ȶ���
O(logn)
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue> 

using namespace std;


struct cmp1{
	bool operator () (int &a,int &b){
		return a>b;//��С���ȶ��� 
	}
};

struct cmp2{
	bool operator () (int &a,int &b){
		return a<b;//������ȶ��� 
	}
};

int T=0;
int n=0; 

int main()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&n);
		priority_queue<int, vector<int>, cmp1> que1;
		priority_queue<int, vector<int>, cmp2> que2;
		int num1=0;
		int num2=0;
		char c[100]={'\0'};
		char c1[100]={'\0'};
		int n1=0;
		int n2=0;
		for(int j=0;j<n;j++)
		{
			gets(c);
			if(c[0]=='I')
			{
				int k=0;
				for(k=2;c[k]!='\0';k++)
				{
					c1[k-2]=c[k]; 
				}
				c1[k-2]='\0';
				n1=atoi(c1);
				if(num1==0&&num2==0)//ע�⴦���һ�����ȶ���Ϊ�յ���� 
				{
					que1.push(n1);
					num1++;
					continue;
				}
				if(num1==num2)
				{
					if(n1>que1.top())
					{
						que1.push(n1);
						num1++;
					}else{
						que2.push(n1);
						num2++;
					}
				}else if(num1<num2)
				{
					if(n1>que1.top())
					{
						que1.push(n1);
						num1++;
					}else{
						que2.push(n1);
						que1.push(que2.top());
						que2.pop();
						num1++;
					}
				}else
				{
					if(!que2.empty())//ע�⴦��ڶ������ȶ���Ϊ�յ���� 
					{ 
						if(n1<que2.top())
						{
							que2.push(n1);
							num2++;
						}else{
							que1.push(n1);
							que2.push(que1.top());
							que1.pop();
							num2++;
						}
					}else{//ע����� 
						if(n1<=que1.top())
						{
							que2.push(n1);
							num2++;
						}
						else
						{
							que1.push(n1);
							que2.push(que1.top());
							que1.pop();
							num2++;
						}
					} 
				}
			}
			else if(c[0]=='D')
			{
				if(num1==num2)
				{
					if(!que2.empty())
					{
						que2.pop();
						num2--;
					}	
				}else if(num1<num2)
				{	
					if(!que2.empty())
					{
						que2.pop();
						num2--;
					}
				}else
				{	
					if(!que1.empty())
					{
						que1.pop();
						num1--;
					}
				}
			}
			else if(c[0]=='Q')
			{
				if(num1==num2)
				{
					n2=que2.top();
				}else if(num1<num2)
				{
					n2=que2.top();
				}else
				{
					n2=que1.top();
				}	
				printf("%d\n",n2);
			}else{//ע���ȡ�ַ���Ϊ�յ���� 
				j--;
			}
		}
		
	}
	return 0;
} 
