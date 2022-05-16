#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int x, n;
//	scanf("%d%d", &x, &n);
//	double sum = 1;
//	for (int i = 0; i < n; i++)
//	{
//		sum *= x;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}


//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int x, n;
//	scanf("%d%d", &x, &n);
//	double sum = pow(x, n);
//	printf("%lf\n", sum);
//	return 0;
//}

#include<stdio.h>
//double(double x, int n) // 计算并返回x^n的值
double factorial(double x, double n)
{
	if (n == 0)
		return 1.0;
	else
		return (x * factorial(x, n - 1));
}
int main()
{
	double x = 1;
	int  n = 1;
	scanf("%lf %d", &x, &n);
	if (n < 0)
		printf("%lf^%d=%lf\n", x, n, 1 / factorial(x, -n));
	else
		printf("%lf^%d=%lf\n", x, n, factorial(x, n));
	return 0;
}
