/*
许智敏：2017-01-08
OpenJudge：算法分析和复杂性理论 / 2016年模拟考试 B:Butterfly
http://algorithm.openjudge.cn/betaexam/B/
并查集扩展，将一个带压缩路径的并查集扩展到2n长度，前n个为第一类，后n个为第二类 
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
	int temp1=i,temp2;//路径压缩开始 
	while(pre[temp1]!=r)
	{
		temp2=pre[temp1];
		pre[temp1]=r;
		temp1=temp2;
	}
	return r;
}

void union_node(int x,int y,int type)//改自普通并查集 type 0-相同类，type 1-不同类 
{
	int fx1=find_parent(x);
	int fx2=find_parent(x+n);
	int fy1=find_parent(y);
	int fy2=find_parent(y+n);
	if(type==0)//即将存储为相同类型 
	{
		if(fx2==fy1&&fx1==fy2)//之前已经存储类型为不同
		{
			result=1; //冲突 
		}else{
			if(fx1!=fy1&&fx2!=fy2)//存为相同类型 
			{
				pre[fy1]=fx1;
				pre[fy2]=fx2;	
			} 
		}
	}else{//即将存储为不同类型 
		if(fx2==fy2&&fx1==fy1)//之前已经存储类型为相同 
		{
			result=1; //冲突 
		}else{
			if(fx1!=fy2&&fx2!=fy1)//存为不同类型 
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
