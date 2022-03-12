#define _CRT_SECURE_NO_WARNINGS 1
//递归和非递归分别实现求n的阶乘
//正整数1到n的连乘积，叫做n的阶乘，记作“n!”。2、n != 1x2x3x……xn
#include<stdio.h>
int fib(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) * n;
	}
}
int main()
{
	int x=0;
	scanf("%d", &x);
	int sum = 1;
	for (int i = 1; i <= x; i++)
	{
		sum = sum * i;
	}
	printf("非递归:%d\n", sum);
	printf("递归:%d\n", fib(x));
	return 0;
}