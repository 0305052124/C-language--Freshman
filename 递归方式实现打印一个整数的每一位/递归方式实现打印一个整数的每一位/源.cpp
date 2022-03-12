#define _CRT_SECURE_NO_WARNINGS 1
//递归方式实现打印一个整数的每一位
#include<stdio.h>
void print(int x)
{
	if (x >9)
	{
		print(x / 10);
	}
	printf("%d ", x%10);
}
int main()
{
	int x = 0;
	scanf("%d", &x);
	print(x);
	printf("\n");
	return 0;
}