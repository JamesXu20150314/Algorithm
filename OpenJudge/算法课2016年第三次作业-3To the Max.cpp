/*
�������㷨�����͸��������� / 2016���������ҵ 
3:To the Max
��ʱ������: 5000ms �ڴ�����: 65536kB
http://algorithm.openjudge.cn/200603/3/

˼·��
������ѡȡһЩ������ѹ��Ϊһά���飬����������к��㷨��O(n)�� ����⣬����Ӷ�Ϊ��O(n^3)�� ��O(n^4)��TLE 

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
		for(int j=1;j<=N;j++)//�ǵ�Ԥ������ 
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
