#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//3.��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
int main()
{
	int a=0;
	scanf("%d", &a);
    int ret =0;
	int sum =0;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ret = ret*10+a;
		sum += ret;
	}
	printf("Sn=%d\n", sum);
	return 0;
}

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret; //		�� 
//	int sum = 0;
//	for (int i = 0; i < 5; i++) {
//
//		ret = 10 * ret + a; //		ÿһ�ε���       
//		sum = sum + ret;//		ÿһ��ѭ������ʱ�ĺ�
//
//	}
//
//	printf("Sn=%d\n", sum);
//}
