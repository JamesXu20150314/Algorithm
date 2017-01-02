/*
Leetcode: 371. Sum of Two Integers
Src: https://leetcode.com/problems/sum-of-two-integers/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b;
	int c;
	
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		c = 0;
		c = a & b;//��λΪ1
		b = a ^ b;//����Ҫ����λ���� 
		while(c != 0)
		{
			a = c << 1;
			c = a & b;
			b = a ^ b;
		} 
		printf("%d\n",b);
		
	} 
	
	return 0;
} 

˼·��
��������������������
O(1) 
*/


#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if(a == 0) {
        	return b;
		}
		if(b == 0) {
			return a;
		}
		
		int Xor = 0;
		int And = 0;
		
		Xor = a ^ b;
		And = (a & b) << 1;
		
		return getSum(Xor, And);
    }
};

int main()
{
	int x = 0;
	int y = 0;
	
	cin >> x >> y;
	
	Solution s;
	
	cout << s.getSum(x,y) << endl;;	
	
	return 0;
}
