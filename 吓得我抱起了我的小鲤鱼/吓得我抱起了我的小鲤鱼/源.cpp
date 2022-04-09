#define _CRT_SECURE_NO_WARNINGS 1
//假设递归函数形式为recursion(int  level)
//要求:
//recursion(0)输出内容为：  吓得我抱起了        我的小鲤鱼
//recursion(2)输出内容为：  吓得我抱起了抱着抱着我的小鲤鱼的我的我
//
//请根据上面的要求写出递归函数recursion(int  level)

#include<stdio.h>
void recursion(int level)
{
	printf("抱着");
	if (!level)
	{
		printf("我的小鲤鱼");
	}
	else
	{
		recursion(level - 1);
	}
	printf("的我");
}
int main()
{
	int n = 0;
	printf("请输入一个数字：");
	scanf("%d", &n);
	printf("吓得我抱起了");
	if (n == 0)
	{
		printf("我的小鲤鱼");
	}
	else
	{
		recursion(n - 1);
	}
	return 0;
}


