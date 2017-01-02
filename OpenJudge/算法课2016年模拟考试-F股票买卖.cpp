/*
百练：算法分析和复杂性理论 / 2016年模拟考试 
F:股票买卖
总时间限制: 1000ms 内存限制: 65536kB
http://algorithm.openjudge.cn/betaexam/F/

思路：
类似于二段最大连续子序列和问题
1.正向遍历，针对每个点，保存其前面的最优解（最大收益） 
2.逆向遍历，针对每个点，保存其之后的最优解（最大收益） 
3.正向（逆向）走一遍，求出之前两步对应位置的和，同时找出最大值即为最优解（最大收益） 
复杂度O(n)
可以扩展到 K 段（待解） 

*/
#include <stdio.h>
#include <stdlib.h>

int num[100006]={0};
int f1[100006]={0};
int f2[100006]={0};

int main()
{
	int T=0;
	int n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			f1[i]=0;
			f2[i]=0;
		}
		int temp=num[0];
		int max=0;
		for(int i=0;i<n;i++)
		{
			if(num[i]>temp)
			{
				f1[i]=num[i]-temp;
				if(max>f1[i])
				{
					f1[i]=max;
				}else{
					max=f1[i];
				}
			}else{
				f1[i]=0;
				temp=num[i];
			}
		}
		temp=num[n-1];
		max=0;
		for(int i=n-1;i>=0;i--)
		{
			if(num[i]<temp)
			{
				f2[i]=temp-num[i];
				if(max>f2[i])
				{
					f2[i]=max;
				}else{
					max=f2[i];
				}
			}else{
				f2[i]=0;
				temp=num[i];
			}
		}
		temp=0;
		for(int i=0;i<n;i++)
		{
			if(temp<(f1[i]+f2[i]))
			{
				temp=f1[i]+f2[i];
			}
		}
		printf("%d\n",temp);
	}
	
	return 0;
} 
