#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int Find(int a, int b)
//{
//	int x = a;
//	for (x = (a+1); x < 10000000; x++)
//	{
//		if (x % a == 0 && x % b == 0)
//			return x;
//		break;
//	}
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int max = 0;
//	int min = 0;
//	printf("请输入两个整数：");
//	scanf("%d%d", &i, &j);
//	//先求出最大值
//	if (i >= j)
//	{
//		 max = i;
//		 min = j;
//	}
//	else
//	{
//		 max = j
//		 min = i;
//	}
//	if (max % min == 0)
//	{
//		printf("最大公约数是%d", max);
//	}
//	else
//	{
//		int fine=Find(max, min);
//		printf("最大公约数是%d", fine);
//	}
//	return 0;
//}
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入两个整数:");
	scanf("%d%d", &a, &b);
	if (a >= b) 
	{
		int i = 0;
		for (i = b; i >= 1; i--) 
		{
			if (a % i == 0 && b % i == 0) 
			{
				printf("最大公约数为：%d\n", i);
				break;
			}
		}
	}
	//公约数<=最小的数
	else 
	{
		int j = 0;
		for (j = a; j >= 1; j--) 
		{
			if (a % j == 0 && b % j == 0) 
			{
				printf("最大公约数为：%d\n", j);
				break;
			}
		}
	}

	return 0;
}
