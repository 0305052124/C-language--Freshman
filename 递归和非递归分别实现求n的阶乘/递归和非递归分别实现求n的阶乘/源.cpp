#define _CRT_SECURE_NO_WARNINGS 1
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//������1��n�����˻�������n�Ľ׳ˣ�������n!����2��n != 1x2x3x����xn
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
	printf("�ǵݹ�:%d\n", sum);
	printf("�ݹ�:%d\n", fib(x));
	return 0;
}