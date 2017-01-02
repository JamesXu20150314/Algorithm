/*
百练：算法分析和复杂性理论 / 2016年模拟考试 
D:求逆序对数
总时间限制: 500ms 内存限制: 65536kB
http://algorithm.openjudge.cn/betaexam/D/

思路： 
归并排序，加入带//的代码，计算某个数往后挪了多少个位置，求所有挪动位置的总和即为逆序对数 
利用了归并排序 O(nlogn) 

*/
#include <stdio.h>
#include <stdlib.h>

int n = 0; 
int num[20005]={0};
int count=0;// 

void print()
{
	for(int i=0; i<n; i++)
	{
		printf("%d ",num[i]);
	}
	printf("\n");
}

int merge(int a,int b,int c)
{
	int l[b-a+1]={0};
	int h[c-b]={0};
	for(int i=0;i<b-a+1;i++)
	{
		l[i]=num[a+i];
	}
	for(int i=0;i<c-b;i++)
	{
		h[i]=num[i+b+1];
	}
	
	for(int i=0,j=0,k=0;i<c-a+1;i++)
	{
		if(j==b-a+1)
		{
			num[i+a]=h[k];
			if((i+a) > (k+b+1))//
			{
				count = count + (i+a) - (k+b+1);// 
			}
			k++;
			continue;
		}
		if(k==c-b)
		{
			num[i+a]=l[j];
			if((i+a) > (j+a))//
			{
				count = count + (i+a) - (j+a);// 
			}
			j++;
			continue;
		}
		if(l[j]<=h[k])
		{
			num[i+a]=l[j];
			if((i+a) > (j+a))//
			{
				count = count + (i+a) - (j+a);// 
			}
			j++;
		}else{
			num[i+a]=h[k];
			if((i+a) > (k+b+1))//
			{
				count = count + (i+a) - (k+b+1);// 
			}
			k++;
		}
	}
	
	return 0;
}

int merge_sort(int a,int b)
{
	if(a<b)
	{
		int c=(a+b)/2;
		merge_sort(a,c);
		merge_sort(c+1,b);
		merge(a,c,b); 
	}
	return 0;
}

int main()
{
	
	while(scanf("%d",&n)!=EOF && n != 0)
	{
		count=0;// 
		for(int i=0; i<n; i++)
		{
			scanf("%d",&num[i]);
		}
		merge_sort(0,n-1);
		//print();
		printf("%d\n",count);
	} 
	
	return 0;
} 
