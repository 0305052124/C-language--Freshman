#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>
char* My_strcpy(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);
	char* ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	*dest = *src;
	return ret;
}
int main()
{
	char arr1[] = "I LOVE YOU";
	char arr2[] = "SORRY";
	My_strcpy(arr1, arr2);
	//��������My_strcpy�� ��arr1��Ӧ����arr2����ַ���SORRY
	printf("arr1: %s\n", arr1);
	return 0;
}