#define _CRT_SECURE_NO_WARNINGS 1
//4.��������湫ʽ��ֵ, Ҫ���д�׳˺���, �ɲ��õݹ鷽�����ٵ��á�
#include<stdio.h>
int factorial(int n)
{
	//factorial(n)=n*factorial(n-1)
	if (n <= 1)
	{
		return 1;
	}
	return n * factorial(n - 1);
}
int main()
{
	int n = 1;
	int m = 1;
	printf("�Ⱥ�����m n:");
	scanf("%d %d", &m, &n);
	int x = factorial(m);
	int y = factorial(n);
	int z = factorial(m - n);
	int sum = x/(y * z);
	printf("%ld\n", sum);
	return 0;
}

