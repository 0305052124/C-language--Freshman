#define _CRT_SECURE_NO_WARNINGS 1
//1. 某汽车尾号具有如下特点：
//第一：它是一个4位数
//第二：它的前两位数相同，后两位数也相同，并且位数字不是同一个数字
//第三：它是另一个数的平方数。
//编程求该汽车尾号。
#include<stdio.h>
int main()
{
	int i = 1000;
	int a, b, c, d;
	for (i = 1000; i < 9999; i++)
	{
		a = i / 1000;
		b = (i / 100) % 10;
		c = (i % 100) / 10;
		d = i % 10;
		if ((a == b) &&(a!=c)&& (c == d))
		{
			if ((a == (c * c)) || (c == (a * a)))
			{
				printf("%d ", i);
			}
		}
	}
	return 0;
}