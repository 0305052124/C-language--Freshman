#define _CRT_SECURE_NO_WARNINGS 1
//��1��һֻ����һ�ο������� 1 ��̨�ף�Ҳ��������2 ����
//// �����������һ��n ����̨���ܹ��ж�����������
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
//	printf("������%d��̨����%d������", n, count);
//	return 0;
//}
/*��2��һֻ����һ�ο�������1��̨�ף�Ҳ��������2��,��Ҳ������n����
     ��ʱ����������һ��n����̨���ܹ��ж�����������*/
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
	printf("������%d��̨����%d������", n, count);
	return 0;
}
