#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
	int i = 0;
	int a, b, c;
	int max = a;
	int min = a;
	printf("请输入三个数字：");
	scanf("%d", &a, &b, &c);
	if (b > max)
	{
		max = b;
		min = a;
		if (c > b)
		{
			max = c;
			min = a;
		}
		else if (c < a)
		{
			max = b;
			min = c;
		}
	}
	else
	{
		max = a;
		min = b;
		if (c > a)
		{
			max = c;
			min = b;
		}
		else if (c < b)
		{
			max = a;
			min = c;
		}
	}
	printf("%d %d", max, min);
	return 0;
}