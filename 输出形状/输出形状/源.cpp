#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1.����Ļ���������ͼ����
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************  13
// ***********
//  *********
//   *******
//    *****
//     ***
//      *

int main()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6 - i; j++)
		{
			printf(" ");
	    }
		for (int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 6; i < 13; i++)
	{
		for (int j = 0; j <i - 6; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 13 - 2 * (i - 6); j++)
		{
			printf("*");
		}
			printf("\n");
	}
	return 0;
}
//#include<stdio.h>
//int main()
//{
//	for (int i = 0; i < 6; i++)//�ϰ벿��
//	{
//		for (int j = 0; j < 6 - i; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//
//		}
//		printf("\n");
//	}
//	for (int i = 6; i < 13; i++)//�°벿��
//	{
//		for (int j = 0; j < i - 6; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < 13 - 2 * (i - 6); j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
