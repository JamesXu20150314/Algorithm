/******************************************
     Author: Zhimin Xu
       Time: 2017-10-19
Description: Record
*******************************************/ 
/******************************************

3:线性表元素删除
总时间限制: 1000ms 内存限制: 65535kB
描述
将输入数据存储于顺序表中，对其完成元素删除操作。

对于一组包含n项数据的输入完成下述操作：

        －存储于顺序表中

        －删除线性表中所有值大于x的元素的函数

        －输出删除完毕后的顺序表

所输入的数据均为整型， n <= 2000.



输入
第一行：一个整数c，表示共有c组数据
第2行到第2c+1行：输入的c组数据
每组数据包含两行：
－第一行：以空格分隔的n x
－第二行：以空格分割的n个整型输入
输出
每组数据输出一行，输出删除完毕后顺序表中的元素，以空格分隔
样例输入
1
10 6
1 4 9 0 2 6 7 5 8 3 
样例输出
1 4 0 2 6 5 3
提示
输出数据的每一行中，两个相邻数据之间有空格，但每行开头没有空格。

*******************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int c=0;
	int *const a=(int *)malloc(sizeof(int)*2000),*p=NULL;
	for(scanf("%d",&c);c;c--)
	{
		int n=0,x=0;
		scanf("%d%d",&n,&x);
		for(p=a;n;n--)
			scanf("%d",p++);
		int *b=p,*q=a;
		for(p=a;p!=b;p++)
			if(*p<=x)
				*(q++)=*p;
		b=q;
		for(p=a;p!=b;p++)
			printf("%d ",*p);
		putchar('\n');
	}
	return 0;
}
