/*
许智敏：2017-01-02 
百练：4110:圣诞老人的礼物-Santa Clau’s Gifts 
http://bailian.openjudge.cn/practice/4110
贪心法，一直装性价比最高的物品 
O(n)+O(n)+O(nlogn)->O(nlogn)
*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int n=0;
int w=0;
double value=0;

struct Candy{
	int v=0;
	int w=0;
	float v_p_w=0;
};

struct Candy Candys[105];

bool cmp(const struct Candy a, const struct Candy b)
{
	if(a.v_p_w>b.v_p_w)
	{
		return true; 
	} 
	return false;
}

int main()
{
	scanf("%d %d",&n,&w);
	
	for(int i=0;i<n;i++)//O(n)
	{
		scanf("%d %d",&Candys[i].v,&Candys[i].w);
		Candys[i].v_p_w=Candys[i].v/(Candys[i].w*1.0); 
	} 
	
	sort(Candys,Candys+n,cmp);//O(nlogn)
	
	for(int i=0,temp=0;i<n;i++)//O(n) 
	{
		if((temp+Candys[i].w)<=w)
		{
			value+=Candys[i].v;
			temp+=Candys[i].w;
		}else
		{
			value+=(w-temp)*Candys[i].v_p_w;
			break;
		}
	} 
	
	printf("%.1lf\n",value); 
	
	return 0;
}
