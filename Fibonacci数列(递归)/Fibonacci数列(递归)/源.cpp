#define _CRT_SECURE_NO_WARNINGS 1
//�õݹ麯����Fibonacci���е�ǰ20�ÿ�����5�
#include<stdio.h>
int Fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else//Fibonacci(n)=Fibonacci(n-1)+Fibonacci(n-2);
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
int main()
{
	int n = 1;
	for (n = 1; n <= 20; n++)
	{
		int ret = Fibonacci(n);
		printf("%4d ", ret);
		if (n % 5 == 0)
		{
			printf("\n");
		}
	}
	return 0;
}