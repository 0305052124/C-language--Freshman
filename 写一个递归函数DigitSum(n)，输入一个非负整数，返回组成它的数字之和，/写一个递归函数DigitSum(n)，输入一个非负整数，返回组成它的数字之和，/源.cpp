#define _CRT_SECURE_NO_WARNINGS 1
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19

#include<stdio.h>
int DigitSum(int n)
{

	if (n /10 == 0)
	{
		return n%10;
	}
	else
	{
		return DigitSum(n % 10) + DigitSum(n/10);
	}
	
}
int main()
{
	int n;
	scanf("%d", &n);

	int sum = DigitSum(n);
	printf("%d", sum);

	return 0;
}

