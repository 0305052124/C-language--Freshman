#define _CRT_SECURE_NO_WARNINGS 1
//设计一个求n阶矩阵  所有元素之和的函数
//设计一个求n阶矩阵主对角元素之和的函数。
//设计一个求n阶矩阵次对角元素之和的函数。
//设计一个求n阶矩阵每行元素之和的函数
//设计一个求n阶矩阵每列元素之和的函数。
#include<stdio.h>
int i = 0,j=0;
int n=0;
int a[50][50] = { 0 };
int sum = 0, sum1 = 0, sum2 = 0, sum3=0,sum4=0;
void AllSum(int n)
{
	int sum = 0;
	for (i = 0; i < n; i++)//设计一个求n阶矩阵  所有元素之和的函数
	{
		for (j = 0; j < n; j++)
		{
			sum += a[i][j];
		}
	}	
	printf("所有元素之和为%d\n", sum);
}
void RowSum(int n)
{
	for (i = 0; i < n; i++)//求n阶矩阵每行元素之和
	{
		for (j = 0; j < n; j++)
		{
			sum1 += a[i][j];
		}
		printf("%2d ", sum1);
		sum1 = 0;
	}
	printf("\n");
}
void ColSum(int n)
{
	for (j = 0; j < n; j++)//求n阶矩阵每行元素之和
	{
		for (i = 0; i < n; i++)
		{
			sum2 += a[i][j];
		}
		printf("%2d ", sum2);
		sum2 = 0;
	}
	printf("\n");
}
void MainSum(int n)
{
	for (j = 0; j < n; j++)//求n阶矩阵每行元素之和
	{
		for (i = 0; i < n; i++)
		{
			if (i == j)
			{
				sum3 += a[i][j];
			}
		}
	}
	printf("%2d\n", sum3);
}
void MinSum(int n)
{
	for (i = 0, j = n - 1; i < n, j >=0; i++, j--)
	{
		sum4 += a[i][j];
	}
	printf("%2d\n", sum4);
}
int main()
{
	
	printf("请输入有几阶矩阵：");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
		printf("\n");
	}
	AllSum(n);
	RowSum(n);
	ColSum(n);
	MainSum(n);
	MinSum(n);
	return 0;
}
