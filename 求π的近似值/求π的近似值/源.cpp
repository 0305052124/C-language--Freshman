#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 1;
	double sum = 0;
	double pi;
	int count = 0;
	double sign = 1.0;
	double term;
	/*for (i = 1; i < 10000; i += 2)
	{
		sum +=(sign* (1 / i));
		sign = - sign;
		count++;
	}*/
	do {
		term = sign / i;
		sum += term;
		count ++ ;
		sign = -sign;
		i+= 2;
	} while (fabs(term) >= 1e-4);//fabs(x)就是返回x的绝对值
	pi = 4 * sum;
	printf("pi=%lf\n count=%d\n", pi,count);
	return 0 ;
}
