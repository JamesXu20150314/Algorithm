/*
百练：算法分析和复杂性理论 / 2016年第三次作业 
3:To the Max
总时间限制: 5000ms 内存限制: 65536kB
http://algorithm.openjudge.cn/200603/3/

思路：
将矩阵选取一些行数，压缩为一维数组，用最大子序列和算法（O(n)） 来求解，最后复杂度为（O(n^3)） ，O(n^4)会TLE 

*/

#include<stdio.h>
#include<stdlib.h>

int n[501][501];
int f[501];

int maxSum(int n)
{
	int max=0,temp=0;
	for(int i=0;i<n;i++)
	{
		if(temp>0)
		{
			temp+=f[i];
			if(temp<0)
			{
				temp=0;
			}
		}else{
			temp=f[i];
		}
		if(max<temp)
		{
			max=temp;
		}
	}
	return max;
}

int main()
{
	int max=0,N=0;
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)//记得预处理列 
		{
			scanf("%d",&n[i][j]);
		}	
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int k=1;k<=N;k++)
		{
			f[k]=0;
		}
		for(int j=i;j<=N;j++)
		{
			for(int k=0;k<N;k++)
			{
				f[k]+=n[j][k];
			}
			int temp=maxSum(N);
			if(max<temp)
			{
				max=temp;
			}	
		}	
	}
	printf("%d\n",max);	
	return 0;
 } 
