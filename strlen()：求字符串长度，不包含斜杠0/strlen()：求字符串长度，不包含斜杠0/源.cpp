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
	char arr1[] = "I LOVE YOU";//定义一个数组，通过手算发现有10个字符
	int len = strlen(arr1);    //把个数存入len
	printf("%d", len);         //或写成  printf("%d", strlen(arr1));
	return 0;
}


