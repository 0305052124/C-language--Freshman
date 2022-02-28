#define _CRT_SECURE_NO_WARNINGS 1
// 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
#include<stdio.h>
int main()
{
	int i = 0;
	double sum = 0;
	int  flat= 1;
	for (i = 1; i <= 100; i++)
	{
		sum += flat*(1.0/i);
		flat = -flat;
	}
	printf("求和结果为：%f\n", sum);
	return 0;
}
