/******************************************
     Author: Zhimin Xu
       Time: 2017-10-19
Description: Record
*******************************************/ 
/******************************************

2:˳������������
��ʱ������: 1000ms �ڴ�����: 65535kB
����
���������ݴ洢��˳����У����������������Ҳ�����

����һ�����n�����ݵ������������������

        ���洢��˳�����

        ����˳�������

        �����ڸ�����x��y�����˳���������һ��ֵ���� x��С��y��Ԫ�ص�ǰ���ͺ��Ԫ��

����������ݾ�Ϊ����, n <= 2000,�����ܹ���֤ǰ���ͺ��Ԫ��һ�����ڡ�

����
��һ�У�һ������c����ʾ����c������
��2�е���2c+1�У������c������
ÿ�����ݰ������У�
����һ�У��Կո�ָ���n x y
���ڶ��У��Կո�ָ��n����������
���
ÿ���������һ�У����˳���������һ��ֵ���� x��С��y��Ԫ�ص�ǰ���ͺ��Ԫ�أ��Կո�ָ�
��������
1
10 3 7
8 7 9 5 4 6 2 3 0 1 
�������
2 4
��ʾ
������ݵ�ÿһ���У�������������֮���пո񣬵�ÿ�п�ͷû�пո�

*******************************************/

#include<stdio.h>
#include<malloc.h>
#define Max 2000 

struct list
{
	int n;
	int *element;
};   
typedef struct list * Plist; //�ṹ��ָ����������� 
     
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
	    for(j=plist->n-1;j>=0;j--) // �����ڶ����ʱ��ֱ�����棬���߲��ҵ�ʱ������� 
	    {
		  	scanf("%d",&plist->element[j]); 
		}
		for(j=0;j<plist->n;j++)
		{
		    if(plist->element[j]>x&&plist->element[j]<y)//��������Ҫ���Ԫ�� 
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


