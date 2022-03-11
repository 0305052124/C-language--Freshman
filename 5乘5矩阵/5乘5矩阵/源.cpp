#define _CRT_SECURE_NO_WARNINGS 1
//输入一个5 * 5矩阵，将主对角线以外的上三角每个元素加1，下三角每个元素减1
#include<stdio.h>
int main()
{
	int a[5][5] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &a[i][j]);
		}
		printf("\n");
	}//输入了5*5的矩阵
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i > j)
			{
				a[i][j]--;
			}
			else if (i < j)
			{
				a[i][j]++;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}





