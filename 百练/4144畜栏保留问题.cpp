/*
许智敏：2017-01-02 
百练：4144畜栏保留问题 
http://bailian.openjudge.cn/practice/4144/
贪心法(注意区间每头牛会在一个特定的时间区间[A, B]（包括A和B）在畜栏里挤奶)，不能有相同的时间 
O(nlogn)
*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

struct xulan{
	int num=0;
	int start=0;
	int end=0;
	int xulanhao=0;
};

struct xulan xulans[50005];

int n=0;
int num=0;

bool cmp(const struct xulan a, const struct xulan b)
{
	if(a.start<b.start)
	{
		return true;
	}
	return false;
}


struct cmp1{
    bool operator ()(struct xulan &a,struct xulan &b){
        return a.end>b.end;//最小值优先队列 
    }
};

bool cmp2(const struct xulan a, const struct xulan b)
{
	if(a.num<b.num)
	{
		return true;
	}
	return false;
}

int main()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)//O(n)
	{
		scanf("%d %d",&xulans[i].start,&xulans[i].end);
		xulans[i].num=i;
	}
	
	sort(xulans,xulans+n,cmp);//O(nlogn)
	
	priority_queue<struct xulan,vector<struct xulan>,cmp1> que;//最小值优先
	
	if(que.empty())
	{
		num++;
		xulans[0].xulanhao=num;
		que.push(xulans[0]); 
	}
	
	for(int i=1;i<n;i++)//O(nlogn)
	{
		if(que.top().end<xulans[i].start) 
		{
			xulans[i].xulanhao=que.top().xulanhao;
			que.pop(); 
			que.push(xulans[i]);//O(logn)
		}
		else
		{
			num++;
			xulans[i].xulanhao=num;
			que.push(xulans[i]);//O(logn)		
		}
	}
	
	sort(xulans,xulans+n,cmp2);//O(nlogn)
	
	printf("%d\n",num);
	
	for(int i=0;i<n;i++)//O(n)
	{
		printf("%d\n",xulans[i].xulanhao);
	}	
	
	return 0;
} 
