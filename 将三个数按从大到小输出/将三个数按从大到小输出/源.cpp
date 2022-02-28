#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()//自己第一遍做的
//{
//	int arr[3] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	int min = arr[0];
//	int mid = arr[0];
//	for (i = 0; i < 3; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//		if (min > arr[i])
//		{
//			min = arr[i];
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		if (arr[i] != min && arr[i] != max)
//			mid = arr[i];
//	}
//	
//	printf("%d %d %d", max, mid, min);
//	return 0;
//}
//int main()//冒泡函数
//{
//	int arr[3] = { 0 };
//	int x = 0;
//	int t;
//	printf("请输入三个整数：");
//	for (x = 0; x < 3; x++)
//	{
//		scanf("%d", &arr[x]);
//	}
//	for(int a=0;a<2;a++)//重点
//	{ 
//		for (int j = 0; j <2-a ; j++)
//		{
//			if (arr[j+1]<  arr[j ])
//			{
// 				t = arr[j + i];
//				arr[j + 1] = arr[j];
//				arr[j] = t;
//			}
//		}
//	}
//	for (int i = 0; i >3; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}
//
//  

//2.从键盘输入3个数，输出最大值和最小值
//要求：
//(1)用scanf函数输入三个数，且在输入前要有提示；
//(2)使用if…else结构出最大值，然后求出最小值，并使用printf输出
//提示：printf(“请输入三个数字：”)
