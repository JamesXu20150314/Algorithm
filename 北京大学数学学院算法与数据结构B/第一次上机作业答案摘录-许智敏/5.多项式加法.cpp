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
#define MAX 350 
struct Node;
typedef struct Node*PNode; //�ṹ��ָ��������
struct Node{
	int num; //ϵ��
	int power; //�ݴ�
};
struct List
{
	int max;              
	int n;            
	PNode element;
};
typedef struct List*Plist; //�ṹ��ָ�������� 

Plist crea(int b); //�������� 
void inse(Plist llist, Node p); //�������� 
int find(Plist llist, Node p); //��������
int main(){
	int s,i=0,j,t,k,l;
	Node p,a,b;
	Plist llist;	
	scanf("%d",&k);
	for(l=0;l<k;l++){
		Plist plist1 = crea(MAX);
		Plist plist2 = crea(MAX);
		Plist plist3 = crea(MAX);
		while(scanf("%d %d", &p.num, &p.power) && p.power>=0) // �����һ������ʽ 
		{
			s = find(plist1, p);
			if( s == plist1->n) 
				plist1->element[plist1->n++]=p;
			else
				plist1->element[s].num+=p.num;
		}	
		while(scanf("%d %d", &p.num, &p.power) && p.power>=0) // ����ڶ�������ʽ 
		{
			s = find(plist1, p);
			if( s == plist1->n) 
				plist1->element[plist1->n++]=p;
			else
				plist1->element[s].num+=p.num;
		}
		
		for(s=1;s<plist1->n;s++) //���� 
		{
			for(j=0;j<plist1->n-s;j++)
				if(plist1->element[j].power<plist1->element[j+1].power)
				{
					p=plist1->element[j];
					plist1->element[j]=plist1->element[j+1];
					plist1->element[j+1]=p;	
				}
		}
		for(s=1;s<plist3->n;s++) //���� 
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
		while(i<plist1->n&&j<plist3->n) // �ϲ���ͬ�ݴ��� 
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
		for(;i<plist1->n;i++) {inse(plist2, plist1->element[i]);}//�鲢δ�ϲ����� 
		for(;j<plist3->n;j++) {inse(plist2, plist3->element[j]);}//�鲢δ�ϲ����� 
		for(i=0;i<plist2->n;i++) //��� 
			if(plist2->element[i].num!=0)
				printf("[ %d %d ] ", plist2->element[i].num, plist2->element[i].power);	
		printf("\n");
		free(plist1); free(plist2); //�ͷ�������ڴ�ռ� 
	}
	return 0;
}

Plist crea(int b) // ����˳��� 
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

void inse(Plist llist, Node p) //����Ԫ�� 
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


