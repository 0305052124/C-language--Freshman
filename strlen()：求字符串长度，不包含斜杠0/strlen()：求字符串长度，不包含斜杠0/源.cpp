#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int My_strlen(const char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char arr1[] = "I LOVE YOU";//����һ�����飬ͨ�����㷢����10���ַ�
	int len = strlen(arr1);    //�Ѹ�������len
	printf("%d", len);         //��д��  printf("%d", strlen(arr1));
	return 0;
}


