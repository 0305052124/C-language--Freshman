#define _CRT_SECURE_NO_WARNINGS 1
//���� 98��ͷ��386ֻ��
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i < 98; i++)
	{
		for (j = 1; j < 98; j++)
		{
			if ((i + j == 98 )&& (4 * i + 2 * j == 386))
			{
				printf("����%dֻ������%dֻ\n", j, i);
			}
		}
	}
	return 0;
}