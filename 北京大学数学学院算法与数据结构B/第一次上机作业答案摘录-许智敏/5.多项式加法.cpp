/******************************************
     Author: Zhimin Xu
       Time: 2017-10-19
Description: Record
*******************************************/ 
/******************************************

5:多项式加法
总时间限制: 1000ms 内存限制: 5000kB
描述
    我们经常遇到两多项式相加的情况，在这里，我们就需要用程序来模拟实现把两个多项式相加到一起。首先，我们会有两个多项式，每个多项式是独立的一行，每个多项式由系数、幂数这样的多个整数对来表示。

如多项式2x20- x17+ 5x9- 7x7+ 16x5+ 10x4 + 22x2- 15

对应的表达式为：2 20 -1 17 5 9 - 7 7 16 5 10 4 22 2 -15 0。  

为了标记每行多项式的结束，在表达式后面加上了一个幂数为负数的整数对。

同时输入表达式的幂数大小顺序是随机的。

我们需要做的就是把所给的两个多项式加起来。

输入
输入包括多行。
第一行整数n,表示有多少组的多项式需要求和。(1 < n < 100)
下面为2n行整数，每一行都是一个多项式的表达式。表示n组需要相加的多项式。
每行长度小于300。
输出
输出包括n行，每行为1组多项式相加的结果。
在每一行的输出结果中，多项式的每一项用“[x y]”形式的字符串表示，x是该项的系数、y 是该项的幂数。要求按照每一项的幂从高到低排列，即先输出幂数高的项、再输出幂数低的项。
系数为零的项不要输出。
样例输入
2
-1 17 2 20 5 9 -7 7 10 4 22 2 -15 0 16 5 0 -1
2 19 7 7 3 17 4 4 15 10 -10 5 13 2 -7 0 8 -8
-1 17 2 23 22 2 6 8 -4 7 -18 0 1 5 21 4 0 -1
12 7 -7 5 3 17 23 4 15 10 -10 5 13 5 2 19 9 -7
样例输出
[ 2 20 ] [ 2 19 ] [ 2 17 ] [ 15 10 ] [ 5 9 ] [ 6 5 ] [ 14 4 ] [ 35 2 ] [ -22 0 ]
[ 2 23 ] [ 2 19 ] [ 2 17 ] [ 15 10 ] [ 6 8 ] [ 8 7 ] [ -3 5 ] [ 44 4 ] [ 22 2 ] [ -18 0 ]
提示
第一组样例数据的第二行末尾的8 -8，因为幂次-8为负数，所以这一行数据结束，8 -8不要参与计算。

*******************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAX 350 
struct Node;
typedef struct Node*PNode; //结构体指针重命名
struct Node{
	int num; //系数
	int power; //幂次
};
struct List
{
	int max;              
	int n;            
	PNode element;
};
typedef struct List*Plist; //结构体指针重命名 

Plist crea(int b); //函数声明 
void inse(Plist llist, Node p); //函数声明 
int find(Plist llist, Node p); //函数声明
int main(){
	int s,i=0,j,t,k,l;
	Node p,a,b;
	Plist llist;	
	scanf("%d",&k);
	for(l=0;l<k;l++){
		Plist plist1 = crea(MAX);
		Plist plist2 = crea(MAX);
		Plist plist3 = crea(MAX);
		while(scanf("%d %d", &p.num, &p.power) && p.power>=0) // 读入第一个多项式 
		{
			s = find(plist1, p);
			if( s == plist1->n) 
				plist1->element[plist1->n++]=p;
			else
				plist1->element[s].num+=p.num;
		}	
		while(scanf("%d %d", &p.num, &p.power) && p.power>=0) // 读入第二个多项式 
		{
			s = find(plist1, p);
			if( s == plist1->n) 
				plist1->element[plist1->n++]=p;
			else
				plist1->element[s].num+=p.num;
		}
		
		for(s=1;s<plist1->n;s++) //排序 
		{
			for(j=0;j<plist1->n-s;j++)
				if(plist1->element[j].power<plist1->element[j+1].power)
				{
					p=plist1->element[j];
					plist1->element[j]=plist1->element[j+1];
					plist1->element[j+1]=p;	
				}
		}
		for(s=1;s<plist3->n;s++) //排序 
		{
			for(j=0;j<plist3->n-s;j++)
				if(plist3->element[j].power<plist3->element[j+1].power)
				{
					p=plist3->element[j];
					plist3->element[j]=plist3->element[j+1];
					plist3->element[j+1]=p;	
				}
		}		
		i=0; j=0;
		while(i<plist1->n&&j<plist3->n) // 合并相同幂次项 
		{
			a = plist1->element[i];
			b = plist3->element[j];
			if(a.power==b.power) {
				a.num += b.num;
				if(a.num!=0) {inse(plist2, a);}
				++i;++j;
			}else{
				if(a.power>b.power) {inse(plist2, a);++i;}
				else {inse(plist2, b);++j;}
			}
		}
		for(;i<plist1->n;i++) {inse(plist2, plist1->element[i]);}//归并未合并的项 
		for(;j<plist3->n;j++) {inse(plist2, plist3->element[j]);}//归并未合并的项 
		for(i=0;i<plist2->n;i++) //输出 
			if(plist2->element[i].num!=0)
				printf("[ %d %d ] ", plist2->element[i].num, plist2->element[i].power);	
		printf("\n");
		free(plist1); free(plist2); //释放申请的内存空间 
	}
	return 0;
}

Plist crea(int b) // 创建顺序表 
{
	Plist palist;
	palist = (Plist) malloc(sizeof(struct List));
	if(palist!= NULL)
	{
		palist->element = (PNode) malloc(sizeof(Node)*b);
		if(palist->element!=NULL)
		{
			palist->max = b;
			palist->n = 0;
			return(palist);
		}
		else
			free(palist);
	}
	printf("Out of Space!\n");
	return NULL; 
}

void inse(Plist llist, Node p) //插入元素 
{
	llist->element[llist->n]=p;
	llist->n+=1;
	return ;
}

int find(Plist llist, Node p) {
	int i=0;
	for (i=0; i<llist->n; i++) {if(p.power==llist->element[i].power) break;}
	return i;
}


