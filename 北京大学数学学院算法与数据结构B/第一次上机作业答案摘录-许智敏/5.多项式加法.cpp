/******************************************
     Author: Zhimin Xu
       Time: 2017-10-19
Description: Record
*******************************************/ 
/******************************************

5:����ʽ�ӷ�
��ʱ������: 1000ms �ڴ�����: 5000kB
����
    ���Ǿ�������������ʽ��ӵ��������������Ǿ���Ҫ�ó�����ģ��ʵ�ְ���������ʽ��ӵ�һ�����ȣ����ǻ�����������ʽ��ÿ������ʽ�Ƕ�����һ�У�ÿ������ʽ��ϵ�������������Ķ������������ʾ��

�����ʽ2x20- x17+ 5x9- 7x7+ 16x5+ 10x4 + 22x2- 15

��Ӧ�ı��ʽΪ��2 20 -1 17 5 9 - 7 7 16 5 10 4 22 2 -15 0��  

Ϊ�˱��ÿ�ж���ʽ�Ľ������ڱ��ʽ���������һ������Ϊ�����������ԡ�

ͬʱ������ʽ��������С˳��������ġ�

������Ҫ���ľ��ǰ���������������ʽ��������

����
����������С�
��һ������n,��ʾ�ж�����Ķ���ʽ��Ҫ��͡�(1 < n < 100)
����Ϊ2n��������ÿһ�ж���һ������ʽ�ı��ʽ����ʾn����Ҫ��ӵĶ���ʽ��
ÿ�г���С��300��
���
�������n�У�ÿ��Ϊ1�����ʽ��ӵĽ����
��ÿһ�е��������У�����ʽ��ÿһ���á�[x y]����ʽ���ַ�����ʾ��x�Ǹ����ϵ����y �Ǹ����������Ҫ����ÿһ����ݴӸߵ������У�������������ߵ������������͵��
ϵ��Ϊ����Ҫ�����
��������
2
-1 17 2 20 5 9 -7 7 10 4 22 2 -15 0 16 5 0 -1
2 19 7 7 3 17 4 4 15 10 -10 5 13 2 -7 0 8 -8
-1 17 2 23 22 2 6 8 -4 7 -18 0 1 5 21 4 0 -1
12 7 -7 5 3 17 23 4 15 10 -10 5 13 5 2 19 9 -7
�������
[ 2 20 ] [ 2 19 ] [ 2 17 ] [ 15 10 ] [ 5 9 ] [ 6 5 ] [ 14 4 ] [ 35 2 ] [ -22 0 ]
[ 2 23 ] [ 2 19 ] [ 2 17 ] [ 15 10 ] [ 6 8 ] [ 8 7 ] [ -3 5 ] [ 44 4 ] [ 22 2 ] [ -18 0 ]
��ʾ
��һ���������ݵĵڶ���ĩβ��8 -8����Ϊ�ݴ�-8Ϊ������������һ�����ݽ�����8 -8��Ҫ������㡣

*******************************************/

#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node*PNode;
struct Node{
	int a;
	int c;
	PNode link;
};
typedef struct Node*Plist;

Plist crea(void);
int inse(Plist llist,PNode p,int x,int y);

int main(){
	int s,i=0,j,t,k,l;
	PNode p,q;
	Plist llist;
	
	scanf("%d",&k);
	for(l=0;l<k;l++){
	llist=crea();
	p=llist;

	while(scanf("%d %d",&s,&t)!=NULL&&t>=0){
		p=llist;
		if(i==0){
			inse(llist,p,s,t);
		}
		else {
		while(p->link!=NULL&&t<p->link->c) p=p->link;
        if(p->link!=NULL){
		if(t!=p->link->c) inse(llist,p,s,t);
		else p->link->a+=s;}
		else inse(llist,p,s,t);
		}
		i++;
	}
	while(scanf("%d %d",&s,&t)!=NULL&&t>=0){
		p=llist;
		while(p->link!=NULL&&t<p->link->c)  p=p->link;
		if(p->link!=NULL){
		if(t!=p->link->c) inse(llist,p,s,t);
		else p->link->a+=s;}
		else 
		inse(llist,p,s,t);
		i++;
	}

	p=llist;
	while(p->link!=NULL){
		if(p->link->a!=0) printf("[ %d %d ] ",p->link->a,p->link->c);
		p=p->link;
	}printf("\n");}
	return 0;
}

Plist crea(void)
{
	Plist llist=(Plist)malloc(sizeof(struct Node));
	if(llist!=NULL) llist->link=NULL;
	else printf("Out of space!\n");
	return llist;
}

int inse(Plist llist,PNode p,int x,int y)
{
	PNode q=(PNode)malloc(sizeof(struct Node));
	if(q==NULL) return 0;
	q->a=x;q->c=y;q->link=p->link;p->link=q;
	return 1;
}
