#define _CRT_SECURE_NO_WARNINGS 1
////1�����ܱ�3��������
////��дһ��������ѡ��
//�ܱ�3����������һλ��5����λ����
//��������������������������������������λ����
#include<stdio.h>
int IsPerfect(int x)
{
	if (x % 3 == 0 && (x / 10 == 5 || x % 10 == 5))
	{
		return x;
	}
	/*if (x % 3 == 0)
	{
		if (x / 10 == 5)
		{
			if (x % 10 == 5)
			{
				return x;
			}
		}
	}*/
	else
	{
		return 0;
	}
	
}
int main()
{
	int x = 10;
	for (x = 10; x < 100; x++)
	{
     int n=IsPerfect(x);
	 if (n != 0)
	 {
        printf("%d\n", n);
	 }
	}
	return 0;
}
