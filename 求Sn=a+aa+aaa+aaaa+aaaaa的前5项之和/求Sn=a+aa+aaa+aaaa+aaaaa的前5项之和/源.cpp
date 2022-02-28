#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//3.求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
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
//	int ret; //		项 
//	int sum = 0;
//	for (int i = 0; i < 5; i++) {
//
//		ret = 10 * ret + a; //		每一次的项       
//		sum = sum + ret;//		每一次循环结束时的和
//
//	}
//
//	printf("Sn=%d\n", sum);
//}
