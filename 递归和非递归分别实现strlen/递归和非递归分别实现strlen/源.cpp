#define _CRT_SECURE_NO_WARNINGS 1
//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//strlen�������������������ַ����ĳ���
#include<stdio.h>
int Mystrlen(char* arr)
{
	int count = 0;
	while (*arr)
	{
		arr++;
		count++;
	}
	return count;
}
int fibstrlen(char* arr)
{
	if (*arr == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + fibstrlen(arr + 1);
	}
}
int main()
{
	int size = 0;
	char arr[] = "fbdndfhmns";
	
	int ret =Mystrlen(arr);
	int sum = fibstrlen(arr);
	printf("  �ݹ飺%d \n", sum);
	printf("�ǵݹ飺%d \n",ret);
	return 0;
}
