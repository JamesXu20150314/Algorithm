/******************************************
     Author: Zhimin Xu
       Time: 2017-10-19
Description: Record
*******************************************/ 
/******************************************

2:顺序表置逆与查找
总时间限制: 1000ms 内存限制: 65535kB
描述
将输入数据存储于顺序表中，对其完成置逆与查找操作。

对于一组包含n项数据的输入完成下述操作：

        －存储于顺序表中

        －将顺序表置逆

        －对于给定的x与y，输出顺序表置逆后第一个值大于 x，小于y的元素的前驱和后继元素

所输入的数据均为整型, n <= 2000,数据能够保证前驱和后继元素一定存在。

输入
第一行：一个整数c，表示共有c组数据
第2行到第2c+1行：输入的c组数据
每组数据包含两行：
－第一行：以空格分隔的n x y
－第二行：以空格分割的n个整型输入
输出
每组数据输出一行，输出顺序表置逆后第一个值大于 x，小于y的元素的前驱和后继元素，以空格分隔
样例输入
1
10 3 7
8 7 9 5 4 6 2 3 0 1 
样例输出
2 4
提示
输出数据的每一行中，两个相邻数据之间有空格，但每行开头没有空格。

*******************************************/

#include<stdio.h>
#include<malloc.h>
#define Max 2000 

struct list
{
	int n;
	int *element;
};   
typedef struct list * Plist; //结构体指针变量重命名 
     
int main() 
{
	int i,j,m,*pre,*post,x,y;
	Plist plist;
	
	scanf("%d",&m);
	plist=(Plist)malloc(sizeof(struct list));
	plist->element=(int*)malloc(sizeof(int)*Max);
	pre=(int*)malloc(sizeof(int)*m); 
	post=(int*)malloc(sizeof(int)*m); 
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&plist->n,&x,&y);
	    for(j=plist->n-1;j>=0;j--) // 可以在读入的时候直接置逆，或者查找的时候反向查找 
	    {
		  	scanf("%d",&plist->element[j]); 
		}
		for(j=0;j<plist->n;j++)
		{
		    if(plist->element[j]>x&&plist->element[j]<y)//查找满足要求得元素 
		    {
				*(pre+i)=plist->element[j-1];
		      	*(post+i)=plist->element[j+1];
		      	break;
			}
		}
	}
	   
	for(i=0;i<m;i++)
	{
		printf("%d %d\n",*(pre+i),*(post+i));
	}
	free(plist->element);
	free(plist); 
	free(pre);
	free(post);
	
	return 0;
}


