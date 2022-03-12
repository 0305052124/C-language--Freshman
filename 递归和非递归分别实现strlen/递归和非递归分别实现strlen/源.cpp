#define _CRT_SECURE_NO_WARNINGS 1
//递归和非递归分别实现strlen
//strlen（）函数是用来计算字符串的长度
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
	printf("  递归：%d \n", sum);
	printf("非递归：%d \n",ret);
	return 0;
}
