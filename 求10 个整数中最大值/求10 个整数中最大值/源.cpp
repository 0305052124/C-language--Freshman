#define _CRT_SECURE_NO_WARNINGS 1
//求10 个整数中最大值
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = {0};
	int i=0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max = arr[0];
	for(i=0;i<10;i++)
	{
		if (max<arr[i])
		{
			max = arr[i];
		}
	}
	printf("%d", max);
		return 0;
}