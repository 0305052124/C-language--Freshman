#define _CRT_SECURE_NO_WARNINGS 1
//����һ��5 * 5���󣬽����Խ��������������ÿ��Ԫ�ؼ�1��������ÿ��Ԫ�ؼ�1
#include<stdio.h>
int main()
{
	int a[5][5] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &a[i][j]);
		}
		printf("\n");
	}//������5*5�ľ���
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i > j)
			{
				a[i][j]--;
			}
			else if (i < j)
			{
				a[i][j]++;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}





