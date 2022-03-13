#define _CRT_SECURE_NO_WARNINGS 1
//这个数列从第3项开始，每一项都等于前两项之和。
//递归和非递归分别实现求第n个斐波那契数
#include<stdio.h>
int My_fib(int x)
{
	int n1 = 0, n2  = 1,sum = 0;
	if (x <0)
	{
		return 0;
	}
	if (x == 1||x == 2)
	{
		return 1;
	}
	else if(x>=3)
	{
		for (int i = 1;i <x;i++)
		{
			n2 = n1 + n2; 
		    n1 = n2 - n1;
		}
		return n2;
	}
}
int fib(int x)
{
	if (x == 1 || x == 2)
	{
		return 1;
	}
	return fib(x - 1) + fib(x - 2);
}
int main()
{
	int x = 0;
	scanf("%d", &x);
	printf("非递归：%d\n", My_fib(x));
	printf("  递归：%d\n",fib(x));
	return 0;
}