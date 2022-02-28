#define _CRT_SECURE_NO_WARNINGS 1
//鸡兔 98个头，386只脚
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
				printf("鸡有%d只，兔有%d只\n", j, i);
			}
		}
	}
	return 0;
}