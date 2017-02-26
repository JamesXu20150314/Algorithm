/*
��������2017-01-08
OpenJudge���㷨�����͸��������� / 2016��ģ�⿼�� B:Butterfly
http://algorithm.openjudge.cn/betaexam/B/
���鼯��չ����һ����ѹ��·���Ĳ��鼯��չ��2n���ȣ�ǰn��Ϊ��һ�࣬��n��Ϊ�ڶ��� 
O(nm) 
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

int n=0;
int m=0;
int pre[2010]={0};
int result=0;

int initial()
{
	for(int i=0;i<2*n;i++)
	{
		pre[i]=i;
	}
	return 0;
} 

int find_parent(int i)
{
	int r=i;
	while(r!=pre[r])
	{
		r=pre[r];
	}
	int temp1=i,temp2;//·��ѹ����ʼ 
	while(pre[temp1]!=r)
	{
		temp2=pre[temp1];
		pre[temp1]=r;
		temp1=temp2;
	}
	return r;
}

void union_node(int x,int y,int type)//������ͨ���鼯 type 0-��ͬ�࣬type 1-��ͬ�� 
{
	int fx1=find_parent(x);
	int fx2=find_parent(x+n);
	int fy1=find_parent(y);
	int fy2=find_parent(y+n);
	if(type==0)//�����洢Ϊ��ͬ���� 
	{
		if(fx2==fy1&&fx1==fy2)//֮ǰ�Ѿ��洢����Ϊ��ͬ
		{
			result=1; //��ͻ 
		}else{
			if(fx1!=fy1&&fx2!=fy2)//��Ϊ��ͬ���� 
			{
				pre[fy1]=fx1;
				pre[fy2]=fx2;	
			} 
		}
	}else{//�����洢Ϊ��ͬ���� 
		if(fx2==fy2&&fx1==fy1)//֮ǰ�Ѿ��洢����Ϊ��ͬ 
		{
			result=1; //��ͻ 
		}else{
			if(fx1!=fy2&&fx2!=fy1)//��Ϊ��ͬ���� 
			{
				pre[fy1]=fx2;
				pre[fy2]=fx1;	
			} 
		}
	}
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		result=0;
		initial();//O(n) 
		int a,b,c;
		for(int i=0;i<m;i++)//O(nm) 
		{
			scanf("%d %d %d",&a,&b,&c);
			union_node(a,b,c);//O(n) 
		}	
		if(result==1)
		{
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	 
	return 0;
} 
