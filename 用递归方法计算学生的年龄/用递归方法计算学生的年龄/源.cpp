#define _CRT_SECURE_NO_WARNINGS 1
//3.���³���Ĺ������õݹ鷽������ѧ�������䣬
//��֪��һλѧ��������С��Ϊ10��
//����ѧ��һ����һ����2�꣬���12λѧ�������䡣
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

