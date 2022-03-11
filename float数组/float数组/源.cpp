#define _CRT_SECURE_NO_WARNINGS 1
////1．定义一个拥有10个元素的float数组。
//要求：(1)用for循环结构，从键盘输入数组元素。
//      (2)找出并输出数组中的最大值max，最小值min。

#include<stdio.h>
int main()
{
	int j = 0;
	float a[10] = { 0.0 };
	
	
	for (j = 0; j < 10; j++)
	{
		scanf("%f", &a[j]);
	}
	float max=a[0];
	float min = a[0];
	for (j = 0; j < 10; j++)
	{
		if (a[j] > max)
		{
			max = a[j];
		}
		if (a[j] < min)
		{
			min = a[j];
		}
     }
	
	for (j = 0; j < 10; j++)
	{
		printf("%f\n ", a[j]);
	}	
	printf("最小值是%f\n ", min);
	printf("最大值是%f\n ", max);
	return 0;
}
