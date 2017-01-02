/*
�������㷨�����͸��������� / 2016��ģ�⿼�� 
F:��Ʊ����
��ʱ������: 1000ms �ڴ�����: 65536kB
http://algorithm.openjudge.cn/betaexam/F/

˼·��
�����ڶ���������������к�����
1.������������ÿ���㣬������ǰ������Ž⣨������棩 
2.������������ÿ���㣬������֮������Ž⣨������棩 
3.����������һ�飬���֮ǰ������Ӧλ�õĺͣ�ͬʱ�ҳ����ֵ��Ϊ���Ž⣨������棩 
���Ӷ�O(n)
������չ�� K �Σ����⣩ 

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
