#define _CRT_SECURE_NO_WARNINGS 1
//2��������
//��д�����ж�ĳ���Ƿ�Ϊ������������������򷵻�1��
//���򷵻�0����main�����е��øú��������ݷ���ֵ�ж��Ƿ�Ϊ������
#include<stdio.h>
int Isprime(int i)
{
	
	int j = 0;
	for (j =2; j < i; j++)
	{
		if (i % j == 0)
		{
			return 0;
		}
	}	
	return 1;
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	int ret = Isprime(i);
	if (ret == 1)
	{
		printf("%d������", i);
	}
	else
	{
		printf("%d��������", i);
	}
	return 0;
}

