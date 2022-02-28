#define _CRT_SECURE_NO_WARNINGS 1
//3.以下程序的功能是用递归方法计算学生的年龄，
//已知第一位学生年龄最小，为10岁
//其余学生一个比一个大2岁，求第12位学生的年龄。
#include<stdio.h>
int age(int n)
{
	if (n == 1)
	{
		return 10;
	}
	else 
	{
      return age(n - 1) + 2;
	}
	
}
int main()
{
	int n = 12;

	printf("%d\n", age(n));
	return 0;
}

