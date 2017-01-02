/*
1232:��ͨ���� 
Time Limit: 4000/2000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
http://acm.hdu.edu.cn/showproblem.php?pid=1232
���鼯 
O(m*n) 
*/
#include <stdio.h>
#include <stdlib.h>

int pre[1005]={0};//�����Ŀ
int n=0;//node �� 
int m=0;//road �� 
int tree[1005]={0};//���������Ŀ 

void init()//��ʼ�����н��Ϊһ���������࣬���ڵ�Ϊ�Լ� 
{
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;
		tree[i]=0;
	}
}

int find_root(int a)//����������ĸ��ڵ� 
{
	int r=a;
	
	while(pre[r]!=r)
	{
		r=pre[r];
	}
	//
	//���Լ���·��ѹ�� 
	int temp1=a,temp2=pre[temp1];
	while(temp2!=r)
	{
		pre[temp1]=r;
		temp1=temp2;
		temp2=pre[temp1];
	}
	// 
	return r;
}

void union_node(int x, int y)//ͬһ��ϲ� 
{
	int r_x=find_root(x);
	int r_y=find_root(y);
	if(r_x!=r_y)
	{
		pre[r_x]=r_y;
	}
}

int main()
{
	
	while(scanf("%d",&n)!=EOF && n != 0)
	{
		scanf("%d",&m);
		int a=0,b=0;
		init(); 
		while(m--)
		{
			scanf("%d %d",&a,&b);
			union_node(a,b);
		}
		//find tree number
		int num=0;
		for(int i=1;i<=n;i++)
		{
			tree[find_root(i)]=1; 
		}
		for(int i=1;i<=n;i++)
		{
			if(tree[i]==1)
			{
				num++;
			}
		}
		printf("%d\n",num-1);
	}
	
	return 0;
}
