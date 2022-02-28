#define _CRT_SECURE_NO_WARNINGS 1
//在商场购物时，若所购物品的总价值x（由键盘输入）在某一范围时，付款y按对应折扣支付，即
//x    x < 1000
//	y = 0.9x   1000 x < 2000
//	0.8x   2000 x < 3000
//	0.7x   x 3000
//	编写程序，根据x的值计算y
//	要求：
//	(1)用scanf函数输入x（x为小数），且在输入前要有提示“请输入商品总价值x的值： ”；
//	(2)使用if 语句判断，计算y的值
//	(2)使用printf输出y的值，小数点保留2位
//
#include<stdio.h>
int main()
{
	float x=0.0;
	double y = 0.0;
	printf("请输入商品总价值x的值：\n");
	scanf("%f", &x);
	if (x < 1000)
	{
		y = x;
	}
	else if (x < 2000)
	{
		y = 0.9 * x;
	}
	else if (x < 3000)
	{
		y = 0.8 * x;
	}
	else
	{
		y = 0.7 * x;
	}
	printf("%.2f", y);
	return 0;
}
