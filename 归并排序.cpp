/*
算法导论 
归并排序
O(n*log(n)) 
*/
#include <stdio.h>
#include <stdlib.h>

int n = 0; 
int num[20005]={0};

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
			k++;
			continue;
		}
		if(k==c-b)
		{
			num[i+a]=l[j];
			j++;
			continue;
		}
		if(l[j]<=h[k])
		{
			num[i+a]=l[j];
			j++;
		}else{
			num[i+a]=h[k];
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
		for(int i=0; i<n; i++)
		{
			scanf("%d",&num[i]);
		}
		merge_sort(0,n-1);
		print();
	} 
	
	return 0;
} 
