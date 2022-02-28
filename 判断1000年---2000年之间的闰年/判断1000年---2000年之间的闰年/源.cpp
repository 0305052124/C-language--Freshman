#define _CRT_SECURE_NO_WARNINGS 1
//判断1000年-- - 2000年之间的闰年
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	int count=0;
	for (i = 1000; i <= 2000; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n%d", count);
	return 0;
}