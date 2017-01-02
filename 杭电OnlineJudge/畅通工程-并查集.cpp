/*
1232:畅通工程 
Time Limit: 4000/2000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
http://acm.hdu.edu.cn/showproblem.php?pid=1232
并查集 
O(m*n) 
*/
#include <stdio.h>
#include <stdlib.h>

int pre[1005]={0};//结点数目
int n=0;//node 数 
int m=0;//road 数 
int tree[1005]={0};//最后树的数目 

void init()//初始化所有结点为一个单独的类，根节点为自己 
{
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;
		tree[i]=0;
	}
}

int find_root(int a)//发现所属类的根节点 
{
	int r=a;
	
	while(pre[r]!=r)
	{
		r=pre[r];
	}
	//
	//可以加入路径压缩 
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

void union_node(int x, int y)//同一类合并 
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
