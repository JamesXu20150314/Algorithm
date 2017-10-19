/******************************************
     Author: Zhimin Xu
       Time: 2017-10-19
Description: Record
*******************************************/ 
/******************************************

4:有序表的归并
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65535kB
描述
根据两位助教分别统计的成绩表，给出全班成绩的排序，数据如课件中所示，学生姓名以拼音首字母表示。

你可以选择在代码中直接初始化结构体（忽略题目的输入），也可以读入程序的输入构建结构体。


两位助教的成绩表均已按降序排序，分数相同时优先输出助教一中的学生。



输入
两位助教的成绩表
输出
归并排序后的成绩表
样例输入
18001 LMZ 99
18003 ZW 96
18007 ZJ 91
18002 YC 86
18010 HJJ 83
18020 ZX 80
18019 XD 79
18011 LH 75
18012 FF 73
18008 WYW 71
18006 JX 69
18005 HB 65

18004 SC 100
18013 BTT 95
18009 ZL 90
18023 QM 89
18024 TC 88
18014 XY 85
18015 TK 82
18021 ZXO 78
18025 LJ 76
18016 ZY 73
18022 CM 70
18018 LS 67
18017 XZ 66
样例输出
18004 SC 100
18001 LMZ 99
18003 ZW 96
18013 BTT 95
18007 ZJ 91
18009 ZL 90
18023 QM 89
18024 TC 88
18002 YC 86
18014 XY 85
18010 HJJ 83
18015 TK 82
18020 ZX 80
18019 XD 79
18021 ZXO 78
18025 LJ 76
18011 LH 75
18012 FF 73
18016 ZY 73
18008 WYW 71
18022 CM 70
18006 JX 69
18018 LS 67
18017 XZ 66
18005 HB 65
提示
两位助教的成绩表均已按降序排序，分数相同时优先输出助教一中的学生。

*******************************************/
#include<stdio.h>
#include<malloc.h>

struct student
{
	int num;
	char name[5];
	int grade;
}; 
    
int main()
{
	int i,j,k;
	struct student palist[13],pblist[14],pclist[26];
	for(i=1;i<=12;i++)
    {
    	scanf("%d%s%d",&palist[i].num,palist[i].name,&palist[i].grade);  
	}
	for(j=1;j<=13;j++)
    {
    	scanf("%d%s%d",&pblist[j].num,pblist[j].name,&pblist[j].grade);
	}

	
	i=j=1;
	for(k=1;k<=25;k++)
   {
  		if(i<=12&&j<=13&&(palist[i].grade)>=(pblist[j].grade)||j>13)             
      	{
		  	pclist[k]=palist[i];
      		i++;
	  	}
		else
      	{
		  	pclist[k]=pblist[j]; 
      		j++;
	  	}
	} 

	for(k=1;k<=25;k++)
   {
   		printf("%d %s %d\n",pclist[k].num,pclist[k].name,pclist[k].grade);
	} 
	
	return 0;
}


