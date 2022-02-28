#define _CRT_SECURE_NO_WARNINGS 1
//2．求素数
//编写函数判断某数是否为素数，如果是素数，则返回1，
//否则返回0，在main函数中调用该函数，根据返回值判断是否为素数。
#include<stdio.h>
int Isprime(int i)
{
	
	int j = 0;
	for (j =2; j < i; j++)
	{
		if (i % j == 0)
		{
			return 0;
		}
	}	
	return 1;
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	int ret = Isprime(i);
	if (ret == 1)
	{
		printf("%d是素数", i);
	}
	else
	{
		printf("%d不是素数", i);
	}
	return 0;
}

