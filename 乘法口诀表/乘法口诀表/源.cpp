#define _CRT_SECURE_NO_WARNINGS 1
//����˷��ھ���
// �̶��ľžų˷���
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	int j = 1;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j < 10; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//�Զ���˷��ھ���
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int x = 1;
	scanf("%d", &x);
	for (i = 1; i <=x; i++)
	{
		for (j = 1; j <= x; j++)
		{
			printf("%2d*%2d=%3d ",i,j, i * j);
		}
		printf("\n");
	}
	return 0;
}













