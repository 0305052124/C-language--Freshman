#define _CRT_SECURE_NO_WARNINGS 1
//��дһ������ʵ��n^ k��ʹ�õݹ�ʵ��
#include<stdio.h>
int fib(int n, int k)//n^k=n^(k-1)
{
	if (k == 1)
		return n;
	else if (k == 0)
		return 1;
	else
		return n * fib(n, k - 1);
}
int main()
{
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);
	int sum = fib(n, k);
	printf("%d", sum);
	return 0;
}