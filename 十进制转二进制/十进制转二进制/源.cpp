#define _CRT_SECURE_NO_WARNINGS 1
//将任意一个十进制转换成二进制数 ，并将每位二进制数顺序存放到数组中，然后输出。
#include<stdio.h>
int main()
{
	int n = 0;
	int arr[32] = { 0 };
	int i=0,j=0;

	printf("Please input a number:\n");
	scanf("%d", &n);//x是十进制数字
	for (i = 1; i <= n; n /= 2)
	{
		if (n % 2 == 1)
		{
			arr[j] = 1;
		}
		else 
		{
			arr[j] = 0;
		}
		j++;
	}
	j -= 1;
	while (j >= 0)
	{
		printf("%d", arr[j]);
		j--;//倒序打印
	}
	return 0;
}
