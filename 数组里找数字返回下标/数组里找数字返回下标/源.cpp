#define _CRT_SECURE_NO_WARNINGS 1
//写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回 - 1.（折半查找）
// 第一遍写的没有折半查找
//#include<stdio.h>
//int main()
//{
//	int a[10] = { 0,1,2,3,4,5,6,7,8,9};
//	int x = 0;
//	int j = 0;
//	scanf("%d", &x);
//	for ( j = 0; j < 10; j++)
//	{
//		int i = a[j];
//		if (x == i)
//		{
//			printf("%d", j+1);
//			break;
//		}
//	}
//	if (j == 10)
//	{
//		printf("-1");
//	}
//	return 0;
//}
#include<stdio.h>
#include <stdlib.h>
int halfFindArgs(int a[], int n,int x) 
{
	int left = 0;
	int mid = 0;
	int right =n - 1;//9
	int i = 0;//i是下标
	for (i = 0; i <= n; ++i)
	{
		mid = (right + left) / 2;//4
		if (x < a[mid])
		{
			right = mid - 1;
		}
		else if (x > a[mid])
		{
			left = mid + 1;
		}
		else//直接猜对or数组内没有猜的数字
		{
			return mid;
		}
	}
return -1;
}
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int x = 0;//猜的数字
	int n = sizeof(a) / sizeof(a[1]);
	printf("请输入您所要查找的数字:\n");
	scanf("%d", &x);
	printf("%d\n", halfFindArgs(a, n,x));
	return 0;
}


