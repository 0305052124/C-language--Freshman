#define _CRT_SECURE_NO_WARNINGS 1
//（1）一只青蛙一次可以跳上 1 级台阶，也可以跳上2 级。
//// 求该青蛙跳上一个n 级的台阶总共有多少种跳法。
//#include<stdio.h>
////int climbStairs(int n)
////{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else if (n == 2)
//	{
//		return 2;
//	}
//	else if (n > 2)
//	{
//		return climbStairs(n - 1) + climbStairs(n - 2);
//	}
//}

//int climbStairs(int n)
//{
//    if (n <= 2)    return n;
//    int p = 0, q = 0, r = 1;
//    for (int i = 1; i <= n; ++i)
//    {
//        p = q;
//        q = r;
//        r = p + q;
//    }
//    return r;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int count = climbStairs(n);
//	printf("跳到第%d阶台阶有%d种跳法", n, count);
//	return 0;
//}
/*（2）一只青蛙一次可以跳上1级台阶，也可以跳上2级,它也可以跳n级，
     此时该青蛙跳上一个n级的台阶总共有多少种跳法？*/
#include<stdio.h>
int fib(int n)
{
	if (n==1)
	{
		return 1;
	}
	else 
	{
		return 2 * fib(n - 1);
	}
	
}
int main()
{
	int n=0;
	scanf_s("%d", &n);
	int count = fib(n);
	printf("跳到第%d阶台阶有%d种跳法", n, count);
	return 0;
}
